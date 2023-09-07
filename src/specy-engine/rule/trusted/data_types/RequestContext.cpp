// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements RequestContext class.

#include "RequestContext.h"

#include "sgx_tcrypto.h"
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
