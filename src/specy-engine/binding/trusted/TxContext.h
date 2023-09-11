// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// Request resolver and response constructor.
#pragma once

#include <map>
#include <string>
#include <vector>

#include "BindingEnclave_t.h"
#include "binding_enclave/Regulator.pb.h"
#include "e2e_message/RuleCheck.pb.h"

class TxContext {
    public:
        request_proto::TaskRequest* taskRequest;
        request_proto::TaskResponse* taskResponse;
        e2e_message::RuleCheckResponse* ruleCheckResponse;  

    public:
        // init Proof Request from string stream
        void initTxContext (std::string& rquestString);

        // call ruleCheck enclave for result
        void checkRules();

        // get signature from key management enclave
        std::string getSignature(const char* data);

        // generate Proof Response
        void generateTaskResponse();
        void serializeTaskResponse(char* output, size_t size);

        // safe release malloc memory
        ~TxContext();

    private:
        sgx_enclave_id_t bindingEnclaveId;
        sgx_enclave_id_t keyEnclaveId;
        sgx_enclave_id_t ruleEnclaveId;

};