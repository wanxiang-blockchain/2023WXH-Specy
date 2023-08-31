#include "Expr.h"
#include "Entity.h"
#include "Instance.h"
#include <stdio.h>

#include "RuleEnclave_t.h" /* sgx generated proxy header */

using namespace RuleLanguage;

bool queryExpr::isSelect() {
    return select;
}

bool queryExpr::isCollect() {
    return collect;
}

Type queryExpr::type() {
    return select ? Type::INSTANCE : Type::INSTANCELIST;
}

std::string queryExpr::dump() {

    ocall_print_string((std::string("enter queryExpr dump")).c_str(), __FILE__, __LINE__);
    std::string op = select ? "select" : "collect";
    std::string entity_name = instance == nullptr ? entity->get_name() : instance->getName();
    return op + " " + entity_name + " " + expr->dump();
}

std::string numberExpr::dump() {
    ocall_print_string((std::string("enter numberExpr dump")).c_str(), __FILE__, __LINE__);
    std::string negative_str = negative ? "-" : "";
    
    if (instance != nullptr) {
        return negative_str + instance->dump();
    }
    std::string left_expr_str = left_expr == nullptr ? "" : left_expr->dump();
    std::string right_expr_str = right_expr == nullptr ? "" : right_expr->dump();
    std::string op_str = RuleLanguage::ArithmeticOperatorToString(arith_operator);
    return negative_str + " " + left_expr_str + " " + op_str + " " + right_expr_str;
}

std::string booleanExpr::dump() {
    ocall_print_string((std::string("enter boolean dump")).c_str(), __FILE__, __LINE__);

    if (expr != nullptr) {
        return expr->dump();
    }

    if (instance != nullptr) {
        return instance->dump();
    }

    return literalValue ? "true" : "false";
}

std::string relationExpr::dump() {
    ocall_print_string((std::string("enter relationExpr dump")).c_str(), __FILE__, __LINE__);
    std::string relation_str = first_expr->dump();
    for (int i = 0; i < numbers.size(); i++) {
        relation_str = relation_str + " " + RelationOperatorToString(operators[i]) + " " + numbers[i]->dump();
    }
    return relation_str;
}

std::string logicalExpr::dump() {

    ocall_print_string((std::string("enter logical dump")).c_str(), __FILE__, __LINE__);
    if (boolean_expr != nullptr) {
        return boolean_expr->dump();
    }

    if (logical_operator == LogicalOperator::NOT) {
        ocall_print_string((std::string("dump right_expr")).c_str(), __FILE__, __LINE__);
        return LogicalOperatorToString(logical_operator) + " " + right_expr->dump();
    } else {
        ocall_print_string((std::string("dump left_expr and right_expr")).c_str(), __FILE__, __LINE__);
        return left_expr->dump() + " " + LogicalOperatorToString(logical_operator) + " " + right_expr->dump();
    }
}

std::string basicCondExpr::dump() {
    ocall_print_string((std::string("enter basicCondExpr dump")).c_str(), __FILE__, __LINE__);
    std::string relation_expr_str = rExpr == nullptr ? "" : rExpr->dump();
    std::string list_expr_str = lExpr == nullptr ? "" : lExpr->dump();

    if (logical_operator != LogicalOperator::LOGICAL_NON) {
        return LogicalOperatorToString(logical_operator) + " " + list_expr_str + relation_expr_str;
    }

    return list_expr_str + relation_expr_str;;
}

std::string conditionExpr::dump() {
    ocall_print_string((std::string("enter conditionExpr dump")).c_str(), __FILE__, __LINE__);
    std::string condition_expr_str = basic_expr->dump();
    for (int i = 0; i < basicExprs.size(); i++) {
        condition_expr_str = condition_expr_str + " " + basicExprs[i]->dump();
    }
    return condition_expr_str;
}

std::string RuleLanguage::TypeToString(Type type) {
    switch (type)
    {
    case Type::NUMBER :
        return "number";

    case Type::BOOLEAN :
        return "boolean";

    case Type::STRING :
        return "string";

    case Type::DATE :
        return "date";

    case Type::INSTANCE :
        return "instance";

    case Type::INSTANCELIST :
        return "instance list";
    
    default:
        return "";
    }
}

std::string RuleLanguage::LogicalOperatorToString(LogicalOperator op) {
    switch (op)
    {
    case LogicalOperator::AND:
        return "and";

    case LogicalOperator::OR:
        return "or";

    case LogicalOperator::NOT:
        return "not";

    case LogicalOperator::LOGICAL_NON:
        return "logical non";
    
    default:
        return "";
    }
}

std::string RuleLanguage::ArithmeticOperatorToString(ArithmeticOperator op) {
    switch (op)
    {
    case ArithmeticOperator::DIVIDE :
        return "/";
    
    case ArithmeticOperator::MINUS:
        return "-";

    case ArithmeticOperator::PLUS:
        return "+";

    case ArithmeticOperator::MODULO:
        return "%";

    case ArithmeticOperator::MULTIPLY:
        return "*";

    case ArithmeticOperator::ARITH_NON:
        return "arith_non";
    
    default:
        return "";
    }
}

std::string RuleLanguage::QueryOperatorToString(QueryOperator op) {
    switch (op)
    {
    case QueryOperator::SELECT :
        return "select";
        break;

    case QueryOperator::COLLECT:
        return "collect";

    case QueryOperator::QUERY_NON:
        return "query_non";
    
    default:
        return "";
    }
}

std::string RuleLanguage::RelationOperatorToString(RelationOperator op) {
    switch (op)
    {
    case RelationOperator::EQUALS:
        return "==";

    case RelationOperator::GREATER:
        return ">";

    case RelationOperator::GREATER_OR_EQUALS:
        return ">=";

    case RelationOperator::LESS_OR_EQUALS:
        return "<=";

    case RelationOperator::LESS_THAN:
        return "<";

    case RelationOperator::NOT_EQUALS:
        return "!=";

    case RelationOperator::RELATION_NON:
        return "relation_non";
    
    default:
        return "";
    }
}

std::string RuleLanguage::RelationOperatorToSuffixString(RelationOperator op) {
    switch (op)
    {
    case RelationOperator::EQUALS:
        return "";

    case RelationOperator::GREATER:
        return "_gt";

    case RelationOperator::GREATER_OR_EQUALS:
        return "_gte";

    case RelationOperator::LESS_OR_EQUALS:
        return "_lte";

    case RelationOperator::LESS_THAN:
        return "_lt";

    case RelationOperator::NOT_EQUALS:
        return "_not";

    case RelationOperator::RELATION_NON:
        return "relation_non";
    
    default:
        return "";
    }
}

Type definitionExpr::type() {
    return instance->type();
}
std::string definitionExpr::dump() {
    return instance->dump();
}