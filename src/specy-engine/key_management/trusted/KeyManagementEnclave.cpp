// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements utils functions which is used for key management.

#include "KeyManagementEnclave.h"
#include "common/local_attestation/trusted/EnclaveMessageExchange.h"

using namespace e2e_message;

// enclave sk and pk (both are little endian) used for out signatures
sgx_ec256_private_t enclave_sk = {0};
sgx_ec256_public_t enclave_pk = {0};

// Local copy of previous SGX report and corresponding pub/priv key
// TODO How to deal with enclave shutdown?
bool local_key_pairs_exist = false;
// enclave sk and pk used for out encryption
const int RSA_KEY_SIZE = 256;
//  *g_enclave_rsa = NULL;
char *g_enclave_rsa_pub = NULL; // PEM encoded RSA public key
// creates new identity if not exists
// extern G_Session_Info_Map g_session_info_map;
// test code for local attestation
#define UNUSED(val) (void)(val)

extern std::map<sgx_enclave_id_t, dh_session_t> g_src_session_info_map;

// sign_challenge_wrapper is used to wrap sign_chanllenge function,
// which signs the cproof with private key.
// Params: ms: the input function parameter structrue
//         param_lenth: the length of input data
// Return: resp_buffer: the output result of function
//         resp_length: the length of output data
static uint32_t sign_challenge_wrapper(ms_in_msg_exchange_t *ms, size_t param_lenth,
                                       char **resp_buffer, size_t *resp_length);
const struct
{
    size_t num_funcs;
    const void *table[1];
} func_table = {
    1,
    {
        (const void *)sign_challenge_wrapper,
    }};

//Makes use of the sample code function to do an enclave to enclave call (Test Vector)
uint32_t ecall_enclave_to_enclave_call(sgx_enclave_id_t src_enclave_id,
                                       sgx_enclave_id_t dest_enclave_id)
{
    ocall_print_string("enter key_management::ecall enclave_to_enclave_call", __FILE__, __LINE__);
    ATTESTATION_STATUS ke_status = (ATTESTATION_STATUS)kLA_SUCCESS;
    uint32_t var1, var2;
    uint32_t target_fn_id, msg_type;
    char *marshalled_inp_buff;
    size_t marshalled_inp_buff_len;
    char *out_buff;
    size_t out_buff_len;
    dh_session_t *dest_session_info;
    size_t max_out_buff_size;
    char *retval;

    var1 = 0x4;
    var2 = 0x5;
    target_fn_id = 0;
    msg_type = (uint32_t)ENCLAVE_TO_ENCLAVE_CALL;
    max_out_buff_size = 50;

    //Marshals the input parameters for calling function foo1 in Enclave2 into a input buffer
    ke_status = marshal_input_parameters_e2_foo1(target_fn_id, msg_type, var1, var2, &marshalled_inp_buff, &marshalled_inp_buff_len);
    if (ke_status != (ATTESTATION_STATUS)kLA_SUCCESS)
    {
        return ke_status;
    }

    //Search the map for the session information associated with the destination enclave id of Enclave2 passed in
    std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    if (it != g_src_session_info_map.end())
    {
        dest_session_info = &it->second;
    }
    else
    {
        // SAFE_FREE(marshalled_inp_buff);
        return (uint32_t)kLA_INVALID_SESSION;
    }

    //Core Reference Code function
    ke_status = send_request_receive_response(src_enclave_id, dest_enclave_id, dest_session_info, marshalled_inp_buff,
                                              marshalled_inp_buff_len, max_out_buff_size, &out_buff, &out_buff_len);

    if (ke_status != (uint32_t)kLA_SUCCESS)
    {
        // SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }

    //Un-marshal the return value and output parameters from foo1 of Enclave 2
    ke_status = unmarshal_retval_and_output_parameters_e2_foo1(out_buff, &retval);
    if (ke_status != (uint32_t)kLA_SUCCESS)
    {
        // SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }

    // SAFE_FREE(marshalled_inp_buff);
    SAFE_FREE(out_buff);
    // SAFE_FREE(retval);
    ocall_print_string("exit key_management::ecall enclave_to_enclave_call", __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}

uint32_t ecall_message_exchange(sgx_enclave_id_t src_enclave_id,
                                sgx_enclave_id_t dest_enclave_id)
{
    ATTESTATION_STATUS ke_status = (uint32_t)kLA_SUCCESS;
    uint32_t target_fn_id, msg_type;
    char *marshalled_inp_buff;
    size_t marshalled_inp_buff_len;
    char *out_buff;
    size_t out_buff_len;
    dh_session_t *dest_session_info;
    size_t max_out_buff_size;
    char *secret_response;
    uint32_t secret_data;

    ocall_print_string("enter key_management::ecall message_exchange", __FILE__, __LINE__);

    target_fn_id = 0;
    msg_type = MESSAGE_EXCHANGE;
    max_out_buff_size = 50;
    secret_data = 0x12345678; //Secret Data here is shown only for purpose of demonstration.

    //Marshals the secret data into a buffer
    ke_status = marshal_message_exchange_request(target_fn_id, msg_type, secret_data, &marshalled_inp_buff, &marshalled_inp_buff_len);
    if (ke_status != (uint32_t)kLA_SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        return ke_status;
    }
    //Search the map for the session information associated with the destination enclave id passed in
    std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    if (it != g_src_session_info_map.end())
    {
        dest_session_info = &it->second;
    }
    else
    {
        SAFE_FREE(marshalled_inp_buff);
        return (uint32_t)kLA_INVALID_SESSION;
    }

    //Core Reference Code function
    ke_status = send_request_receive_response(src_enclave_id, dest_enclave_id, dest_session_info, marshalled_inp_buff,
                                              marshalled_inp_buff_len, max_out_buff_size, &out_buff, &out_buff_len);
    if (ke_status != (uint32_t)kLA_SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }
    SAFE_FREE(marshalled_inp_buff);

    //Un-marshal the secret response data
    ke_status = umarshal_message_exchange_response(out_buff, &secret_response);
    if (ke_status != (uint32_t)kLA_SUCCESS)
    {
        // SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(secret_response);
        SAFE_FREE(out_buff);
        return ke_status;
    }

    // SAFE_FREE(marshalled_inp_buff);
    SAFE_FREE(out_buff);
    // SAFE_FREE(secret_response);
    
    // TODO (Xufei) What's next about secret_response?
    ocall_print_string("exit key_management::ecall message exchange", __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}

extern "C" uint32_t verify_peer_enclave_trust(sgx_dh_session_enclave_identity_t *peer_enclave_identity)
{
    if (!peer_enclave_identity)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
    if (peer_enclave_identity->isv_prod_id != 0 || !(peer_enclave_identity->attributes.flags & SGX_FLAGS_INITTED))
    // || peer_enclave_identity->attributes.xfrm !=3)// || peer_enclave_identity->mr_signer != xx //TODO: To be hardcoded with values to check
    {
        return (uint32_t)kLA_ENCLAVE_TRUST_ERROR;
    }
    else
    {
        return (uint32_t)kLA_SUCCESS;
    }
}

extern "C" uint32_t enclave_to_enclave_call_dispatcher(char *decrypted_data,
                                                       size_t decrypted_data_length,
                                                       char **resp_buffer,
                                                       size_t *resp_length)
{
    ms_in_msg_exchange_t *ms;
    uint32_t (*fn1)(ms_in_msg_exchange_t * ms, size_t, char **, size_t *);
    if (!decrypted_data || !resp_length)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
    ms = (ms_in_msg_exchange_t *)decrypted_data;
    if (ms->target_fn_id >= func_table.num_funcs)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
    fn1 = (uint32_t(*)(ms_in_msg_exchange_t *, size_t, char **, size_t *))func_table.table[ms->target_fn_id];
    return fn1(ms, decrypted_data_length, resp_buffer, resp_length);
}

//Operates on the input secret and generates the output secret
uint32_t get_message_exchange_response(uint32_t inp_secret_data)
{
    uint32_t secret_response;

    //User should use more complex encryption method to protect their secret, below is just a simple example
    secret_response = inp_secret_data & 0x11111111;

    return secret_response;
}

extern "C" uint32_t message_exchange_response_generator(char *decrypted_data,
                                                        char **resp_buffer,
                                                        size_t *resp_length)
{
    ms_in_msg_exchange_t *ms;
    uint32_t inp_secret_data;
    uint32_t out_secret_data;
    if (!decrypted_data || !resp_length)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }
    ms = (ms_in_msg_exchange_t *)decrypted_data;

    if (umarshal_message_exchange_request(&inp_secret_data, ms) != (uint32_t)kLA_SUCCESS)
        return (uint32_t)kLA_ATTESTATION_ERROR;

    out_secret_data = get_message_exchange_response(inp_secret_data);

    if (marshal_message_exchange_response(resp_buffer, resp_length, out_secret_data) != (uint32_t)kLA_SUCCESS) {
        SAFE_FREE(*resp_buffer);
        return (uint32_t)kLA_MALLOC_ERROR;
    }
        

    ocall_print_string(*resp_buffer, __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}

// sign_challenge_wrapper is used to wrap sign_chanllenge function,
// which signs the cproof with private key.
static uint32_t sign_challenge_wrapper(ms_in_msg_exchange_t *ms,
                                       size_t param_lenth,
                                       char **resp_buffer,
                                       size_t *resp_length)
{
    UNUSED(param_lenth);

    if (!ms || !resp_length)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    // parse function request input
    string function_input;
    if (RequestResponseUtil::UnmarshalFunctionInput(&function_input, ms) != (uint32_t)kLA_SUCCESS)
        return (uint32_t)kLA_ATTESTATION_ERROR;

    E2ERequest e2e_request;
    ocall_print_string(string("sign_challenge_wrapper::function_input:" + function_input).c_str(), __FILE__, __LINE__);
    e2e_request.ParseFromString(function_input);
    if (!e2e_request.has_sign_input())
    {
        ocall_print_string("sign_challenge_wrapper::no sign input", __FILE__, __LINE__);
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    SignInput request_input;
    request_input = e2e_request.sign_input();

    string challenge = request_input.datas();
    // prepare input parameters

    uint8_t sig[sizeof(sgx_ec256_signature_t)];
    ocall_print_string(string("sign_challenge_wrapper::request_input.datas:" + challenge).c_str(), __FILE__, __LINE__);

    int ret = sign_challenge(challenge, &enclave_sk, (sgx_ec256_signature_t *)sig);
    if (ret != 0)
    {
        ocall_print_string("sign_challenge_wrapper::sign chanllenge error", __FILE__, __LINE__);
    }

    std::string base64_sig = base64_encode((const unsigned char *)sig, sizeof(sgx_ec256_signature_t));

    SignOutput *response_output = new SignOutput();
    response_output->set_signature(base64_sig);

    // construct rule check response output
    E2EResponse e2e_response;
    e2e_response.set_allocated_sign_output(response_output);

    // build output value
    string function_output;
    if (!e2e_response.SerializeToString(&function_output))
    {
        // SAFE_DELETE(response_output);
        ocall_print_string("sign_challenge_wrapper::serialize function output error", __FILE__, __LINE__);
        return (uint32_t)kLA_ATTESTATION_ERROR;
    }

    // SAFE_DELETE(response_output);
    // serialize function response output
    if (RequestResponseUtil::MarshalFunctionOutput(resp_buffer, resp_length, &function_output) != (uint32_t)kLA_SUCCESS)
        return (uint32_t)kLA_MALLOC_ERROR; //can set resp buffer to null here

    ocall_print_string("exit sign_challenge_wrapper", __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}

// ecall_init is used to init KeyManagement enclave and generate ecc265 key pairs.
// Params: void
// Return: KEYMANAGEMENT_ERROR_CODE: status of ecall_init
KEYMANAGEMENT_ERROR_CODE ecall_init(void)
{
    //  if (!local_key_pairs_exist){
    // 	// create new pub/prv key pair with RSA algorithm for encryption
    // int ret = 0;
    // //        RSA *rsa = NULL;
    // BIGNUM *bne = NULL;
    // BIO *bp_public = BIO_new(BIO_s_mem()), *bp_private = BIO_new(BIO_s_mem());

    // int bits = RSA_KEY_SIZE * 8; // This should be 2048
    // unsigned long e = RSA_F4;

    // char *err = (char*)malloc(130);

    // /*------------------- RSA Public Key -------------------*/
    // // 1. generate rsa key
    // ocall_print_string("Trying to generate new Big Number\n");
    // bne = BN_new();
    // ret = BN_set_word(bne, e);
    // if(ret != 1) {
    // 		ERR_load_crypto_strings();
    // 		ERR_error_string(ERR_get_error(), err);
    // 		ocall_print_string("Failed to generate new Big Number: ");
    // 		ocall_print_string(err);
    // 	ocall_print_string("\n");

    // 		ocall_print_string("Now free all allocated pointers\n");

    // 		BIO_free_all(bp_public);
    // 		BIO_free_all(bp_private);
    // 		BN_free(bne);

    // 		SAFE_FREE(err);
    // 		return SGX_ERROR_UNEXPECTED;
    // }

    // ocall_print_string("Trying to generate new RSA key\n");
    // g_enclave_rsa = RSA_new(); // Enclave global RSA key
    // ret = RSA_generate_key_ex(g_enclave_rsa, bits, bne, NULL);
    // if(ret != 1){
    // 		ERR_load_crypto_strings();
    // 		ERR_error_string(ERR_get_error(), err);
    // 		ocall_print_string("Failed to generate new RSA key\n");
    // 		ocall_print_string(err);
    // 		ocall_print_string("\n");

    // 		ocall_print_string("Now free all allocated pointers\n");

    // 		BIO_free_all(bp_public);
    // 		BIO_free_all(bp_private);
    // 		BN_free(bne);

    // 		RSA_free(g_enclave_rsa);

    // 		SAFE_FREE(err);
    // 		return SGX_ERROR_UNEXPECTED;
    // }

    // // 2. encrypt with public key
    // char *msg = "Hello World!\0";
    // char *cipher_msg = (char*)malloc(RSA_size(g_enclave_rsa));
    // int cipher_len = 0;

    // cipher_len = RSA_public_encrypt(strlen(msg) + 1, (unsigned char*)msg,
    //     	                        (unsigned char*)cipher_msg, g_enclave_rsa,
    //             	                RSA_PKCS1_OAEP_PADDING);
    // if (cipher_len == -1 || cipher_len != RSA_size(g_enclave_rsa)) {
    // 		ERR_load_crypto_strings();
    // 		ERR_error_string(ERR_get_error(), err);
    // 		ocall_print_string("Failed to encrypt message with RSA public key\n");
    // 		ocall_print_string(err);
    // 		ocall_print_string("\n");

    // 		ocall_print_string("Now free all allocated pointers\n");

    // 		BIO_free_all(bp_public);
    // 		BIO_free_all(bp_private);
    // 		BN_free(bne);

    // 		RSA_free(g_enclave_rsa);

    // 		SAFE_FREE(cipher_msg);
    // 		SAFE_FREE(err);
    // 	return SGX_ERROR_UNEXPECTED;
    // }

    // ocall_print_string("Cipher message: ");
    // ocall_print_string(base64_encode((unsigned char*)cipher_msg, RSA_size(g_enclave_rsa)).c_str());
    // ocall_print_string("\n");

    // // 3. decrypt with private key
    // char *decrypt_msg = (char*)malloc(RSA_size(g_enclave_rsa));
    // int plain_len = 0;

    // plain_len = RSA_private_decrypt(cipher_len, (unsigned char*)cipher_msg,
    //     	                        (unsigned char*)decrypt_msg,
    //             	                g_enclave_rsa, RSA_PKCS1_OAEP_PADDING);
    // if (plain_len == -1 || plain_len != strlen(msg) + 1) {
    // 		ERR_load_crypto_strings();
    // 		ERR_error_string(ERR_get_error(), err);
    // 		ocall_print_string("Failed to encrypt message with RSA public key\n");
    // 		ocall_print_string(err);
    // 		ocall_print_string("\n");

    // 		ocall_print_string("Now free all allocated pointers\n");

    // 		BIO_free_all(bp_public);
    // 		BIO_free_all(bp_private);
    // 	BN_free(bne);

    // 		RSA_free(g_enclave_rsa);

    // 		SAFE_FREE(cipher_msg);
    // 		SAFE_FREE(decrypt_msg);
    // 		SAFE_FREE(err);
    // 		return SGX_ERROR_UNEXPECTED;
    // }

    // ocall_print_string("Decrypt plain message: ");
    // ocall_print_string(decrypt_msg);
    // ocall_print_string("\n");

    // // 4. store PEM encoded RSA public key
    // ocall_print_string("Trying to convert into PEM encoded RSA public key\n");

    // if (!PEM_write_bio_RSAPublicKey(bp_public, g_enclave_rsa)) {
    // 		ocall_print_string("Failed to write RSA public key to PEM\n");
    // 		BIO_free_all(bp_public);
    // 		BIO_free_all(bp_private);
    // 		BN_free(bne);

    // 		RSA_free(g_enclave_rsa);

    // 		SAFE_FREE(cipher_msg);
    // 		SAFE_FREE(decrypt_msg);
    // 		SAFE_FREE(err);
    // 		return SGX_ERROR_UNEXPECTED;
    // }

    // if (!PEM_write_bio_RSAPrivateKey(bp_private, g_enclave_rsa, NULL, NULL, 0, NULL, NULL)) {
    // 		ocall_print_string("Failed to write RSA private key to PEM\n");
    // 		BIO_free_all(bp_public);
    // 		BIO_free_all(bp_private);
    // 		BN_free(bne);

    // 		RSA_free(g_enclave_rsa);

    // 		SAFE_FREE(cipher_msg);
    // 		SAFE_FREE(decrypt_msg);
    // 		SAFE_FREE(err);
    // 		return SGX_ERROR_UNEXPECTED;
    // }

    // size_t bp_public_len = BIO_pending(bp_public);
    // size_t bp_private_len = BIO_pending(bp_private);

    // char *l_rsa_pub_key = (char*)malloc(bp_public_len + 1);
    // BIO_read(bp_public, l_rsa_pub_key, bp_public_len);
    // l_rsa_pub_key[bp_public_len] = '\0';

    // ocall_print_string("RSA Public Key (in PEM):\n");
    // ocall_print_string(l_rsa_pub_key);
    // ocall_print_string("\n");

    // char *l_rsa_pri_key = (char*)malloc(bp_private_len + 1);
    // BIO_read(bp_private, l_rsa_pri_key, bp_private_len);
    // l_rsa_pri_key[bp_private_len] = '\0';

    // ocall_print_string("RSA Private Key (in PEM):\n");
    // ocall_print_string(l_rsa_pri_key);
    // ocall_print_string("\n");

    // g_enclave_rsa_pub = (char*)malloc(bp_public_len + 1);
    // memcpy(g_enclave_rsa_pub, l_rsa_pub_key, bp_public_len);
    // g_enclave_rsa_pub[bp_public_len] = '\0';

    // // 5. free all the allocated memory
    // BIO_free_all(bp_public);
    // BIO_free_all(bp_private);
    // BN_free(bne);

    // SAFE_FREE(cipher_msg);
    // SAFE_FREE(decrypt_msg);
    // SAFE_FREE(err);

    // SAFE_FREE(l_rsa_pub_key);
    // SAFE_FREE(l_rsa_pri_key);

    // create new pub/prv key pair with ECC algorithm for signature
    sgx_ecc_state_handle_t ecc_handle = NULL;
    sgx_status_t sgx_ret = sgx_ecc256_open_context(&ecc_handle);
    if (sgx_ret != SGX_SUCCESS)
    {
        // LOG_DEBUG("Enclave: sgx_ecc256_open_context: %d", sgx_ret);
        return KEYMANAGEMENT_ERROR_CODE::kECALL_INIT_ERROR;
    }
    // LOG_ERROR("ENCLAVE_INIT: 6");
    // create pub and private signature key
    sgx_ret = sgx_ecc256_create_key_pair(&enclave_sk, &enclave_pk, ecc_handle);
    if (sgx_ret != SGX_SUCCESS)
    {
        // LOG_DEBUG("Enclave: sgx_ecc256_create_key_pair: %d", sgx_ret);
        return KEYMANAGEMENT_ERROR_CODE::kECALL_INIT_ERROR;
    }
    // LOG_ERROR("ENCLAVE_INIT: 6.5");
    sgx_ecc256_close_context(ecc_handle);//TODO error code
    // LOG_ERROR("ENCLAVE_INIT: 6.7");
    std::string base64_pk = base64_encode((const unsigned char *)&enclave_pk, sizeof(sgx_ec256_public_t));
    // LOG_ERROR("ENCLAVE_INIT: 6.8");
    // LOG_DEBUG("Enc: Enclave pk (little endian): %s", base64_pk.c_str());
    // LOG_ERROR("ENCLAVE_INIT: 7");
    // LOG_DEBUG("Enc: Identity generated!");
    // Mark local key pairs as exists
    //     local_key_pairs_exist = true;
    // }
    // TODO free 
    return KEYMANAGEMENT_ERROR_CODE::kKM_SUCCESS;
}

// ecall_create_report is used to generate report for remote attestation.
// Return: target: the SGX internal data structure
//         report_out: the SGX internal data structure
//         pubkey_out: the ecc256 public key generated by KeyManagement enclave
//         pubEncryptKey_out: maybe useless?
//         KEYMANAGEMENT_ERROR_CODE: the status of ecall_create_report
KEYMANAGEMENT_ERROR_CODE ecall_create_report(
    const sgx_target_info_t *target, sgx_report_t *report_out, uint8_t *pubkey_out, uint8_t *pubEncryptKey_out)
{
    sgx_report_t report;
    sgx_report_data_t report_data = {{0}};

    memset(&report, 0, sizeof(report));
    
    // transform enclave_pk to Big Endian before hashing
    uint8_t enclave_pk_be[sizeof(sgx_ec256_public_t)];
    memcpy(enclave_pk_be, &enclave_pk, sizeof(sgx_ec256_public_t));
    bytes_swap(enclave_pk_be, 32);
    bytes_swap(enclave_pk_be + 32, 32);
    // LOG_ERROR("ENCLAVE: 1");
    // write H(enclave_pk) in report data
    assert(sizeof(report_data) >= sizeof(sgx_sha256_hash_t));
    // TOTO error code
    sgx_sha256_msg(enclave_pk_be, sizeof(sgx_ec256_public_t), (sgx_sha256_hash_t *)&report_data);
    // write H(g_enclave_rsa_pub) in report data
    // LOG_ERROR("ENCLAVE: 2");
    // TOTO error code
    sgx_sha256_msg((const uint8_t *)g_enclave_rsa_pub, RSA_KEY_SIZE, (sgx_sha256_hash_t *)(report_data.d + 256));

    // copy enclave_pk_be outside
    memcpy(pubkey_out, enclave_pk_be, sizeof(sgx_ec256_public_t));
    // copy enclave RSA public key outside
    // LOG_ERROR("ENCLAVE: 3");

    // memcpy(pubEncryptKey_out, g_enclave_rsa_pub, strlen(g_enclave_rsa_pub) + 1);

    // create the report
    sgx_status_t ret = sgx_create_report(target, &report_data, &report);
    if (ret != SGX_SUCCESS)
    {
        // LOG_ERROR("Enclave: Error while creating report");
        return KEYMANAGEMENT_ERROR_CODE::kCREATE_REPORT_ERROR;
    }
    memcpy(report_out, &report, sizeof(sgx_report_t));
    // LOG_ERROR("ENCLAVE: 4");
    // LOG_DEBUG("Enc: Report generated!");
    return KEYMANAGEMENT_ERROR_CODE::kKM_SUCCESS;
}

// ecall_get_pk is used to get ec265 public key and return enclave pk in Big Endian format.
// Params: void
// Return: pubkey: the generated ec256 public key
//         KEYMANAGEMENT_ERROR_CODE: the status of ecall_get_pk
KEYMANAGEMENT_ERROR_CODE ecall_get_pk(uint8_t *pubkey)
{
    // transform enclave_pk to Big Endian before hashing
    uint8_t enclave_pk_be[sizeof(sgx_ec256_public_t)];
    if (sizeof(sgx_ec256_public_t) == 0)
    {
        return KEYMANAGEMENT_ERROR_CODE::kGET_PK_KEY_ERROR;
    }

    memcpy(enclave_pk_be, &enclave_pk, sizeof(sgx_ec256_public_t));
    bytes_swap(enclave_pk_be, 32);
    bytes_swap(enclave_pk_be + 32, 32);

    memcpy(pubkey, &enclave_pk_be, sizeof(sgx_ec256_public_t));

    // LOG_DEBUG("Enc: Return enclave pk as Big Endian");
    return KEYMANAGEMENT_ERROR_CODE::kKM_SUCCESS;
}