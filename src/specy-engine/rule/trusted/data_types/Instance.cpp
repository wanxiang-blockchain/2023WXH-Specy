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
        schema_name = expr->getName() + "s";
    }
    json11::Json instance_data = instance_json[schema_name];
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

        if (attribute.second->getType() == RuleLanguage::Type::INSTANCELIST) {
            ocall_print_string(("update list attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            ListAttribute* list_attribute = dynamic_cast<ListAttribute*>(attribute.second.get());
            update_succ &= updateListValue(instance_data[attribute.first], list_attribute);
            
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

bool Instance::updateListValue(const json11::Json& json_value, ListAttribute* attribute) {

    ocall_print_string("Debug: enter updateListValue", __FILE__, __LINE__);
    if (!json_value.is_array()) {
        ocall_print_string(("Error! input json is not array!" + json_value.dump()).c_str(), __FILE__, __LINE__);
        return false;
    }

    RuleLanguage::Type inter_type = attribute->getInterType();
    switch (inter_type)
    {
    case RuleLanguage::Type::STRING:
        return attribute->updateStringValue(json_value.array_items());
        
    case RuleLanguage::Type::NUMBER:
        return attribute->updateNumberValue(json_value.array_items());

    case RuleLanguage::Type::BOOLEAN:
        return attribute->updateBooleanValue(json_value.array_items());
    
    default:
        break;
    }
    return false;
}

bool Instance::needQuery() {
    if (instance_kind == InstanceKind::UNIQUE_ENTITY) {
        return true;
    }

    if (instance_kind == InstanceKind::EXPR) {
        RuleLanguage::queryExpr* query_expr = dynamic_cast<RuleLanguage::queryExpr*>(expr.get());
        if (query_expr != nullptr) {
            std::shared_ptr<Instance> query_expr_instance = query_expr->getInstance();
            return query_expr_instance == nullptr || query_expr_instance->getInstanceKind() == InstanceKind::SYMBOL;
        } else {
            return false;
        }
    }

    return false;
}

bool Instance::needCalculate() {
    if (instance_kind == InstanceKind::EXPR) {
        RuleLanguage::queryExpr* query_expr = dynamic_cast<RuleLanguage::queryExpr*>(expr.get());
        if (query_expr == nullptr)
        {
            return true;
        } else {
            std::shared_ptr<Instance> query_expr_instance = query_expr->getInstance();
            return query_expr_instance != nullptr && query_expr_instance->getInstanceKind() != InstanceKind::SYMBOL;
        }
    }
    return false;
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

std::string ListAttribute::dumpValue() {
    std::string value_stirng = "[\n";
    if (interType == RuleLanguage::Type::NUMBER) {
        for (auto value : values) {
            value_stirng.append(std::to_string(value.number_value))
                .append(" ");
        }
    }

    if (interType == RuleLanguage::Type::STRING) {
        for (auto value : values) {
            value_stirng.append(value.string_value)
                .append(" ");
        }
    }

    if (interType == RuleLanguage::Type::BOOLEAN) {
        for (auto value : values) {
            value_stirng.append(value.boolean_value ? "true" : "false")
                .append(" ");
        }
    }
    value_stirng.append("\n]");
    return value_stirng;
}

bool ListAttribute::updateStringValue(const json11::Json::array& json_array) {
    for (auto json_value : json_array) {
        Value value;
        value.string_value = json_value.string_value();
        values.push_back(value);
    }
    return true;
}
bool ListAttribute::updateNumberValue(const json11::Json::array& json_array) {
    for (auto json_value : json_array) {
        Value value;
        value.number_value = json_value.number_value();
        values.push_back(value);
    }
    return true;
}
bool ListAttribute::updateBooleanValue(const json11::Json::array& json_array) {
    for (auto json_value : json_array) {
        Value value;
        value.boolean_value = json_value.bool_value();
        values.push_back(value);
    }
    return true;
}