// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares RuleProcessor class.

#pragma once

#include <string>
#include <mutex>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "antlr4-runtime.h"
#include "common/data_types/rule_check/ErrorType.h"

#include "trusted/antlr4_generated/RuleLexer.h"
#include "trusted/antlr4_generated/RuleParser.h"
#include "trusted/data_provider/DataProvider.h"
#include "trusted/data_types/RequestContext.h"
#include "trusted/rule_visitors/SymbolCollector.h"
// #include "trusted/rule_visitors/RuleEvaluator.h"

// TODO Add thread-safe support

// RuleProcessor is used to process rule checking, which provides
// core method to check the compliance of transaction.
class RuleProcessor
{

public:
    RuleProcessor() = default;
    ~RuleProcessor() = default;

    // EvaluateRule is used to regulate transaction with rules
    // Params: request_context: context of compliance request which contains necessary regulatory information
    // Return: RuleEnclaveStatus: status of EvaluateRule
    RuleEnclaveStatus EvaluateRule(RequestContext *const request_context);
};