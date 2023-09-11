// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements RequestHandler class.

#include "RequestHandler.h"

using namespace std;

static void dumpRuleidList(const vector<string> &rule_id_list) {
    string rule_id_text = "\n[";
    uint32_t counter = 0;
    for (const auto &rule_id : rule_id_list)
    {
        if (counter++ > 0)
        {
            rule_id_text += ", ";
        }
        rule_id_text += rule_id;
    }
    rule_id_text += "]";

    ocall_print_string((string("rule id to be checked: ") + rule_id_text).c_str(), __FILE__, __LINE__);
}

// CheckRule is used to assemble RequestContext object by given params
RuleEnclaveStatus RequestHandler::CheckRule(const string &req_id, const string &rule_text,
                                            vector<bool> *const status_list,
                                            RequestContext* request_context)
{
    ocall_print_string((string("enter CheckRule with request id: ") + req_id).c_str(), __FILE__, __LINE__);
    ocall_print_string((string("rule text:\n") + rule_text).c_str(), __FILE__, __LINE__);

    // employ rule processor to evaluate rule
    RuleProcessor rule_processor;
    if (rule_processor.EvaluateRule(request_context) != RuleEnclaveStatus::kOK) {
        ocall_print_string("Error: evaluate rule error!", __FILE__, __LINE__);
        return RuleEnclaveStatus::kError;
    }
    // TODO build rule check result
    
    ocall_print_string("exit CheckRule", __FILE__, __LINE__);
    return RuleEnclaveStatus::kOK;
}