
#include "SymbolCollector.h"

class SemanticModelEngine {
    private:
        SymbolCollector* symbol_collector;
        std::unique_ptr<ExecuteRule> root;

        std::map<std::string, json11::Json> instance_data;

    public:
        SemanticModelEngine(SymbolCollector* collector);
        ~SemanticModelEngine() = default;

        // fetch data from the graph
        bool queryData();
        // execute rule file 
        bool execute();
        // execute 
        bool executeRule(ExecuteRule* rule);

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

};