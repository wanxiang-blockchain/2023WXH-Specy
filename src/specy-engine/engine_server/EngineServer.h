#pragma once
#include "common/data_types/request_processor/ErrorType.h"
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>
#include "sgx_urts.h"


class EngineServer
{
public:
    uint32_t RunServer();

    uint32_t ReadConfig();

    void RegisteEnclaveID(sgx_enclave_id_t key_management_id, sgx_enclave_id_t binding_id);

private:
    std::unique_ptr<grpc::Server> server;
    std::string address;

    sgx_enclave_id_t keyManagementEnclaveID;
    sgx_enclave_id_t bindingEnclaveID;
};