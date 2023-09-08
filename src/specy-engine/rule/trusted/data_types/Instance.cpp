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

bool Instance::updateAttributeValue(json11::Json& instance_json) {
    ocall_print_string("Debug: enter updateAttributeValue", __FILE__, __LINE__);
    ocall_print_string(instance_json.dump().c_str(), __FILE__, __LINE__);
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
    if (instance_data.array_items().size() == 1) {
        instance_data = instance_data[0];
    }
    ocall_print_string(instance_data.dump().c_str(), __FILE__, __LINE__);
    for (auto attribute : attribute_list) {
        if (attribute.second->getType() == RuleLanguage::Type::NUMBER) {
            ocall_print_string(("update number attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            NumberAttribute* number_attribute = dynamic_cast<NumberAttribute*>(attribute.second.get());
            if (number_attribute == nullptr) {
                ocall_print_string(( "attribute "+ attribute.first + " type not match ").c_str(), __FILE__, __LINE__);
                return false;
            }
            update_succ &= number_attribute->updateValue(instance_data[attribute.first].int_value());
            if (attribute_list.size() == 1) {
                value.number_value = number_attribute->getValue();
            }
        }

        if (attribute.second->getType() == RuleLanguage::Type::BOOLEAN) {
            ocall_print_string(("update boolean attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            BooleanAttribute* boolean_attribute = dynamic_cast<BooleanAttribute*>(attribute.second.get());
            if (boolean_attribute == nullptr) {
                ocall_print_string(( "attribute "+ attribute.first + " type not match ").c_str(), __FILE__, __LINE__);
                return false;
            }
            update_succ &= boolean_attribute->updateValue(instance_data[attribute.first].bool_value());
            if (attribute_list.size() == 1) {
                value.boolean_value = boolean_attribute->getValue();
            }
        }

        if (attribute.second->getType() == RuleLanguage::Type::STRING) {
            ocall_print_string(("update string attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            StringAttribute* string_attribute = dynamic_cast<StringAttribute*>(attribute.second.get());
            if (string_attribute == nullptr) {
                ocall_print_string(( "attribute "+ attribute.first + " type not match ").c_str(), __FILE__, __LINE__);
                return false;
            }
            update_succ &= string_attribute->updateValue(instance_data[attribute.first].string_value());
            if (attribute_list.size() == 1) {
                value.string_value = string_attribute->getValue();
            }
        }

        if (attribute.second->getType() == RuleLanguage::Type::INSTANCELIST) {
            ocall_print_string(("update list attribute " + attribute.first).c_str(), __FILE__, __LINE__);
            ListAttribute* list_attribute = dynamic_cast<ListAttribute*>(attribute.second.get());
            if (list_attribute == nullptr) {
                ocall_print_string(( "attribute "+ attribute.first + " type not match ").c_str(), __FILE__, __LINE__);
                return false;
            }
            update_succ &= list_attribute->updateValue(instance_data[attribute.first]);
            if (attribute_list.size() == 1) {
                ocall_print_string(("update instance " + name + " list value when only one attribute").c_str(), __FILE__, __LINE__);                
                list_values.insert(list_values.end(), list_attribute->getValues().begin(), list_attribute->getValues().end());
                for (auto value : list_values) {
                    ocall_print_string(value.dump().c_str(), __FILE__, __LINE__);
                }
            }
        }
    }

    return update_succ;
}

bool ListAttribute::updateValue(const json11::Json& json_value) {
    ocall_print_string(("Debug! enter updateValue with json" + json_value.dump()).c_str(), __FILE__, __LINE__);

    if (!json_value.is_array()) {
        ocall_print_string(("Error! input json is not array!" + json_value.dump()).c_str(), __FILE__, __LINE__);
        return false;
    }

    switch (interType)
    {
        case RuleLanguage::Type::STRING:
            return updateStringValue(json_value.array_items());
            
        case RuleLanguage::Type::NUMBER:
            return updateNumberValue(json_value.array_items());

        case RuleLanguage::Type::BOOLEAN:
            return updateBooleanValue(json_value.array_items());
        
        default:
            break;
    }
    return false;
}

bool Instance::updateListValue(const json11::Json& json_value) {

    ocall_print_string("Debug: enter instance updateListValue", __FILE__, __LINE__);
    
    if (!json_value.is_array()) {
        ocall_print_string(("Error! input json is not array!" + json_value.dump()).c_str(), __FILE__, __LINE__);
        return false;
    }

    if (json_value.array_items().size() == 0) {
        ocall_print_string(("Debug: output json is empty, rule not match" + json_value.dump()).c_str(), __FILE__, __LINE__);
        return false;
    }

    for (auto json_data : json_value.array_items()) {
        Value value;
        if (list_type == RuleLanguage::Type::BOOLEAN) {
            value.boolean_value = json_data.bool_value();
        }

        if (list_type == RuleLanguage::Type::NUMBER) {
            value.number_value = json_data.number_value();
        }

        if (list_type == RuleLanguage::Type::STRING) {
            value.string_value = json_data.string_value();
        }
        list_values.push_back(value);
    }
    return true;
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
    ocall_print_string("Debug: updateStringValue", __FILE__, __LINE__);
    for (auto json_value : json_array) {
        Value value;
        value.string_value = json_value.string_value();
        ocall_print_string(value.dump().c_str(), __FILE__, __LINE__);
        values.push_back(value);
    }
    return true;
}
bool ListAttribute::updateNumberValue(const json11::Json::array& json_array) {
    ocall_print_string("Debug: updateNumberValue", __FILE__, __LINE__);
    for (auto json_value : json_array) {
        Value value;
        value.number_value = json_value.number_value();
        ocall_print_string(value.dump().c_str(), __FILE__, __LINE__);
        values.push_back(value);
    }
    return true;
}
bool ListAttribute::updateBooleanValue(const json11::Json::array& json_array) {
    ocall_print_string("Debug: updateBooleanValue", __FILE__, __LINE__);
    for (auto json_value : json_array) {
        Value value;
        value.boolean_value = json_value.bool_value();
        ocall_print_string(value.dump().c_str(), __FILE__, __LINE__);
        values.push_back(value);
    }
    return true;
}

bool ListAttribute::updateValueFromRelatedInstance() {
    ocall_print_string("Debug! enter updateValueFromRelatedInstance", __FILE__, __LINE__);
    if (instance->type() != RuleLanguage::Type::INSTANCELIST) {
        ocall_print_string("Error! type not match!", __FILE__, __LINE__);
        return false;
    }

    if (instance->list_type != interType) {
        ocall_print_string("Error! list type not match! ", __FILE__, __LINE__);
        ocall_print_string(RuleLanguage::TypeToString(instance->list_type).c_str(), __FILE__, __LINE__);
        ocall_print_string(RuleLanguage::TypeToString(interType).c_str(), __FILE__, __LINE__);
        return false;
    }

    auto& list_value = instance->list_values;
    values.clear();
    values.insert(values.end(), list_value.begin(), list_value.end());
    return true;
}

json11::Json Instance::dumpJson() {
    
    json11::Json::array instance_attributes;

    for (auto attribute : attribute_list) {
        instance_attributes.push_back(attribute.second->dumpJson());
    };
    
    json11::Json::object instance {
        {name, instance_attributes}
    };
    json11::Json ans = instance;
    return ans;
}

json11::Json ListAttribute::dumpJson() {
    json11::Json::array list_json;
    for (auto value : values) {
        if (interType == RuleLanguage::Type::BOOLEAN) {
            list_json.push_back(json11::Json(value.boolean_value));
        }

        if (interType == RuleLanguage::Type::NUMBER) {
            list_json.push_back(json11::Json((int32_t)value.number_value));
        }

        if (interType == RuleLanguage::Type::STRING) {
            list_json.push_back(json11::Json(value.string_value));
        }
    }

    json11::Json::object attribute {
        {name, list_json}
    };

    json11::Json ans = attribute;

    return ans;
}

json11::Json ObjectAttribute::dumpJson() {
    json11::Json instance_json = instance_value->dumpJson();
    json11::Json::object attribute {
        {name, instance_json}
    };
    json11::Json ans = attribute;
    return ans;
}