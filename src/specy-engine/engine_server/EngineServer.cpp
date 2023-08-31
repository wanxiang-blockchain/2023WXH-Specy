#include "EngineServer.h"

#include <yaml-cpp/yaml.h>
#include <spdlog/spdlog.h>
#include <string>

#include "Config.h"
#include "RegisterServiceImpl.h"
#include "RegulatorServiceImpl.h"

using namespace std;

uint32_t EngineServer::ReadConfig() {
    string core_regulator_endpoint;
    try
    {
        core_regulator_endpoint = config["requestprocessor"]["ENGINE_SERVER_ENDPOINT"].as<string>();
    }
    catch (YAML::TypedBadConversion<string> &e)
    {
        SPDLOG_INFO("requestprocessor:ENGINE_SERVER_ENDPOINT is NULL");
        return -1;
    }

    SPDLOG_INFO("Compliance Engine Endpoint: {0}", core_regulator_endpoint);

    if (!core_regulator_endpoint.empty())
    {
        int idx = core_regulator_endpoint.find(":");
        string ip_tmp = core_regulator_endpoint.substr(0, idx);
        string port_tmp = core_regulator_endpoint.substr(idx + 1);
        // verify ip
        if (!CheckIPAddrIsValid(ip_tmp) || !CheckPortIsValid(port_tmp))
        {
        SPDLOG_INFO("Failed to verfiy Compliance Engine Endpoint {0}", core_regulator_endpoint);
        return -1;
        }
    }

    this->address = core_regulator_endpoint;
    return 0;
}

uint32_t EngineServer::RunServer()
{
    ReadConfig();
    RegulatorServiceImpl regulatorService(bindingEnclaveID);
    RegisterServiceImpl registerService(keyManagementEnclaveID);

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;

    // Listen on the given address without any authentication mechanism.
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
    // Register "service" as the instance through which we'll communicate with
    // clients. In this case it corresponds to an *synchronous* service.
    builder.RegisterService(&regulatorService);
    builder.RegisterService(&registerService);


    // Finally assemble the server.
    this->server = move(builder.BuildAndStart());
    SPDLOG_INFO("Server listening on {}", address);

    // Wait for the server to shutdown. Note that some other thread must be
    // responsible for shutting down the server for this call to ever return.
    server->Wait();
    return 0;
}

void EngineServer::RegisteEnclaveID(sgx_enclave_id_t key_management_id, sgx_enclave_id_t binding_id)
{
    this->keyManagementEnclaveID = key_management_id;
    this->bindingEnclaveID = binding_id;
}