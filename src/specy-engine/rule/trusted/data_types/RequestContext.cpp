// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements RequestContext class.

#include "RequestContext.h"
#include "sgx_tcrypto.h"

#include "sgx_tcrypto.h"
#include "RuleEnclave_t.h"
#include "merklecpp.h"

using namespace std;
using namespace json11;

// Constructors of RequestContext
RequestContext::RequestContext(const string &req_id, const string &rule_text, const std::string &input_data) : task_id_(req_id), rule_file_(rule_text), input_data_(input_data) {}

// Data Member Getters
const string &RequestContext::get_req_id() const { return task_id_; }
const string &RequestContext::get_rule_text() const { return rule_file_; }

void RequestContext::setResult(bool rule_result) {
    result_ = rule_result;
}

void RequestContext::setOutputData(const std::string& output) {
    output_data_ = output;
}

std::string RequestContext::getOutputData() {
    return output_data_;
}

bool RequestContext::getResult() {
    return result_;
}

std::string RequestContext::getInputData() {
    return input_data_;
}

std::string RequestContext::getErrorInfo() {
    return err_info_;
}

void RequestContext::setErrorInfo(const std::string& err) {
    err_info_ = err;
}

void RequestContext::updateRuleFileHash() {
    uint8_t hash[32];
    sgx_sha256_msg((unsigned char*)rule_file_.c_str(), rule_file_.length(), &hash);
    merkle::HashT<32> text_hash_node(hash);
    rule_file_hash_ = text_hash_node.to_string();
}

std::string RequestContext::getRuleFileHash() {
    return rule_file_hash_;
}

std::vector<std::string>& RequestContext::getRules() {
    return rules;
}

std::string RequestContext::getCproofJsonString() {
    string err;
    Json inputdata = Json::parse(input_data_, err);
    if (!err.empty()) {
        ocall_print_string(err.c_str(), __FILE__, __LINE__);
    }
    Json outputdata = Json::parse(output_data_, err);
    if (!err.empty()) {
        ocall_print_string(err.c_str(), __FILE__, __LINE__);
    }
    Json::array json_rules;
    for (auto rule : rules) {
        json_rules.push_back(Json(rule));
    }
    Json executed_rules = json_rules;

    Json::object cproof {
        {"rulefilehash", Json(rule_file_hash_)},
        {"inputdata", inputdata},
        {"outputdata", output_data_},
        {"rules", executed_rules}, 
    };

    Json ans = cproof;
    ocall_print_string("dump cproof", __FILE__, __LINE__);
    ocall_print_string(ans.dump().c_str(), __FILE__, __LINE__);
    return ans.dump();
}
