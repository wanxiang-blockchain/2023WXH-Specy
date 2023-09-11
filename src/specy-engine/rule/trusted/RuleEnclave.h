// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares ecall_test_check_rule method.

#pragma once

#include <vector>
#include <string>
#include <mutex>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

// #include "common/local_attestation/trusted/EnclaveMessageExchange.h"
#include "common/data_types/rule_check/ErrorType.h"

#include "trusted/request_handler/RequestHandler.h"

// ecall_test_check_rule is used to test
void ecall_test_check_rule(void);