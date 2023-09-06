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

    case RuleLanguage::Type::INSTANCELIST:
        ans = new ListAttribute(name, type);
    
    default:
        break;
    }

    return ans;
}


RuleLanguage::Type SymbolCollector::getTypeFromString(std::string type_string) {
    ocall_print_string("Debug: enter getTypeFromString ", __FILE__, __LINE__);
    if (type_string.compare("number") == 0) {
        return RuleLanguage::Type::NUMBER;
    }

    if (type_string.compare("boolean") == 0) {
        return RuleLanguage::Type::BOOLEAN;
    }

    if (type_string.compare("string") == 0) {
        return RuleLanguage::Type::STRING;
    }

    return RuleLanguage::Type::INSTANCE;
}


void SymbolCollector::KeepTrackOfNewEntity(const string &entity_name, RuleParser::AttributeDeclContext* attribute_context)
{

    string attribute_name = attribute_context->attributeName()->getText();
    auto attribute_type = getAttributeTypeFromDef(attribute_context->typeAnno());

    ocall_print_string((string("KeepTrackOfNewEntity: ") +
                        entity_name + string("[") +
                        attribute_name + string("]")).c_str(), __FILE__, __LINE__);

    Attribute* attribute = createAttribute(attribute_name, attribute_type);

    if (attribute == nullptr) {
        ocall_print_string((string("Error: attribute type not support! ")).c_str(), __FILE__, __LINE__);
        return;
    }
    
    if (attribute_type == RuleLanguage::Type::INSTANCELIST) {
        ocall_print_string((string("Debug: add inter type into list attribute ")).c_str(), __FILE__, __LINE__);
        auto* context = attribute_context->typeAnno()->compositeType();
        ocall_print_string((attribute_context->getText()).c_str(), __FILE__, __LINE__);

        ListAttribute* list_attr = dynamic_cast<ListAttribute*>(attribute);
        if (list_attr == nullptr) {
             ocall_print_string((string("Error: list_sttr is nullptr ")).c_str(), __FILE__, __LINE__);
        }
        list_attr->setInterType(getAttributeTypeFromDef(context->listType()->basicType()));
    }

    ocall_print_string((string("Debug: add attribute ")).c_str(), __FILE__, __LINE__);
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

            instance->setType(query_expr->expr_type);
            instance->list_type = query_expr->list_type;
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
        // string attribute_name = attribute->attributeName()->getText();
        // auto attribute_type = getAttributeTypeFromDef(attribute->typeAnno());
        KeepTrackOfNewEntity(entity_name, attribute);
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

shared_ptr<Attribute> SymbolCollector::getNewAttribute(shared_ptr<Attribute>& attribute) {
    if (attribute->getType() == RuleLanguage::Type::INSTANCELIST) {
        ListAttribute* list_attr = dynamic_cast<ListAttribute*>(attribute.get());
        ListAttribute* new_attr = new ListAttribute(attribute->name, attribute->type);
        new_attr->setInterType(list_attr->getInterType());
        shared_ptr<Attribute> result(new_attr);
        return result;
    }

    if (attribute->getType() == RuleLanguage::Type::NUMBER) {
        NumberAttribute* new_attr = new NumberAttribute(attribute->name, attribute->type);
        shared_ptr<Attribute> result(new_attr);
        return result;
    }

    if (attribute->getType() == RuleLanguage::Type::STRING) {
        StringAttribute* new_attr = new StringAttribute(attribute->name, attribute->type);
        shared_ptr<Attribute> result(new_attr);
        return result;
    }

    if (attribute->getType() == RuleLanguage::Type::BOOLEAN) {
        BooleanAttribute* new_attr = new BooleanAttribute(attribute->name, attribute->type);
        shared_ptr<Attribute> result(new_attr);
        return result;
    }
    return nullptr;
}

shared_ptr<Instance> SymbolCollector::handleSelectorIdent(RuleParser::SelectorIdentContext *context, RuleLanguage::Type type) {

    string instance_name = context->entityName()->getText();
    string attribute_name = context->attributeName()->getText();
    ocall_print_string((string("handleSelectorIdent: ") + instance_name + "." + attribute_name + " with type " + RuleLanguage::TypeToString(type)).c_str(), __FILE__, __LINE__);

    // return a symbol type instance, which not in instance map
    if (entity_map_.find(instance_name) != entity_map_.end() && entity_map_[instance_name]->hasAttribute(attribute_name, type)) {
        ocall_print_string((string("find selectorident in Entities ")).c_str(), __FILE__, __LINE__);
        shared_ptr<Instance> instance_temp(new Instance(instance_name));
        shared_ptr<Attribute> defined_attribute = entity_map_[instance_name]->getAttribute(attribute_name, type);
        instance_temp->addAttribute(attribute_name, defined_attribute);
        instance_temp->setInstanceKind(InstanceKind::SYMBOL);
        return instance_temp;
    }

    shared_ptr<Attribute> defined_attribute;

    if (instance_name.compare("inputdata") == 0 && input_instance_->hasAttribute(attribute_name, type)) {
         ocall_print_string((string("find selectorident in inpudata ")).c_str(), __FILE__, __LINE__);
        defined_attribute = input_instance_->getAttribute(attribute_name, type);
        
    }

    if (instance_name.compare("outputdata") == 0 && output_instance_->hasAttribute(attribute_name, type)) {
         ocall_print_string((string("find selectorident in output data ")).c_str(), __FILE__, __LINE__);
        defined_attribute = output_instance_->getAttribute(attribute_name, type);
    }

    if (global_instance_map_.find(instance_name) != global_instance_map_.end() && global_instance_map_[instance_name]->hasAttribute(attribute_name, type)) {
        ocall_print_string((string("find selectorident in global instances ")).c_str(), __FILE__, __LINE__);
        defined_attribute = global_instance_map_[instance_name]->getAttribute(attribute_name, type);
    }

    auto& rule_instances = rule_instance_map_[curr_rule_name_];
    if (rule_instances.find(instance_name) != rule_instances.end() ) {
        ocall_print_string((string("Debug: instance name found in ") + curr_rule_name_).c_str(), __FILE__, __LINE__);
        if (rule_instances[instance_name]->hasAttribute(attribute_name, type)) {
            ocall_print_string((string("Debug: instance attribute type match ") + RuleLanguage::TypeToString(type)).c_str(), __FILE__, __LINE__);
            defined_attribute = rule_instances[instance_name]->getAttribute(attribute_name, type);
        }
    }

    if (defined_attribute != nullptr) {
        shared_ptr<Instance> instance(new Instance(instance_name));
        instance->setType(defined_attribute->getType());
        instance->setInstanceKind(InstanceKind::SPECIFIC_ATTRIBUTE);
        instance->addAttribute(attribute_name, defined_attribute);
        return instance;
    }

    ocall_print_string((string("Error: undefined instance! ")).c_str(), __FILE__, __LINE__);
    return nullptr;
}

shared_ptr<Instance> SymbolCollector::handleSelectorIdent(RuleParser::SelectorIdentContext *context) {

    string instance_name = context->entityName()->getText();
    string attribute_name = context->attributeName()->getText();
    ocall_print_string((string("handleSelectorIdent: ") + instance_name + "." + attribute_name).c_str(), __FILE__, __LINE__);

    shared_ptr<Attribute> defined_attribute;
    // return a symbol type instance, which not in instance map
    if (entity_map_.find(instance_name) != entity_map_.end()) {
        ocall_print_string((string("find selectorident in Entities ")).c_str(), __FILE__, __LINE__);
        shared_ptr<Instance> instance_temp(new Instance(instance_name));
        defined_attribute = entity_map_[instance_name]->getAttribute(attribute_name);
        instance_temp->addAttribute(attribute_name, getNewAttribute(defined_attribute));
        instance_temp->setInstanceKind(InstanceKind::SYMBOL);
        return instance_temp;
    }

    

    if (instance_name.compare("inputdata") == 0 ) {
        ocall_print_string((string("find selectorident in inpudata ")).c_str(), __FILE__, __LINE__);
        defined_attribute = input_instance_->getAttribute(attribute_name);
    }

    if (instance_name.compare("outputdata") == 0) {
        ocall_print_string((string("find selectorident in output data ")).c_str(), __FILE__, __LINE__);
        defined_attribute = output_instance_->getAttribute(attribute_name);
    }

    if (global_instance_map_.find(instance_name) != global_instance_map_.end()) {
        ocall_print_string((string("find selectorident in global instances ")).c_str(), __FILE__, __LINE__);
        defined_attribute = global_instance_map_[instance_name]->getAttribute(attribute_name);
    }

    auto& rule_instances = rule_instance_map_[curr_rule_name_];
    if (rule_instances.find(instance_name) != rule_instances.end() ) {
        ocall_print_string((string("Debug: instance name found in ") + curr_rule_name_).c_str(), __FILE__, __LINE__);
        defined_attribute = rule_instances[instance_name]->getAttribute(attribute_name);
    }

    if (defined_attribute != nullptr) {
        shared_ptr<Instance> instance(new Instance(instance_name));
        instance->setType(defined_attribute->getType());
        instance->setInstanceKind(InstanceKind::SPECIFIC_ATTRIBUTE);
        instance->addAttribute(attribute_name, getNewAttribute(defined_attribute));
        return instance;
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

shared_ptr<Instance> SymbolCollector::getInstance(string name) {
    if (name.compare("inputdata") == 0) {
        return input_instance_;
    }

    if (name.compare("outputdata") == 0) {
        return output_instance_;
    }
    
    if (global_instance_map_.find(name) != global_instance_map_.end()) {
        return global_instance_map_[name];
    }

    auto& rule_instances = rule_instance_map_[curr_rule_name_];
    if (rule_instances.find(name) != rule_instances.end()) {
        return rule_instances[name];
    }    
    return nullptr;
}

shared_ptr<Instance> SymbolCollector::getInstance(string name, RuleLanguage::Type type ) {
    if (name.compare("inputdata") == 0) {
        return input_instance_;
    }
    
    if (global_instance_map_.find(name) != global_instance_map_.end()) {
        auto instance = global_instance_map_[name];
        if (instance->type() == type) {
            return instance;
        }
    }

    auto& rule_instances = rule_instance_map_[curr_rule_name_];
    if (rule_instances.find(name) != rule_instances.end()) {
        auto instance = rule_instances[name];
        if (instance->type() == type) {
            return instance;
        }
    }    
    return nullptr;
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
        return RuleLanguage::Type::INSTANCELIST;
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


RuleLanguage::Type SymbolCollector::getAttributeTypeFromDef(RuleParser::BasicTypeContext* context) {

    if (context->NUMBER()) {
        return RuleLanguage::Type::NUMBER;
    }

    if (context->BOOLEAN()) {
        return RuleLanguage::Type::BOOLEAN;
    }

    if (context->DATE()) {
        return RuleLanguage::Type::DATE;
    }

    if (context->STRING()) {
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
    ocall_print_string("Debug: handleConditionExpr", __FILE__, __LINE__);
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

    shared_ptr<Entity> entity;
    shared_ptr<Instance> instance;

    if (context->entityName()) {
        ocall_print_string("Debug: try to get entity or instance", __FILE__, __LINE__);
        auto entity_name = context->entityName()->getText();
        entity = getEntity(entity_name);
        instance = getInstance(entity_name);
    }

    if (context->selectorIdent()) {
        // auto entity_name = context->selectorIdent()->entityName()->getText();
        // std::string attribute_name = context->selectorIdent()->attributeName()->getText();
        // ocall_print_string(("Debug: try to get entity or instance " + entity_name + " with specific attribute " + attribute_name).c_str(), __FILE__, __LINE__);
        // entity = getEntity(entity_name);
        // instance = getInstance(entity_name);
        instance = handleSelectorIdent(context->selectorIdent());
        std::string attribute_name = context->selectorIdent()->attributeName()->getText();
        expr->setAttributeName(attribute_name);
        ocall_print_string(("Debug: try to get entity or instance  with specific attribute " + attribute_name).c_str(), __FILE__, __LINE__);
    }
    

    if (entity == nullptr && instance == nullptr) {
        ocall_print_string((string("Error: undefined entity or type miss match! ")).c_str(), __FILE__, __LINE__);
        delete(expr);
        return nullptr;
    }
    expr->setEntity(entity);
    expr->setInstance(instance);
    expr->updateExprType();

    auto condExpr = handleConditionExpr(context->conditionExpr());
    if (condExpr == nullptr && context->WHERE() == nullptr) {
        ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
        return nullptr;
    }

    expr->setExpr(condExpr);
    return expr;
}

RuleLanguage::basicCondExpr* SymbolCollector::handleBasicCondExpr(RuleParser::BasicCondExprContext *context) {
    ocall_print_string("Debug: enter handleBasicCondExpr", __FILE__, __LINE__);

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

RuleLanguage::RelationOperator SymbolCollector::getCompareOperator(RuleParser::CompareOperatorContext *context) {
    
    if (context->EQUALS()) {
        return RuleLanguage::RelationOperator::EQUALS;
    }

    if (context->NOT_EQUALS()) {
        return RuleLanguage::RelationOperator::NOT_EQUALS;
    }

    return RuleLanguage::RelationOperator::RELATION_NON;
}

RuleLanguage::stringExpr* SymbolCollector::handleStringExprFromNumberExpr(RuleParser::NumberExprContext *context) {
    ocall_print_string("Debug: enter handleStringExprFromNumberExpr", __FILE__, __LINE__);

    if (context->selectorIdent()) {
        auto instance = handleSelectorIdent(context->selectorIdent(), RuleLanguage::Type::STRING);
        if (instance == nullptr) {
            ocall_print_string("Error: undefined instance", __FILE__, __LINE__);
            return nullptr;
        }
        RuleLanguage::stringExpr* expr = new RuleLanguage::stringExpr();
        expr->setInstance(instance);
        return expr;
    }

    return nullptr;
}

RuleLanguage::stringExpr* SymbolCollector::handleStringExpr(RuleParser::StringExprContext *context) {
    ocall_print_string("Debug: enter handleStringExpr", __FILE__, __LINE__);

    if (context->instanceName()) {
        shared_ptr<Instance> instance = getInstance(context->instanceName()->getText(), RuleLanguage::Type::STRING);
        RuleLanguage::stringExpr* expr = new RuleLanguage::stringExpr();
        expr->setInstance(instance);
        return expr;
    }

    if (context->selectorIdent()) {
        string instance_name = context->selectorIdent()->entityName()->getText();
        string attribute_name = context->selectorIdent()->attributeName()->getText();
        auto defined_instance = getInstance(instance_name, RuleLanguage::INSTANCE);
        if (defined_instance == nullptr) {
            defined_instance = getInstance(instance_name, RuleLanguage::INSTANCELIST);
            if (defined_instance == nullptr) {
                ocall_print_string("Error: undefined instance", __FILE__, __LINE__);
                return nullptr;
            }
        }
        shared_ptr<Instance> instance(new Instance(instance_name));
        auto defined_attribute = defined_instance->getAttribute(attribute_name, RuleLanguage::Type::STRING);
        if (defined_attribute == nullptr) {
            ocall_print_string("Error: undefined attribute", __FILE__, __LINE__);
            return nullptr;
        }
        instance->addAttribute(attribute_name, defined_attribute);
        RuleLanguage::stringExpr* expr = new RuleLanguage::stringExpr();
        expr->setInstance(instance);
        return expr;
    }

    if (context->INTERPRETED_STRING_LIT()) {
        RuleLanguage::stringExpr* expr = new RuleLanguage::stringExpr();
        expr->setLiteralValue(context->INTERPRETED_STRING_LIT()->getText());
        return expr;
    }

    return nullptr;
}


RuleLanguage::relationExpr* SymbolCollector::handleRelationExpr(RuleParser::RelationExprContext *context) {
    ocall_print_string("Debug: enter handleRelationExpr", __FILE__, __LINE__);
    
    if (context->relationExpr()) {
        return handleRelationExpr(context->relationExpr());
    }

    if (!context->numberExpr().empty()) {
        auto numbers = context->numberExpr();
        auto operators = context->relationOperator();

        if (numbers.size() != 2) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }
        auto expr = new RuleLanguage::relationExpr();
        auto left_number_expr = handleNumberExpr(numbers[0]);
        expr->setLeftNumberExpr(left_number_expr);
        auto right_number_expr = handleNumberExpr(numbers[1]);
        expr->setRightNumberExpr(right_number_expr);
        expr->setOperator(getRelationOperator(operators));

        if (left_number_expr == nullptr && right_number_expr == nullptr) {
            ocall_print_string("Debug: handle string expr", __FILE__, __LINE__);
            auto left_string_expr = handleStringExprFromNumberExpr(numbers[0]);
            expr->setLeftStringExpr(left_string_expr);
            auto right_string_expr = handleStringExprFromNumberExpr(numbers[1]);
            expr->setRightStringExpr(right_string_expr);
            expr->setOperator(getRelationOperator(operators));
        }

        return expr;
    }

    if (!context->stringExpr().empty()) {
        auto strings = context->stringExpr();
        if (strings.size() < 2) {
            ocall_print_string((string("Error: illegal syntax! ")).c_str(), __FILE__, __LINE__);
            return nullptr;
        }

        auto expr = new RuleLanguage::relationExpr();
        RuleLanguage::stringExpr* left_string_expr = handleStringExpr(strings[0]);
        RuleLanguage::stringExpr* right_string_expr = handleStringExpr(strings[1]);
        expr->setLeftStringExpr(left_string_expr);
        expr->setRightStringExpr(right_string_expr);
        expr->setOperator(getCompareOperator(context->compareOperator()));
        return expr;
    }
    
    return nullptr;
}

RuleLanguage::listExpr* SymbolCollector::handleListExpr(RuleParser::ListExprContext *context) {
    ocall_print_string("Debug: enter handleListExpr ", __FILE__, __LINE__);

    auto left_context = context->listFirstExpr();
    auto right_context = context->listSecondExpr();

    RuleLanguage::listExpr* expr = new RuleLanguage::listExpr();

    if (left_context->instanceName()) {
        expr->left_instance = getInstance(left_context->instanceName()->getText());
    }

    if (left_context->selectorIdent()) {
        expr->left_instance = handleSelectorIdent(left_context->selectorIdent());
    }

    if (right_context->instanceName()) {
        expr->right_instance = getInstance(right_context->instanceName()->getText());
    }

    if (right_context->selectorIdent()) {
        expr->right_instance = handleSelectorIdent(right_context->selectorIdent());
    }

    if (context->SET_IN()) {
        expr->inside = true;
    } else if (context->SET_NOT_IN()) {
        expr->inside = false;
    }
    
    return expr->isLegal() ? expr : nullptr;
}



antlrcpp::Any SymbolCollector::visitDefinitionStmt(RuleParser::DefinitionStmtContext *context)
{
    ocall_print_string((string(" enter visitDefinitionStmt ")).c_str(), __FILE__, __LINE__);
    
    // handle outputdata.** = ***
    if (context->selectorIdent()) {
        ocall_print_string("Debug: handle assignment of output data", __FILE__, __LINE__);
        string attribute_name = context->selectorIdent()->attributeName()->getText();
        shared_ptr<Attribute> attribute = output_instance_->getAttribute(attribute_name);
        if (attribute == nullptr) {
            ocall_print_string("Error: undefined attribute", __FILE__, __LINE__);
            return nullptr;
        }
        if (context->assignElement()->instanceName()) {
            string instance_name = context->assignElement()->instanceName()->getText();
            shared_ptr<Instance> instance = getInstance(instance_name, attribute->getType());
            if (instance == nullptr) {
                ocall_print_string(("Error: undefined instance " + attribute_name).c_str(), __FILE__, __LINE__);

            }
            attribute->setInstance(instance);
        }

        if (context->assignElement()->selectorIdent()) {
            shared_ptr<Instance> instance = handleSelectorIdent(context->assignElement()->selectorIdent(), attribute->getType());
            if (instance == nullptr) {
                ocall_print_string(("Error: undefined instance or attribute " + context->assignElement()->selectorIdent()->getText()).c_str(), __FILE__, __LINE__);
            }
            attribute->setInstance(instance);
        }
        RuleLanguage::definitionExpr* expr = new RuleLanguage::definitionExpr();
        shared_ptr<Instance> output_specific_attr_instance(new Instance("outputdata"));
        output_specific_attr_instance->specific_attribute = attribute->getName();
        output_specific_attr_instance->setInstanceKind(InstanceKind::SPECIFIC_ATTRIBUTE);
        expr->instance = output_specific_attr_instance;
        unique_ptr<RuleLanguage::Expr> expr_ptr(expr);
        rule_stmt_map_[curr_rule_name_].push_back(std::move(expr_ptr));
        return nullptr;
    }


    if (context->instanceName()) {

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
    }

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

    // global_instance_map_["inputdata"] = input_instance_;

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
        auto attribute_context = context->outputAttribute();
        auto attribute_name = attribute_context->attributeName()->getText();
        auto attribute_type = getAttributeTypeFromDef(attribute_context->typeAnno());
        Attribute* attribute = createAttribute(attribute_name, attribute_type);
        if (attribute_type == RuleLanguage::Type::INSTANCELIST) {
            ListAttribute* list_attr = dynamic_cast<ListAttribute*>(attribute);
            auto list_context = attribute_context->typeAnno()->compositeType()->listType();
            list_attr->setInterType(getAttributeTypeFromDef(list_context->basicType()));
        }
        return attribute;
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

    // global_instance_map_["outputdata"] = output_instance_;

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

