#pragma once

#include <set>
#include <string>

#include "EntityType.h"
#include "Expr.h"
#include "third_party/json_lib/json11.hpp"

// using namespace std;

class Attribute;

class Entity : public EntityType {
   private:
    std::string id_;  // we use entity name as its id, i.e., id_ = name_
    std::string name_;
    std::map<std::string, std::shared_ptr<Attribute>> attribute_list;
    std::set<std::string> constraints_;
    bool unique;

   public:
    Entity(const std::string &name);
    Entity() = default;
    ~Entity() = default;

    /* Data Member Getters */

    const std::string &get_id() const;
    const std::string &get_name() const;
    const std::map<std::string, std::shared_ptr<Attribute>>& get_attribute_list() const;
    const std::set<std::string> &get_constraints_set() const;
    bool hasAttribute(std::string& attributr_name, RuleLanguage::Type type);

    const std::string toJSONString() const;

    void setUnique(bool value);
    bool isUnique();

    void addAttribute(const std::string &attribute_name, std::shared_ptr<Attribute>& attribute);
    std::shared_ptr<Attribute> getAttribute(std::string attribute_name, RuleLanguage::Type type);

    void addConstraint(const std::string &attribute_name);
    void clearAttributes();

    friend bool operator<(const Entity &left, const Entity &right);
    friend bool operator==(const Entity &left, const Entity &right);

    /* debug */
    std::string dump();
};