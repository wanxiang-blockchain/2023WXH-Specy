#pragma once

#include <iostream>
#include <grpcpp/grpcpp.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>

#include "common/data_types/request_processor/ErrorType.h"
#include <sgx_error.h>
#include <BindingEnclave_u.h>

#include "protos/untrusted/Regulator.grpc.pb.h"
#include "protos/untrusted/Regulator.pb.h"

class  RegulatorServiceImpl final : public request_proto::Regulator::Service
{

    private:
    sgx_enclave_id_t eid;
    virtual grpc::Status GetTaskResult(::grpc::ServerContext *context,
                                            grpc::ServerReaderWriter<::request_proto::TaskResponse, ::request_proto::TaskRequest> *stream) override;

    REQUESTPROCESSOR_ERROR_CODE ProofRequestProcess(const request_proto::TaskRequest& request, request_proto::TaskResponse* response);
    
    public:
        RegulatorServiceImpl(sgx_enclave_id_t g_binding_enclave_id) : eid(g_binding_enclave_id) {}

};