#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <string>

class Instance;
class Entity;
class Attribute;

namespace RuleLanguage
{
    
enum Type {
    NON = 0,
    NUMBER,
    BOOLEAN,
    STRING,
    LIST,
    DATE,
    INSTANCELIST,
    INSTANCE
};

enum LogicalOperator {
    LOGICAL_NON = 0,
    NOT,
    AND,
    OR,
};

enum ArithmeticOperator {
    ARITH_NON = 0,
    MULTIPLY,
    DIVIDE,
    MODULO,
    PLUS,
    MINUS,
};

enum QueryOperator {
    QUERY_NON = 0,
    SELECT,
    COLLECT,

};

enum RelationOperator {
    RELATION_NON = 0,
    EQUALS,
    NOT_EQUALS,
    LESS_THAN,
    LESS_OR_EQUALS,
    GREATER,
    GREATER_OR_EQUALS,
};

class Expr {
    public:
        Expr() = default;
        ~Expr() = default;
        virtual Type type() = 0;
        virtual std::string dump() = 0;
};

class numberExpr : public Expr {
    public:
        numberExpr() = default;
        ~numberExpr() = default;
        Type type() override {
            return Type::NUMBER;
        }

        bool isNegative() {
            return negative;
        }

        void setNegative() {
            negative = true;
        }

        void setOperator(ArithmeticOperator op) {
            arith_operator = op;
            is_literal = false;
        }

        void setLeftExpr(numberExpr* expr) {
            left_expr.reset(expr);
            is_literal = false;
        }

        void setRightExpr(numberExpr* expr) {
            right_expr.reset(expr);
            is_literal = false;
        }

        void setValue(int64_t value) {
            this->value = value;
            is_literal = true;
        }

        void setInstance(std::shared_ptr<Instance>& instance) {
            this->instance = instance;
        }

        std::string dump() override;

        bool isLiteral() {
            return is_literal;
        }

        int64_t getValue() {
            return value;
        }

        std::shared_ptr<Instance> getInstance() {
            return instance;
        }

        numberExpr* getLeftExpr() {
            return left_expr.get();
        }

        numberExpr* getRightExpr() {
            return right_expr.get();
        }

        ArithmeticOperator getOperator() {
            return arith_operator;
        }

    private:
        bool negative;
        /* TODO: use big number to instead*/
        int64_t value;
        bool is_literal;
        ArithmeticOperator arith_operator;
        std::unique_ptr<numberExpr> left_expr;
        std::unique_ptr<numberExpr> right_expr;
        std::shared_ptr<Instance> instance;
};

class stringExpr : public Expr {
    private:
        bool literal;
        std::string literal_value;
        std::shared_ptr<Instance> instance;
    public:
        stringExpr() = default;
        ~stringExpr() = default;
        Type type() {
            return Type::STRING;
        }
        std::string dump();

        void setLiteralValue(std::string value) {
            literal_value = value;
        }

        void setInstance(std::shared_ptr<Instance> instance) {
            this->instance = instance;
        } 

        void setLiteral() {
            literal = true;
        }

        bool isLiteral() {
            return literal;
        }

        std::string getLiteralValue() {
            return literal_value;
        }

        std::shared_ptr<Instance> getInstance() {
            return instance;
        }

};

class relationExpr : public Expr {
    private:
        std::unique_ptr<numberExpr> left_number_expr;
        std::unique_ptr<numberExpr> right_number_expr;
        std::unique_ptr<stringExpr> left_string_expr;
        std::unique_ptr<stringExpr> right_string_expr;
        RelationOperator operators;

    public:
        relationExpr() = default;
        ~relationExpr() = default;
        std::string dump() override;
        Type type() {
            return Type::BOOLEAN;
        }

        void setOperator(RelationOperator op) {
            operators = op;
        }

        numberExpr* getLeftNumberExpr() {
            return left_number_expr.get();
        }

        numberExpr* getRightNumberExpr() {
            return right_number_expr.get();
        }

        stringExpr* getLeftStringExpr() {
            return left_string_expr.get();
        }

        stringExpr* getRightStringExpr() {
            return right_string_expr.get();
        }

        RelationOperator getOperators() {
            return operators;
        }

        void setLeftStringExpr(stringExpr* expr) {
            left_string_expr.reset(expr);
        }

        void setRightStringExpr(stringExpr* expr) {
            right_string_expr.reset(expr);
        }

         void setLeftNumberExpr(numberExpr* expr) {
            left_number_expr.reset(expr);
        }

        void setRightNumberExpr(numberExpr* expr) {
            right_number_expr.reset(expr);
        }
};

class listExpr : public Expr {
    public:
        std::shared_ptr<Instance> left_instance;
        std::shared_ptr<Instance> right_instance;
        // true = in; false = not in
        bool inside;

        bool isLegal();

        Type type() {
            return Type::BOOLEAN;
        }
        std::string dump();
};

class booleanExpr : public Expr {
    
    public:
        std::unique_ptr<Expr> expr;
        bool literalValue;
        std::shared_ptr<Instance> instance;
    
    public:
        booleanExpr() = default;
        ~booleanExpr() = default;
        std::string dump() override;
        Type type() {
            return Type::BOOLEAN;
        }

        void setValue(bool value) {
            literalValue = value;
        }

        void setExpr(Expr* expr) {
            this->expr.reset(expr);
        }

        void setInstance(std::shared_ptr<Instance> instance) {
            this->instance = instance;
        }
};

class logicalExpr : public Expr {
    public:
        logicalExpr() = default;
        ~logicalExpr() = default;
        std::string dump() override;
        Type type() {
            return Type::BOOLEAN;
        }

        void setOperator(LogicalOperator op) {
            logical_operator = op;
        }

        void setLeftExpr(Expr* expr) {
            left_expr.reset(expr);
        }

        void setRightExpr(Expr* expr) {
            right_expr.reset(expr);
        }

        void setBooleanExpr(booleanExpr* expr) {
            boolean_expr.reset(expr);
        }

    public:
        LogicalOperator logical_operator;
        std::unique_ptr<booleanExpr> boolean_expr;
        std::unique_ptr<Expr> left_expr;
        std::unique_ptr<Expr> right_expr;
};


class basicCondExpr : public Expr {
    private:
        std::unique_ptr<relationExpr> rExpr;
        std::unique_ptr<listExpr> lExpr;
        LogicalOperator logical_operator;
    public:
        basicCondExpr() = default;
        ~basicCondExpr() = default;
        std::string dump() override;
        Type type() override {
            return Type::BOOLEAN;
        }

        void setListExpr(listExpr* expr) {
            lExpr.reset(expr);
        }

        void setRelationExpr(relationExpr* expr) {
            rExpr.reset(expr);
        }

        void setOperator(LogicalOperator op) {
            logical_operator = op;
        }

        relationExpr* getRelationExpr() {
            return rExpr.get();
        }

        listExpr* getListExpr() {
            return lExpr.get();
        }

        LogicalOperator getOperator() {
            return logical_operator;
        }

};

class conditionExpr : public Expr {
    private:
        std::unique_ptr<basicCondExpr> basic_expr;
        std::vector<std::unique_ptr<basicCondExpr>> basicExprs;

    public:
        conditionExpr() = default;
        ~conditionExpr() = default;
        std::string dump() override;
        Type type() override {
            return Type::BOOLEAN;
        }

        void setBasicExpr(basicCondExpr* expr) {
            basic_expr.reset(expr);
        }

        void addExpr(basicCondExpr* expr) {
            std::unique_ptr<basicCondExpr> expr_ptr(expr);
            basicExprs.push_back(std::move(expr_ptr));
        }

        basicCondExpr* getBasicExpr() {
            return basic_expr.get();
        }

        std::vector<std::unique_ptr<basicCondExpr>>& getBasicExprs() {
            return basicExprs;
        }
};

class queryExpr : public Expr {
    
    public:
        bool select;
        bool collect;
        // type is type of selected Entity/Instance/Attribute
        RuleLanguage::Type expr_type;
        // list_type is the basic type of a list
        RuleLanguage::Type list_type;

        std::shared_ptr<Instance> instance;
        std::shared_ptr<Entity> entity;
        std::unique_ptr<conditionExpr> expr;
        std::string attribute_name;
    
    public:
        queryExpr() = default;
        ~queryExpr() = default;
        std::string dump() override;
        bool isSelect();
        bool isCollect();
        Type type();
        void updateExprType();

        void setSelect(bool value) {
            select = value;
        }

        void setCollect(bool value) {
            collect = value;
        }

        void setInstance(std::shared_ptr<Instance>& instance) {
            this->instance = instance;
        }

        void setEntity(std::shared_ptr<Entity>& entity) {
            this->entity = entity;
        }

        void setExpr(conditionExpr* expr) {
            this->expr.reset(expr);
        }

        std::shared_ptr<Entity> getEntity() {
            return entity;
        }

        std::shared_ptr<Instance> getInstance() {
            return instance;
        }

        conditionExpr* getExpr() {
            return expr.get();
        }

        void setAttributeName(std::string& name) {
            attribute_name = name;
        }

        std::string getAttributeName() {
            return attribute_name;
        }

        std::string getQueryTable();
        const std::map<std::string, std::shared_ptr<Attribute>>& getAttributs();
        std::string getName();

};

class definitionExpr : public Expr {
    public:
        std::shared_ptr<Instance> instance;
        Type type();
        std::string dump();
};

class literal : public Expr {
    private:
        Type literalType;

        std::string stringValue;
        bool booleanValue;
        uint64_t uNumberValue;
        int64_t sNumberValue;
        std::string dateValue;

    public:
        literal() = default;
        ~literal() = default;
        Type type();
};

std::string TypeToString(Type type);
std::string LogicalOperatorToString(LogicalOperator op);
std::string ArithmeticOperatorToString(ArithmeticOperator op);
std::string QueryOperatorToString(QueryOperator op);
std::string RelationOperatorToString(RelationOperator op);
std::string RelationOperatorToSuffixString(RelationOperator op);

} // namespace RuleLanguage