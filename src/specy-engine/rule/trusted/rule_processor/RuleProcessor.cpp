// LICENSE: Apache 2.0
// https://github.com/RegTech-OXH/compliance-engine
//
// Author:
//
// This file implements RuleProcessor class.

#include "RuleProcessor.h"


#include <regex>
#include <vector>
#include <set>
#include "merklecpp.h"
#include "sgx_tcrypto.h"
#include "trusted/rule_visitors/SemanticModelEngine.h"
// #include "openssl/sha.h"

using namespace std;
using namespace json11;
using namespace antlr4;

static void dumpEntitySetList(vector<EntitySet>& entity_set_list) {
    ocall_print_string("EvaluateRule: dump entity set list", __FILE__, __LINE__);
    for (auto &entity_set : entity_set_list)
    {
        string entity_set_string;

        // basic entity set info
        auto entity_name = entity_set.get_name();
        auto constraint_list = entity_set.get_constraint_list();

        entity_set_string += ("EvaluateRule: entity set: " + entity_name + "[");

        ocall_print_string(("EvaluateRule: constraint_list size: " +
                            to_string(constraint_list.size())).c_str(), __FILE__, __LINE__);

        // traverse through constraint list
        uint64_t counter = 0;
        for (auto constraint_iter = constraint_list.begin();
             constraint_iter != constraint_list.end(); constraint_iter++)
        {
            if (counter++ > 0)
            {
                entity_set_string += ", ";
            }
            entity_set_string += constraint_iter->Utf8DebugString();
        }

        entity_set_string += "]";

        ocall_print_string((string("EvaluateRule: new entity set: ") + entity_set_string).c_str(), __FILE__, __LINE__);
    }
}

static inline void sha256_sgx(
    const merkle::HashT<32>& l,
    const merkle::HashT<32>& r,
    merkle::HashT<32>& out)
{
    uint8_t block[32 * 2];
    memcpy(&block[0], l.bytes, 32);
    memcpy(&block[32], r.bytes, 32);
    sgx_sha256_msg(block, sizeof(block), &out.bytes);
}

void GenerateQuerySentences (const string& rule_text, vector<string>& sentences) {
    sentences.push_back(R"-({"query" : "{interchainnftreceives(where : {timestamp_gt:1672502400}) { receiver class_id }}"})-");
    sentences.push_back(R"-({"query" : "{rewardlists { list }}"})-");
}

// EvaluateRule is used to regulate transaction with rules
RuleEnclaveStatus RuleProcessor::EvaluateRule(RequestContext *const request_context)
{
    ocall_print_string("enter EvaluateRule", __FILE__, __LINE__);

    RuleEnclaveStatus status_code = RuleEnclaveStatus::kOK;
    
    ocall_print_string("parse rule text", __FILE__, __LINE__);
    // build a parse tree from requested rule text
    ANTLRInputStream input(request_context->get_rule_text());
    RuleLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    // print out lexer parsed tokens
    tokens.fill();
    uint64_t counter = 0;
    ocall_print_string("traverse tokens", __FILE__, __LINE__);
    for (const auto &token : tokens.getTokens())
    {
        ocall_print_string((string("token at pos ") +
                            to_string(counter++) +
                            string(": ") + token->toString()).c_str(), __FILE__, __LINE__);
    }

    RuleParser parser(&tokens);
    auto tree = parser.root();

    // visit AST by SymbolCollector
    SymbolCollector entity_collector; // rule language visitor
    tree->accept(&entity_collector);

    entity_collector.dump();

    SemanticModelEngine semantic_model(&entity_collector);
    bool execute_result = semantic_model.execute();


    return RuleEnclaveStatus::kOK;
}