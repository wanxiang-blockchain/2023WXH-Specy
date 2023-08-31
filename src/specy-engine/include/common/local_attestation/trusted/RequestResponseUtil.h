// RequestResponseUtil class's functions are all static.
// Inside static functions, memories are allocated and freed automatically,
// no need to free/delete by manual

#pragma once

#include <stdio.h>

#include <map>
#include <string>
#include <cstring>
#include <mutex>

#include "EnclaveMessageExchange.h"
#include "common/local_attestation/dh_session_protocol.h"
#include "common/local_attestation/datatypes.h"
#include "common/data_types/local_attestation/ErrorType.h"

extern std::map<sgx_enclave_id_t, dh_session_t> g_src_session_info_map;
extern std::mutex mtx_gSrcSessionInfoMap;

class RequestResponseUtil
{
public:
    // maximal size of output buffer size
    static const uint64_t kMaxOutBuffSize = 8192;

    /* For Outcoming Function Request */

    static uint32_t MarshalFunctionInput(uint32_t target_fn_id,
                                         uint32_t msg_type,
                                         std::string *function_input,
                                         char **marshalled_buff,
                                         size_t *marshalled_buff_len);
    static uint32_t UnmarshalFunctionOutput(char *out_buff, std::string *function_output);

    /* For Incoming Function Response */

    static uint32_t UnmarshalFunctionInput(std::string *function_input, ms_in_msg_exchange_t *ms);
    static uint32_t MarshalFunctionOutput(char **resp_buffer, size_t *resp_length, std::string *function_output);

    /* Helper Functions for E2E Call Request and Response */

    // both serialized_function_input and serialized_function_output are considered protocol buffer seralized string
    // more specifically, serialized_function_input = bytes(E2ERequest), serialized_function_output = bytes(E2EResponse)
    static uint32_t E2ERequestResponse(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id,
                                       uint32_t target_fn_id, uint32_t msg_type,
                                       std::string serialized_function_input, std::string *serialized_function_output);

    /* Helper Functions for E2E Call Tests */

    // static string GenerateSerializedEntityRequest();
    // static string GenerateSerializedEntitySetRequest();
};
