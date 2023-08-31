// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// Exported function of binding enclave.
#pragma once

#include "TxContext.h"
#include "common/data_types/binding/ErrorType.h"
#include "BindingEnclave_t.h"

// typedef unsigned size_t;

// ecall_process_cproof is used to parse transaction to bind data with rule.
// Params: request: serialized proofRequest
//         input_size: the size of proof request
// Return: response: serialized proof response related to the input request
//         output_size: the size of proof response
// BINDING_ERROR_CODE ecall_process_proof_request(const char *request, size_t input_size, char *response, size_t output_size);
