#include "nft_transfer.h"
#include <string>
#include <regex>

using namespace json11;
using namespace std;
// data of binding
string TestTaskHash = "0x1004";
string TestTaskRule = R"(task autoFollow entities friend { entity follower {  address is string     follows is list[ string ] }} input { usera is string userb is string} output { newFollows is list[string] } rules { rule checkNewFollowers {  followsA = select follower.follows where follower.address == inputdata.usera  followsB = select follower.follows where follower.address == inputdata.userb  newFollows = collect followsB where followsB not in followsA   outputdata.newFollows = newFollows }}execute { check rule checkNewFollowers})";

void mockTaskRequest_NFTList(request_proto::TaskRequest* request) {
    request->set_taskhash(TestTaskHash);
    request->set_rule_file(TestTaskRule);
    json11::Json::object data{
        {"inputdatas",
            json11::Json::object{
                {"usera", "usera_addr"},
                {"userb", "userb_addr"},
            }
        }
    };
    Json result = data;
    request->set_input_data(result.dump());
}

void InitMockDataBase_NFT(MockDatabase_NFT& mockDatabase) {
    mockDatabase.insertTask("0x307831303034", TestTaskRule);
    mockDatabase.insertTask("0x1004", TestTaskRule);
}

std::string MockDatabase_Taska::handleQuery(std::string& query, std::string& target){
    cout << target << endl;
    cout << query << endl;
    
    if (target.compare("specy") == 0)
        return MockDatabase_NFT::handleSystemQuery(query);

    if (target.compare("friend") == 0)
        return MockDatabase_Taska::handleTaskaQuery(query);

    return "";
}

bool MockDatabase_Taska::matchDatabase (std::string& target) {
    cout << "match database: " << target << endl; 
    if (target.compare("friend") == 0)
        return true;
    if (target.compare("specy") == 0)
        return true;
    return false;
}


std::string MockDatabase_Taska::handleTaskaQuery(std::string& query) {

    cout << "enter handleTaskaQuery: "<< query << endl;

    if (query.find("followers") != string::npos && query.find("usera_addr") != string::npos) {
        cout << "return data for Followers usera_addr: "<< query << endl;
        Json::array datas;
        datas.push_back("userb_addr");
        datas.push_back("usera_addr");
        Json::object followers {
            {"follows", datas}
        };
        Json::object data {
            {"followers", followers}
        };
        Json result = data;
        return result.dump();
    }

    if (query.find("followers") != string::npos && query.find("userb_addr") != string::npos) {
        cout << "return data for Followers usera_addr: "<< query << endl;
        Json::array datas;
        datas.push_back("userb_addr");
        datas.push_back("userc_addr");
        Json::object followers {
            {"follows", datas}
        };
        Json::object data {
            {"Followerss", followers}
        };
        Json result = data;
        return result.dump();
    }
    
    return "";
}