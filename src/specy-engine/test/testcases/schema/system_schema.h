#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

#include <third_party/json_lib/json11.hpp>
#include "basic_server/database.h"

class MockSystemDatabase : public Database {
   public:

    void insertTask(std::string taskhash, std::string rule_content) {
        Tasks.insert({taskhash, rule_content});
    }
    std::string GetRule(std::string& taskhash);

    std::string handleSystemQuery(std::string& query);

    // taskhash -> content
    std::map<std::string, std::string> Tasks;

    
};