#pragma once

#include <protos/untrusted/Register.grpc.pb.h>
#include <protos/untrusted/Register.pb.h>

#include <common/data_types/key_management/ErrorType.h>
#include <common/data_types/request_processor/ErrorType.h>

#include <KeyManagementEnclave_u.h>


//cosmos register
class RegisterServiceImpl final : public request_proto::Register::Service
{
    
    private:
        sgx_enclave_id_t eid;
        virtual grpc::Status GetEngineInfo(::grpc::ServerContext* context, 
                                            const request_proto::EngineInfoRequest* request, 
                                            request_proto::EngineInfoResponse* response) override;

        KEYMANAGEMENT_ERROR_CODE StartRemoteAttestationCosmos(request_proto::EngineInfoResponse *const register_resp);
    
    public:
        RegisterServiceImpl(sgx_enclave_id_t id) : eid(id) {}
};