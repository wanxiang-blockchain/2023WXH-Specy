// For Binding Function Request
// NOTE:
// Do not use `ocall_print_string` in this file.
// `ocall_print_string` function is defined in 'UntrustedEnclaveMessageExchange.h',
// while this file has to include 'EnclaveMessageExchange.h'. There are some same function declarations.
#include "common/local_attestation/trusted/RequestResponseUtil.h"
using namespace std;

uint32_t RequestResponseUtil::MarshalFunctionInput(uint32_t target_fn_id,
                                                   uint32_t msg_type,
                                                   string *function_input,
                                                   char **marshalled_buff,
                                                   size_t *marshalled_buff_len)
{
    ms_in_msg_exchange_t *ms;
    size_t param_len, ms_len;
    char *temp_buff;

    if (!function_input || !marshalled_buff_len)
    {
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    }

    param_len = function_input->length();
    temp_buff = (char *)malloc(param_len);
    if (!temp_buff)
    {
        SAFE_FREE(temp_buff);
        return (uint32_t)kLA_MALLOC_ERROR;
    }

    memcpy(temp_buff, function_input->c_str(), param_len); //can be optimized
    //ocall_print_string(function_input->c_str());

    //ocall_print_string(temp_buff);
    ms_len = sizeof(ms_in_msg_exchange_t) + param_len;
    ms = (ms_in_msg_exchange_t *)malloc(ms_len);
    if (!ms)
    {
        SAFE_FREE(temp_buff);
        SAFE_FREE(ms);
        return (uint32_t)kLA_MALLOC_ERROR;
    }
    ms->msg_type = msg_type;
    ms->target_fn_id = target_fn_id;
    ms->inparam_buff_len = (uint32_t)param_len;
    // TODO (xufei): why &?
    memcpy(&ms->inparam_buff, temp_buff, param_len);

    *marshalled_buff_len = ms_len;
    *marshalled_buff = (char *)ms;
    // *marshalled_buff = (char *)malloc(*marshalled_buff_len);
    // memset(*marshalled_buff, 0, *marshalled_buff_len);
    // memcpy(*marshalled_buff, (char *)ms, ms_len);

    SAFE_FREE(temp_buff);
    // SAFE_FREE(ms);
    return (uint32_t)kLA_SUCCESS;
}

uint32_t RequestResponseUtil::UnmarshalFunctionOutput(char *out_buff, string *function_output)
{
    ocall_print_string("enter UnmarshalFunctionOutput", __FILE__, __LINE__);
    size_t retval_len;
    ms_out_msg_exchange_t *ms;
    if (!out_buff)
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;
    ms = (ms_out_msg_exchange_t *)out_buff;
    retval_len = ms->retval_len;
    //function_output = new string();
    //function_output->copy(ms->ret_outparam_buff, retval_len);
    (*function_output).assign(ms->ret_outparam_buff, retval_len);
    // ocall_print_string(function_output->c_str(), __FILE__, __LINE__);
    ocall_print_string("exit UnmarshalFunctionOutput", __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}

/* For Rule Function Response */

uint32_t RequestResponseUtil::UnmarshalFunctionInput(string *function_input, ms_in_msg_exchange_t *ms)
{
    char *buff;
    size_t len;
    if (!function_input || !ms)
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;

    buff = ms->inparam_buff;
    len = ms->inparam_buff_len;

    //function_input->copy(buff, len);
    function_input->assign(buff, len);
    return (uint32_t)kLA_SUCCESS;
}

uint32_t RequestResponseUtil::MarshalFunctionOutput(char **resp_buffer, size_t *resp_length, string *function_output)
{
    ms_out_msg_exchange_t *ms;
    size_t ret_param_len, ms_len;
    char *temp_buff;
    size_t retval_len;
    if (!resp_length)
        return (uint32_t)kLA_INVALID_PARAMETER_ERROR;

    retval_len = function_output->length();
    ret_param_len = retval_len; //no out parameters
    temp_buff = (char *)malloc(ret_param_len);
    if (!temp_buff)
    {
        SAFE_FREE(temp_buff);
        return (uint32_t)kLA_MALLOC_ERROR;
    }

    memcpy(temp_buff, function_output->c_str(), retval_len);

    ms_len = sizeof(ms_out_msg_exchange_t) + ret_param_len;
    ms = (ms_out_msg_exchange_t *)malloc(ms_len);
    if (!ms)
    {
        SAFE_FREE(temp_buff);
        SAFE_FREE(ms);
        return (uint32_t)kLA_MALLOC_ERROR;
    }

    ms->retval_len = (uint32_t)retval_len;
    ms->ret_outparam_buff_len = (uint32_t)ret_param_len;
    memcpy(&ms->ret_outparam_buff, temp_buff, ret_param_len);

    //resp_buffer = (char *)ms;
    *resp_length = ms_len;
    *resp_buffer = (char *)ms;
    // *resp_buffer = (char *)malloc(*resp_length);
    // memset(*resp_buffer, 0, *resp_length);
    // memcpy(*resp_buffer, (char *)ms, ms_len);

    SAFE_FREE(temp_buff);
    // SAFE_FREE(ms);
    return (uint32_t)kLA_SUCCESS;
}

// Helper Functions for E2E Call Request and Response
uint32_t RequestResponseUtil::E2ERequestResponse(sgx_enclave_id_t src_enclave_id,
                                                 sgx_enclave_id_t dest_enclave_id,
                                                 uint32_t target_fn_id,
                                                 uint32_t msg_type,
                                                 string serialized_request_input,
                                                 string *serialized_response_output)
{
    ocall_print_string("enter E2ERequestResponse", __FILE__, __LINE__);
    uint32_t ke_status = (uint32_t)kLA_SUCCESS;
    // param_struct_t *p_struct_var, struct_var;
    // uint32_t target_fn_id, msg_type;
    char *marshalled_inp_buff;
    size_t marshalled_inp_buff_len;
    char *out_buff;
    size_t out_buff_len;
    dh_session_t *dest_session_info;
    size_t max_out_buff_size = kMaxOutBuffSize;
    char *retval;

    ocall_print_string(serialized_request_input.c_str(), __FILE__, __LINE__);
    //Marshals the input parameters for calling function foo1 in Enclave3 into a input buffer
    // ke_status = marshal_input_parameters_e3_foo1(target_fn_id, msg_type, p_struct_var, &marshalled_inp_buff, &marshalled_inp_buff_len);
    ke_status = RequestResponseUtil::MarshalFunctionInput(target_fn_id, msg_type, &serialized_request_input,
                                                          &marshalled_inp_buff, &marshalled_inp_buff_len);
    if (ke_status != (ATTESTATION_STATUS)kLA_SUCCESS)
    {
        SAFE_FREE(marshalled_inp_buff);
        ocall_print_string("exit E2ERequestResponse::MarshalFunctionInput Error", __FILE__, __LINE__);
        return ke_status;
    }

    //Search the map for the session information associated with the destination enclave id passed in
    mtx_gSrcSessionInfoMap.lock();
    std::map<sgx_enclave_id_t, dh_session_t>::iterator it = g_src_session_info_map.find(dest_enclave_id);
    if (it != g_src_session_info_map.end())
    {
        dest_session_info = &it->second;
    }
    else
    {
        mtx_gSrcSessionInfoMap.unlock();
        SAFE_FREE(marshalled_inp_buff);
        ocall_print_string("exit E2ERequestResponse::INVALID_SESSION Error", __FILE__, __LINE__);
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
        ocall_print_string("exit E2ERequestResponse::send_request_receive_response Error", __FILE__, __LINE__);
        return ke_status;
    }
    SAFE_FREE(marshalled_inp_buff);
    // protocol buffer serialized response output
    //string seralized_response_output;

    //Un-marshal the return value and output parameters from foo1 of Enclave3
    // ke_status = unmarshal_retval_and_output_parameters_e3_foo1(out_buff, p_struct_var, &retval);
    ke_status = RequestResponseUtil::UnmarshalFunctionOutput(out_buff, serialized_response_output);
    if (ke_status != (ATTESTATION_STATUS)kLA_SUCCESS)
    {
        SAFE_FREE(out_buff);
        ocall_print_string("exit E2ERequestResponse::UnmarshalFunctionOutput Error", __FILE__, __LINE__);
        return ke_status;
    }
    SAFE_FREE(out_buff);
    ocall_print_string("exit E2ERequestResponse::SUCCESS", __FILE__, __LINE__);
    return (uint32_t)kLA_SUCCESS;
}
