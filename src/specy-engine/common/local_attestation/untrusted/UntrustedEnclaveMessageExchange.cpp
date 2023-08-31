#include "UntrustedEnclaveMessageExchange.h"
#include <unistd.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <cstdio>

using namespace std;

std::map<sgx_enclave_id_t, SubModule> g_enclave_id_map;
std::mutex mtx_gEnclaveIdMap;

uint32_t ocall_query_enclave_id(uint64_t target_module_id, sgx_enclave_id_t *target_enclave_id)
{
	SPDLOG_INFO("enter ocall_query_enclave_id::target_module_id {}", target_module_id);
	mtx_gEnclaveIdMap.lock();
	for(auto iter=g_enclave_id_map.begin(); iter != g_enclave_id_map.end(); iter++){
		if((uint64_t)iter->second == target_module_id){
			mtx_gEnclaveIdMap.unlock();
			*target_enclave_id = iter->first;
			return (uint32_t)kLA_SUCCESS;
		}
	}
	mtx_gEnclaveIdMap.unlock();

	SPDLOG_INFO("exit ocall_query_enclave_id::INVALID_PARAMETER");
	return (uint32_t)kLA_INVALID_PARAMETER;
	/*if (g_enclave_id_map.find(target_module_id) != g_enclave_id_map.end())
	{
		*target_enclave_id = g_enclave_id_map[target_module_id];
		return SUCCESS;
	}
	else
	{
		return INVALID_PARAMETER;
	}*/
}

// TODO (Xufei) Improve log system. Add parameters like: file name, line number
// ocall for printing string from inside enclave
void ocall_print_string(const char *str, const char *file, const int line)
{
	string prefix = "[" + string(file) + ":" + to_string(line) + "] : ";
	spdlog::get("trusted_logger")->info(prefix + string(str));

    // spdlog::get("trusted_logger")->flush();

	// cout << str << endl;
}

//Makes an sgx_ecall to the destination enclave to get session id and message1
ATTESTATION_STATUS ocall_session_request(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg1_t *dh_msg1, uint32_t *session_id)
{
	uint32_t status = 0;
	sgx_status_t ret = SGX_SUCCESS;
	SubModule temp_enclave_no;

	mtx_gEnclaveIdMap.lock();
	std::map<sgx_enclave_id_t, SubModule>::iterator it = g_enclave_id_map.find(dest_enclave_id);
	if (it != g_enclave_id_map.end())
	{
		temp_enclave_no = it->second;
	}
	else
	{
		mtx_gEnclaveIdMap.unlock();
		SPDLOG_INFO("exit ocall_session_request::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
	mtx_gEnclaveIdMap.unlock();

	switch (temp_enclave_no)
	{
	case SubModule::kKeyManagement:
		ret = KeyManagementEnclave_ecall_session_request(dest_enclave_id, &status, src_enclave_id, dh_msg1, session_id);
		break;
	case SubModule::kRuleCheck:
		ret = RuleEnclave_ecall_session_request(dest_enclave_id, &status, src_enclave_id, dh_msg1, session_id);
		break;
	case SubModule::kBinding:
		ret = BindingEnclave_ecall_session_request(dest_enclave_id, &status, src_enclave_id, dh_msg1, session_id);
		break;
	}
	if (ret == SGX_SUCCESS) {
		return (ATTESTATION_STATUS)status;
	}
	else {
		SPDLOG_INFO("exit ocall_session_request::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
		
}
//Makes an sgx_ecall to the destination enclave sends message2 from the source enclave and gets message 3 from the destination enclave
ATTESTATION_STATUS ocall_exchange_report(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, sgx_dh_msg2_t *dh_msg2, sgx_dh_msg3_t *dh_msg3, uint32_t session_id)
{
	SPDLOG_INFO("enter ocall_exchange_report");
	uint32_t status = 0;
	sgx_status_t ret = SGX_SUCCESS;
	SubModule temp_enclave_no;

	mtx_gEnclaveIdMap.lock();
	std::map<sgx_enclave_id_t, SubModule>::iterator it = g_enclave_id_map.find(dest_enclave_id);
	if (it != g_enclave_id_map.end())
	{
		temp_enclave_no = it->second;
	}
	else
	{
		mtx_gEnclaveIdMap.unlock();
		SPDLOG_INFO("exit ocall_exchange_report::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
	mtx_gEnclaveIdMap.unlock();

	switch (temp_enclave_no)
	{
	case SubModule::kKeyManagement:
		ret = KeyManagementEnclave_ecall_exchange_report(dest_enclave_id, &status, src_enclave_id, dh_msg2, dh_msg3, session_id);
		break;
	case SubModule::kRuleCheck:
		ret = RuleEnclave_ecall_exchange_report(dest_enclave_id, &status, src_enclave_id, dh_msg2, dh_msg3, session_id);
		break;
	case SubModule::kBinding:
		ret = BindingEnclave_ecall_exchange_report(dest_enclave_id, &status, src_enclave_id, dh_msg2, dh_msg3, session_id);
		break;
	}
	if (ret == SGX_SUCCESS) {
		return (ATTESTATION_STATUS)status;
	}
	else {
		SPDLOG_INFO("exit ocall_exchange_report::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
		
}

//Make an sgx_ecall to the destination enclave function that generates the actual response
ATTESTATION_STATUS ocall_send_request(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id, secure_message_t *req_message, size_t req_message_size, size_t max_payload_size, secure_message_t *resp_message, size_t resp_message_size)
{
	SPDLOG_INFO("enter ocall_send_request");
	uint32_t status = 0;
	sgx_status_t ret = SGX_SUCCESS;
	SubModule temp_enclave_no;

	mtx_gEnclaveIdMap.lock();
	std::map<sgx_enclave_id_t, SubModule>::iterator it = g_enclave_id_map.find(dest_enclave_id);
	if (it != g_enclave_id_map.end())
	{
		temp_enclave_no = it->second;
	}
	else
	{
		mtx_gEnclaveIdMap.unlock();
		SPDLOG_INFO("exit ocall_send_request::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
	mtx_gEnclaveIdMap.unlock();

	switch (temp_enclave_no)
	{
	case SubModule::kKeyManagement:
		SPDLOG_INFO("key Management {0} call {1}", to_string(src_enclave_id), to_string(dest_enclave_id));
		ret = KeyManagementEnclave_ecall_generate_response(dest_enclave_id, &status, src_enclave_id, req_message, req_message_size, max_payload_size, resp_message, resp_message_size);
		break;
	case SubModule::kRuleCheck:
		SPDLOG_INFO("rue  checker {0} call {1}", to_string(src_enclave_id), to_string(dest_enclave_id));

		ret = RuleEnclave_ecall_generate_response(dest_enclave_id, &status, src_enclave_id, req_message, req_message_size, max_payload_size, resp_message, resp_message_size);
		break;
	case SubModule::kBinding:
		SPDLOG_INFO("binding {0} call {1}", to_string(src_enclave_id), to_string(dest_enclave_id ));

		ret = BindingEnclave_ecall_generate_response(dest_enclave_id, &status, src_enclave_id, req_message, req_message_size, max_payload_size, resp_message, resp_message_size);
		SPDLOG_INFO("ret: {0}",ret);
		break;
	}
	if (ret == SGX_SUCCESS) {
		return (ATTESTATION_STATUS)status;
	}
	else {
		SPDLOG_INFO("exit ocall_send_request::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
}

//Make an sgx_ecall to the destination enclave to close the session
ATTESTATION_STATUS ocall_end_session(sgx_enclave_id_t src_enclave_id, sgx_enclave_id_t dest_enclave_id)
{
	SPDLOG_INFO("enter ocall_end_session");
	uint32_t status = 0;
	sgx_status_t ret = SGX_SUCCESS;
	SubModule temp_enclave_no;

	mtx_gEnclaveIdMap.lock();
	std::map<sgx_enclave_id_t, SubModule>::iterator it = g_enclave_id_map.find(dest_enclave_id);
	if (it != g_enclave_id_map.end())
	{
		temp_enclave_no = it->second;
	}
	else
	{
		mtx_gEnclaveIdMap.unlock();
		SPDLOG_INFO("exit ocall_end_session::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
	mtx_gEnclaveIdMap.unlock();

	switch (temp_enclave_no)
	{
	case SubModule::kKeyManagement:
		ret = KeyManagementEnclave_ecall_end_session(dest_enclave_id, &status, src_enclave_id);
		break;
	case SubModule::kRuleCheck:
		ret = RuleEnclave_ecall_end_session(dest_enclave_id, &status, src_enclave_id);
		break;
	case SubModule::kBinding:
		ret = BindingEnclave_ecall_end_session(dest_enclave_id, &status, src_enclave_id);
		break;
	}
	if (ret == SGX_SUCCESS) {
		return (ATTESTATION_STATUS)status;
	}
	else {
		SPDLOG_INFO("exit ocall_end_session::INVALID_SESSION");
		return (ATTESTATION_STATUS)kLA_INVALID_SESSION;
	}
}
