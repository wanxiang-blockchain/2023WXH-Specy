// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements DataProvider class.

#include "DataProvider.h"

using namespace std;
using namespace json11;
using namespace rule_check_proto;
static const unsigned long kMaxOutSize = 8192UL;
// Constructor of DataProvider
DataProvider::DataProvider() {}

// Destructor of DataProvider
DataProvider::~DataProvider() {}

// Parse JSON string to retrieve entity value object
RuleEnclaveStatus DataProvider::ParseEntityOutputJSON(
    const Json &json_output, Json *const entity_value) const {
    ocall_print_string(string("enter ParseEntityOutputJSON with json_output: " +
                              json_output.dump())
                           .c_str(),
                       __FILE__, __LINE__);

    // example output JSON: {"message": "SUCCESS", "result": {"Transfer":
    // {"Value": ["20000"]}}, "type": "entity"}

    // TODO add error handling
    if (!json_output.is_object() || json_output["message"] != "SUCCESS" ||
        !json_output["result"].is_object() || json_output["type"] != "entity") {
        return RuleEnclaveStatus::kEntity_struct_error;
    }

    // TODO add more parsing logic, e.g., re-construct result object as array of
    // objects
    map<string, Json> parsed_json_output_list;

    // traverse through each returned entity
    // {"Transfer": [{"Value": "20000"}}]
    auto json_output_object_map = json_output["result"]["data"].object_items();

    // TODO add error handling
    // assert(json_output_object_map.size() == 1);
    if (json_output_object_map.size() != 1) {
        return RuleEnclaveStatus::kEntity_struct_error;
    }

    for (auto entity_iter = json_output_object_map.begin();
         entity_iter != json_output_object_map.end(); entity_iter++) {
        string entity_name = entity_iter->first.substr(
            0,
            entity_iter->first.size() - 1);  // e.g., "transfers" to "transfer"

        ocall_print_string(entity_name.c_str(), __FILE__, __LINE__);
        transform(entity_name.begin(), entity_name.end(), entity_name.begin(),
                  std::tolower);             //"Transfer" to "transfer"
        Json entitys = entity_iter->second;  // e.g., [{"Value": "20000"}]
        ocall_print_string(entitys.dump().c_str(), __FILE__, __LINE__);
        if (!entitys.is_array() || entitys.array_items().size() != 1) {
            return RuleEnclaveStatus::kEntity_struct_error;
        }
        // entity json object
        Json entity = entitys[0];
        ocall_print_string(entity.dump().c_str(), __FILE__, __LINE__);
        map<string, Json> collected_entity_json_map;

        // traverse through each entity attribute
        auto entity_json_map = entity.object_items();
        for (auto attribute_iter = entity_json_map.begin();
             attribute_iter != entity_json_map.end(); attribute_iter++) {
            string attribute_name = attribute_iter->first;
            ocall_print_string(attribute_name.c_str(), __FILE__, __LINE__);
            transform(attribute_name.begin(), attribute_name.end(),
                      attribute_name.begin(),
                      std::tolower);  // e.g., "Value" to "value"

            Json attribute_value = attribute_iter->second;  // e.g., "20000"

            collected_entity_json_map[attribute_name] = attribute_value;
        }

        // update new entity instance
        parsed_json_output_list[entity_name] = Json(collected_entity_json_map);
    }

    // omit eneity name in later binding
    // e.g., {"Transfer": {"Value": ["20000"]}}} for entity "Transfer"
    // NOTE: we have exactly one entity, so we can safely use begin() here
    // Json parsed_json_output = Json(parsed_json_output_list.begin()->second);
    Json parsed_json_output = Json(parsed_json_output_list);

    ocall_print_string(
        (string("exit ParseEntityOutputJSON with parsed_json_output: ") +
         parsed_json_output.dump())
            .c_str(),
        __FILE__, __LINE__);

    // return parsed_json_output;
    *entity_value = parsed_json_output;
    return RuleEnclaveStatus::kOK;
}

// Parse JSON string to retrieve entity set value object
RuleEnclaveStatus DataProvider::ParseEntitySetOutputJSON(
    const Json &json_output, Json *const entity_set_value) const {
    // example output JSON: {"message": "SUCCESS", "result": {"Transfer":
    // {"Value": ["20000", "30000"]}}, "type": "entity"}

    if (!json_output.is_object() || json_output["message"] != "SUCCESS" ||
        !json_output["result"].is_object() || json_output["type"] != "entity") {
        return RuleEnclaveStatus::kEntity_struct_error;
    }

    ocall_print_string(("json_outpu string: \n" + json_output.dump()).c_str(),
                       __FILE__, __LINE__);

    // TODO add more parsing logic, e.g., re-construct result object as array of
    // objects
    vector<Json> parsed_json_output_list;

    // traverse through each returned entity
    // {"Transfer": {"Value": ["20000", "30000"]}}
    auto json_output_object_map = json_output["result"]["data"].object_items();

    for (auto entity_iter = json_output_object_map.begin();
         entity_iter != json_output_object_map.end(); entity_iter++) {
        string entity_name = entity_iter->first.substr(
            0,
            entity_iter->first.size() - 1);  // e.g., "transfers" to "transfer"
        transform(entity_name.begin(), entity_name.end(), entity_name.begin(),
                  std::tolower);  // e.g., "Transfer" to "transfer"
        Json entitys =
            entity_iter
                ->second;  // e.g., [{"Value": "20000"}, {"Value": "30000"}]

        // assert(!entity.object_items().empty());
        // assert(entity.object_items().begin()->second.is_array());
        if (!entitys.is_array()) {
            return RuleEnclaveStatus::kEntity_struct_error;
        }
        // decide on number of entities in the entity set
        uint64_t num_entities;
        // TODO check if each attribute list has the same size
        num_entities = entitys.array_items().size();

        // collect and construct each entity
        for (uint64_t i = 0; i < num_entities; i++) {
            map<string, Json> collected_entity_json_map;

            // traverse through each entity attribute
            auto entity_json_map = entitys[i].object_items();
            for (auto attribute_iter = entity_json_map.begin();
                 attribute_iter != entity_json_map.end(); attribute_iter++) {
                string attribute_name = attribute_iter->first;
                transform(attribute_name.begin(), attribute_name.end(),
                          attribute_name.begin(),
                          std::tolower);  // e.g., "Value" to "value"
                Json attribute_value =
                    attribute_iter->second;  // e.g., "20000", "30000"

                collected_entity_json_map[attribute_name] =
                    attribute_value;  // the i-th entity's attribute
            }

            // update new entity instance
            // parsed_json_output_list.push_back(Json(collected_entity_json_map));
            auto parsed_json_object =
                Json(Json::object{{entity_name, collected_entity_json_map}});
            // ocall_print_string(("parsed_json_object string is :\n" +
            // parsed_json_object.dump()).c_str(), __FILE__, __LINE__);
            parsed_json_output_list.push_back(parsed_json_object);
        }
    }

    Json parsed_json_output = Json(parsed_json_output_list);

    ocall_print_string(
        (string("exit ParseEntitySetOutputJSON with parsed_json_output: ") +
         parsed_json_output.dump())
            .c_str(),
        __FILE__, __LINE__);

    // return parsed_json_output;
    *entity_set_value = parsed_json_output;
    return RuleEnclaveStatus::kOK;
}

RuleEnclaveStatus DataProvider::QueryDataFromGraphnodeJson(
    const string &query_str, const string &subgraph_name,
    Json &json_result) const {
    char *result = (char *)(malloc(kMaxOutSize));
    if (ocall_query_entity(query_str.c_str(), kMaxOutSize,
                           subgraph_name.c_str(), subgraph_name.length() + 1,
                           result, kMaxOutSize) != SGX_SUCCESS) {
        return RuleEnclaveStatus::kError;
    }

    string raw_json_output = string(result);
    string json_parse_err = "error: failed to parse Query output JSON";

    // TODO convert raw JSON output to Json object
    json_result = Json::parse(result, json_parse_err);
    ocall_print_string(json_result.dump().c_str(), __FILE__, __LINE__);
    return RuleEnclaveStatus::kOK;
}