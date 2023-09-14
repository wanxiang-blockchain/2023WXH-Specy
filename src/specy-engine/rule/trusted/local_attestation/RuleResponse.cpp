// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements glue methods between enclave to enclave.

#include "RuleResponse.h"

using namespace std;
using namespace e2e_message;
using namespace json11;

static void helper_function(const string& output) {
    uint32_t length = output.length() + 1;
    if (length <= 1) {
        ocall_print_string("Warning! want to output an empty string", __FILE__,
                           __LINE__);
    }
    char* outputBuffer = (char*)malloc(length);
    memcpy(outputBuffer, output.c_str(), length);
    ocall_print_string(outputBuffer, __FILE__, __LINE__);
}

#define RULE_INFO_STRING(str) helper_function(str)

// check_rule function for E2E Incoming Call
// NOTE: `status_list` is assumed to be created outside of this function and
// managed (e.g., freed) as well
RuleEnclaveStatus check_rule(const string& req_id, const string& rule_text,
                             vector<bool>* const status_list,
                             RequestContext* request_context) {
    RequestHandler request_handler;
    RuleEnclaveStatus ret =
        request_handler.CheckRule(req_id, rule_text, status_list, request_context);
    return ret;
}

// get RuleCheckRequest from buffer of ms which inputed by binding enclave
bool get_RuleCheckRequest_from_ms(ms_in_msg_exchange_t* ms,
                                  RuleCheckRequest& request_input) {
    E2ERequest e2e_request;
    RULE_INFO_STRING("enter unmarshal_input_param");
    string function_input;
    ocall_print_string(
        string("rulechecker ms->inparam_buff:" + string(ms->inparam_buff))
            .c_str(),
        __FILE__, __LINE__);

    if (RequestResponseUtil::UnmarshalFunctionInput(&function_input, ms) !=
        (uint32_t)kLA_SUCCESS)
        return false;

    ocall_print_string(
        string("function_input rulechecker:" + function_input).c_str(),
        __FILE__, __LINE__);
    e2e_request.ParseFromString(function_input);

    if (!e2e_request.has_rule_check_input()) {
        return false;
    }
    request_input = e2e_request.rule_check_input();
    return true;
}

string serialize_function_output(RuleCheckResponse* rulecheck_response) {
    E2EResponse e2e_response;
    e2e_response.set_allocated_rule_check_output(rulecheck_response);

    // build output value
    string function_output;
    e2e_response.SerializeToString(&function_output);
    return function_output;
}

RuleEnclaveStatus fill_rule_check_response(
    const RuleCheckRequest& request_input, RuleCheckResponse* response_output) {
    RULE_INFO_STRING("enter fill_rule_check_response");

    string request_id = request_input.taskhash();
    string rule_content = request_input.rule_file();
    string input_data = request_input.input_data();
    // allocate a new request context pointer
    RequestContext* request_context = new RequestContext(request_id, rule_content, input_data);
    request_context->updateRuleFileHash();
    vector<bool> status_list;

    // call delegate function to get rule result
    RuleEnclaveStatus status_code =
        check_rule(request_id, rule_content, &status_list, request_context);
    if (status_code != RuleEnclaveStatus::kOK) {
        return status_code;
    }

    response_output->set_taskhash(request_input.taskhash());
    response_output->set_error_info(request_context->getErrorInfo());
    response_output->set_output_data(request_context->getOutputData());
    response_output->set_status(request_context->getResult());
    response_output->set_cproof(request_context->getCproofJsonString());
    RULE_INFO_STRING(string("rule check response is: " +
                            response_output->SerializeAsString()));
    delete(request_context);
    return status_code;
}

// Wrapper function which is executed on request from the binding enclave
RuleEnclaveStatus check_rule_wrapper(ms_in_msg_exchange_t* ms,
                                     size_t param_lenth, char** resp_buffer,
                                     size_t* resp_length) {
    UNUSED(param_lenth);
    ocall_print_string("enter check_rule_wrapper", __FILE__, __LINE__);
    if (!ms || !resp_length) {
        return RuleEnclaveStatus::kInvalid_parameter_error;
    }

    RuleCheckRequest request_input;
    if (!get_RuleCheckRequest_from_ms(ms, request_input)) {
        return RuleEnclaveStatus::kInvalid_parameter_error;
    }

    RuleCheckResponse* response_output = new RuleCheckResponse();
    RuleEnclaveStatus status =
        fill_rule_check_response(request_input, response_output);
    if (status != RuleEnclaveStatus::kOK) {
        return status;
    }

    // construct function output, response_output will be delete after this
    // invoke
    string function_output = serialize_function_output(response_output);
    ocall_print_string(function_output.c_str(), __FILE__, __LINE__);

    // serialize function response output
    if (RequestResponseUtil::MarshalFunctionOutput(resp_buffer, resp_length,
                                                   &function_output) !=
        (uint32_t)kLA_SUCCESS) {
        ocall_print_string("enter check_rule_wrapper::Malloc_error", __FILE__,
                           __LINE__);
        return RuleEnclaveStatus::kMalloc_error;  // can set resp buffer to null
                                                  // here
    }

    ocall_print_string("exit check_rule_wrapper", __FILE__, __LINE__);
    return RuleEnclaveStatus::kOK;
}