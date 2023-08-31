#pragma once
#include "Expr.h"
#include <string>
#include <map>
#include "third_party/json_lib/json11.hpp"

class Instance;

enum InstanceKind {
    EXPR = 0,
    UNIQUE_ENTITY,
    SYMBOL,
    SPECIFIC_ATTRIBUTE,
    INSTANCE_NON
};

class Value {
    public:
        int64_t number_value;
        bool boolean_value;
        std::string string_value;
};

class Attribute {
    private:
        std::string name;
        RuleLanguage::Type type;

    public:
        Attribute() = default;
        ~Attribute() = default;
        Attribute(std::string attribute_name, RuleLanguage::Type attribute_type) : name(attribute_name), type(attribute_type) {}
        bool isAttributeType(RuleLanguage::Type type) {
            return type == this->type;
        }

        std::string getName() {
            return name;
        }

        RuleLanguage::Type getType() {
            return type;
        }

        virtual std::string dump() {
            return name + " is " + RuleLanguage::TypeToString(type) + "\n";
        }

        virtual std::string getValueString() {
            return "";
        }

        virtual std::string dumpValue() = 0;

};

class NumberAttribute : public Attribute {
    private:
        int64_t number_value;

    public:
        NumberAttribute() = default;
        NumberAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        NumberAttribute(std::string name, RuleLanguage::Type type, int64_t value) : Attribute(name, type), number_value(value) {}
        ~NumberAttribute() = default;

        int64_t value() {
            return number_value;
        }

        bool updateValue(int64_t new_value) {
            number_value = new_value;
            return true;
        }

        std::string getValueString() override {
            return std::to_string(number_value);
        }

        int64_t getValue() {
            return number_value;
        }

        std::string dumpValue() {
            return std::to_string(number_value);
        }
};

class BooleanAttribute : public Attribute {
    private:
        bool boolean_value;
    
    public:
        BooleanAttribute() = default;
        BooleanAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        BooleanAttribute(std::string name, RuleLanguage::Type type, bool value) : Attribute(name, type), boolean_value(value) {}
        ~BooleanAttribute() = default;

        bool value() {
            return boolean_value;
        }

        bool updateValue(bool new_value) {
            boolean_value = new_value;
            return true;
        }

        bool getValue() {
            return boolean_value;
        }

        std::string getValueString() override {
            return boolean_value ? "true" : "false";
        }

        std::string dumpValue() {
            return boolean_value ? "true" : "false";
        }
};

class StringAttribute : public Attribute {
    private:
        std::string string_value;

    public:
        StringAttribute() = default;
        StringAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        StringAttribute(std::string name, RuleLanguage::Type type, std::string value) : Attribute(name, type), string_value(value) {}
        ~StringAttribute() = default;

        std::string value() {
            return string_value;
        }

        bool updateValue(std::string new_value) {
            string_value = new_value;
            return true;
        }

        std::string getValueString() {
            return string_value;
        }

        std::string getValue() {
            return string_value;
        }

        std::string dumpValue() {
            return string_value;
        }
};

class ObjectAttribute : public Attribute {
    private:
        std::unique_ptr<Instance> instance_value;
    
    public:
        ObjectAttribute() = default;
        ObjectAttribute(std::string name, RuleLanguage::Type type) : Attribute(name, type) {}
        ObjectAttribute(std::string name, RuleLanguage::Type type, Instance* value) : Attribute(name, type) {
            instance_value.reset(value);
        }
        ~ObjectAttribute() = default;

        Instance* value() {
            return instance_value.get();
        }

        std::string dump() override;

        std::string dumpValue();
};

class Instance {

    private:
        std::string name;
        std::string specific_attribute;
        std::unique_ptr<RuleLanguage::Expr> expr;
        std::string unique_entity_name;
        std::map<std::string, std::shared_ptr<Attribute>> attribute_list;
        InstanceKind instance_kind;
        RuleLanguage::Type instance_type;
        Value value;

    public:
        Instance() = default;
        Instance(const std::string& instanceName) : name(instanceName), instance_kind(InstanceKind::INSTANCE_NON) {}

        ~Instance() = default;

        std::string getName() {
            return name;
        }

        RuleLanguage::Expr* getExpr() {
            return expr.get();
        }


        RuleLanguage::Type type() {
            if (instance_kind == InstanceKind::EXPR) {
                return expr->type();
            }

            if (instance_kind == InstanceKind::UNIQUE_ENTITY) {
                return RuleLanguage::Type::INSTANCE;
            }

            return instance_type;
        }

        InstanceKind getInstanceKind() {
            return instance_kind;
        }

        void setInstanceKind(InstanceKind type) {
            this->instance_kind = type;
        }

        bool isUniqueEntityInstance() {
            return !unique_entity_name.empty();
        }

        void setExpr(RuleLanguage::Expr* expr) {
            this->expr.reset(expr);
        }

        void setUniqueEntityName(std::string& name) {
            unique_entity_name = name;
        }

        void addAttributes(const std::map<std::string, std::shared_ptr<Attribute>>& attributes) {
            attribute_list.insert(attributes.begin(), attributes.end());
        }

        void addAttribute(std::string name, std::shared_ptr<Attribute> attribute) {
            if (instance_kind == InstanceKind::SPECIFIC_ATTRIBUTE) {
                specific_attribute = name;
            }
            attribute_list[name] = attribute;
        }

        void setType(RuleLanguage::Type type) {
            this->instance_type = type;
        }

        bool hasAttribute(const std::string attribute_name, RuleLanguage::Type type) {
            if (attribute_list.find(attribute_name) != attribute_list.end()) {
                auto attribute = attribute_list[attribute_name];
                if (attribute->isAttributeType(type)) {
                    return true;
                }
            }
            return false;
        }

        std::string dump();
        std::string dumpAttributeValue();
        std::shared_ptr<Attribute> getAttribute(const std::string attribute_name, RuleLanguage::Type type) {
            if (hasAttribute(attribute_name, type)) {
                return attribute_list[attribute_name];
            }
            return nullptr;
        }

        const std::map<std::string, std::shared_ptr<Attribute>>& get_attribute_list() const {
            return attribute_list;
        }

        Value getValue() {
            return value;
        }

        std::shared_ptr<Attribute> getSpecificAttribute() {
            return attribute_list[specific_attribute];
        }

        bool updateValue(json11::Json& instance_json);
        bool updateNumberValue(int64_t new_value, NumberAttribute* attribute);
        bool updateBooleanValue(bool new_value, BooleanAttribute* attribute);
        bool updateStringValue(std::string new_value, StringAttribute* attribute);
        bool updateNumberValue(int64_t new_value);
        bool updateBooleanValue(bool new_value);
        bool updateStringValue(std::string new_value);

        bool needQuery();
        bool needCalculate();

        bool calculateValue();

};