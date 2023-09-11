
#include <vector>
#include <spdlog/spdlog.h>
#include "RegisterServiceImpl.h"
#include "common/remote_attestation/untrusted/EnclaveQuote.h"
#include "common/base64/base64.h"


using namespace std;

#define PUB_KEY_SIZE 64
#define PUB_ENCRYPT_KEY_SIZE 512  //for RSA pem format

string mock_verification_report = "{\"nonce\":\"35E8FB64ACFB4A8E\",\"id\":\"284773557701539118279755254416631834508\",\"timestamp\":\"2018-07-11T19:30:35.556996\",\"epidPseudonym\":\"2iBfFyk5LE9du4skK9JjlRh1x5RvCIz/Z2nnoViIYY8W8TmIHg53UlEm2sp8NYVgT+LGSp0oxZgFcIg4p0BWxXqoBEEDnJFaVxgw0fS/RfhtF8yVNbVQjYjgQjw06wPalXzzNnjFpb873Rycj3JKSzkR3KfvKZfA/CJqEkTZK7U=\",\"isvEnclaveQuoteStatus\":\"GROUP_OUT_OF_DATE\",\"platformInfoBlob\":\"1502006504000700000808010101010000000000000000000007000006000000020000000000000AE791776C1D5C169132CA96D56CC2D59E5A46F23E39933DFB3B4962A8608AB53D84F77D254627D906B46F08073D33FF511E74BC318E8E0C37483C5B08899D1B5E9F\",\"isvEnclaveQuoteBody\":\"AgABAOcKAAAGAAUAAAAAAImTjvVbjrhQGXLFwbdtyMgAAAAAAAAAAAAAAAAAAAAABwf///8BAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAABwAAAAAAAAAHAAAAAAAAAMnL+UpC5HcF6MBCXsbYd5KUw2gc1tWgNPHNtK4g1NgKAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACp0uDGT8avpUCoA1LU47KLt5L/RJSpeFFT9807MyvETgAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAOeQAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAy7+m9Dx2rPbbbBWJUud3AHHnxoFWhlMQCyNjtVRvD2AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\"}";

grpc::Status RegisterServiceImpl::GetEngineInfo(::grpc::ServerContext* context, 
                                            const request_proto::EngineInfoRequest* request, 
                                            request_proto::EngineInfoResponse* response) {
    SPDLOG_INFO("--- GetEngineInfo start cosmos---");
    uint32_t error_code = StartRemoteAttestationCosmos(response);

    if (KEYMANAGEMENT_ERROR_CODE::kECALL_INIT_ERROR == error_code)
    {
        SPDLOG_INFO("fail to call key enclave, ecc_pubkey is null");
        response->set_error_info("fail to call key enclave, ecc_pubkey is null");
        return grpc::Status(grpc::StatusCode::INTERNAL, "fail to call key enclave, ecc_pubkey is null");
    }

    if (KEYMANAGEMENT_ERROR_CODE::kGET_QUOTE_ERROR == error_code)
    {
        SPDLOG_INFO("fail to call get enclave quote, ecc_pubkey is null");
        response->set_error_info("fail to call get enclave quote, ecc_pubkey is null");
        return grpc::Status(grpc::StatusCode::INTERNAL, "fail to call get enclave quote, ecc_pubkey is null");
    }

    SPDLOG_INFO("--- GetEngineInfo finish ---");
    return grpc::Status::OK;
}



KEYMANAGEMENT_ERROR_CODE RegisterServiceImpl::StartRemoteAttestationCosmos(request_proto::EngineInfoResponse *const register_resp) {

    KEYMANAGEMENT_ERROR_CODE enclave_ret;

    string attestation_verification_report;


    SPDLOG_INFO("start remote attestation");
    
#ifdef BUILD_ONLY_REGISTRATION_ENCLAVE
    int ret = ecall_init(eid, &enclave_ret);
#else
    int ret = KeyManagementEnclave_ecall_init(eid, &enclave_ret);
#endif

    if (ret != SGX_SUCCESS)
    {
        SPDLOG_INFO("failed to invoke KeyManagementEnclave_ecall_init, error code: " + ret);
        return KEYMANAGEMENT_ERROR_CODE::kECALL_INIT_ERROR;
    }
    if (KEYMANAGEMENT_ERROR_CODE::kKM_SUCCESS != enclave_ret)
    {
        SPDLOG_INFO("occur an error during init keyManagementEnclave, error code: " + enclave_ret);
        return enclave_ret;
    }
    

    uint8_t *pubkey = (uint8_t *)malloc(PUB_KEY_SIZE);
    uint8_t *pubEncryptKey = (uint8_t *)malloc(PUB_ENCRYPT_KEY_SIZE);

    std::shared_ptr<std::vector<uint8_t>> quote;
    KEYMANAGEMENT_ERROR_CODE error_code = GetEnclaveQuote(eid, pubkey, pubEncryptKey, quote);
    if (KEYMANAGEMENT_ERROR_CODE::kGET_QUOTE_ERROR == error_code)
    {
        return KEYMANAGEMENT_ERROR_CODE::kGET_QUOTE_ERROR;
    }
    

    // IntelIAS ias(intel_api_primary, intel_api_secondary, IntelIAS::DEVELOPMENT);
    // TODO change to real Intel IAS attestation report
    attestation_verification_report = mock_verification_report;

    std::string base64_pk = base64_encode((const unsigned char *)pubkey, PUB_KEY_SIZE);

    register_resp->set_enclave_pk(base64_pk);
    register_resp->set_ias_attestation_report(attestation_verification_report);

    SAFE_FREE(pubkey);
    SAFE_FREE(pubEncryptKey);

    return KEYMANAGEMENT_ERROR_CODE::kKM_SUCCESS;
}

