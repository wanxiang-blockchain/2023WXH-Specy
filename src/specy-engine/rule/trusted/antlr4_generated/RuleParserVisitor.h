
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "RuleParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by RuleParser.
 */
class  RuleParserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by RuleParser.
   */
    virtual antlrcpp::Any visitRoot(RuleParser::RootContext *context) = 0;

    virtual antlrcpp::Any visitTaskDecl(RuleParser::TaskDeclContext *context) = 0;

    virtual antlrcpp::Any visitInputBlock(RuleParser::InputBlockContext *context) = 0;

    virtual antlrcpp::Any visitOutputBlock(RuleParser::OutputBlockContext *context) = 0;

    virtual antlrcpp::Any visitOutputDecl(RuleParser::OutputDeclContext *context) = 0;

    virtual antlrcpp::Any visitOutputAttribute(RuleParser::OutputAttributeContext *context) = 0;

    virtual antlrcpp::Any visitOutputObject(RuleParser::OutputObjectContext *context) = 0;

    virtual antlrcpp::Any visitObjectName(RuleParser::ObjectNameContext *context) = 0;

    virtual antlrcpp::Any visitEntitiesBlock(RuleParser::EntitiesBlockContext *context) = 0;

    virtual antlrcpp::Any visitEntityList(RuleParser::EntityListContext *context) = 0;

    virtual antlrcpp::Any visitEntityDecl(RuleParser::EntityDeclContext *context) = 0;

    virtual antlrcpp::Any visitEntityName(RuleParser::EntityNameContext *context) = 0;

    virtual antlrcpp::Any visitAttributeList(RuleParser::AttributeListContext *context) = 0;

    virtual antlrcpp::Any visitAttributeDecl(RuleParser::AttributeDeclContext *context) = 0;

    virtual antlrcpp::Any visitAttributeName(RuleParser::AttributeNameContext *context) = 0;

    virtual antlrcpp::Any visitTypeAnno(RuleParser::TypeAnnoContext *context) = 0;

    virtual antlrcpp::Any visitBasicType(RuleParser::BasicTypeContext *context) = 0;

    virtual antlrcpp::Any visitCompositeType(RuleParser::CompositeTypeContext *context) = 0;

    virtual antlrcpp::Any visitListType(RuleParser::ListTypeContext *context) = 0;

    virtual antlrcpp::Any visitExecutionBlock(RuleParser::ExecutionBlockContext *context) = 0;

    virtual antlrcpp::Any visitExecutionStmt(RuleParser::ExecutionStmtContext *context) = 0;

    virtual antlrcpp::Any visitExecuteRuleDef(RuleParser::ExecuteRuleDefContext *context) = 0;

    virtual antlrcpp::Any visitExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext *context) = 0;

    virtual antlrcpp::Any visitExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext *context) = 0;

    virtual antlrcpp::Any visitRulesBlock(RuleParser::RulesBlockContext *context) = 0;

    virtual antlrcpp::Any visitRuleList(RuleParser::RuleListContext *context) = 0;

    virtual antlrcpp::Any visitBasicRule(RuleParser::BasicRuleContext *context) = 0;

    virtual antlrcpp::Any visitRuleName(RuleParser::RuleNameContext *context) = 0;

    virtual antlrcpp::Any visitRuleStmtList(RuleParser::RuleStmtListContext *context) = 0;

    virtual antlrcpp::Any visitRuleStmt(RuleParser::RuleStmtContext *context) = 0;

    virtual antlrcpp::Any visitSimpleStmt(RuleParser::SimpleStmtContext *context) = 0;

    virtual antlrcpp::Any visitComplexStmt(RuleParser::ComplexStmtContext *context) = 0;

    virtual antlrcpp::Any visitListStmt(RuleParser::ListStmtContext *context) = 0;

    virtual antlrcpp::Any visitListExpr(RuleParser::ListExprContext *context) = 0;

    virtual antlrcpp::Any visitRelationStmt(RuleParser::RelationStmtContext *context) = 0;

    virtual antlrcpp::Any visitRelationExpr(RuleParser::RelationExprContext *context) = 0;

    virtual antlrcpp::Any visitRelationOperator(RuleParser::RelationOperatorContext *context) = 0;

    virtual antlrcpp::Any visitNumberExpr(RuleParser::NumberExprContext *context) = 0;

    virtual antlrcpp::Any visitSelectorIdent(RuleParser::SelectorIdentContext *context) = 0;

    virtual antlrcpp::Any visitAggregationExpr(RuleParser::AggregationExprContext *context) = 0;

    virtual antlrcpp::Any visitBooleanExpr(RuleParser::BooleanExprContext *context) = 0;

    virtual antlrcpp::Any visitBooleanLiteral(RuleParser::BooleanLiteralContext *context) = 0;

    virtual antlrcpp::Any visitLogicalStmt(RuleParser::LogicalStmtContext *context) = 0;

    virtual antlrcpp::Any visitLogicalExpr(RuleParser::LogicalExprContext *context) = 0;

    virtual antlrcpp::Any visitDefinitionStmt(RuleParser::DefinitionStmtContext *context) = 0;

    virtual antlrcpp::Any visitInstanceName(RuleParser::InstanceNameContext *context) = 0;

    virtual antlrcpp::Any visitQueryExpr(RuleParser::QueryExprContext *context) = 0;

    virtual antlrcpp::Any visitConditionExpr(RuleParser::ConditionExprContext *context) = 0;

    virtual antlrcpp::Any visitLogicalOperator(RuleParser::LogicalOperatorContext *context) = 0;

    virtual antlrcpp::Any visitBasicCondExpr(RuleParser::BasicCondExprContext *context) = 0;

    virtual antlrcpp::Any visitExpr(RuleParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitAssignStmt(RuleParser::AssignStmtContext *context) = 0;

    virtual antlrcpp::Any visitAssignExpr(RuleParser::AssignExprContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(RuleParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitSequentialStmt(RuleParser::SequentialStmtContext *context) = 0;

    virtual antlrcpp::Any visitSequentialExpr(RuleParser::SequentialExprContext *context) = 0;

    virtual antlrcpp::Any visitDateStmt(RuleParser::DateStmtContext *context) = 0;

    virtual antlrcpp::Any visitDateExpr(RuleParser::DateExprContext *context) = 0;

    virtual antlrcpp::Any visitTimeStmt(RuleParser::TimeStmtContext *context) = 0;

    virtual antlrcpp::Any visitTimeExpr(RuleParser::TimeExprContext *context) = 0;

    virtual antlrcpp::Any visitEos(RuleParser::EosContext *context) = 0;


};

