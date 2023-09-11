#pragma once
#include <string>

class Database {
public:

    // check whether the target subgraph has been mocked by database
    virtual bool matchDatabase (std::string& target) {
        return false;
    }
    // handle query and reply the mocked and formated data 
    virtual std::string handleQuery(std::string& query, std::string& target) {
        return "";
    }
};

extern Database* testdatabase;