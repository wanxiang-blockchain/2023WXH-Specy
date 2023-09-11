// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements BaseVisitor class.

#include "BaseVisitor.h"

using namespace std;
using namespace antlr4;

void BaseVisitor::FilterNumberLiteral(const string &number_string, string *const filtered_number_string) const
{
    // string pure_number_string;
    filtered_number_string->clear();

    // filter out ',' from input number string, e.g., "20,000" to "20000"
    for (const auto &character : number_string)
    {
        if (character == ',')
        {
            continue;
        }
        filtered_number_string->push_back(character);
    }
}

RuleEnclaveStatus BaseVisitor::ParseNumberLiteral(tree::TerminalNode *const terminal_node, double *const number_value) const
{
    ocall_print_string((string("parse number literal: ") + terminal_node->getText()).c_str(), __FILE__, __LINE__);

    // TODO implement complex parsing logic
    if (terminal_node->getSymbol()->getType() == RuleLexer::DECIMAL_LIT)
    {
        return this->ParseNumberLiteral(terminal_node->getText(), number_value);
    }
    else if (terminal_node->getSymbol()->getType() == RuleLexer::DECIMAL_FLOAT_LIT)
    {
        return this->ParseNumberLiteral(terminal_node->getText(), number_value);
    }
    else
    {
        /* this should never be reached */
        // assert(false);
        return RuleEnclaveStatus::kError;
    }
}

RuleEnclaveStatus BaseVisitor::ParseNumberLiteral(const string &number_string, double *const number_value) const
{
    string filtered_number_string;
    this->FilterNumberLiteral(number_string, &filtered_number_string);
    // TODO Deal with exception here?
    *number_value = stod(filtered_number_string);
    return RuleEnclaveStatus::kError;
}

void BaseVisitor::ParseBooleanLiteral(tree::TerminalNode *const terminal_node, bool *const boolean_value) const
{
    this->ParseBooleanLiteral(terminal_node->getText(), boolean_value);
}

void BaseVisitor::ParseBooleanLiteral(const string &boolean_string, bool *const boolean_value) const
{
    // TODO Deal with hardcoded boolean literal
    *boolean_value = (boolean_string == "True" || boolean_string == "true") ? true : false;
}
