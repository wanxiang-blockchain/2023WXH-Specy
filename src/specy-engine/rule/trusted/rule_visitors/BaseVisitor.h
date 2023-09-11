// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file declares BaseVisitor class.

#pragma once

#include <string>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

#include "antlr4-runtime.h"
#include "common/data_types/rule_check/ErrorType.h"

#include "trusted/antlr4_generated/RuleParserBaseVisitor.h"
#include "trusted/antlr4_generated/RuleLexer.h"


// `BaseVisitor` extends ANTLR generated base visitor with additional utility functions
class BaseVisitor : public RuleParserBaseVisitor
{
protected:
    /* Utility functions for rule language visitors in use with Rule Enclave */

    // NOTE: `filtered_number_string` is assumed to be created and managed outside of this function
    void FilterNumberLiteral(const std::string &number_string, std::string *const filtered_number_string) const;

    // NOTE: `number_value` is assumed to be created and managed outside of this function
    RuleEnclaveStatus ParseNumberLiteral(const std::string &number_string, double *const number_value) const;

    // NOTE: `number_value` is assumed to be created and managed outside of this function
    RuleEnclaveStatus ParseNumberLiteral(antlr4::tree::TerminalNode *const terminal_node, double *const number_value) const;

    // NOTE: `boolean_value` is assumed to be created and managed outside of this function
    void ParseBooleanLiteral(const std::string &boolean_string, bool *const boolean_value) const;

    // NOTE: `boolean_value` is assumed to be created and managed outside of this function
    void ParseBooleanLiteral(antlr4::tree::TerminalNode *const terminal_node, bool *const boolean_value) const;
};