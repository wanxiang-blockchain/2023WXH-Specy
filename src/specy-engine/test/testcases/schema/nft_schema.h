#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

#include <third_party/json_lib/json11.hpp>
#include "system_schema.h"

// for transfer subgraph
// In test context, there are two users only 0x1, 0x2
class interchain_nft_receives {
   public:
    std::string hash;
    std::string classid;
    std::string tocken_id;

    bool operator<(const interchain_nft_receives& t1) const {
        if (this->tocken_id < t1.tocken_id) {
            return true;
        }
        return false;
    }

};

class MockDatabase_NFT : public MockSystemDatabase {
   public:

   // transfers index by hash, contract_address, sender and receiver
    std::map<std::string, interchain_nft_receives*> nft_classid_index;
    std::map<std::string, interchain_nft_receives*> nft_id_index;
    std::map<std::string, interchain_nft_receives*> nft_hash_index;

    // transfer container ordered by timestamp
    std::set<interchain_nft_receives> nfts;
    // std::string subgraph_name_;

    void insertNFTItem(interchain_nft_receives* nft) {
        nft_classid_index.insert({nft->classid, nft});
        nft_id_index.insert({nft->tocken_id, nft});
        nft_hash_index.insert({nft->hash, nft});
        nfts.insert(*nft);
    }

    interchain_nft_receives* GetNFTByid(std::string& tocken_id) {
        return nft_id_index[tocken_id];
    }

    interchain_nft_receives* GetNFTByhash(std::string& hash) {
        return nft_hash_index[hash];
    }

};


