#include "EntitySet.h"
#include "RuleEnclave_t.h" /* sgx generated proxy header */

using namespace std;
using namespace json11;
using namespace rule_check_proto;

/* Constructors and Destructors */

EntitySet::EntitySet(const string &id, const string &name) {
    this->id_ = id;
    this->name_ = name;
}

EntitySet::EntitySet(const string &id, const string &name,
                     const vector<Constraint> &constraint_list) {
    this->id_ = id;
    this->name_ = name;
    this->constraint_list_ = constraint_list;
}

EntitySet::~EntitySet() {}

/* Data Member Getters */ /* Handle existing entity binding */

const string &EntitySet::get_id() const { return this->id_; }

const string &EntitySet::get_name() const { return this->name_; }

// vector<string> EntitySet::get_member_list()
// {
//     return this->member_list_;
// }

const vector<Constraint> &EntitySet::get_constraint_list() const {
    return this->constraint_list_;
}

const string EntitySet::toJSONString() const {
    vector<string> constraint_string_list;
    for (const auto &constraint : this->constraint_list_) {
        constraint_string_list.push_back(constraint.Utf8DebugString());
    }

    Json entity_set_json =
        Json::object{{"id", this->id_},
                     {"name", this->name_},
                     {"constraints", constraint_string_list}};

    return entity_set_json.dump();
}

const string EntitySet::dump() const {
    // build entity set string for display
    string entity_set_string;
    entity_set_string += get_name();
    entity_set_string += "{";

    uint64_t counter = 0;
    for (const auto &constraint : get_constraint_list()) {
        if (counter++ > 0) {
            entity_set_string += ", ";
        }
        // decide on different constraint types
        if (constraint.has_provided()) {
            ocall_print_string("new provided constraint", __FILE__, __LINE__);

            auto provided = constraint.provided();
            entity_set_string += provided.Utf8DebugString();
        } else if (constraint.has_where()) {
            ocall_print_string("new where constraint", __FILE__, __LINE__);

            auto where = constraint.where();
            entity_set_string += where.Utf8DebugString();
        } else if (constraint.has_within()) {
            ocall_print_string("new within constraint", __FILE__, __LINE__);

            auto within = constraint.within();
            entity_set_string += within.Utf8DebugString();
        }
    }

    entity_set_string += "}";
    return entity_set_string;
}

const std::set<std::string>& EntitySet::get_attribute_set() const{
    return this->attribute_set_;
}

void EntitySet::add_attributes(const std::string& attribute) {
    this->attribute_set_.insert(attribute);
}

/* Operator Overloadings */

bool operator<(const EntitySet &left, const EntitySet &right) {
    return left.name_ < right.name_;
    // return left.id_ < right.id_;
}

bool operator==(const EntitySet &left, const EntitySet &right) {
    return left.name_ == right.name_;
    // return left.id_ == right.id_;
}