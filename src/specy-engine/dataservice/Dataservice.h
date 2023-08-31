#pragma once
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <memory>
#include <iostream>

#include <third_party/json_lib/json11.hpp>

class Dataservice {
    private:
        // need to change this to config file
        const char* host;
        const char* port;
        const char* target;
        const char* subgraph;

    std::string generateQueryTarget(const char* subgraph);

    public:
        Dataservice(const char* host, const char* port, const char* target) : host(host), port(port), target(target), subgraph("specy") {}
        
        Dataservice() {
            // for default, visit graph node from localhost:8000 and
            // query the regchain system subgraph
            this->host = "localhost";
            this->port = "8000";
            this->target = "/subgraphs/name/";
            this->subgraph = "specy";
        }

        json11::Json query(const char* querySentence, const char* subgraph);
};

extern std::unique_ptr<Dataservice> dataservice;
