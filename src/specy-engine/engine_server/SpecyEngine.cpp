// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements methods for SpecyEngine launching up.

#include "SpecyEngine.h"
#include "dataservice/Dataservice.h"

#include <spdlog/spdlog.h>
#include "KeyManagementEnclave_u.h"
#include "RuleEnclave_u.h"
#include "BindingEnclave_u.h"
#include "Config.h"

// #include "KeyManagementEnclave_u.h"
// #include "RuleEnclave_u.h"

using namespace std;

// LoadEnclaves is used to init and create SGX enclaves.
uint32_t SpecyEngine::LoadEnclaves()
{
    uint32_t status;
    uint32_t enclave_temp_num = 0; //

    // obtain enclave filename from config file
    string KEY_MANAGEMENT_ENCLAVE_FILENAME;
    string RULE_ENCLAVE_FILENAME;
    string BINDING_ENCLAVE_FILENAME;
    try
    {
        KEY_MANAGEMENT_ENCLAVE_FILENAME = config["keymanagement"]["KEY_MANAGEMENT_ENCLAVE_FILENAME"].as<string>();
        RULE_ENCLAVE_FILENAME = config["rulecheck"]["RULE_ENCLAVE_FILENAME"].as<string>();
        BINDING_ENCLAVE_FILENAME = config["binding"]["BINDING_ENCLAVE_FILENAME"].as<string>();
    }
    catch (YAML::TypedBadConversion<string> &e)
    {
        std::cout << "SpecyEngine: ENCLAVE_FILENAME is NULL" << std::endl;
        return uint32_t(ConfigStatus::kConfigReadError);
    }


    // load binding enclave
    status = sgx_create_enclave(BINDING_ENCLAVE_FILENAME.c_str(), SGX_DEBUG_FLAG,
                                NULL, NULL, &g_binding_enclave_id, NULL);
    if (status != SGX_SUCCESS)
    {
        SPDLOG_INFO("Binding sgx_create_enclave failed: Error code is {}\n", status);
        return status;
    }
    g_enclave_id_map[g_binding_enclave_id] = SubModule::kBinding;
    enclaveIDDebugString[g_binding_enclave_id] = "Bind";

    // load key management enclave
    status = sgx_create_enclave(KEY_MANAGEMENT_ENCLAVE_FILENAME.c_str(), SGX_DEBUG_FLAG,
                                NULL, NULL, &g_key_management_enclave_id, NULL);
    if (status != SGX_SUCCESS)
    {
        SPDLOG_INFO("Key Management sgx_create_enclave failed: Error code is {}\n", status);
        return status;
    }

    // keep a global map from enclave id to enclave index (used for ocall forward)
    // enclave_temp_num++;
    g_enclave_id_map[g_key_management_enclave_id] = SubModule::kKeyManagement;
    enclaveIDDebugString[g_key_management_enclave_id] = "Key Management";

    // load rule enclave
    status = sgx_create_enclave(RULE_ENCLAVE_FILENAME.c_str(), SGX_DEBUG_FLAG,
                                NULL, NULL, &g_rule_enclave_id, NULL);
    if (status != SGX_SUCCESS)
    {
        SPDLOG_INFO("Rule sgx_create_enclave failed: Error code is {}\n", status);
        return status;
    }
    g_enclave_id_map[g_rule_enclave_id] = SubModule::kRuleCheck;
    enclaveIDDebugString[g_rule_enclave_id] = "Rule";

    server.RegisteEnclaveID(g_key_management_enclave_id, g_binding_enclave_id);

    return SGX_SUCCESS;
}

// StartLocalAttestation is used to attest the identities between enclaves.
uint32_t SpecyEngine::StartLocalAttesttion()
{
    uint32_t status, ret_status;

    /* Establish Secure Channel Between Key Management and Binding Enclaves */
    // from key management to binding
    status = KeyManagementCreateSession(this->g_binding_enclave_id);
    // from binding to key management
    status = BindingCreateSession(this->g_key_management_enclave_id);

    /* Establish Secure Channel Between Rule and Binding Enclaves */
    // from rule to binding
    status = RuleCreateSession(this->g_binding_enclave_id);
    // from binding to rule
    status = BindingCreateSession(this->g_rule_enclave_id); 

    return status;
}

// LaunchGRPCServer is used to launch GRPC server for receiving registration and compliance requests.
uint32_t SpecyEngine::LaunchGRPCServer()
{

    server.RegisteEnclaveID(g_key_management_enclave_id, g_binding_enclave_id);
    if (REQUESTPROCESSOR_ERROR_CODE::kRPSUCCESS != server.RunServer())
    {
        return uint32_t(EngineStatus::kGRPCServerError);
    }

    return uint32_t(EngineStatus::kOK);
}

uint32_t SpecyEngine::LaunchDataService() {
    SPDLOG_INFO("Create http client");
    dataservice.reset(new Dataservice());
    return uint32_t(EngineStatus::kOK);
}


uint32_t SpecyEngine::KeyManagementCreateSession (sgx_enclave_id_t dest_enclave_id) {
    uint32_t status = 0;
    uint32_t ret_status = 0;
    status = KeyManagementEnclave_ecall_create_session(
        g_key_management_enclave_id, &ret_status, g_key_management_enclave_id, dest_enclave_id);
    ReportCreateSessionError(g_key_management_enclave_id, dest_enclave_id, status, ret_status);
    return status;
}

uint32_t SpecyEngine::BindingCreateSession (sgx_enclave_id_t dest_enclave_id) {

    uint32_t status = 0;
    uint32_t ret_status = 0;
    status = BindingEnclave_ecall_create_session(
        g_binding_enclave_id, &ret_status, g_binding_enclave_id, dest_enclave_id);
    ReportCreateSessionError(g_binding_enclave_id, dest_enclave_id, status, ret_status);

    return status;   
}

uint32_t SpecyEngine::RuleCreateSession (sgx_enclave_id_t dest_enclave_id) {

    uint32_t status = 0;
    uint32_t ret_status = 0;
    status = RuleEnclave_ecall_create_session(
        g_rule_enclave_id, &ret_status, g_rule_enclave_id, dest_enclave_id);
    ReportCreateSessionError(g_rule_enclave_id, dest_enclave_id, status, ret_status);

    return status;   
}

void SpecyEngine::ReportCreateSessionError (sgx_enclave_id_t source_enclave_id,
                                                sgx_enclave_id_t dest_enclave_id,
                                                uint32_t status, uint32_t ret_status) {

    string statusReportFormat = "{} create session Ecall failed: Error code is {}\n";
    string retStatusSuccessReportFormat = "Secure Channel Establishment between Source ({}) and Destination ({}) Enclaves successful !!!\n";
    string retStatusFailedReportFormat = "\nSession establishment and key exchange failure between Source ({}) and Destination ({}): Error code is {}\n";

    if (status != SGX_SUCCESS)
    {
        SPDLOG_INFO(statusReportFormat,enclaveIDDebugString[dest_enclave_id], status);
    }
    else
    {
        if (ret_status == 0)
        {
            SPDLOG_INFO(retStatusSuccessReportFormat, enclaveIDDebugString[source_enclave_id], enclaveIDDebugString[dest_enclave_id]);
        }
        else
        {
            SPDLOG_INFO(retStatusFailedReportFormat, enclaveIDDebugString[source_enclave_id], enclaveIDDebugString[dest_enclave_id], ret_status);
        }
    }
}