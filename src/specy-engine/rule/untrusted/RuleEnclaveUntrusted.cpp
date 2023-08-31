// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements print method.

#include "RuleEnclaveUntrusted.h"

using namespace std;
using namespace json11;

#ifdef __cplusplus
extern "C"
{
#endif
    // ocall for printing string from inside enclave
    void ocall_query_entity(const char* query_request, size_t request_length,
                            const char* request_contract, size_t contract_length,
                            char* query_result, size_t result_length)
    {
        string contract = request_contract;
        string subgraph = "specy";
        if (contract != ""){
            subgraph = contract ;
        }
        Json queryResult = dataservice->query(query_request, subgraph.c_str());
        map<string, Json> outter;
        outter["message"] = Json("SUCCESS");
        outter["type"] = Json("entity");
        outter["result"] = queryResult;
        string content = queryResult.dump();
        memcpy(query_result, content.c_str(), content.length()+1);
        return;
    }

#ifdef __cplusplus
}
#endif