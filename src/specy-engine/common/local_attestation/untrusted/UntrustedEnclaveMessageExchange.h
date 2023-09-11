#pragma once

#include <map>
#include <iostream>
#include <cstddef>
#include <mutex>

#include "sgx_eid.h"
#include "sgx_dh.h"
#include "sgx_urts.h"
#include "common/data_types/local_attestation/ErrorType.h"
#include "common/local_attestation/datatypes.h"
#include "common/local_attestation/dh_session_protocol.h"
#include "common/data_types/EnclaveId.h"

#ifndef ULOCALATTESTATION_H_
#define ULOCALATTESTATION_H_

/* all functions appeared in this file should be implemented by importing app */
// TODO mark this as a common untrusted local attestation library

#ifdef __cplusplus
extern "C"
{
#endif

    sgx_status_t KeyManagementEnclave_ecall_session_request(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg1_t *dh_msg1, uint32_t *session_id);
    sgx_status_t KeyManagementEnclave_ecall_exchange_report(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg2_t *dh_msg2, sgx_dh_msg3_t *dh_msg3, uint32_t session_id);
    sgx_status_t KeyManagementEnclave_ecall_generate_response(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, secure_message_t *req_message, size_t req_message_size, size_t max_payload_size, secure_message_t *resp_message, size_t resp_message_size);
    sgx_status_t KeyManagementEnclave_ecall_end_session(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id);

    sgx_status_t RuleEnclave_ecall_session_request(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg1_t *dh_msg1, uint32_t *session_id);
    sgx_status_t RuleEnclave_ecall_exchange_report(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg2_t *dh_msg2, sgx_dh_msg3_t *dh_msg3, uint32_t session_id);
    sgx_status_t RuleEnclave_ecall_generate_response(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, secure_message_t *req_message, size_t req_message_size, size_t max_payload_size, secure_message_t *resp_message, size_t resp_message_size);
    sgx_status_t RuleEnclave_ecall_end_session(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id);

    sgx_status_t BindingEnclave_ecall_session_request(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg1_t *dh_msg1, uint32_t *session_id);
    sgx_status_t BindingEnclave_ecall_exchange_report(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, sgx_dh_msg2_t *dh_msg2, sgx_dh_msg3_t *dh_msg3, uint32_t session_id);
    sgx_status_t BindingEnclave_ecall_generate_response(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id, secure_message_t *req_message, size_t req_message_size, size_t max_payload_size, secure_message_t *resp_message, size_t resp_message_size);
    sgx_status_t BindingEnclave_ecall_end_session(sgx_enclave_id_t eid, uint32_t *retval, sgx_enclave_id_t src_enclave_id);

    uint32_t ocall_session_request(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg1_t *dh_msg1, uint32_t *session_id);
    uint32_t ocall_exchange_report(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg2_t *dh_msg2, sgx_dh_msg3_t *dh_msg3, uint32_t session_id);
    uint32_t ocall_send_request(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, secure_message_t *req_message, size_t req_message_size, size_t max_payload_size, secure_message_t *resp_message, size_t resp_message_size);
    uint32_t ocall_end_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id);

    uint32_t ocall_query_enclave_id(uint64_t target_module_id, sgx_enclave_id_t *target_enclave_id);
    void ocall_print_string(const char *str, const char *file, const int line);

#ifdef __cplusplus
}
#endif

#endif
