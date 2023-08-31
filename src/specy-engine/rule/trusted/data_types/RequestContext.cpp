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
RequestContext::RequestContext(const string &req_id, const string &rule_text) {
    this->req_id_ = req_id;
    this->rule_text_ = rule_text;
    split();
}

RequestContext::RequestContext(const std::string &contract_id,
                               const std::string &tx_hash,
                               const std::string &rule_text)
    : contract_id(contract_id),
      tx_hash(tx_hash),
      rule_text_(rule_text) {
    req_id_ = contract_id + ":" + tx_hash;
}

// Destrucotr of RequestContext
RequestContext::~RequestContext() {}

// Data Member Getters
const string &RequestContext::get_req_id() const { return this->req_id_; }

const string &RequestContext::get_rule_text() const { return this->rule_text_; }


const Json &RequestContext::get_entity_binding(const string &entity_id) const {
    ocall_print_string(
        (string("get entity binding: ") + entity_id + string("[") +
         this->entity_binding_map_.at(entity_id).dump() + string("]"))
            .c_str(),
        __FILE__, __LINE__);
    return this->entity_binding_map_.at(entity_id);
}

const Json &RequestContext::get_entity_set_binding(
    const string &entity_set_id) {
    return this->entity_set_binding_map_[entity_set_id];
}

// get_rule_evaluation_result_map is used to return raw evaluation result map
std::map<string, bool> RequestContext::get_rule_evaluation_result_map() {
    std::map<string, bool> rule_evaluation_result_map;
    for (auto iter = this->rule_evaluation_result_map_.begin();
         iter != this->rule_evaluation_result_map_.end(); iter++) {
        rule_evaluation_result_map[iter->first] = iter->second ? true : false;
    }

    return rule_evaluation_result_map;
}

// get_rule_evaluation_result_list is used to return compact evaluation result
// list
vector<bool> RequestContext::get_rule_evaluation_result_list() {
    vector<bool> rule_evaluation_result_list;

    // traverse on rule evaluation result map, i.e., rule id => result
    for (auto iter = this->rule_evaluation_result_map_.begin();
         iter != this->rule_evaluation_result_map_.end(); iter++) {
        rule_evaluation_result_list.push_back(iter->second ? true : false);
    }

    return rule_evaluation_result_list;
}

// get_rule_evaluation_result is used to return give rule id evaluation result
bool RequestContext::get_rule_evaluation_result() {
    // false if rule evaluation result not known
    bool status = true;
    for (auto result : rule_evaluation_result_map_) {
        status &= result.second;
    }
    return status;
}

// Data Member Setters
void RequestContext::set_entity_binding(const string &entity_id,
                                        const Json &binding) {
    ocall_print_string((string("set entity binding: ") + entity_id +
                        string("[") + binding.dump() + string("]"))
                           .c_str(),
                       __FILE__, __LINE__);

    // update entity binding map
    if (this->entity_binding_map_.find(entity_id) ==
        this->entity_binding_map_.end()) {
        // TODO (Xufei) entity_binding_map should have a upper limit
        // if (this->entity_binding_map_.size() > 50) {
        //     this->entity_binding_map_.erase(this->entity_binding_map_.begin(),
        //     this->entity_binding_map_.end());
        // }
        this->entity_binding_map_[entity_id] = binding;
    } else {
        /* TODO Handle existing entity binding */

        ocall_print_string("set_entity_binding: existing entity binding",
                           __FILE__, __LINE__);
    }
}

void RequestContext::set_entity_set_binding(const string &entity_set_id,
                                            const Json &binding) {
    ocall_print_string((string("set entity set binding: ") + entity_set_id +
                        string("[") + binding.dump() + string("]"))
                           .c_str(),
                       __FILE__, __LINE__);

    // update entity set binding map
    if (this->entity_set_binding_map_.find(entity_set_id) ==
        this->entity_set_binding_map_.end()) {
        // TODO (Xufei) entity_set_binding_map should have a upper limit
        // if (this->entity_set_binding_map_.size() > 50) {
        //     this->entity_set_binding_map_.erase(this->entity_set_binding_map_.begin(),
        //     this->entity_set_binding_map_.end());
        // }
        this->entity_set_binding_map_[entity_set_id] = binding;
    } else {
        /* TODO Handle existing entity binding */

        ocall_print_string("set_entity_binding: existing entity set binding",
                           __FILE__, __LINE__);
    }
}

void RequestContext::set_rule_evaluation_result_map(
    const map<string, bool> &rule_evaluation_result_map) {
    this->rule_evaluation_result_map_ = rule_evaluation_result_map;
}

void RequestContext::set_rule_evaluation_result(const string &rule_id,
                                                const bool &evaluation_result) {
    // decide on whether evaluation result if known before
    if (this->rule_evaluation_result_map_.find(rule_id) ==
        this->rule_evaluation_result_map_.end()) {
        this->rule_evaluation_result_map_[rule_id] = evaluation_result;
        this->overall_evaluation_result_ &= evaluation_result;
    }
}

void RequestContext::split() {

    string delimiter = ":";
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();

    while ((pos_end = req_id_.find(delimiter, pos_start)) != string::npos) {
        contract_id = req_id_.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
    }

    tx_hash = req_id_.substr(pos_start);
}