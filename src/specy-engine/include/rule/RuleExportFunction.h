// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares external functions provided by rule enclave.

#pragma once

// list of external functions provided by rule enclave
enum class ExportedRuleFunction
{
    kCheckRule = 0, // CheckRule(const string req_id, const string rule_text, const vector<string> rule_id_list);
};