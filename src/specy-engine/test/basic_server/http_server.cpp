#include "http_server.h"
#include "database.h"

#include <iostream>
#include <regex>

using namespace std;

// "Loop" forever accepting new connections.
void http_server(tcp::acceptor& acceptor, tcp::socket& socket) {
    acceptor.async_accept(socket, [&](beast::error_code ec) {
        if (!ec) std::make_shared<http_connection>(std::move(socket))->start();
        http_server(acceptor, socket);
    });
}

void http_connection::read_request() {
    auto self = shared_from_this();

    http::async_read(
        socket_, buffer_, request_,
        [self](beast::error_code ec, std::size_t bytes_transferred) {
            boost::ignore_unused(bytes_transferred);
            if (!ec) self->process_request();
        });
}

void http_connection::process_request() {
    response_.version(request_.version());
    response_.keep_alive(false);
    switch (request_.method()) {
        case http::verb::post:
            response_.result(http::status::ok);
            response_.set(http::field::server, "Beast");
            create_response();
            break;
        default:
            // We return responses indicating an error if
            // we do not recognize the request method.
            response_.result(http::status::bad_request);
            response_.set(http::field::content_type, "text/plain");
            beast::ostream(response_.body())
                << "Invalid request-method '"
                << std::string(request_.method_string()) << "'";
            break;
    }
    write_response();
}

string http_connection::getSubgraphName(string& target) {
    smatch target_match;
    if (regex_search(target, target_match, regex(R"(/subgraphs/name/(.*))"))) {
        return target_match[1].str();
    }

    return "";
}

void http_connection::create_response() {
    string target_string = request_.target();
    string request_body = request_.body();
    cout << "target_string : " << target_string << endl;
    cout << "request_body : " << request_body << endl;
    string target_name = getSubgraphName(target_string);
    // string target_name("specy");
    cout << target_name << endl;
    if (testdatabase->matchDatabase(target_name)) {
        beast::ostream(response_.body()) << testdatabase->handleQuery(request_body, target_name);
    }
    else {
        response_.result(http::status::not_found);
        response_.set(http::field::content_type, "text/plain");
        beast::ostream(response_.body()) << "Data not found\r\n";
    }
}

void http_connection::write_response() {
    auto self = shared_from_this();
    response_.content_length(response_.body().size());
    http::async_write(
        socket_, response_, [self](beast::error_code ec, std::size_t) {
            self->socket_.shutdown(tcp::socket::shutdown_send, ec);
            self->deadline_.cancel();
        });
}

void http_connection::check_deadline() {
    auto self = shared_from_this();
    deadline_.async_wait([self](beast::error_code ec) {
        if (!ec) {
            // Close socket to cancel any outstanding operation.
            self->socket_.close(ec);
        }
    });
}

void GraphNodeTestServer::RunServer() {
    auto const address = net::ip::make_address("0.0.0.0");
    unsigned short port = 8000;
    tcp::acceptor acceptor{ioc_, {address, port}};
    tcp::socket socket{ioc_};
    http_server(acceptor, socket);
    ioc_.run();
}

void GraphNodeTestServer::ShutDownServer() { ioc_.stop(); }