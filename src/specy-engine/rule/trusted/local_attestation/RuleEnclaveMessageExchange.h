// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares local attestation methods.

#pragma once

#include <map>
#include <cstring>

#include "sgx_eid.h"
#include "sgx_trts.h"
#include "sgx_utils.h"
#include "sgx_ecp_types.h"
#include "sgx_thread.h"
#include "sgx_dh.h"
#include "sgx_tcrypto.h"

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "common/local_attestation/dh_session_protocol.h"
#include "common/local_attestation/datatypes.h"
#include "common/local_attestation/trusted/EnclaveMessageExchange.h"
#include "common/local_attestation/trusted/RequestResponseUtil.h"

#include "trusted/local_attestation/RuleResponse.h"

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