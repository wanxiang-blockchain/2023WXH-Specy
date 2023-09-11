#pragma once

#include <string>
#include <vector>
#include "RuleEnclave_t.h"
#include "third_party/json_lib/json11.hpp"
#include "rule_enclave/EntityQuery.pb.h"
#include "trusted/data_provider/DataProvider.h"
#include "trusted/data_types/RequestContext.h"

#include "trusted/data_types/Entity.h"
#include "trusted/data_types/Instance.h"
#include "trusted/data_types/Expr.h"
#include "trusted/data_types/EntityRule.h"
#include "trusted/data_types/EntitySet.h"

class QueryBuilder {
   public:
    // Constructor of DataProvider
    QueryBuilder() = default;

    // Destructor of DataProvider
    ~QueryBuilder() = default;

    /******************************/

    std::string generateQueryString(shared_ptr<Instance> instance);
    std::string getConstrainFromInstance(Instance* instance, const std::string query_entity);
    std::string getConstrainFromNumberExpr(RuleLanguage::numberExpr* expr, const std::string query_entity);
    std::string getConstrainFromStringExpr(RuleLanguage::stringExpr* expr, string query_entity);
    std::string getConstrainFromBasicCondExpr(RuleLanguage::basicCondExpr* expr, const std::string query_entity);
    std::string getConstrainFromConditionExpr(RuleLanguage::conditionExpr* expr, const std::string query_entity);
    std::string getConstrainFromRelationExpr(RuleLanguage::relationExpr* expr, const std::string query_entity);

    private:
    uint64_t handleWithinValue(uint64_t timestamp, const rule_check_proto::Within& within);

    static const std::string QUERY_PREFIX;
    static const std::string QUERY_SUBFIX;
    static const std::string QUERY_CONSTRAINS_PREFIX;
    static const std::string QUERY_CONSTRAINS_SUBFIX;
    static const std::string QUERY_ATTRIBUTES_PREFIX;
    static const std::string QUERY_ATTRIBUTES_SUBFIX;
};
