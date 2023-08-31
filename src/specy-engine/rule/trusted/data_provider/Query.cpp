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

// for now, it is a particular function for rule
string QueryBuilder::GenerateQueryString(const EntityRule& entity) {
    string rule_query_string_prefix(R"-({"query":"{tasks(where:{hash:\")-");
    string rule_query_string_subfix(R"-(\"}){rule_file \n }}"})-");
    return rule_query_string_prefix + entity.get_name() +
           rule_query_string_subfix;
}

string QueryBuilder::concatenateQueryString (const EntityType& entity, const RequestContext* context, const vector<string>& constraintStrs) {
    string query_tables(entity.get_name() + "s");
    
    string query_constrains;
    query_constrains.append(QUERY_CONSTRAINS_PREFIX);
    for (auto constrain : constraintStrs) {
        query_constrains.append(constrain);
    }
    query_constrains.append(QUERY_CONSTRAINS_SUBFIX);

    string query_attributes;
    query_attributes.append(QUERY_ATTRIBUTES_PREFIX);
    for (auto attribute : entity.get_attribute_set()) {
        query_attributes.append(attribute).append(" ");
    }
    query_attributes.append(QUERY_ATTRIBUTES_SUBFIX);

    string query_string;
    query_string.append(QUERY_PREFIX)
        .append(query_tables)
        .append(query_constrains)
        .append(query_attributes)
        .append(QUERY_SUBFIX);
    
    return query_string;
}

string QueryBuilder::GenerateQueryString(const Entity& entity, const RequestContext* context) {

    vector<string> constraintStrs;
    collectConstrainStrings(entity, context, constraintStrs);
    string query_string = concatenateQueryString(dynamic_cast<const EntityType&>(entity), context, constraintStrs);
    
    ocall_print_string(("GenerateQueryString(const Entity& entity, const RequestContext* context) : " + query_string).c_str(), __FILE__, __LINE__);
    return query_string;
}

string QueryBuilder::GenerateQueryString(EntitySet& entity, const RequestContext* context) {
    vector<string> constraintStrs;
    collectConstrainStrings(entity, context, constraintStrs);
    string query_string = concatenateQueryString(dynamic_cast<const EntityType&>(entity), context, constraintStrs);

    ocall_print_string(("GenerateQueryString(const EntitySet& entity, const RequestContext* context) : " + query_string).c_str(), __FILE__, __LINE__);
    return query_string;
}

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

    // TODO: After query data, we should update instance value
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

string QueryBuilder::getConstrainFromRelationExpr(RuleLanguage::relationExpr* expr, string query_entity) {
    string first_number_expr_str = getConstrainFromNumberExpr(expr->getFirstNumberExpr(), query_entity);
    string relation_suffix = RuleLanguage::RelationOperatorToSuffixString(expr->getOperators()[0]);
    string second_numbr_expr_str = getConstrainFromNumberExpr(expr->getNumbers()[0].get(), query_entity);
    return first_number_expr_str + relation_suffix + " : " + second_numbr_expr_str;
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
    if (instance->getInstanceKind() == InstanceKind::UNIQUE_ENTITY) {
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
        RuleLanguage::queryExpr* expr = dynamic_cast<RuleLanguage::queryExpr*>(instance->getExpr());
        if (expr != nullptr) {
            string query_table = expr->entity->get_name() + "s";
            string attributes_str = "";
            for (auto attribute : expr->entity->get_attribute_list()) {
                attributes_str = attributes_str + attribute.first + " ";
            }

            string constraint_str = getConstrainFromConditionExpr(expr->getExpr(), expr->entity->get_name());
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


uint64_t QueryBuilder::getTimestampValue(const RequestContext* context, const string& entity_name) {
    const auto initial_binding = context->get_entity_binding(entity_name);
    auto timestamp_json = initial_binding[entity_name]["timestamp"];

    uint64_t timestamp = 0;
    int entity_timestamp_value = stoi(timestamp_json.string_value());
    if (entity_timestamp_value < 0) {
        uint64_t mask = 0x000000007FFFFFFFUL;
        uint64_t minus_bit = 0x0000000080000000UL;
        timestamp = entity_timestamp_value & mask | minus_bit;
    } else {
        timestamp = static_cast<uint64_t>(entity_timestamp_value);
    }

    return timestamp;
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

void QueryBuilder::collectConstrainStrings(EntitySet& entity, const RequestContext* context, vector<string>& constraintStrs) {
    // constraintStrs.push_back(R"-(contract_address:\")-" +
    //                               context->contract_id + R"-(\" )-");
    for (auto constrain : entity.get_constraint_list()) {
        if (constrain.has_within()) {
            ocall_print_string("handle within", __FILE__, __LINE__);
            auto within = constrain.within();
            uint64_t timestamp = getTimestampValue(context, entity.get_name());
            timestamp = handleWithinValue(timestamp, within);
            constraintStrs.push_back(R"-(timestamp_gt:)-" + to_string(timestamp) + R"-( )-");
        }

        if (constrain.has_provided()) {
            ocall_print_string("handle provided", __FILE__, __LINE__);
            auto provide = constrain.provided();
            constraintStrs.push_back(provide.entity() + ":" + R"(\")" + provide.member() + R"(\" )");
        }

        if (constrain.has_where()) {
            ocall_print_string("handle where", __FILE__, __LINE__);
            auto where = constrain.where();
            const auto entity_name = where.left_entity();
            const auto attribute_name = where.left_member();

            ocall_print_string((entity_name + "." + attribute_name).c_str(), __FILE__, __LINE__);
            auto binding_json = context->get_entity_binding(entity_name);
            ocall_print_string(binding_json.dump().c_str(), __FILE__, __LINE__);
            auto binding_data = binding_json[entity_name][attribute_name].string_value();
            ocall_print_string(binding_data.c_str(), __FILE__, __LINE__);
            constraintStrs.push_back(string(attribute_name + ":") + R"(\")" + binding_data + R"(\" )");

            entity.add_attributes(attribute_name);
        }
    }
}

void QueryBuilder::collectConstrainStrings(const Entity& entity, const RequestContext* context, vector<string>& constraintStrs) {
    constraintStrs.push_back(R"-(contract_address:\")-" +
                                  context->contract_id + R"-(\" )-");
    constraintStrs.push_back(R"-(hash:\")-" + context->tx_hash + R"-(\" )-");
}