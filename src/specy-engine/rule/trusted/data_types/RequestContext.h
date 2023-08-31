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
    std::string req_id_;
    std::string rule_text_;

    // map from entity name to corresponding entity binding (JSON)
    std::map<std::string, json11::Json> entity_binding_map_;

    // map from rule context text to corresponding entity set binding (JSON)
    // TODO we should have used a smarter way to mark each entity set request,
    // TODO instead of the whole rule context text
    std::map<std::string, json11::Json> entity_set_binding_map_;

    // map from rule id (e.g., "r1") to evaluation result
    std::map<std::string, bool> rule_evaluation_result_map_;

    void split();

    bool overall_evaluation_result_;

   public:
    std::string contract_id;
    std::string tx_hash;
    std::string result_byte;
    std::string rule_file_hash;

   public:
    // Constructor of RequestContext
    RequestContext(const std::string &req_id, const std::string &rule_text);

    RequestContext(const std::string &contract_id, const std::string &tx_hash,
                   const std::string &rule_text);

    // Destructor of RequestContext
    ~RequestContext();

    // Data Member Getters
    const std::string &get_req_id() const;
    const std::string &get_rule_text() const;
    const std::vector<std::string> &get_rule_id_list() const;

    const json11::Json &get_entity_binding(const std::string &entity_id) const;
    const json11::Json &get_entity_set_binding(
        const std::string &entity_set_id);

    // get_rule_evaluation_result_map is used to return raw evaluation result
    // map, i.e., rule id => result
    std::map<std::string, bool> get_rule_evaluation_result_map();

    // get_rule_evaluation_result_list is used to return compact evaluation
    // result list, i.e., [result], presuming the same order with rule_id_list
    std::vector<bool> get_rule_evaluation_result_list();

    // get_rule_evaluation_result is used to return give rule id evaluation
    // result
    bool get_rule_evaluation_result();

    // // return overall rule evaluation result, i.e., and[result], conjunction
    // of each individual result bool get_overall_evaluation_result();

    // Data Member Setters
    void set_entity_binding(const std::string &entity_id,
                            const json11::Json &binding);
    void set_entity_set_binding(const std::string &entity_set_id,
                                const json11::Json &binding);
    void set_rule_evaluation_result_map(
        const std::map<std::string, bool> &rule_evaluation_result_map);
    void set_rule_evaluation_result(const std::string &rule_id,
                                    const bool &evaluation_result);
};