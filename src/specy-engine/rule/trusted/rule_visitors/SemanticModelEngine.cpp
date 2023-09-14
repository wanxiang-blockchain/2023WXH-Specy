#include "SemanticModelEngine.h"
#include "trusted/data_provider/Query.h"
#include "trusted/data_provider/DataProvider.h"
#include "RuleEnclave_t.h"

using namespace std;
using namespace RuleLanguage;

SemanticModelEngine::SemanticModelEngine(SymbolCollector* collector, RequestContext* context) : symbol_collector(collector), request_context(context) {
    root = collector->getExecuteRoot();
    output_instance = symbol_collector->getOutputInstance();
}

bool SemanticModelEngine::bindInputData(std::string input_data) {
    ocall_print_string(("bind input data : " + input_data).c_str(), __FILE__, __LINE__);
    std::string error_info;
    json11::Json input_json = json11::Json::parse(input_data, error_info);
    if (!error_info.empty()) {
        ocall_print_string(error_info.c_str(), __FILE__, __LINE__);
        return false;
    }
    auto instance = symbol_collector->getInputInstance();
    return instance->updateAttributeValue(input_json);
}

// handle global instances
bool SemanticModelEngine::queryData() {
    QueryBuilder builder;
    DataProvider provider;

    // handle unique_entity data
    InstanceMap& global_instances = symbol_collector->getGlobalInstanceMap();
    string entities_space = symbol_collector->getEntitiesSpace();
    for (auto instance : global_instances) {
        string query_string = builder.generateQueryString(instance.second);
        ocall_print_string(query_string.c_str(), __FILE__, __LINE__);
        json11::Json instance_json;
        auto ans = provider.QueryDataFromGraphnodeJson(query_string, entities_space, instance_json);
        if (!instance.second->updateAttributeValue(instance_json)) {
            ocall_print_string((string("Error: update ") + instance.first + string(" value error")).c_str(), __FILE__, __LINE__);
            return false;
        }

        ocall_print_string(instance.second->dumpAttributeValue().c_str(), __FILE__, __LINE__);

    }

    ocall_print_string("queryData end. ", __FILE__, __LINE__);
    return true;
}

bool SemanticModelEngine::updateInstanceValue(shared_ptr<Instance> instance) {
    ocall_print_string("Debug: enter updateInstanceValue", __FILE__, __LINE__);
    string addr = std::to_string(reinterpret_cast<uint64_t>(instance.get()));
    ocall_print_string((instance->name + ": " + addr.c_str()).c_str(), __FILE__, __LINE__);
    QueryBuilder builder;
    DataProvider provider;
    string entities_space = symbol_collector->getEntitiesSpace();
    if (instance->getName().compare("outputdata") == 0) {
        ocall_print_string("Debug: handle outputdata", __FILE__, __LINE__);
        auto attribute = output_instance->getAttribute(instance->specific_attribute);
        return attribute->updateValueFromRelatedInstance();
    }

    if (instance->needQuery()) {
        string query_str = builder.generateQueryString(instance);
        ocall_print_string(query_str.c_str(), __FILE__, __LINE__);
        json11::Json instance_json;
        if (provider.QueryDataFromGraphnodeJson(query_str, entities_space, instance_json) != RuleEnclaveStatus::kOK) {
            return false;
        }
        if (!instance->updateAttributeValue(instance_json)) {
            return false;
        }
    }

    if (instance->needCalculate()) {

        switch (instance->type())
        {
        case RuleLanguage::Type::NUMBER :
            ocall_print_string("Debug: Calculate instance number value", __FILE__, __LINE__);
            return instance->updateNumberValue(getNumberValueFromInstance(instance.get()));

        case RuleLanguage::Type::BOOLEAN :
            ocall_print_string("Debug: Calculate instance boolean value", __FILE__, __LINE__);
            return instance->updateBooleanValue(getBooleanValueFromInstance(instance.get()));

        case RuleLanguage::Type::STRING :
            ocall_print_string("Debug: Calculate instance string value", __FILE__, __LINE__);
            return instance->updateStringValue(getStringValueFromInstance(instance.get()));

        case RuleLanguage::Type::INSTANCELIST :
            ocall_print_string("Debug: Calculate instance list value", __FILE__, __LINE__);
            return instance->updateListValue(getListValueFromInstance(instance.get()));
        
        default:
            ocall_print_string("Error: instance type error!", __FILE__, __LINE__);
            return false;
            break;
        }
    }

    return true;
}

bool SemanticModelEngine::execute() {

    if (!bindInputData(request_context->getInputData())) {
        ocall_print_string("Error: bind input data error!", __FILE__, __LINE__);
        return false;
    }

    // update global instance value
    if (!queryData()) {
        return false;
    }
    // execute rule
    ocall_print_string("start execute", __FILE__, __LINE__);
    bool execute_result = executeRule(root.get());
    if (execute_result){
        ocall_print_string("execute result is true", __FILE__, __LINE__);
    } else {
        ocall_print_string("execute result is false", __FILE__, __LINE__);
    }
    
    request_context->setResult(execute_result);
    ocall_print_string("execute result output is ", __FILE__, __LINE__);
    json11::Json execute_output = output_instance->dumpJson();
    ocall_print_string(execute_output.dump().c_str(), __FILE__, __LINE__);
    request_context->setOutputData(execute_output.dump());
    
    return true;
}

bool SemanticModelEngine::executeStmt(RuleLanguage::Expr* expr) {
    ocall_print_string("enter executeStmt", __FILE__, __LINE__);
    if (dynamic_cast<RuleLanguage::definitionExpr*>(expr) != nullptr) {
        RuleLanguage::definitionExpr* def_expr = dynamic_cast<RuleLanguage::definitionExpr*>(expr);
        ocall_print_string(("handle difinition expr " + def_expr->dump()).c_str(), __FILE__, __LINE__);
        return updateInstanceValue(def_expr->instance);
    }

    if (dynamic_cast<RuleLanguage::relationExpr*>(expr) != nullptr) {
        RuleLanguage::relationExpr* relation_expr = dynamic_cast<RuleLanguage::relationExpr*>(expr);
        ocall_print_string(("calculate relation expr" + relation_expr->dump()).c_str(), __FILE__, __LINE__);
        return calculateRelationExpr(relation_expr);
    }

    if (dynamic_cast<RuleLanguage::logicalExpr*>(expr) != nullptr) {
        RuleLanguage::logicalExpr* logical_expr = dynamic_cast<RuleLanguage::logicalExpr*>(expr);
        ocall_print_string(("calculate logical expr" + logical_expr->dump()).c_str(), __FILE__, __LINE__);
        return calculateLogicalExpr(logical_expr);
    }
}

bool SemanticModelEngine::executeRule(ExecuteRule* rule) {
    

    curr_rule_name = rule->rule_name;
    auto& rule_stmts = symbol_collector->getRuleStmtMap()[curr_rule_name];
    auto& executed_rules = request_context->getRules();
    executed_rules.push_back(curr_rule_name);
    bool execute_result = true;

    // start execute rule
    for (int i = 0; i < rule_stmts.size(); i++) {
        execute_result &= executeStmt(rule_stmts[i].get());
    }

    if (rule->true_branch != nullptr && execute_result) {
        return executeRule(rule->true_branch);
    }

    if (rule->false_branch != nullptr && !execute_result) {
        return executeRule(rule->false_branch);
    }

    return execute_result;
}

bool SemanticModelEngine::calculateRelationExpr(RuleLanguage::relationExpr* expr) {
    int64_t leftValue = calculateNumberExpr(expr->getLeftNumberExpr());
    auto operators = expr->getOperators();
    int64_t rightValue = calculateNumberExpr(expr->getRightNumberExpr());
    switch (operators)
    {
    case RuleLanguage::RelationOperator::EQUALS :
        return leftValue == rightValue;

    case RuleLanguage::RelationOperator::GREATER:
        return leftValue > rightValue;
    
    case RuleLanguage::RelationOperator::GREATER_OR_EQUALS:
        return leftValue >= rightValue;

    case RuleLanguage::RelationOperator::LESS_OR_EQUALS:
        return leftValue <= rightValue;

    case RuleLanguage::RelationOperator::LESS_THAN:
        return leftValue < rightValue;

    case RuleLanguage::RelationOperator::NOT_EQUALS:
        return leftValue != rightValue;
    
    default:
        break;
    }
    return false;
}

bool SemanticModelEngine::calculateBooleanExpr (RuleLanguage::booleanExpr* expr) {
    if (expr->expr == nullptr && expr->instance == nullptr) {
        return expr->literalValue;
    }

    if (expr->expr != nullptr) {
        RuleLanguage::relationExpr* relation_expr = dynamic_cast<RuleLanguage::relationExpr*>(expr->expr.get());
        if (relation_expr != nullptr) {
            return calculateRelationExpr(relation_expr);
        }

        //TODO: List Expr
    }

    if (expr->instance != nullptr) {
        if (expr->instance->getInstanceKind() == InstanceKind::EXPR) {
            auto value = expr->instance->getValue();
            return value.boolean_value;
        }

        if (expr->instance->getInstanceKind() == InstanceKind::SPECIFIC_ATTRIBUTE) {
            auto attribute = expr->instance->getSpecificAttribute();
            BooleanAttribute* boolean_attribute = dynamic_cast<BooleanAttribute*>(attribute.get());
            return boolean_attribute->getValue();
        }
    }
}

bool SemanticModelEngine::calculateLogicalExpr(RuleLanguage::logicalExpr* expr) {
    ocall_print_string("enter calculateLogicalExpr, handle expr", __FILE__, __LINE__);
    ocall_print_string(expr->dump().c_str(), __FILE__, __LINE__);
    if (expr->logical_operator == RuleLanguage::LogicalOperator::NOT) {
        ocall_print_string("not operator", __FILE__, __LINE__);
        return !calculateLogicalExpr(dynamic_cast<RuleLanguage::logicalExpr*>(expr->right_expr.get()));
    }

    if (expr->boolean_expr != nullptr) {
        ocall_print_string("boolean expr", __FILE__, __LINE__);
        return calculateBooleanExpr(dynamic_cast<RuleLanguage::booleanExpr*>(expr->boolean_expr.get()));
    }

    RuleLanguage::logicalExpr* left_logical_expr = dynamic_cast<RuleLanguage::logicalExpr*>(expr->left_expr.get());
    RuleLanguage::logicalExpr* right_logical_expr = dynamic_cast<RuleLanguage::logicalExpr*>(expr->right_expr.get());


    if (expr->logical_operator == RuleLanguage::LogicalOperator::AND) {
        return calculateLogicalExpr(left_logical_expr) && calculateLogicalExpr(right_logical_expr);
    }

    if (expr->logical_operator == RuleLanguage::LogicalOperator::OR) {
        return calculateLogicalExpr(left_logical_expr) || calculateLogicalExpr(right_logical_expr);
    }

    return false;

}

int64_t SemanticModelEngine::calculateNumberExpr(RuleLanguage::numberExpr* expr) 
{
    int negative = expr->isNegative() ? -1 : 1;
    if (expr->isLiteral()) {
        return expr->getValue() * negative;
    }

    if (expr->getInstance() != nullptr) {
        auto instance = expr->getInstance();
        return getNumberValueFromInstance(instance.get()) * negative;    
    }

    int64_t left = calculateNumberExpr(expr->getLeftExpr());
    int64_t right = calculateNumberExpr(expr->getRightExpr());
    switch (expr->getOperator())
    {
    case RuleLanguage::ArithmeticOperator::DIVIDE :
        return left / right;

    case RuleLanguage::ArithmeticOperator::MODULO :
        return left % right;

    case RuleLanguage::ArithmeticOperator::MULTIPLY :
        return left * right;

    case RuleLanguage::ArithmeticOperator::MINUS :
        return left - right;

    case RuleLanguage::ArithmeticOperator::PLUS :
        return left + right;
    
    default:
        break;
    }

    return 0;
}

int64_t SemanticModelEngine::getNumberValueFromInstance(Instance* instance) {
    if (instance->getInstanceKind() == InstanceKind::SPECIFIC_ATTRIBUTE) {
        Attribute* attribute = instance->getSpecificAttribute().get();
        NumberAttribute* number_attr = dynamic_cast<NumberAttribute*>(attribute);
        return number_attr->getValue();
    }

    if (instance->getInstanceKind() == InstanceKind::EXPR) {
        RuleLanguage::Expr* expr = instance->getExpr();

        if (expr->type() != RuleLanguage::NUMBER) {
            ocall_print_string("Error! expr type wrong", __FILE__, __LINE__);
        }

        return calculateNumberExpr(dynamic_cast<RuleLanguage::numberExpr*>(expr));
    }

    ocall_print_string("Error! getNumberValueFromInstance error!", __FILE__, __LINE__);
    return 0;
}

bool SemanticModelEngine::getMatchValues(RuleLanguage::basicCondExpr* condition_expr,
                                         const std::vector<Value>& list_value,
                                         const RuleLanguage::Type list_type,
                                         std::vector<Value>& match_values) {
    //for now support list only 
    ocall_print_string("Debug: enter getMatchValues", __FILE__, __LINE__);
    RuleLanguage::listExpr* expr = condition_expr->getListExpr();
    if (expr == nullptr) {
        ocall_print_string("Error: for now, support list only!", __FILE__, __LINE__);
        return false;
    }

    string right_instance_name = expr->right_instance->name;
    shared_ptr<Instance> right_instancc = symbol_collector->getRuleInstanceMap()[curr_rule_name][right_instance_name];
    auto& right_values = right_instancc->list_values;

    ocall_print_string("left value is", __FILE__, __LINE__);
    for (auto value : list_value) {
        ocall_print_string(value.dump().c_str(), __FILE__, __LINE__);
    }


    ocall_print_string("right value is", __FILE__, __LINE__);
    for (auto value : right_values) {
        ocall_print_string(value.dump().c_str(), __FILE__, __LINE__);
    }

    if (expr->inside) {
        ocall_print_string("left value in right list", __FILE__, __LINE__);
        for (auto lvalue : list_value) {
            for (auto rvalue : right_values) {
                if (lvalue.match(list_type, rvalue)) {
                    match_values.push_back(lvalue);
                    break;
                }
            }
        }
        return true;
    }

    if (!expr->inside) {
        ocall_print_string("left value not in right list", __FILE__, __LINE__);
        for (auto lvalue : list_value) {
            bool match = false;
            for (auto rvalue : right_values) {
                match |= lvalue.match(list_type,rvalue);
            }
            if (!match) {
                match_values.push_back(lvalue);
            }
        }
        return true;
    }

    return false;
}

json11::Json SemanticModelEngine::calculateQueryExpr(RuleLanguage::queryExpr* expr) {

    ocall_print_string("Debug: enter calculateQueryExpr", __FILE__, __LINE__);
    RuleLanguage::conditionExpr* condition_expr = expr->getExpr();
    auto& list_value = expr->getInstance()->list_values;
    auto list_type = expr->getInstance()->list_type;
    json11::Json result;

    RuleLanguage::basicCondExpr* first_condition = condition_expr->getBasicExpr();
    std::vector<Value> match_values;
    if (!getMatchValues(first_condition, list_value, list_type, match_values)) {
        ocall_print_string("Error: select or collect data from list error!", __FILE__, __LINE__);
        return result;
    }

    json11::Json::array json_result;
    for (auto value : match_values) {
        if (list_type == RuleLanguage::Type::BOOLEAN) {
            json_result.push_back(json11::Json(value.boolean_value));
        }

        if (list_type == RuleLanguage::Type::NUMBER) {
            json_result.push_back(json11::Json(static_cast<int>(value.number_value)));
        }

        if (list_type == RuleLanguage::Type::STRING) {
            json_result.push_back(json11::Json(value.string_value));
        }
    }
    
    result = json_result;
    ocall_print_string(("Debug: dump result json " + result.dump()).c_str(), __FILE__, __LINE__);
    return result;
}

json11::Json SemanticModelEngine::getListValueFromInstance(Instance* instance) {
    
    ocall_print_string("Debug: getListValueFromInstance", __FILE__, __LINE__);
    RuleLanguage::Expr* expr = instance->getExpr();
    RuleLanguage::queryExpr* query_expr = dynamic_cast<RuleLanguage::queryExpr*>(expr);
    if (query_expr == nullptr) {
        ocall_print_string("Error: we only support query expr in list now!", __FILE__, __LINE__);
    }

    return calculateQueryExpr(query_expr);
}


bool SemanticModelEngine::getBooleanValueFromInstance(Instance* instance) {
    if (instance->getInstanceKind() == InstanceKind::SPECIFIC_ATTRIBUTE) {
        Attribute* attribute = instance->getSpecificAttribute().get();
        BooleanAttribute* boolean_attr = dynamic_cast<BooleanAttribute*>(attribute);
        return boolean_attr->getValue();
    }

    if (instance->getInstanceKind() == InstanceKind::EXPR) {
        RuleLanguage::Expr* expr = instance->getExpr();

        if (expr->type() != RuleLanguage::BOOLEAN) {
            ocall_print_string("Error! expr type wrong", __FILE__, __LINE__);
        }

        return calculateLogicalExpr(dynamic_cast<RuleLanguage::logicalExpr*>(instance->getExpr()));

    }

    ocall_print_string("Error! getNumberValueFromInstance error!", __FILE__, __LINE__);
    return false;
}

string SemanticModelEngine::getStringValueFromInstance(Instance* instance) {
    if (instance->getInstanceKind() == InstanceKind::SPECIFIC_ATTRIBUTE) {
        Attribute* attribute = instance->getSpecificAttribute().get();
        StringAttribute* string_attr = dynamic_cast<StringAttribute*>(attribute);
        return string_attr->getValue();
    }
}


json11::Json SemanticModelEngine::getOutputData() {
    return output_instance->dumpJson();
}