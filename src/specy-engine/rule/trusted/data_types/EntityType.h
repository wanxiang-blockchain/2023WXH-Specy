#pragma once
#include <set>
#include <string>

class EntityType {
   public:
    EntityType() = default;
    ~EntityType() = default;

    virtual const std::set<std::string>& get_attribute_set() const {
        return null_attribute_set;
    }
    
    private:
    std::set<std::string> null_attribute_set;
};
