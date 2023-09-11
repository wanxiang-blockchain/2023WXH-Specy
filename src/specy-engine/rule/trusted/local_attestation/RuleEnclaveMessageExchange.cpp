// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements local attestation methods.

#include "RuleEnclaveMessageExchange.h"

using namespace std;

extern std::map<sgx_enclave_id_t, dh_session_t> g_src_session_info_map;
extern std::mutex mtx_gSrcSessionInfoMap;

//Function pointer table containing the list of functions that the enclave exposes
const struct
{
    size_t num_funcs;
    const void *table[1];
} func_table = {
    1,
    {
        (const void *)check_rule_wrapper,
    }};

//Makes use of the sample code function to do an enclave to enclave call (Test Vector)
uint32_t ecall_enclave_to_enclave_call(sgx_enclave_id_t src_enclave_id,
                                       sgx_enclave_id_t dest_enclave_id)
{
    ATTESTATION_STATUS ke_status = (ATTESTATION_STATUS)kLA_SUCCESS;
    // param_struct_t *p_struct_var, struct_var;
    uint32_t target_fn_id, msg_type;
    char *marshalled_inp_buff;
    size_t marshalled_inp_buff_len;
    char *out_buff;
    size_t out_buff_len;
    dh_session_t *dest_session_info;
    size_t max_out_buff_size;
    char *retval;

    ocall_print_string("enter rule-check::ecall enclave_to_enclave_call", __FILE__, __LINE__);
    // TODO test function and parameters
    max_out_buff_size = RequestResponseUtil::kMaxOutBuffSize;
    target_fn_id = 0;
    msg_type = ENCLAVE_TO_ENCLAVE_CALL;

    // struct_var.var1 = 0x3;
    // struct_var.var2 = 0x4;
    // p_struct_var = &struct_var;

    // TEST generate mock binding request input
    // string serialized_request_input = RequestResponseUtil::GenerateSerializedEntityRequest();
    string serialized_request_input;

    //Marshals the input parameters for calling function foo1 in Enclave3 into a input buffer
    // ke_status = marshal_input_parameters_e3_foo1(target_fn_id, msg_type, p_struct_var, &marshalled_inp_buff, &marshalled_inp_buff_len);
    ke_status = RequestResponseUtil::MarshalFunctionInput(target_fn_id, msg_type, &serialized_request_input,
                                                          &marshalled_inp_buff, &marshalled_inp_buff_len);
    if (ke_status != (ATTESTATION_STATUS)kLA_SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        return ke_status;
    }

    mtx_gSrcSessionInfoMap.lock();
    //Search the map for the session information associated with the destination enclave id passed in
    std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    if (it != g_src_session_info_map.end())
    {
        dest_session_info = &it->second;
    }
    else
    {
        mtx_gSrcSessionInfoMap.unlock();
        SAFE_FREE(marshalled_inp_buff);
        return (uint32_t)kLA_INVALID_SESSION;
    }
    mtx_gSrcSessionInfoMap.unlock();

    //Core Reference Code function
    ke_status = send_request_receive_response(src_enclave_id, dest_enclave_id, dest_session_info, marshalled_inp_buff,
                                              marshalled_inp_buff_len, max_out_buff_size, &out_buff, &out_buff_len);

    if (ke_status != (ATTESTATION_STATUS)kLA_SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        SAFE_FREE(out_buff);
        return ke_status;
    }
    SAFE_FREE(marshalled_inp_buff);

    // protocol buffer serialized response output
    string seralized_response_output;

    //Un-marshal the return value and output parameters from foo1 of Enclave3
    // ke_status = unmarshal_retval_and_output_parameters_e3_foo1(out_buff, p_struct_var, &retval);
    ke_status = RequestResponseUtil::UnmarshalFunctionOutput(out_buff, &seralized_response_output);
    if (ke_status != (ATTESTATION_STATUS)kLA_SUCCESS)
    {
        SAFE_FREE(out_buff);
        return ke_status;
    }

    SAFE_FREE(out_buff);
    ocall_print_string("exit rule-check::ecall enclave_to_enclave_call", __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}

//Makes use of the sample code function to do a generic secret message exchange (Test Vector)
uint32_t ecall_message_exchange(sgx_enclave_id_t src_enclave_id,
                                sgx_enclave_id_t dest_enclave_id)
{
    
}

//Function that is used to verify the trust of the other enclave
//Each enclave can have its own way verifying the peer enclave identity
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

//Dispatch function that calls the approriate enclave function based on the function id
//Each enclave can have its own way of dispatching the calls from other enclave
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
    
}

//Generates the response from the request message
extern "C" uint32_t message_exchange_response_generator(char *decrypted_data,
                                                        char **resp_buffer,
                                                        size_t *resp_length)
{
    
}