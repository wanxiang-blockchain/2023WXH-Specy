#pragma once
#include "schema/nft_schema.h"
#include "Regulator.pb.h"

class MockDatabase_Taska : public MockDatabase_NFT {
    // function override by Database
    bool matchDatabase (std::string& target) override;
    std::string handleQuery(std::string& query, std::string& target) override;

    std::string handleTaskaQuery(std::string& query);
    std::string getSchemaName(std::string& query);

};


void InitMockDataBase_NFT(MockDatabase_NFT& mockDatabase);
void mockTaskRequest_NFTList(request_proto::TaskRequest* request);