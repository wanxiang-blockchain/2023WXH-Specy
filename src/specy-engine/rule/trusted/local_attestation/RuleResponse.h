// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares glue methods between enclave to enclave.

#pragma once

#include <string>
#include <vector>
#include <cstring>
#include <mutex>

#include "common/data_types/rule_check/ErrorType.h"
#include "common/local_attestation/datatypes.h"
#include "common/local_attestation/trusted/RequestResponseUtil.h"
#include "third_party/json_lib/json11.hpp"
#include "e2e_message/RuleCheck.pb.h"
#include "e2e_message/E2EMessage.pb.h"
#include "trusted/RuleEnclave.h"
#include "trusted/data_provider/DataProvider.h"
// using namespace std;
// using namespace request_proto;

#define UNUSED(val) (void)(val)

// forward declaration to resolve cyclic include dependency
class RequestHandler;

// check_rule function for E2E Incoming Call
// NOTE: `status_list` is assumed to be created outside of this function and managed (e.g., freed) as well
RuleEnclaveStatus check_rule(const std::string &req_id, const std::string &rule_text,
                             const std::vector<std::string> &rule_id_list,
                             std::vector<bool> *const status_list);

//Wrapper function which is executed on request from the binding enclave
RuleEnclaveStatus check_rule_wrapper(ms_in_msg_exchange_t *ms, size_t param_lenth,
                            char **resp_buffer, size_t *resp_length);