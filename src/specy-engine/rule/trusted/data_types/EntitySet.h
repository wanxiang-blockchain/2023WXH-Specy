#pragma once

#include <string>
#include <vector>

#include "EntityType.h"
#include "third_party/json_lib/json11.hpp"

#ifdef BUILD_WITH_PROTOCOL_BUFFER_3_7
#include <rule_enclave/EntityQuery.pb.h>
#else
#include <rule_enclave/EntityQuery.pb.h>
#endif

class EntitySet : public EntityType {
   private:
    // we use rule context text (which triggers this entity set request) as
    // entity set id NOTE: while there may be alternatives, we find rule context
    // text the most explicit
    std::string id_;
    std::string name_;
    // vector<string> member_list_;
    std::vector<rule_check_proto::Constraint> constraint_list_;
    std::set<std::string> attribute_set_;

   public:
    EntitySet(const std::string &id, const std::string &name);
    EntitySet(const std::string &id, const std::string &name,
              const std::vector<rule_check_proto::Constraint> &constraint_list);
    ~EntitySet();

    /* Data Member Getters */

    const std::string &get_id() const;
    const std::string &get_name() const override;
    const std::vector<rule_check_proto::Constraint> &get_constraint_list()
        const;
    
    const std::set<std::string>& get_attribute_set() const override;
    void add_attributes(const std::string& attribute);

    const std::string toJSONString() const;
    const std::string dump() const;

    friend bool operator<(const EntitySet &left, const EntitySet &right);
    friend bool operator==(const EntitySet &left, const EntitySet &right);
};