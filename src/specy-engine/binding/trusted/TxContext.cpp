#include "TxContext.h"
#include "common/base64/Transform.h"

#include "binding_enclave/BindingQuery.pb.h"
#include "e2e_message/E2EMessage.pb.h"
#include "e2e_message/Signature.pb.h"

#include "common/data_types/EnclaveId.h"
#include "common/local_attestation/trusted/RequestResponseUtil.h"
#include "key_management/KeyManagementExportFunction.h"
#include "rule/RuleExportFunction.h"
#include "BindingEnclave_t.h"
#include "test_utils/TestUtils.h"


using namespace std;
static const unsigned long kMaxOutSize = 8192UL;

// init Proof Request from string stream
// Todo
void TxContext::initTxContext (string& requestString) {
    BINDING_INFO("BindingEnclave: init proof request");
    this->taskRequest = new request_proto::TaskRequest();
    this->taskRequest->ParseFromString(requestString);

    BINDING_INFO("BindingEnclave: init enclave id");
    sgx_status_t status;
    uint32_t retcode;
    ocall_query_enclave_id(&retcode, uint64_t(SubModule::kKeyManagement), &this->keyEnclaveId);
    ocall_query_enclave_id(&retcode, uint64_t(SubModule::kBinding), &this->bindingEnclaveId);
    ocall_query_enclave_id(&retcode, uint64_t(SubModule::kRuleCheck), &this->ruleEnclaveId);
}


// serialize this->ruleChecRequest and call ruleCheck enclave for result
// Todo
void TxContext::checkRules() {

    e2e_message::E2ERequest e2eRuleCheckRequest;
    e2e_message::RuleCheckRequest* request = new e2e_message::RuleCheckRequest();
    request->set_taskhash(taskRequest->taskhash());
    
    e2eRuleCheckRequest.set_func_id((uint64_t)ExportedRuleFunction::kCheckRule);
    e2eRuleCheckRequest.set_allocated_rule_check_input(request);

    string rulecheckString = e2eRuleCheckRequest.SerializeAsString();

    BINDING_INFO_STRING(rulecheckString);

    BINDING_INFO("BindingEnclave: send rule check e2e request");
    string rulecheckResponseString;
    RequestResponseUtil::E2ERequestResponse(this->bindingEnclaveId, this->ruleEnclaveId,
                                        uint32_t(ExportedRuleFunction::kCheckRule),
                                        ENCLAVE_TO_ENCLAVE_CALL,
                                        rulecheckString, &rulecheckResponseString);

    BINDING_INFO("check response");
    BINDING_INFO_STRING(rulecheckResponseString);

    e2e_message::E2EResponse response;
    response.ParseFromString(rulecheckResponseString);
    ruleCheckResponse = new e2e_message::RuleCheckResponse(response.rule_check_output());
    BINDING_INFO_STRING(ruleCheckResponse->SerializeAsString());
    BINDING_INFO("BindingEnclave: receive response");
    BINDING_INFO("BindingEnclave: end check rules");
}
        
// get signature from key management enclave
// Todo
string TxContext::getSignature(const char* data) {

    e2e_message::E2ERequest signRequest;
    // mock an siganture request
    BINDING_INFO("BindingEnclave: start getting signature");
    e2e_message::SignInput* signData = new e2e_message::SignInput();

    signData->set_datas(data);
    signRequest.set_allocated_sign_input(signData);

    // // prepare e2e call
    string serializedSignRequest = signRequest.SerializeAsString();
    string serializedSignResonse;

    BINDING_INFO("BindingEnclave: send signature e2e request");
    RequestResponseUtil::E2ERequestResponse(this->bindingEnclaveId, this->keyEnclaveId,
                                            uint32_t(ExportedKeyManagementFunction::kSign),
                                            ENCLAVE_TO_ENCLAVE_CALL,
                                            serializedSignRequest, &serializedSignResonse);
    
    e2e_message::E2EResponse signResponse;
    if (!signResponse.ParseFromString(serializedSignResonse)) {
        BINDING_INFO("GetSignature failed! Invalid output!");
        return "";
    }

    if (signResponse.output_case() != e2e_message::E2EResponse::kSignOutput) {
        BINDING_INFO("GetSignature failed! Invalid output format!");
        return "";
    }

    const string& signString = signResponse.sign_output().signature();
    BINDING_INFO_STRING(signString);

    return signString;
}

// generate Proof Response
void TxContext::generateTaskResponse() {
    BINDING_INFO("generateTaskResponse start!");
    taskResponse = new request_proto::TaskResponse();
    taskResponse->set_taskhash(ruleCheckResponse->taskhash());
    taskResponse->set_rule_file_hash(ruleCheckResponse->rule_file_hash());
    request_proto::Result* result = new request_proto::Result();

    const e2e_message::RuleCheckResult& rule_check_result = ruleCheckResponse->result();
    result->set_status(rule_check_result.status());
    result->set_error_info(rule_check_result.error_info());
    result->set_task_result(rule_check_result.task_result());
    BINDING_INFO("generateTaskResponse start!");
    taskResponse->set_allocated_result(result);
    string response_string = taskResponse->SerializeAsString();
    string response_signature = getSignature(response_string.c_str());

    taskResponse->set_signature(response_signature);
    BINDING_INFO("generateTaskResponse end!");
}

void TxContext::serializeTaskResponse(char* output, size_t size) {
    string outputString = this->taskResponse->SerializeAsString();

    string encodeOutputString = EncodeFromStringToString(outputString);
    uint32_t outputSize = encodeOutputString.length() + 1;

    if (outputSize > size) {
        BINDING_INFO("Binding Enclave: Error! output data exceed the max output size! ");
        return;
    }

    BINDING_INFO("Binding Enclave: output proof response data");
    memcpy(output, encodeOutputString.c_str(), outputSize);
    BINDING_INFO(output);
    return;
}

TxContext::~TxContext() {
    SAFE_DELETE(taskRequest);
    SAFE_DELETE(taskResponse);
}
