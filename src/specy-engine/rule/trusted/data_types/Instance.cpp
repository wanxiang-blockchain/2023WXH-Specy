#include "Instance.h"
#include "Entity.h"
#include "RuleEnclave_t.h"

std::string ObjectAttribute::dump() {
    return instance_value->dump();
}

std::string Instance::dump() {    
    if (instance_kind == InstanceKind::EXPR) {
        return name + ": " + expr->dump();
    }
    if (instance_kind == InstanceKind::UNIQUE_ENTITY ) {
        std::string instance_str = name + "{  \n";
        for (auto attribute : attribute_list) {
            instance_str = instance_str + attribute.second->dump() + "\n";
        }
        instance_str += "}\n";
        return instance_str;
    }
    if (instance_kind == InstanceKind::SYMBOL) {
        return name;
    }

    if (instance_kind == InstanceKind::SPECIFIC_ATTRIBUTE) {
        std::string instance_str = name + ".";
        for (auto attribute : attribute_list) {
            instance_str = instance_str + attribute.second->dump();
        }
        return instance_str;
    }

    return "error!";
}

std::string Instance::dumpAttributeValue() {
    std::string instance_str = name + ":\n";
    for (auto attribute : attribute_list) {
        instance_str = instance_str + attribute.first + " : " + attribute.second->dumpValue();
    }
    return instance_str;
}

bool Instance::updateValue(json11::Json& instance_json) {
    bool update_succ = true;
    std::string schema_name;

    if (instance_kind == InstanceKind::UNIQUE_ENTITY) {
        schema_name = name + "s";
    }

    if (instance_kind == InstanceKind::EXPR) {
        RuleLanguage::queryExpr* expr = dynamic_cast<RuleLanguage::queryExpr*>(getExpr());
        schema_name = expr->entity->get_name() + "s";
    }
    json11::Json instance_data = instance_json[schema_name][0];
    ocall_print_string(instance_data.dump().c_str(), __FILE__, __LINE__);
    for (auto attribute : attribute_list) {
        if (attribute.second->getType() == RuleLanguage::Type::NUMBER) {
            ocall_print_string(("update number attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            NumberAttribute* number_attribute = dynamic_cast<NumberAttribute*>(attribute.second.get());
            update_succ &= updateNumberValue(instance_data[attribute.first].int_value(), number_attribute);
        }

        if (attribute.second->getType() == RuleLanguage::Type::BOOLEAN) {
            ocall_print_string(("update boolean attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            BooleanAttribute* boolean_attribute = dynamic_cast<BooleanAttribute*>(attribute.second.get());
            update_succ &= updateBooleanValue(instance_data[attribute.first].bool_value(), boolean_attribute);
        }

        if (attribute.second->getType() == RuleLanguage::Type::STRING) {
            ocall_print_string(("update string attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            StringAttribute* string_attribute = dynamic_cast<StringAttribute*>(attribute.second.get());
            update_succ &= updateStringValue(instance_data[attribute.first].string_value(), string_attribute);
        }
    }
    return update_succ;
}
bool Instance::updateNumberValue(int64_t new_value, NumberAttribute* attribute) {
    if (attribute == nullptr) {
        ocall_print_string("Error!  attribute is nullptr" , __FILE__, __LINE__);
    }
    attribute->updateValue(new_value);
    return true;
}
bool Instance::updateBooleanValue(bool new_value, BooleanAttribute* attribute) {
    attribute->updateValue(new_value);
    return true;
}
bool Instance::updateStringValue(std::string new_value, StringAttribute* attribute) {
    attribute->updateValue(new_value);
    return true;
}

bool Instance::needQuery() {
    if (instance_kind == InstanceKind::UNIQUE_ENTITY) {
        return true;
    }

    if (instance_kind == InstanceKind::EXPR) {
        return dynamic_cast<RuleLanguage::queryExpr*>(expr.get()) != nullptr;
    }

    return false;
}

bool Instance::needCalculate() {
    if (instance_kind == InstanceKind::EXPR) {
        return dynamic_cast<RuleLanguage::queryExpr*>(expr.get()) == nullptr;
    } 
}

bool Instance::updateNumberValue(int64_t new_value) {
    value.number_value = new_value;
}
bool Instance::updateBooleanValue(bool new_value) {
    value.boolean_value = new_value;
}
bool Instance::updateStringValue(std::string new_value) {
    value.string_value = new_value;
}

bool Instance::calculateValue() {
    
}

std::string ObjectAttribute::dumpValue() {
    return instance_value->dumpAttributeValue();
}