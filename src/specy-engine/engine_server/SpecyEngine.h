#include <iostream>
#include <map>
#include <memory>

#include <spdlog/spdlog.h>
#include <yaml-cpp/yaml.h>

#include "sgx_urts.h"
#include "common/data_types/EnclaveId.h"
#include "EngineServer.h"

enum class EngineStatus
{
    kOK = 0,
    kEnclaveLoadError,
    kLocalAttestationError,
    kDataserviceError,
    kGRPCServerError,
    kConfigReadError,
    kInitLoggerError,
};

// #define KEY_MANAGEMENT_ENCLAVE_FILENAME "key_management_enclave.signed.so"
// #define RULE_ENCLAVE_FILENAME "rule_enclave.signed.so"
// #define BINDING_ENCLAVE_FILENAME "binding_enclave.signed.so"

// map from enclave id to enclave index (used for ocall forward)
extern std::map<sgx_enclave_id_t, SubModule> g_enclave_id_map;

class SpecyEngine
{
    public:
        // SGX related
        uint32_t LoadEnclaves();
        uint32_t StartLocalAttesttion();

        // grpc server
        uint32_t LaunchGRPCServer();

        // Data service for 
        uint32_t LaunchDataService();


    private:
        EngineServer server;

        sgx_enclave_id_t g_key_management_enclave_id;
        sgx_enclave_id_t g_rule_enclave_id;
        sgx_enclave_id_t g_binding_enclave_id;

        // wrapper function for create local attestation
        uint32_t BindingCreateSession (sgx_enclave_id_t dest_enclave_id);
        uint32_t KeyManagementCreateSession (sgx_enclave_id_t dest_enclave_id);
        uint32_t RuleCreateSession (sgx_enclave_id_t dest_enclave_id);

        // for debug
        std::map<sgx_enclave_id_t, std::string> enclaveIDDebugString;
        void ReportCreateSessionError (sgx_enclave_id_t source_enclave_id,
                                       sgx_enclave_id_t dest_enclave_id,
                                       uint32_t status, uint32_t ret_status);
        
};