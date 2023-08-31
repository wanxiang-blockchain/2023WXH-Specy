#include "nft_transfer.h"
#include <string>
#include <regex>

using namespace json11;
using namespace std;
// data of binding
string TestTaskHash_0elements = "0x1000";
string TestTaskHash_4elements = "0x1004";

string TestTaskRule_0elements = "regulation nft_reward entities { entity interchainnft {hash  sender  receiver  class_id  tocken_id  timestamp }  entity reward_list0 { token_id } } rules { rule nft_white_list { count on interchainnft where interchainnft.token_id in reward_list0 after 2023-01-01T00:00:00+08:00 within 1 days } }";
string TestTaskRule_4elements = R"(task erc20  entities taska {         entity PoolData {                 pool is number                                         centerHead is number                 centerTail is number         }                  entity BatchOrder {                 orderId is number                 direction is boolean                 tickUpper is number                 tickLower is number         }                  entity PoolSlot0 {       pool is number          tick is number         }                  entity block {                 timestamp is number         } }  input {         pool is number }  output {         pool is number         walkDirection is number         deadline is number }  rules {          rule checkCenterHeadITM {                 poolData = select PoolData where PoolData.pool == inputdata.pool                 poolSlot0 = select PoolSlot0 where PoolSlot0.pool == inputdata.pool                 order = select BatchOrder where BatchOrder.orderId == poolData.centerHead                 order.direction && poolSlot0.tick > order.tickUpper           }                  rule checkCenterTailITM {                 poolData =select PoolData where PoolData.pool == inputdata.pool                 poolSlot0 = select PoolSlot0 where PoolSlot0.pool == inputdata.pool                 order = select BatchOrder where BatchOrder.orderId == poolData.centerTail                 order.direction && poolSlot0.tick < order.tickUpper     } }  execute {         check rule checkCenterHeadITM  false : checkCenterTailITM})";

string TestTaskRewardList_0elements = "";
string TestTaskRewardList_4elements = "";


void mockTaskRequest_NFTList_0elements(request_proto::TaskRequest* request) {
    request->set_taskhash(TestTaskHash_0elements);
}

void mockTaskRequest_NFTList_4elements(request_proto::TaskRequest* request) {
    request->set_taskhash(TestTaskHash_4elements);
}

void InitMockDataBase_NFT_0elements(MockDatabase_NFT& mockDatabase) {
    mockDatabase.insertTask("0x307831303030", TestTaskRule_0elements);
}

void InitMockDataBase_NFT_4elements(MockDatabase_NFT& mockDatabase) {
    mockDatabase.insertTask("0x307831303034", TestTaskRule_4elements);
    mockDatabase.insertTask("0x1004", TestTaskRule_4elements);
}

std::string MockDatabase_Taska::handleQuery(std::string& query, std::string& target){
    cout << target << endl;
    cout << query << endl;
    
    if (target.compare("specy") == 0)
        return MockDatabase_NFT::handleSystemQuery(query);

    if (target.compare("taska") == 0)
        return MockDatabase_Taska::handleTaskaQuery(query);

    return "";
}

bool MockDatabase_Taska::matchDatabase (std::string& target) {
    cout << "match database: " << target << endl; 
    if (target.compare("taska") == 0)
        return true;
    if (target.compare("specy") == 0)
        return true;
    return false;
}


std::string MockDatabase_Taska::handleTaskaQuery(std::string& query) {

    cout << "enter handleTaskaQuery: "<< query << endl;
    if (query.find("inputdatas") != string::npos) {
        cout << "enter inputdatas: "<< query << endl;
        Json::array datas;
        Json::object value {
            {"pool" , 100}
        };
        datas.push_back(value);
        Json::object data {
            {"inputdatas", datas}
        };
        Json result = data;
        return result.dump();
    }

    if (query.find("outputdatas") != string::npos) {
        cout << "enter outputdatas: "<< query << endl;
        Json::array datas;
        Json::object value {
            {"deadline" , 2000},
            {"pool", 100},
            {"walkDirection", 300}
        };
        datas.push_back(value);
        Json::object data {
            {"outputdatas", datas}
        };
        Json result = data;
        return result.dump();
    }

    if (query.find("PoolDatas") != string::npos) {
        cout << "enter PoolDatas: "<< query << endl;
        Json::array datas;
        Json::object value {
            {"centerHead" , 105},
            {"centerTail", 100},
            {"pool", 100}
        };
        datas.push_back(value);
        Json::object data {
            {"PoolDatas", datas}
        };
        Json result = data;
        return result.dump();
    }

    if (query.find("PoolSlot0s") != string::npos) {
        cout << "enter PoolSlot0s: "<< query << endl;

        Json::array datas;
        Json::object value {
            {"tick", 100},
            {"pool", 100}
        };
        datas.push_back(value);
        Json::object data {
            {"PoolSlot0s", datas}
        };
        Json result = data;
        return result.dump();
    }
    
    if (query.find("BatchOrders") != string::npos) {
        cout << "enter BatchOrders: "<< query << endl;

        Json::array datas;
        Json::object value {
            {"orderId", 1},
            {"direction", true},
            {"tickLower", 100},
            {"tickUpper", 105}
        };
        datas.push_back(value);
        Json::object data {
            {"BatchOrders", datas}
        };
        Json result = data;
        return result.dump();
    }
    return "";
}