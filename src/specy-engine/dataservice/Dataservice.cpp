#include "Dataservice.h"
#include <boost/beast/version.hpp>
#include <spdlog/spdlog.h>
#include <algorithm>

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp; 

std::string Dataservice::generateQueryTarget(const std::string& subgraph) {
    std::string querySubgraph = subgraph.empty() ? this->subgraph : subgraph;
    std::stringstream ss;
    ss << target << querySubgraph;
    return ss.str();
}


json11::Json Dataservice::query(const char* querySentence,
                               const char* subgraph) {
    try {
        // prepare connection

        SPDLOG_INFO("Query Sentence is {}, subgraph is {}", querySentence, subgraph);
        net::io_context ioc;
        tcp::resolver resolver(ioc);
        SPDLOG_INFO("Target Address is {}, Port is {}", host, port);
        auto const resolveResult = resolver.resolve(host, port);
        boost::beast::tcp_stream stream(ioc);
        stream.connect(resolveResult);

        // generate http request
        std::string queryTarget = generateQueryTarget(subgraph);
        http::request<http::string_body> req{http::verb::post, queryTarget.c_str(), 11};
        req.set(http::field::host, this->host);
        req.set(http::field::user_agent, "specy engine http client");
        req.set(http::field::content_type, "application/json");

        // set query language as body

        req.body() = querySentence;
        req.prepare_payload();

        // send
        http::write(stream, req);

        // read response
        http::response<http::string_body> res;
        beast::flat_buffer buffer;
        http::read(stream, buffer, res);

        std::string err;
        auto queryResult = json11::Json::parse(res.body(), err);

        SPDLOG_INFO("the original response data is \n : {}", res.body());
        beast::error_code ec;
        stream.socket().shutdown(tcp::socket::shutdown_both, ec);
        if (!err.empty()) {
            SPDLOG_ERROR("parse response data failed!");
            SPDLOG_INFO("the original response data is \n : {}", res.body());
            return json11::Json();
        }
        return queryResult;
    }
    catch (std::exception const& e)
    {
        SPDLOG_INFO(e.what());
        return json11::Json();
    }
}

std::unique_ptr<Dataservice> dataservice;