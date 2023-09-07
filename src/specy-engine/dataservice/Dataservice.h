#pragma once
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <memory>
#include <iostream>

#include <third_party/json_lib/json11.hpp>

class Dataservice {
    private:
        // need to change this to config file
        std::string host;
        std::string port;
        std::string target;
        std::string subgraph;

    std::string generateQueryTarget(const std::string& subgraph);

    public:
        Dataservice(const std::string& host, const std::string& port, const std::string& target) : host(host), port(port), target(target), subgraph("specy") {}
        Dataservice(const std::string& host, const std::string& port) : host(host), port(port), target("/subgraphs/name/"), subgraph("specy") {}

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
