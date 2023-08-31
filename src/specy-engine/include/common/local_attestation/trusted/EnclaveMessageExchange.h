/*
 * Copyright (C) 2011-2019 Intel Corporation. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *   * Neither the name of Intel Corporation nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#pragma once

#include <map>
#include <cstring>
#include <mutex>

#if defined(BUILD_RULE_CHECK_MODULE)
#include "RuleEnclave_t.h"
#elif defined(BUILD_KEY_MANAGEMENT_MODULE)
#include "KeyManagementEnclave_t.h"
#elif defined(BUILD_BINDING_MODULE)
#include "BindingEnclave_t.h"
// #else
// #include "LocalAttestation_t.h"
#endif

#include "sgx_eid.h"
#include "sgx_trts.h"
#include "sgx_utils.h"
#include "sgx_ecp_types.h"
#include "sgx_thread.h"
#include "sgx_dh.h"
#include "sgx_tcrypto.h"

#include "common/local_attestation/dh_session_protocol.h"
#include "common/local_attestation/datatypes.h"
#include "common/data_types/local_attestation/ErrorType.h"

/* functions provided by this library */

// the following source functions are implemented in this libraray
#ifdef __cplusplus
extern "C"
{
#endif

    uint32_t SGXAPI create_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, dh_session_t *p_session_info);
    uint32_t SGXAPI send_request_receive_response(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, dh_session_t *p_session_info, char *inp_buff, size_t inp_buff_len, size_t max_out_buff_size, char **out_buff, size_t *out_buff_len);
    uint32_t SGXAPI close_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id);

#ifdef __cplusplus
}
#endif

// the following source enclave ecalls are implemented in this libraray
uint32_t ecall_create_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id);
uint32_t ecall_close_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id);

// the following destination enclave ecalls are implemented in this library
uint32_t ecall_session_request(sgx_enclave_id_t src_enclave_id, sgx_dh_msg1_t *dh_msg1, uint32_t *session_id);
uint32_t ecall_exchange_report(sgx_enclave_id_t src_enclave_id, sgx_dh_msg2_t *dh_msg2,
                               sgx_dh_msg3_t *dh_msg3, uint32_t session_id);
uint32_t ecall_generate_response(sgx_enclave_id_t src_enclave_id, secure_message_t *req_message,
                                 size_t req_message_size, size_t max_payload_size,
                                 secure_message_t *resp_message, size_t resp_message_size);
uint32_t ecall_end_session(sgx_enclave_id_t src_enclave_id);

// the following destination functions are implemented in this libraray
uint32_t generate_session_id(uint32_t *session_id);

/* functions implemented by importing enclave */

// the following source enclave ecalls should be implemented by importing enclave
uint32_t ecall_enclave_to_enclave_call(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id);
uint32_t ecall_message_exchange(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id);

// the follwing destination functions should be implemented by importing enclave
#ifdef __cplusplus
extern "C"
{
#endif

    uint32_t verify_peer_enclave_trust(sgx_dh_session_enclave_identity_t *peer_enclave_identity);
    uint32_t enclave_to_enclave_call_dispatcher(char *decrypted_data, size_t decrypted_data_length,
                                                char **resp_buffer, size_t *resp_length);
    uint32_t message_exchange_response_generator(char *decrypted_data, char **resp_buffer, size_t *resp_length);

#ifdef __cplusplus
}
#endif

uint32_t get_message_exchange_response(uint32_t inp_secret_data);
