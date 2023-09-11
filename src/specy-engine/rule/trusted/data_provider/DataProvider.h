// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares DataProvider class.

#pragma once

#include <set>
#include <string>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

// #include "binding/trusted/local_attestation/BindingExportFunction.h"
#include "common/base64/Transform.h"
#include "common/data_types/EnclaveId.h"
#include "common/data_types/rule_check/ErrorType.h"
#include "third_party/json_lib/json11.hpp"
#include "common/local_attestation/trusted/RequestResponseUtil.h"
#include "e2e_message/E2EMessage.pb.h"
#include "rule_enclave/EntityQuery.pb.h"
#include "trusted/data_provider/Query.h"
#include "trusted/data_types/Entity.h"
#include "trusted/data_types/EntityRule.h"
#include "trusted/data_types/EntitySet.h"

// DataProvider is used to request entity value from graph node,
// and provides APIs to parse output object.
// Example of usage:
//   data_provider = new DataProvider();
//   status_code = data_provider.RequestEntity(request_id, entity,
//   &entity_binding);

class DataProvider {
   public:
    // Constructor of DataProvider
    DataProvider();

    // Destructor of DataProvider
    ~DataProvider();

    RuleEnclaveStatus QueryDataFromGraphnodeJson(
        const string &query_str, const string &contract_id,
        json11::Json &json_result) const;

    // Parse JSON string to retrieve entity value object
    // NOTE: `entity_value` are assumed to be created and managed (e.g., freed)
    // outside of this function
    RuleEnclaveStatus ParseEntityOutputJSON(
        const json11::Json &json_output,
        json11::Json *const entity_value) const;

    // Parse JSON string to retrieve entity set value object
    // NOTE: `entity_set_value` are assumed to be created and managed (e.g.,
    // freed) outside of this function
    RuleEnclaveStatus ParseEntitySetOutputJSON(
        const json11::Json &json_output,
        json11::Json *const entity_set_value) const;

};
