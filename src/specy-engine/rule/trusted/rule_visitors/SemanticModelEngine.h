
#include "SymbolCollector.h"

class SemanticModelEngine {
    private:
        SymbolCollector* symbol_collector;
        RequestContext* request_context;
        std::unique_ptr<ExecuteRule> root;
        std::string curr_rule_name;
        std::shared_ptr<Instance> output_instance;
        std::map<std::string, json11::Json> instance_data;

    public:
        SemanticModelEngine(SymbolCollector* collector, RequestContext* context);
        ~SemanticModelEngine() = default;


        bool bindInputData(std::string input_data);
        // fetch global data from the graph
        bool queryData();
        // execute rule file 
        bool execute();
        // execute 
        bool executeRule(ExecuteRule* rule);

        json11::Json getOutputData();

    private:
        bool calculateRelationExpr(RuleLanguage::relationExpr* expr);
        bool calculateBooleanExpr (RuleLanguage::booleanExpr* expr);
        bool calculateLogicalExpr(RuleLanguage::logicalExpr* expr);
        int64_t calculateNumberExpr(RuleLanguage::numberExpr* expr);
        int64_t getNumberValueFromInstance(Instance* instance);
        bool getBooleanValueFromInstance(Instance* instance);
        std::string getStringValueFromInstance(Instance* instance);
        bool updateInstanceValue(std::shared_ptr<Instance> instance);
        bool executeStmt(RuleLanguage::Expr* expr);

        bool getMatchValues(RuleLanguage::basicCondExpr* condition_expr,
                            const std::vector<Value>& list_value,
                            const RuleLanguage::Type list_type,
                            std::vector<Value>& match_values);
        json11::Json calculateQueryExpr(RuleLanguage::queryExpr* expr);
        json11::Json getListValueFromInstance(Instance* instance);
};