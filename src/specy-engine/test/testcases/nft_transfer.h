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

void InitMockDataBase_NFT_0elements(MockDatabase_NFT& mockDatabase);
void InitMockDataBase_NFT_4elements(MockDatabase_NFT& mockDatabase);
void mockTaskRequest_NFTList_0elements(request_proto::TaskRequest* request);
void mockTaskRequest_NFTList_4elements(request_proto::TaskRequest* request);