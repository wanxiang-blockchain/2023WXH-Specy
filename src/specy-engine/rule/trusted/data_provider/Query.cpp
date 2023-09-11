#include "Query.h"
#include "RuleEnclave_t.h"

using namespace std;
using namespace rule_check_proto;
using namespace json11;

const string QueryBuilder::QUERY_PREFIX = R"-( {"query":"{ )-";
const string QueryBuilder::QUERY_SUBFIX = R"-( }"} )-";
const string QueryBuilder::QUERY_CONSTRAINS_PREFIX = R"-((where:{ )-";
const string QueryBuilder::QUERY_CONSTRAINS_SUBFIX = R"-(}))-";
const string QueryBuilder::QUERY_ATTRIBUTES_PREFIX = R"-({)-";
const string QueryBuilder::QUERY_ATTRIBUTES_SUBFIX = R"-(})-";

string QueryBuilder::getConstrainFromInstance(Instance* instance, string query_entity) {
    if (instance->getInstanceKind() == InstanceKind::SYMBOL) {
        if (instance->getName().compare(query_entity) == 0) {
            string query_attribute;
            for (auto a : instance->get_attribute_list()) {
                query_attribute.append(a.first).append(" ");
            }
            return query_attribute;
        }
    }

    if (instance->getInstanceKind() == InstanceKind::SPECIFIC_ATTRIBUTE) {
        auto& attributes = instance->get_attribute_list();
        for (auto attribute : attributes) {
            return attribute.second->getValueString();
        }
    }
}

string QueryBuilder::getConstrainFromNumberExpr(RuleLanguage::numberExpr* expr, string query_entity) {
    string negative = "";
    if (expr->isNegative()) {
        negative.append("-");
    }

    if (expr->isLiteral()) {
        return negative + std::to_string(expr->getValue());
    }

    if (expr->getInstance() != nullptr) {
        return negative + getConstrainFromInstance(expr->getInstance().get(), query_entity);
    }

    string left_expr_str = getConstrainFromNumberExpr(expr->getLeftExpr(), query_entity);
    string right_expr_str = getConstrainFromNumberExpr(expr->getRightExpr(), query_entity);

    return negative + left_expr_str + RuleLanguage::ArithmeticOperatorToString(expr->getOperator()) + right_expr_str;
}

string QueryBuilder::getConstrainFromStringExpr(RuleLanguage::stringExpr* expr, string query_entity) {

    if (expr->isLiteral()) {
        return expr->getLiteralValue();
    }

    if (expr->getInstance() != nullptr) {
        return getConstrainFromInstance(expr->getInstance().get(), query_entity);
    }

    return "";
}

string QueryBuilder::getConstrainFromRelationExpr(RuleLanguage::relationExpr* expr, string query_entity) {

    if (expr->getLeftNumberExpr() != nullptr && expr->getRightNumberExpr() != nullptr) {
        string first_number_expr_str = getConstrainFromNumberExpr(expr->getLeftNumberExpr(), query_entity);
        string relation_suffix = RuleLanguage::RelationOperatorToSuffixString(expr->getOperators());
        string second_numbr_expr_str = getConstrainFromNumberExpr(expr->getRightNumberExpr(), query_entity);
        return first_number_expr_str + relation_suffix + " : " + second_numbr_expr_str;
    } else if (expr->getLeftStringExpr() != nullptr && expr->getRightStringExpr() != nullptr) {
        string first_string_expr_str = getConstrainFromStringExpr(expr->getLeftStringExpr(), query_entity);
        string relation_suffix = RuleLanguage::RelationOperatorToSuffixString(expr->getOperators());
        string second_string_expr_str = R"(\")" + getConstrainFromStringExpr(expr->getRightStringExpr(), query_entity) + R"(\")";
        return first_string_expr_str + relation_suffix + " : " + second_string_expr_str;
    }


}

string QueryBuilder::getConstrainFromBasicCondExpr(RuleLanguage::basicCondExpr* expr, string query_entity) {
    RuleLanguage::relationExpr* relation_expr = expr->getRelationExpr();
    if (relation_expr != nullptr) {
        return getConstrainFromRelationExpr(relation_expr, query_entity);
    }

    // RuleLanguage::listExpr* list_expr = expr->get

    return "";
}

string QueryBuilder::getConstrainFromConditionExpr(RuleLanguage::conditionExpr* expr, string query_entity) {
    ocall_print_string("enter getConstrainFromConditionExpr", __FILE__, __LINE__);
    std::vector<std::unique_ptr<RuleLanguage::basicCondExpr>>& exprs = expr->getBasicExprs(); 
    if (exprs.size() == 0) {
        return getConstrainFromBasicCondExpr(expr->getBasicExpr(), query_entity);
    }

    string LOGICAL_PREFIX = ":[";
    string LOGICAL_SUFFIX = "]";
    string first_expr_str = "{" + getConstrainFromBasicCondExpr(expr->getBasicExpr(), query_entity) + "}";

    string query_str;
    for (int i = 0; i < exprs.size(); i++) {
        string logical_op_str = RuleLanguage::LogicalOperatorToString(exprs[i]->getOperator());
        string next_expr_str = "{" + getConstrainFromBasicCondExpr(exprs[i].get(), query_entity) + "}";
        if (query_str.empty()) {
            query_str.append(logical_op_str)
                .append(LOGICAL_PREFIX)
                .append(first_expr_str)
                .append(" , ")
                .append(next_expr_str)
                .append(LOGICAL_SUFFIX);
        }
        else {
            string temp;
            temp.append(logical_op_str)
                .append(LOGICAL_PREFIX)
                .append(query_str)
                .append(" , ")
                .append(next_expr_str)
                .append(LOGICAL_SUFFIX);
            query_str = temp;
        }

    }
    return query_str;
}

string QueryBuilder::generateQueryString(shared_ptr<Instance> instance) {
    ocall_print_string("enter generateQueryString", __FILE__, __LINE__);

    if (instance->getInstanceKind() == InstanceKind::UNIQUE_ENTITY) {
        ocall_print_string("handle unique_entity", __FILE__, __LINE__);
        string query_table = instance->getName() + "s";
        string attributes_str = "";
        for (auto attribute : instance->get_attribute_list()) {
            attributes_str = attributes_str + attribute.first + " ";
        }
        string query_string;
        query_string.append(QUERY_PREFIX)
            .append(query_table)
            .append(QUERY_ATTRIBUTES_PREFIX)
            .append(attributes_str)
            .append(QUERY_ATTRIBUTES_SUBFIX)
            .append(QUERY_SUBFIX);
        return query_string;
    }

    if (instance->getInstanceKind() == InstanceKind::EXPR) {
        ocall_print_string(("handle instance expr" + instance->dump()).c_str(), __FILE__, __LINE__);
        RuleLanguage::queryExpr* expr = dynamic_cast<RuleLanguage::queryExpr*>(instance->getExpr());
        if (expr != nullptr) {
            string query_table = expr->getQueryTable();
            string attributes_str = "";
            for (auto attribute : expr->getAttributs()) {
                attributes_str = attributes_str + attribute.first + " ";
            }

            string constraint_str = getConstrainFromConditionExpr(expr->getExpr(), expr->getName());
            string query_string;
            return query_string.append(QUERY_PREFIX)
                .append(query_table)
                .append(QUERY_CONSTRAINS_PREFIX)
                .append(constraint_str)
                .append(QUERY_CONSTRAINS_SUBFIX)
                .append(QUERY_ATTRIBUTES_PREFIX)
                .append(attributes_str)
                .append(QUERY_ATTRIBUTES_SUBFIX)
                .append(QUERY_SUBFIX);
        }
    }

    return "error!";
}




uint64_t QueryBuilder::handleWithinValue(uint64_t timestamp, const rule_check_proto::Within& within) {
    uint64_t within_value = within.value();
    Within_UNIT unit = within.unit();
    ocall_print_string("handle within", __FILE__, __LINE__);
    uint64_t result = 0;
    switch (unit) {
        case Within_UNIT_SEC:
            result = timestamp - within_value * 1000;
            break;
        case Within_UNIT_MINIT:
            result = timestamp - within_value * 60 * 1000;
            break;
        case Within_UNIT_HOUR:
            result = timestamp - within_value * 60 * 60 * 1000;
            break;
        case Within_UNIT_DAY:
            result = timestamp - within_value * 24 * 60 * 60 * 1000;
            break;
        default:
            break;
    }
    return result;
}
