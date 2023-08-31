
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include "common/base64/Transform.h"

#include "RegulatorServiceImpl.h"
#include "Queue.h"
#include "Config.h"
#include <spdlog/spdlog.h>
#include <google/protobuf/util/json_util.h>


static const unsigned long kMaxOutSize = 8192UL;

using namespace std;

static string EmitJsonString (const google::protobuf::Message& message) {
    string jsonString;
    google::protobuf::util::MessageToJsonString(message, &jsonString);
    return jsonString;
}

REQUESTPROCESSOR_ERROR_CODE RegulatorServiceImpl::ProofRequestProcess(
    const request_proto::TaskRequest& request,
    request_proto::TaskResponse* response) {

    string requestString = request.SerializeAsString();
    string requestEncodedString = EncodeFromStringToString(requestString);

    BINDING_ERROR_CODE errorCode;
    char* responseBuffer = (char*) malloc(kMaxOutSize);
#ifdef USE_ENCLAVE_PREFIX
    BindingEnclave_ecall_process_proof_request(this->eid, &errorCode, requestEncodedString.c_str(), requestEncodedString.length(), responseBuffer, kMaxOutSize);
#else
    ecall_process_proof_request(this->eid, &errorCode, requestEncodedString.c_str(), requestEncodedString.length(), responseBuffer, kMaxOutSize);
#endif
    SPDLOG_INFO("return to untrsted zoom");
    string responseString = DecodeFromCharToString(responseBuffer);
    response->ParseFromString(responseString);

    SPDLOG_INFO("Receive proof response {}", responseString);
    return kRPSUCCESS;
}



// GetComplianceProof receives compliance request from RegChain system,
// parses the transaction and processes comliance.
// Finally, returns the compliance proof about transaction to RegChain system.
grpc::Status RegulatorServiceImpl::GetTaskResult(::grpc::ServerContext *context,
                                            grpc::ServerReaderWriter<::request_proto::TaskResponse, ::request_proto::TaskRequest> *stream)
{
    Queue<request_proto::TaskRequest> inputQueue(10000);
    Queue<request_proto::TaskResponse> outputQueue(10000);

    int32_t processThreadPoolSize;
    try
    {
        processThreadPoolSize = config["requestprocessor"]["THREAD_POOL_SIZE"].as<int32_t>();
    }
    catch (YAML::TypedBadConversion<int32_t> &e)
    {
        SPDLOG_INFO("requestprocessor:THREAD_POOL_SIZE is NULL, use default value: 3");
        processThreadPoolSize = 5;
    }

    SPDLOG_INFO("start check task request");

    auto ReadReq = [&]() {
        request_proto::TaskRequest taskRequest;
        SPDLOG_INFO("start read request");
        while (stream->Read(&taskRequest)) {
            SPDLOG_INFO("read request {}", taskRequest.taskhash());
            inputQueue.push(taskRequest);
        }
    };

    auto WriteRes = [&]() {
        request_proto::TaskResponse taskResponse;
        int i = 0;
        while (outputQueue.pop(taskResponse)) {
            stream->Write(taskResponse);
            i++; 
        }
    };

    auto RunReqGetRes = [&]() {
        auto threadID = std::this_thread::get_id();
        stringstream ss;
        ss << threadID;
        string idstr = ss.str();

        while (1) {
            request_proto::TaskRequest taskRequest;
            inputQueue.pop(taskRequest);
            // call ecall_process_request to get the response
            request_proto::TaskResponse taskResponse;

            SPDLOG_INFO("handle request: \n {}", EmitJsonString(taskRequest));
            ProofRequestProcess(taskRequest, &taskResponse);
            SPDLOG_INFO("get response: \n {}", EmitJsonString(taskResponse));
            outputQueue.push(taskResponse);
        }
    };

    std::vector<thread> thread_pool;
    thread_pool.push_back(thread(ReadReq));
    thread_pool.push_back(thread(WriteRes));

    for (int i = 0; i < processThreadPoolSize; i++) {
        thread_pool.push_back(thread(RunReqGetRes));
    }
    
    for (auto &t: thread_pool) {
        t.join();
    }

    return grpc::Status::OK;
}