// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares RequestContext class.

#pragma once

#include <map>
#include <string>
#include <vector>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "Entity.h"
#include "EntitySet.h"
#include "third_party/json_lib/json11.hpp"
#include "rule_enclave/EntityQuery.pb.h"

// using namespace std;
// using namespace json11;
// using namespace request_proto;

// RequestContext is used to maintain a context of compliance request,
// and provide APIs to get or set attributes.
// Example of usage:
//   auto request_context = new RequestContext(req_id, rule_text, rule_id_list);
//   auto evaluation_result =
//   request_context->get_rule_evaluation_result(rule_id);
class RequestContext {
   private:
   // data from request
    std::string task_id_;
    std::string rule_file_;
    std::string input_data_;
    std::string rule_file_hash_;
    std::vector<std::string> rules;

    // execute result from engine
    bool result_;
    std::string err_info_;
    std::string output_data_;


   public:
    // Constructor of RequestContext
    RequestContext(const std::string &req_id, const std::string &rule_text, const std::string &input_data);

    // Destructor of RequestContext
    ~RequestContext() = default;

    // Data Member Getters
    const std::string &get_req_id() const;
    const std::string &get_rule_text() const;
    std::string getInputData();

    bool getResult();
    std::string getOutputData();
    std::string getErrorInfo();
    std::string getRuleFileHash();
    std::vector<std::string>& getRules(); 
    std::string getCproofJsonString();

    void setResult(bool rule_result);
    void setOutputData(const std::string& output);
    void setErrorInfo(const std::string& err);
    void updateRuleFileHash();
};