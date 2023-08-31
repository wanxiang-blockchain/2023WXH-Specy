// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements SymbolCollector class.

#include "SymbolCollector.h"

using namespace std;
using namespace antlr4;
using namespace rule_check_proto;

SymbolCollector::~SymbolCollector()
{

}

/* Internal Handler Member Functions */

Attribute* SymbolCollector::createAttribute(std::string name, RuleLanguage::Type type) {

    Attribute* ans = nullptr;

    switch (type)
    {
    case RuleLanguage::Type::NUMBER:
        ans = new NumberAttribute(name, type);
        break;

    case RuleLanguage::Type::BOOLEAN:
        ans = new BooleanAttribute(name, type);
        break;

    case RuleLanguage::Type::STRING:
        ans = new StringAttribute(name, type);
        break;

    case RuleLanguage::Type::INSTANCE:
        ans = new ObjectAttribute(name, type);
        break;
    
    default:
        break;
    }

    return ans;
}


// mark entity as request needed, only concern specific attribute name
void SymbolCollector::KeepTrackOfNewEntity(const string &entity_name, string &attribute_name, RuleLanguage::Type type)
{
    ocall_print_string((string("KeepTrackOfNewEntity: ") +
                        entity_name + string("[") +
                        attribute_name + string("]")).c_str(), __FILE__, __LINE__);
    
    auto attribute = createAttribute(attribute_name, type);
    if (attribute == nullptr) {
        ocall_print_string((string("Error: attribute type not support! ")).c_str(), __FILE__, __LINE__);
        return;
    }

    // decide on whether entity exists
    if (this->entity_map_.find(entity_name) == this->entity_map_.end())
    {
        // NOTE: `entity` is deleted with `SymbolCollector` destructor
        Entity *entity = new Entity(entity_name);
        entity->setUnique(false);
        std::shared_ptr<Attribute> attribute_ptr(attribute);
        entity->addAttribute(attribute_name, attribute_ptr);
        this->entity_map_[entity_name] = shared_ptr<Entity>(entity);
    }
    else
    {
        auto entity = this->entity_map_[entity_name];
        std::shared_ptr<Attribute> attribute_ptr(attribute);
        entity->addAttribute(attribute_name, attribute_ptr);
    }
}

void SymbolCollector::KeepTrackOfNewInstance(const std::string &instance_name, std::string &entity_name) {
    ocall_print_string((string("KeepTrackOfNewInstance: ") +
                        instance_name + string(" related to ") +
                        entity_name).c_str(), __FILE__, __LINE__);
    if (global_instance_map_.find(instance_name) == global_instance_map_.end()) {
        shared_ptr<Instance> instance(new Instance(instance_name));
        if (!entity_name.empty()) {
            instance->setUniqueEntityName(entity_name);
            instance->addAttributes(entity_map_[entity_name]->get_attribute_list());
        }
        instance->setInstanceKind(InstanceKind::UNIQUE_ENTITY);
        global_instance_map_.insert({instance_name, instance});
    } else {
        ocall_print_string((string("Error: ") +
                        instance_name + string(" has been defined! ")).c_str(), __FILE__, __LINE__);
    }
}

void SymbolCollector::KeepTrackOfNewInstance(const std::string &instance_name, RuleLanguage::Expr* expr) {
    ocall_print_string((string("KeepTrackOfNewInstance: ") +
                        instance_name + string(" related to expr")).c_str(), __FILE__, __LINE__);
    auto& instance_map = rule_instance_map_[curr_rule_name_];
    auto& instance_order = rule_instance_order_[curr_rule_name_];
    
    if (instance_map.find(instance_name) == instance_map.end()) {
        ocall_print_string((string("KeepTrackOfNewInstance: insert instance ") +
                        instance_name).c_str(), __FILE__, __LINE__);
        shared_ptr<Instance> instance(new Instance(instance_name));
        instance_order.push_back(instance_name);
        instance->setInstanceKind(InstanceKind::EXPR);

        if (dynamic_cast<RuleLanguage::queryExpr*>(expr) != nullptr) {
            RuleLanguage::queryExpr* query_expr = dynamic_cast<RuleLanguage::queryExpr*>(expr);
            if (query_expr->getEntity() != nullptr) {
                instance->addAttributes(query_expr->getEntity()->get_attribute_list());
            }

            if (query_expr->getInstance() != nullptr) {
                instance->addAttributes(query_expr->getInstance()->get_attribute_list());
            }
        }
        
        instance->setExpr(expr);
        instance_map[instance_name] = instance;
    } else {
        ocall_print_string((string("Error: ") +
                        instance_name + string(" has been defined! ")).c_str(), __FILE__, __LINE__);
    }
}

antlrcpp::Any SymbolCollector::visitEntitiesBlock(RuleParser::EntitiesBlockContext *context) {
    entities_spaec_name = context->IDENTIFIER()->getText();
    return RuleParserBaseVisitor::visitEntitiesBlock(context);
}

/* Overridden Visitor Member Functions */
antlrcpp::Any SymbolCollector::visitEntityDecl(RuleParser::EntityDeclContext *context)
{
    ocall_print_string(("enter visitEntityDecl: " + context->getText()).c_str(), __FILE__, __LINE__);

    // check if we encounter a set entity declaration
   
    string entity_name = context->entityName()->getText();
    const auto& attributes = context->attributeList()->attributeDecl();
    for (auto attribute : attributes) {
        string attribute_name = attribute->attributeName()->getText();
        auto attribute_type = getAttributeTypeFromDef(attribute->typeAnno());
        KeepTrackOfNewEntity(entity_name, attribute_name, attribute_type);
    }

    if (context->UNIQUE()) {
        entity_map_[entity_name]->setUnique(true);
        string instance_name = entity_name;
        KeepTrackOfNewInstance(instance_name, entity_name);
    }

    return nullptr;
}

void SymbolCollector::setCurrRuleName (std::string &rule_name) {
    curr_rule_name_ = rule_name;
}

antlrcpp::Any SymbolCollector::visitBasicRule(RuleParser::BasicRuleContext *context)
{
    ocall_print_string(("enter visitBasicRule: " + context->getText()).c_str(), __FILE__, __LINE__);
    string rule_name = context->ruleName()->getText();
    ocall_print_string(("enter visitBasicRule:  rule name is" + rule_name).c_str(), __FILE__, __LINE__);
    setCurrRuleName(rule_name);
    InstanceMap m;
    rule_instance_map_[rule_name] = m;
    InstanceOrder o;
    rule_instance_order_[rule_name] = o;
    return RuleParserBaseVisitor::visitBasicRule(context);
}

shared_ptr<Instance> SymbolCollector::handleSelectorIdent(RuleParser::SelectorIdentContext *context, RuleLanguage::Type type) {

    string instance_name = context->entityName()->getText();
    string attribute_name = context->attributeName()->getText();
    ocall_print_string((string("handleSelectorIdent: ") + instance_name + "." + attribute_name + " with type " + RuleLanguage::TypeToString(type)).c_str(), __FILE__, __LINE__);

    if (global_instance_map_.find(instance_name) != global_instance_map_.end() && global_instance_map_[instance_name]->hasAttribute(attribute_name, type)) {
        ocall_print_string((string("find selectorident in global instances ")).c_str(), __FILE__, __LINE__);
        shared_ptr<Instance> instance(new Instance(instance_name));
        instance->setType(type);
        instance->setInstanceKind(InstanceKind::SPECIFIC_ATTRIBUTE);
        instance->addAttribute(attribute_name, global_instance_map_[instance_name]->getAttribute(attribute_name, type));
        return instance;
    }

    // return a symbol type instance, which not in instance map
    if (entity_map_.find(instance_name) != entity_map_.end() && entity_map_[instance_name]->hasAttribute(attribute_name, type)) {
        ocall_print_string((string("find selectorident in Entities ")).c_str(), __FILE__, __LINE__);
        // string instance_new_name = instance_name + "." + attribute_name;
        shared_ptr<Instance> instance_temp(new Instance(instance_name));
        instance_temp->addAttribute(attribute_name, entity_map_[instance_name]->getAttribute(attribute_name, type));
        instance_temp->setInstanceKind(InstanceKind::SYMBOL);
        return instance_temp;
    }

    auto& rule_instances = rule_instance_map_[curr_rule_name_];
    if (rule_instances.find(instance_name) != rule_instances.end() ) {
        ocall_print_string((string("Debug: instance name found in ") + curr_rule_name_).c_str(), __FILE__, __LINE__);
        if (rule_instances[instance_name]->hasAttribute(attribute_name, type)) {
            ocall_print_string((string("Debug: instance attribute type match ") + RuleLanguage::TypeToString(type)).c_str(), __FILE__, __LINE__);
            shared_ptr<Instance> instance(new Instance(instance_name));
            instance->setType(type);
            instance->setInstanceKind(InstanceKind::SPECIFIC_ATTRIBUTE);
            instance->addAttribute(attribute_name, rule_instances[instance_name]->getAttribute(attribute_name, type));
            return instance;
        }
    }

    ocall_print_string((string("Error: undefined instance! ")).c_str(), __FILE__, __LINE__);
    return nullptr;
}


RuleLanguage::booleanExpr* SymbolCollector::handleBooleanExpr(RuleParser::BooleanExprContext *context) {
    
    if (context == nullptr) {
        ocall_print_string((string("Error: Parser Error! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    if (context->booleanExpr()) {
        return handleBooleanExpr(context->booleanExpr());
    }
    
    if (context->booleanLiteral()) {
        RuleLanguage::booleanExpr* expr = new RuleLanguage::booleanExpr();
        if (context->booleanLiteral()->getText().compare("true") == 0) {
            expr->setValue(true);
        } else if (context->booleanLiteral()->getText().compare("false") == 0) {
            expr->setValue(false);
        } else {
            ocall_print_string((string("Error: illegal input! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        return expr;
    }
    
    if (context->selectorIdent()) {
        auto instance = handleSelectorIdent(context->selectorIdent(), RuleLanguage::Type::BOOLEAN);
        
        if (instance != nullptr) {
            RuleLanguage::booleanExpr* expr = new RuleLanguage::booleanExpr();
            expr->setInstance(instance);
            return expr;
        }

        ocall_print_string((string("Error: illegal selectorIdent! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    if (context->relationExpr()) {
        auto rExpr = handleRelationExpr(context->relationExpr());
        if (rExpr == nullptr) {
            return nullptr;
        }
        RuleLanguage::booleanExpr* expr = new RuleLanguage::booleanExpr();
        expr->setExpr(rExpr);
        return expr;
    }

    // TODO
    // if (context->listExpr())

    ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
    return nullptr;

}

RuleLanguage::logicalExpr* SymbolCollector::handleLogicalExpr(RuleParser::LogicalExprContext *context) {
    if (context == nullptr) {
        ocall_print_string((string("Error: Parser Error! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    if (context->booleanExpr()) {
        RuleLanguage::logicalExpr *expr = new RuleLanguage::logicalExpr();
        expr->setOperator(RuleLanguage::LogicalOperator::LOGICAL_NON);
        expr->setBooleanExpr(handleBooleanExpr(context->booleanExpr()));
        return expr;
    }
    
    if (context->LOGICAL_NOT()) {
        RuleLanguage::logicalExpr *expr = new RuleLanguage::logicalExpr();
        expr->setOperator(RuleLanguage::LogicalOperator::NOT);
        auto rExpr = handleLogicalExpr(context->logicalExpr(0));
        if (rExpr == nullptr) {
            ocall_print_string((string("Error: illegal input! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        expr->setRightExpr(rExpr);
        return expr;
    } else if (context->LOGICAL_AND() || context->LOGICAL_OR()) {
        RuleLanguage::logicalExpr *expr = new RuleLanguage::logicalExpr();
        auto op = context->LOGICAL_AND() != nullptr ?  RuleLanguage::LogicalOperator::AND : RuleLanguage::LogicalOperator::OR;
        expr->setOperator(op);
        if (context->logicalExpr().size() == 2) {
            expr->setLeftExpr(handleLogicalExpr(context->logicalExpr(0)));
            expr->setRightExpr(handleLogicalExpr(context->logicalExpr(1)));
            return expr;
        } else {
            delete(expr);
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }

    } else {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

}

RuleLanguage::ArithmeticOperator SymbolCollector::getOperator(RuleParser::NumberExprContext* context) {
    if (context->MULTIPLY() != nullptr) {
        return RuleLanguage::ArithmeticOperator::MULTIPLY;
    }

    if (context->MODULO() != nullptr) {
        return RuleLanguage::ArithmeticOperator::MODULO;
    }

    if (context->DIVIDE() != nullptr) {
        return RuleLanguage::ArithmeticOperator::DIVIDE;
    }

    if (context->PLUS() != nullptr) {
        return RuleLanguage::ArithmeticOperator::PLUS;
    }

    if (context->MINUS() != nullptr) {
        return RuleLanguage::ArithmeticOperator::MINUS;
    }
    return RuleLanguage::ArithmeticOperator::ARITH_NON;
}

RuleLanguage::numberExpr* SymbolCollector::handleNumberExpr(RuleParser::NumberExprContext *context) {
    ocall_print_string((string("enter handleNumberExpr ") + context->getText()).c_str(), __FILE__, __LINE__);
    auto number_exprs = context->numberExpr();
    if (number_exprs.size() == 1) {
        auto expr = handleNumberExpr(number_exprs[0]);
        if (context->MINUS()) {
            expr->setNegative();
        }
        return expr;
    }

    if (number_exprs.size() == 2) {
        auto op = getOperator(context);

        if (op == RuleLanguage::ArithmeticOperator::ARITH_NON) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }

        auto left_expr = handleNumberExpr(number_exprs[0]);
        auto right_expr = handleNumberExpr(number_exprs[1]);

        if (left_expr == nullptr || right_expr == nullptr) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        auto expr = new RuleLanguage::numberExpr();
        expr->setLeftExpr(left_expr);
        expr->setRightExpr(right_expr);
        expr->setOperator(op);
        return expr;
    }

    if (context->selectorIdent()) {
        auto instance = handleSelectorIdent(context->selectorIdent(), RuleLanguage::Type::NUMBER);
        if (instance != nullptr) {
            auto expr = new RuleLanguage::numberExpr();
            expr->setInstance(instance);
            return expr;
        }
        ocall_print_string((string("Error: instance == nullptr ")).c_str(), __FILE__, __LINE__);

    }

    if (context->DECIMAL_LIT()) {
        string decimal_string = context->DECIMAL_LIT()->getText();
        std::remove(decimal_string.begin(), decimal_string.end(), ',');

        int64_t decimal_value = stoll(decimal_string);
        if (decimal_value < 0) {
            ocall_print_string((string("Error: illegal syntax! Exceed int64 type")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        auto expr = new RuleLanguage::numberExpr();
        expr->setValue(decimal_value);
        return expr;
    }

    if (context->DECIMAL_FLOAT_LIT()) {
        ocall_print_string((string("Error: illegal syntax! Float not support!")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
    return nullptr;

}

bool SymbolCollector::getQueryOperator(RuleParser::QueryExprContext *context, RuleLanguage::queryExpr *expr) {
    auto sellect_value = context->SELECT() != nullptr ? true : false;
    auto collect_value = context->COLLECT() != nullptr ? true : false;

    // query Expr must has one of sellect and collect
    if (!sellect_value && !collect_value) {
        ocall_print_string((string("Error: illegal syntax! query expr should be sellect or collect")).c_str(), __FILE__, __LINE__);
        return false;
    }

    expr->setSelect(sellect_value);
    expr->setCollect(collect_value);
    return true;
}

shared_ptr<Instance> SymbolCollector::getCurrRuleInstance(string name, RuleLanguage::Type type ) {
    
    ocall_print_string((string("get instance ") + name + " from " + curr_rule_name_).c_str(), __FILE__, __LINE__);

    auto& instance_list = rule_instance_map_[curr_rule_name_];
    
    if (instance_list.find(name) == instance_list.end()) {
        ocall_print_string((string("Error: instance not in list! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }
    auto instance = instance_list[name];
    if (instance->type() != type) {
        ocall_print_string((string("Error: instance type not match! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }
    return instance;
}

shared_ptr<Instance> SymbolCollector::getInstance(string name, RuleLanguage::Type type ) {
    if (global_instance_map_.find(name) == global_instance_map_.end()) {
        return nullptr;
    }
    auto instance = global_instance_map_[name];
    if (instance->type() != type) {
        return nullptr;
    }
    return instance;
}

shared_ptr<Entity> SymbolCollector::getEntity(string name) {
    if (entity_map_.find(name) == entity_map_.end()) {
        return nullptr;
    }

    auto entity = entity_map_[name];
    if (entity->isUnique()) {
        return nullptr;
    }

    return entity;
}

RuleLanguage::Type SymbolCollector::getAttributeTypeFromDef(RuleParser::TypeAnnoContext* context) {
    
    // TODO: Instance should record entity 
    if (context->compositeType()) {
        return RuleLanguage::Type::INSTANCE;
    }

    if (context->basicType()->NUMBER()) {
        return RuleLanguage::Type::NUMBER;
    }

    if (context->basicType()->BOOLEAN()) {
        return RuleLanguage::Type::BOOLEAN;
    }

    if (context->basicType()->DATE()) {
        return RuleLanguage::Type::DATE;
    }

    if (context->basicType()->STRING()) {
        return RuleLanguage::Type::STRING;
    }
}

RuleLanguage::LogicalOperator SymbolCollector::getLogicalOperator(RuleParser::LogicalOperatorContext *context) {
    if (context->LOGICAL_AND()) {
        return RuleLanguage::LogicalOperator::AND;
    }

    if (context->LOGICAL_OR()) {
        return RuleLanguage::LogicalOperator::OR;
    }

    return RuleLanguage::LogicalOperator::LOGICAL_NON;
}

RuleLanguage::conditionExpr* SymbolCollector::handleConditionExpr(RuleParser::ConditionExprContext *context) {
    auto basic_cond_exprs = context->basicCondExpr();
    if (basic_cond_exprs.empty()) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    auto expr = new RuleLanguage::conditionExpr();
    auto first_expr = handleBasicCondExpr(basic_cond_exprs[0]);
    if (first_expr == nullptr) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }
    expr->setBasicExpr(first_expr);

    auto operators = context->logicalOperator();
    for (int i = 1; i < basic_cond_exprs.size(); i++) {
        auto bc_expr = handleBasicCondExpr(basic_cond_exprs[i]);
        auto op = getLogicalOperator(operators[i - 1]);
        bc_expr->setOperator(op);
        expr->addExpr(bc_expr);
    }

    return expr;
}



RuleLanguage::queryExpr* SymbolCollector::handleQueryExpr(RuleParser::QueryExprContext *context) {
    RuleLanguage::queryExpr *expr = new RuleLanguage::queryExpr();
    if (!getQueryOperator(context, expr)) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        delete(expr);
        return nullptr;
    }

    auto entity_name = context->entityName()->getText();
    auto entity = getEntity(entity_name);
    auto instance = getInstance(entity_name, RuleLanguage::Type::INSTANCELIST);

    if (entity == nullptr && instance == nullptr) {
        ocall_print_string((string("Error: undefined entity or type miss match! ")).c_str(), __FILE__, __LINE__);
        delete(expr);
        return nullptr;
    }

    expr->setEntity(entity);
    expr->setInstance(instance);


    auto condExpr = handleConditionExpr(context->conditionExpr());
    if (condExpr == nullptr && context->WHERE() == nullptr) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    expr->setExpr(condExpr);
    return expr;
}

RuleLanguage::basicCondExpr* SymbolCollector::handleBasicCondExpr(RuleParser::BasicCondExprContext *context) {
    if (context->relationExpr()) {
        auto expr = new RuleLanguage::basicCondExpr();
        expr->setRelationExpr(handleRelationExpr(context->relationExpr()));
        expr->setOperator(RuleLanguage::LogicalOperator::LOGICAL_NON);
        return expr;
    }

    if (context->listExpr()) {
        auto expr = new RuleLanguage::basicCondExpr();
        expr->setListExpr(handleListExpr(context->listExpr()));
        expr->setOperator(RuleLanguage::LogicalOperator::LOGICAL_NON);
        return expr;
    }

    return nullptr;
}

RuleLanguage::RelationOperator SymbolCollector::getRelationOperator(RuleParser::RelationOperatorContext *context) {
    if (context->EQUALS()) {
        return RuleLanguage::RelationOperator::EQUALS;
    }

    if (context->NOT_EQUALS()) {
        return RuleLanguage::RelationOperator::NOT_EQUALS;
    }

    if (context->LESS_THAN()) {
        return RuleLanguage::RelationOperator::LESS_THAN;
    }

    if (context->LESS_OR_EQUALS()) {
        return RuleLanguage::RelationOperator::LESS_OR_EQUALS;
    }

    if (context->GREATER_OR_EQUALS()) {
        return RuleLanguage::RelationOperator::GREATER_OR_EQUALS;
    }

    if (context->GREATER_THAN()) {
        return RuleLanguage::RelationOperator::GREATER;
    }

    return RuleLanguage::RelationOperator::RELATION_NON;
}

RuleLanguage::relationExpr* SymbolCollector::handleRelationExpr(RuleParser::RelationExprContext *context) {
    if (context->relationExpr()) {
        return handleRelationExpr(context->relationExpr());
    }
    auto numbers = context->numberExpr();
    auto operators = context->relationOperator();

    if (numbers.size() < 2) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    auto expr = new RuleLanguage::relationExpr();
    auto first_number_expr = handleNumberExpr(numbers[0]);
    expr->setFirstExpr(first_number_expr);

    for (int i = 1; i < numbers.size(); i++) {
        expr->addNumberExpr(handleNumberExpr(numbers[i]));
        expr->addOperator(getRelationOperator(operators[i - 1]));
    }

    return expr;
    
}

RuleLanguage::listExpr* SymbolCollector::handleListExpr(RuleParser::ListExprContext *context) {
    ocall_print_string((string("Error: list Expr is not support yet! ")).c_str(), __FILE__, __LINE__);
    return nullptr;
}



antlrcpp::Any SymbolCollector::visitDefinitionStmt(RuleParser::DefinitionStmtContext *context)
{
    ocall_print_string((string(" enter visitDefinitionStmt ")).c_str(), __FILE__, __LINE__);
    string instance_name = context->instanceName()->getText();
    ocall_print_string((string(" instance name : ") + instance_name).c_str(), __FILE__, __LINE__);

    auto exprCtx = context->expr();
    if (exprCtx->logicalExpr()) {
        ocall_print_string((string(" handle logical expr : ")).c_str(), __FILE__, __LINE__);
        auto logical_expr = handleLogicalExpr(exprCtx->logicalExpr());
        KeepTrackOfNewInstance(instance_name, logical_expr);
    } else if (exprCtx->numberExpr()) {
        ocall_print_string((string(" handle number expr : ")).c_str(), __FILE__, __LINE__);

        auto number_expr = handleNumberExpr(exprCtx->numberExpr());
        KeepTrackOfNewInstance(instance_name, number_expr);
    } else if (exprCtx->queryExpr()) {
        ocall_print_string((string(" handle query expr : ")).c_str(), __FILE__, __LINE__);
        auto query_expr = handleQueryExpr(exprCtx->queryExpr());
        KeepTrackOfNewInstance(instance_name, query_expr);
    }

    RuleLanguage::definitionExpr* expr = new RuleLanguage::definitionExpr();
    expr->instance = rule_instance_map_[curr_rule_name_][instance_name];
    unique_ptr<RuleLanguage::Expr> expr_ptr(expr);
    rule_stmt_map_[curr_rule_name_].push_back(std::move(expr_ptr));

    return nullptr;
}


antlrcpp::Any SymbolCollector::visitLogicalExpr(RuleParser::LogicalExprContext *context)
{
    ocall_print_string((string(" enter visitLogicalExpr ")).c_str(), __FILE__, __LINE__);
    auto expr = handleLogicalExpr(context);
    unique_ptr<RuleLanguage::Expr> expr_ptr(expr);
    rule_stmt_map_[curr_rule_name_].push_back(std::move(expr_ptr));
    // return RuleParserBaseVisitor::visitLogicalExpr(context);
    return nullptr;
}

antlrcpp::Any SymbolCollector::visitRelationExpr(RuleParser::RelationExprContext *context)
{
    ocall_print_string((string(" enter visitRelationExpr ")).c_str(), __FILE__, __LINE__);
    auto expr = handleRelationExpr(context);
    unique_ptr<RuleLanguage::Expr> expr_ptr(expr);
    rule_stmt_map_[curr_rule_name_].push_back(std::move(expr_ptr));
    // return RuleParserBaseVisitor::visitRelationExpr(context);
    return nullptr;
}

/* Data Member Getters */
const vector<Entity> SymbolCollector::get_entity_list() const
{
    vector<Entity> entity_list;
    for (const auto &entity_pair : this->entity_map_)
    {
        entity_list.push_back(*(entity_pair.second));
    }

    return entity_list;
}

ExecuteRule* SymbolCollector::handleExecuteRuleDef(RuleParser::ExecuteRuleDefContext* context) {
    auto rule = new ExecuteRule();
    rule->rule_name = context->ruleName()->getText();

    if (context->executionTrueStmt()) {
        auto tbranch = handleExecutionTrueStmt(context->executionTrueStmt());
        if (tbranch == nullptr) {
            return nullptr;
        }
        rule->true_branch = tbranch;
    }
    
    if (context->executionFalseStmt()) {
        auto fbranch = handleExecutionFalseStmt(context->executionFalseStmt());
        if (fbranch == nullptr) {
            return nullptr;
        }
        rule->false_branch = fbranch;
    }

    return rule;
}

ExecuteRule* SymbolCollector::handleExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext* context) {
    if (context->ruleName()) {
        auto rule = new ExecuteRule();
        rule->rule_name = context->ruleName()->getText();
        return rule;
    }

    // if (context->executeRuleDef()) {
    //     return handleExecuteRuleDef(context->executeRuleDef());
    // }

    return nullptr;
}

ExecuteRule* SymbolCollector::handleExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext* context) {
    if (context->ruleName()) {
        auto rule = new ExecuteRule();
        rule->rule_name = context->ruleName()->getText();
        return rule;
    }

    // if (context->executeRuleDef()) {
    //     return handleExecuteRuleDef(context->executeRuleDef());
    // }

    return nullptr;
}

bool SymbolCollector::generateExecuteTree(RuleParser::ExecuteRuleDefContext* context) {
    
    if (context->executionTrueStmt()) {
        auto true_rule = handleExecutionTrueStmt(context->executionTrueStmt());
        if (true_rule == nullptr) {
            return false;
        }
        execute_root->true_branch = true_rule;
    }
    
    if (context->executionFalseStmt()) {
        auto false_rule = handleExecutionFalseStmt(context->executionFalseStmt());
        if (false_rule == nullptr) {
            return false;
        }
        execute_root->false_branch = false_rule;
    }

    return true;
}

antlrcpp::Any SymbolCollector::visitExecutionBlock(RuleParser::ExecutionBlockContext *context) {
    ocall_print_string((string("visitExecutionBlock start")).c_str(), __FILE__, __LINE__);

    ocall_print_string(context->getText().c_str(), __FILE__, __LINE__);
    ocall_print_string(context->EXECUTE()->getText().c_str(), __FILE__, __LINE__);


    // if (context->executionStmt()) {
    //     ocall_print_string(context->executionStmt()->getText().c_str(), __FILE__, __LINE__);
    // }

    ocall_print_string((string("visitExecutionBlock end")).c_str(), __FILE__, __LINE__);

    return RuleParserBaseVisitor::visitExecutionBlock(context);

}

antlrcpp::Any SymbolCollector::visitExecutionStmt(RuleParser::ExecutionStmtContext *context) {

    ocall_print_string((string("visitExecutionStmt start")).c_str(), __FILE__, __LINE__);

    auto ruleDef = context->executeRuleDef();

    execute_root.reset(new ExecuteRule());
    execute_root->rule_name = ruleDef->ruleName()->getText();
    generateExecuteTree(ruleDef);

    ocall_print_string((string("visitExecutionStmt end")).c_str(), __FILE__, __LINE__);
    ocall_print_string(execute_root->dump().c_str(), __FILE__, __LINE__);


    return RuleParserBaseVisitor::visitExecutionStmt(context);
}

antlrcpp::Any SymbolCollector::visitInputBlock(RuleParser::InputBlockContext *context) {
    auto attributes = context->attributeList()->attributeDecl();
    if (attributes.size() == 0) {
        return nullptr;
    }

    input_instance_.reset(new Instance("inputdata"));

    for (auto attribute : attributes) {
        auto attribute_name = attribute->attributeName()->getText();
        auto attribute_type = getAttributeTypeFromDef(attribute->typeAnno());
        auto attribute_raw_ptr = createAttribute(attribute_name, attribute_type);
        shared_ptr<Attribute>attribute_ptr(attribute_raw_ptr);
        input_instance_->addAttribute(attribute_name, attribute_ptr);
        input_instance_->setInstanceKind(InstanceKind::UNIQUE_ENTITY);
    }

    global_instance_map_["inputdata"] = input_instance_;

    return RuleParserBaseVisitor::visitInputBlock(context);
}

ObjectAttribute* SymbolCollector::handleOutputObject(RuleParser::OutputObjectContext* context) {
    auto object_name = context->objectName()->getText();
    auto decls = context->outputDecl();
    auto instance_value = new Instance(object_name);

    for (auto decl : decls) {
        shared_ptr<Attribute> decl_attribute(handleOutputDecl(decl));
        if (decl_attribute == nullptr) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        instance_value->addAttribute(decl_attribute->getName(), decl_attribute);
    }

    auto object = new ObjectAttribute(object_name, RuleLanguage::Type::INSTANCE, instance_value);
    return object;
}

Attribute* SymbolCollector::handleOutputDecl(RuleParser::OutputDeclContext* context) {
    
    if (context->outputAttribute()) {
        auto attribute = context->outputAttribute();
        auto attribute_name = attribute->attributeName()->getText();
        auto attribute_type = getAttributeTypeFromDef(attribute->typeAnno());
        return createAttribute(attribute_name, attribute_type);
    }

    if (context->outputObject()) {
        return handleOutputObject(context->outputObject());
    }
}

antlrcpp::Any SymbolCollector::visitOutputBlock(RuleParser::OutputBlockContext *context) {
    auto output_decls = context->outputDecl();
    output_instance_.reset(new Instance("outputdata"));

    for (auto output_decl : output_decls) {
        auto attribute = handleOutputDecl(output_decl);
        if (attribute == nullptr) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        shared_ptr<Attribute> attribute_ptr(attribute);
        output_instance_->addAttribute(attribute->getName(), attribute_ptr);
        output_instance_->setInstanceKind(InstanceKind::UNIQUE_ENTITY);
    }

    global_instance_map_["outputdata"] = output_instance_;

    return RuleParserBaseVisitor::visitOutputBlock(context);
}

void SymbolCollector::dump() {
    // dump entities
    ocall_print_string((string("dump symbol collector \n")).c_str(), __FILE__, __LINE__);
    for (auto entity : entity_map_) {
        ocall_print_string((string("dump entity block \n")).c_str(), __FILE__, __LINE__);
        ocall_print_string((entity.second->dump()).c_str(), __FILE__, __LINE__);
    }

    ocall_print_string((string("dump input block \n")).c_str(), __FILE__, __LINE__);
    ocall_print_string((input_instance_->dump()).c_str(), __FILE__, __LINE__);

    ocall_print_string((string("dump output block \n")).c_str(), __FILE__, __LINE__);
    ocall_print_string((output_instance_->dump()).c_str(), __FILE__, __LINE__);

    ocall_print_string((string("dump rule block \n")).c_str(), __FILE__, __LINE__);
    for (auto rule_instance_pair : rule_instance_map_) {
        auto rule_name = rule_instance_pair.first;
        ocall_print_string((string("dump rule ") + rule_name + string(": \n")).c_str(), __FILE__, __LINE__);
        for (auto instance : rule_instance_pair.second) {
            ocall_print_string((string("dump instance: ") + instance.first ).c_str(), __FILE__, __LINE__);
            ocall_print_string(instance.second->dump().c_str(), __FILE__, __LINE__);
        }

        for (int i = 0; i < rule_stmt_map_[rule_name].size(); i++) {
            ocall_print_string((string("dump expr")).c_str(), __FILE__, __LINE__);
            ocall_print_string(RuleLanguage::TypeToString(rule_stmt_map_[rule_name][i]->type()).c_str(), __FILE__, __LINE__);
            ocall_print_string(rule_stmt_map_[rule_name][i]->dump().c_str(), __FILE__, __LINE__);
        }
    }

    ocall_print_string((string("dump execution block:")).c_str(), __FILE__, __LINE__);
    ocall_print_string(execute_root->dump().c_str(), __FILE__, __LINE__);

}

std::unique_ptr<ExecuteRule> SymbolCollector::getExecuteRoot() {
    return std::move(execute_root);
}

InstanceMap& SymbolCollector::getGlobalInstanceMap() {
    return global_instance_map_;
}

std::map<std::string, std::shared_ptr<Entity>>& SymbolCollector::getEntityMap() {
    return entity_map_;
}
std::map<std::string, InstanceMap>& SymbolCollector::getRuleInstanceMap() {
    return rule_instance_map_;
}
std::map<std::string, RuleStmts>& SymbolCollector::getRuleStmtMap() {
    return rule_stmt_map_;
}
std::shared_ptr<Instance> SymbolCollector::getInputInstance() {
    return input_instance_;
}
std::shared_ptr<Instance> SymbolCollector::getOutputInstance() {
    return output_instance_;
}

std::map<std::string, InstanceOrder>& SymbolCollector::getRuleInstanceOrder() {
    return rule_instance_order_;
}

std::string SymbolCollector::getEntitiesSpace() {
    return entities_spaec_name;
}

