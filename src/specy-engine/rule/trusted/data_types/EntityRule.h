#pragma once
#include <string>
#include "EntityType.h"

class EntityRule : public EntityType {
   public:
    EntityRule() = default;
    EntityRule(const std::string& contract_name)
        : contract_name_(contract_name) {}
    const std::string& get_name() const override { return this->contract_name_; }
    std::string contract_name_;
};