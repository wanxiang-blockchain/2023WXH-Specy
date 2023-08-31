#include "SemanticModelEngine.h"
#include "trusted/data_provider/Query.h"
#include "trusted/data_provider/DataProvider.h"
#include "RuleEnclave_t.h"

using namespace std;
using namespace RuleLanguage;

SemanticModelEngine::SemanticModelEngine(SymbolCollector* collector) : symbol_collector(collector) {
    root = collector->getExecuteRoot();
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
        if (!instance.second->updateValue(instance_json)) {
            ocall_print_string((string("Error: update ") + instance.first + string(" value error")).c_str(), __FILE__, __LINE__);
            return false;
        }

        ocall_print_string(instance.second->dumpAttributeValue().c_str(), __FILE__, __LINE__);

    }

    ocall_print_string("queryData end. ", __FILE__, __LINE__);
    return true;
}

bool SemanticModelEngine::updateInstanceValue(shared_ptr<Instance> instance) {
    QueryBuilder builder;
    DataProvider provider;
    string entities_space = symbol_collector->getEntitiesSpace();

    if (instance->needQuery()) {
        string query_str = builder.generateQueryString(instance);
        ocall_print_string(query_str.c_str(), __FILE__, __LINE__);
        json11::Json instance_json;
        if (provider.QueryDataFromGraphnodeJson(query_str, entities_space, instance_json) != RuleEnclaveStatus::kOK) {
            return false;
        }
        if (!instance->updateValue(instance_json)) {
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
        
        default:
            ocall_print_string("Error: instance type error!", __FILE__, __LINE__);
            return false;
            break;
        }
    }
    return true;
}

bool SemanticModelEngine::execute() {
    // update global instance value
    if (!queryData()) {
        return false;
    }
    // execute rule
    ocall_print_string("start execute", __FILE__, __LINE__);
    return executeRule(root.get());
}

bool SemanticModelEngine::executeStmt(RuleLanguage::Expr* expr) {
    ocall_print_string("enter executeStmt", __FILE__, __LINE__);
    if (dynamic_cast<RuleLanguage::definitionExpr*>(expr) != nullptr) {
        ocall_print_string("handle difinition expr", __FILE__, __LINE__);
        RuleLanguage::definitionExpr* def_expr = dynamic_cast<RuleLanguage::definitionExpr*>(expr);
        return updateInstanceValue(def_expr->instance);
    }

    if (dynamic_cast<RuleLanguage::relationExpr*>(expr) != nullptr) {
        ocall_print_string("calculate relation expr", __FILE__, __LINE__);
        RuleLanguage::relationExpr* relation_expr = dynamic_cast<RuleLanguage::relationExpr*>(expr);
        return calculateRelationExpr(relation_expr);
    }

    if (dynamic_cast<RuleLanguage::logicalExpr*>(expr) != nullptr) {
        ocall_print_string("calculate logical expr", __FILE__, __LINE__);
        RuleLanguage::logicalExpr* logical_expr = dynamic_cast<RuleLanguage::logicalExpr*>(expr);
        return calculateLogicalExpr(logical_expr);
    }
}

bool SemanticModelEngine::executeRule(ExecuteRule* rule) {
    

    string rule_name = rule->rule_name;
    auto& rule_stmts = symbol_collector->getRuleStmtMap()[rule_name];
    bool execute_result = true;

    // start execute rule
    for (int i = 0; i < rule_stmts.size(); i++) {
        execute_result &= executeStmt(rule_stmts[i].get());
    }

    // FIX: this is just for test
    execute_result = false;

    if (rule->true_branch != nullptr && execute_result) {
        return executeRule(rule->true_branch);
    }

    if (rule->false_branch != nullptr && !execute_result) {
        return executeRule(rule->false_branch);
    }

    return execute_result;
}

bool SemanticModelEngine::calculateRelationExpr(RuleLanguage::relationExpr* expr) {
    int64_t leftValue = calculateNumberExpr(expr->getFirstNumberExpr());
    auto& numbers = expr->getNumbers();
    auto& operators = expr->getOperators();
    int64_t rightValue = calculateNumberExpr(numbers[0].get());
    switch (operators[0])
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