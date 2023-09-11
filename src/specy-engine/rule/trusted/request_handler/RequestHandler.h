// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares RequestHandler class.

#pragma once

#include <map>
#include <string>
#include <vector>
#include <mutex>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "common/data_types/rule_check/ErrorType.h"
#include "rule_enclave/EntityQuery.pb.h"

#include "trusted/data_types/RequestContext.h"
#include "trusted/rule_processor/RuleProcessor.h"
#include "trusted/rule_visitors/SymbolCollector.h"

// RequestHandler is used to help assemble context of request,
// and provides APIs to init or free it.
class RequestHandler
{

public:
    // Constructor of RequestHandler
    RequestHandler() = default;

    // Destructor of RequestHandler
    ~RequestHandler() = default;

    // CheckRule is used to assemble RequestContext object by given params
    // Params: req_id: identity of each request
    //         rule_text: content of rule file
    //         rule_id_list: rule ids to be checked
    // Return: status_list: result list 
    //         RuleEnclaveStatus: status of CheckRule
    RuleEnclaveStatus CheckRule(const std::string &req_id, const std::string &rule_text,
                                std::vector<bool> *const status_list,
                                RequestContext* request_context);
};