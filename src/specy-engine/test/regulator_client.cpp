#include <grpcpp/grpcpp.h>
#include <gtest/gtest.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>

#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "Regulator.grpc.pb.h"
#include "Regulator.pb.h"

#include "basic_server/http_server.h"
#include "basic_server/database.h"

#include "testcases/nft_transfer.h"

using namespace std;
using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;


// helper function used to start mocked graphnode server
void RunGraphnodeServer(GraphNodeTestServer& server) {
    server.RunServer();
    return;
}

// database used by http connection to mock graphql query result
Database* testdatabase;

class RegulatorClientTest : public ::testing::Test {
   protected:
    static void SetUpTestSuite() {
        graphnode_server_thread = std::thread(RunGraphnodeServer, std::ref(graphnode_server));
    }

    static void TearDownTestSuite() {
        graphnode_server.ShutDownServer();
        graphnode_server_thread.join();
    }

    void SetUp() {
        string target_str = "localhost:50051";
        shared_ptr<Channel> channel =
            grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials());
        stub_ = request_proto::Regulator::NewStub(channel);
        
        std::shared_ptr<grpc::ClientReaderWriter<request_proto::TaskRequest,
                                             request_proto::TaskResponse>>
        stream_(stub_->GetTaskResult(&context));
        stream = stream_;
    }

    // testcase resource: grpc stream
    std::unique_ptr<request_proto::Regulator::Stub> stub_;
    ClientContext context;
    std::shared_ptr<grpc::ClientReaderWriter<request_proto::TaskRequest,
                                             request_proto::TaskResponse>> stream;

    // testsuite resources : thread and server
    static std::thread graphnode_server_thread;
    static GraphNodeTestServer graphnode_server;
};

// definition of testsuite resource
std::thread RegulatorClientTest::graphnode_server_thread;
GraphNodeTestServer RegulatorClientTest::graphnode_server;


TEST_F(RegulatorClientTest, NFTListFail1) {

    // registe your own database
    MockDatabase_NFT* database_ = new MockDatabase_Taska();
    InitMockDataBase_NFT_4elements(*database_);
    testdatabase = database_;

    // generate test request and send
    request_proto::TaskRequest request;
    mockTaskRequest_NFTList_4elements(&request);

    EXPECT_TRUE(stream->Write(request));

    while (!stream->WritesDone()) {
        sleep(1);
    }

    // receive response and check
    request_proto::TaskResponse response;
    EXPECT_TRUE(stream->Read(&response));

    // clean up
    delete(testdatabase);
    testdatabase = nullptr;
}