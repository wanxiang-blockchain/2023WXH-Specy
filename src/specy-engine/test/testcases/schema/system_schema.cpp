#include "system_schema.h"

#include <iostream>
#include <regex>

using namespace std;
using namespace json11;


std::string MockSystemDatabase::GetRule(std::string& taskhash) { 
    Json::object content {
        {"rule_file", Tasks[taskhash]},
    };
    Json::object rules {
        {"tasks", Json::array {content}},
    };
    Json::object data {
        {"data", Json::object{rules}},
    };
    Json result = data;
    return result.dump();
}

string MockSystemDatabase::handleSystemQuery(string& query) {

    if (regex_search(query, regex("tasks"))) {
        smatch m;
        if (regex_search(query, m, regex(R"-(hash:\\"(.*)\\")-"))) {
            string taskhash = m[1].str();
            cout << taskhash << endl;
            return GetRule(taskhash);
        }
    }
    cout << "error occur! check your test case!" << endl;
    return "";
}



