#include "Entity.h"
#include "Instance.h"

using namespace std;
using namespace json11;

/* Constructors and Destructors */

Entity::Entity(const string &name) {
    this->id_ = name;  // we use entity name as its id as well
    this->name_ = name;
}

/* Data Member Getters */

const string &Entity::get_id() const { return this->id_; }

const string &Entity::get_name() const { return this->name_; }

const set<string> &Entity::get_constraints_set() const {
    return this->constraints_;
}

const string Entity::toJSONString() const {
    Json entity_json = Json::object{{"id", this->id_},
                                    {"name", this->name_}};

    return entity_json.dump();
}

void Entity::addAttribute(const string &attribute_name, shared_ptr<Attribute>& attribute) {
    attribute_list.insert({attribute_name, attribute});
}

const std::map<std::string, shared_ptr<Attribute>>& Entity::get_attribute_list() const {
    return attribute_list;
}

void Entity::clearAttributes() { this->attribute_list.clear(); }

void Entity::setUnique(bool value) {
    unique = value;
}

bool Entity::isUnique() {
    return unique;
}


void Entity::addConstraint(const string &c) { this->constraints_.insert(c); }

/* Operator Overloadings */

bool operator<(const Entity &left, const Entity &right) {
    return left.name_ < right.name_;
    // return left.id_ < right.id_;
}

bool operator==(const Entity &left, const Entity &right) {
    return left.name_ == right.name_;
    // return left.id_ == right.id_;
}

string Entity::dump() {
    string entity_string;

    entity_string += this->get_name();
    entity_string += "{ \n";
    uint64_t counter = 0;
    for (auto attribute : get_attribute_list()) {
        entity_string += attribute.second->dump() ;
    }

    entity_string += "} \n";
    return entity_string;
}

bool Entity::hasAttribute(string& attribute_name, RuleLanguage::Type type) {
    return attribute_list.find(attribute_name) != attribute_list.end() && attribute_list[attribute_name]->isAttributeType(type);
}

shared_ptr<Attribute> Entity::getAttribute(string attribute_name, RuleLanguage::Type type) {
    if (hasAttribute(attribute_name, type)) {
        return attribute_list[attribute_name];
    }
    return nullptr;
}