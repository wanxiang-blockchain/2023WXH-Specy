
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "RuleParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by RuleParser.
 */
class  RuleParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterRoot(RuleParser::RootContext *ctx) = 0;
  virtual void exitRoot(RuleParser::RootContext *ctx) = 0;

  virtual void enterTaskDecl(RuleParser::TaskDeclContext *ctx) = 0;
  virtual void exitTaskDecl(RuleParser::TaskDeclContext *ctx) = 0;

  virtual void enterInputBlock(RuleParser::InputBlockContext *ctx) = 0;
  virtual void exitInputBlock(RuleParser::InputBlockContext *ctx) = 0;

  virtual void enterOutputBlock(RuleParser::OutputBlockContext *ctx) = 0;
  virtual void exitOutputBlock(RuleParser::OutputBlockContext *ctx) = 0;

  virtual void enterOutputDecl(RuleParser::OutputDeclContext *ctx) = 0;
  virtual void exitOutputDecl(RuleParser::OutputDeclContext *ctx) = 0;

  virtual void enterOutputAttribute(RuleParser::OutputAttributeContext *ctx) = 0;
  virtual void exitOutputAttribute(RuleParser::OutputAttributeContext *ctx) = 0;

  virtual void enterOutputObject(RuleParser::OutputObjectContext *ctx) = 0;
  virtual void exitOutputObject(RuleParser::OutputObjectContext *ctx) = 0;

  virtual void enterObjectName(RuleParser::ObjectNameContext *ctx) = 0;
  virtual void exitObjectName(RuleParser::ObjectNameContext *ctx) = 0;

  virtual void enterEntitiesBlock(RuleParser::EntitiesBlockContext *ctx) = 0;
  virtual void exitEntitiesBlock(RuleParser::EntitiesBlockContext *ctx) = 0;

  virtual void enterEntityList(RuleParser::EntityListContext *ctx) = 0;
  virtual void exitEntityList(RuleParser::EntityListContext *ctx) = 0;

  virtual void enterEntityDecl(RuleParser::EntityDeclContext *ctx) = 0;
  virtual void exitEntityDecl(RuleParser::EntityDeclContext *ctx) = 0;

  virtual void enterEntityName(RuleParser::EntityNameContext *ctx) = 0;
  virtual void exitEntityName(RuleParser::EntityNameContext *ctx) = 0;

  virtual void enterAttributeList(RuleParser::AttributeListContext *ctx) = 0;
  virtual void exitAttributeList(RuleParser::AttributeListContext *ctx) = 0;

  virtual void enterAttributeDecl(RuleParser::AttributeDeclContext *ctx) = 0;
  virtual void exitAttributeDecl(RuleParser::AttributeDeclContext *ctx) = 0;

  virtual void enterAttributeName(RuleParser::AttributeNameContext *ctx) = 0;
  virtual void exitAttributeName(RuleParser::AttributeNameContext *ctx) = 0;

  virtual void enterTypeAnno(RuleParser::TypeAnnoContext *ctx) = 0;
  virtual void exitTypeAnno(RuleParser::TypeAnnoContext *ctx) = 0;

  virtual void enterBasicType(RuleParser::BasicTypeContext *ctx) = 0;
  virtual void exitBasicType(RuleParser::BasicTypeContext *ctx) = 0;

  virtual void enterCompositeType(RuleParser::CompositeTypeContext *ctx) = 0;
  virtual void exitCompositeType(RuleParser::CompositeTypeContext *ctx) = 0;

  virtual void enterListType(RuleParser::ListTypeContext *ctx) = 0;
  virtual void exitListType(RuleParser::ListTypeContext *ctx) = 0;

  virtual void enterExecutionBlock(RuleParser::ExecutionBlockContext *ctx) = 0;
  virtual void exitExecutionBlock(RuleParser::ExecutionBlockContext *ctx) = 0;

  virtual void enterExecutionStmt(RuleParser::ExecutionStmtContext *ctx) = 0;
  virtual void exitExecutionStmt(RuleParser::ExecutionStmtContext *ctx) = 0;

  virtual void enterExecuteRuleDef(RuleParser::ExecuteRuleDefContext *ctx) = 0;
  virtual void exitExecuteRuleDef(RuleParser::ExecuteRuleDefContext *ctx) = 0;

  virtual void enterExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext *ctx) = 0;
  virtual void exitExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext *ctx) = 0;

  virtual void enterExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext *ctx) = 0;
  virtual void exitExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext *ctx) = 0;

  virtual void enterRulesBlock(RuleParser::RulesBlockContext *ctx) = 0;
  virtual void exitRulesBlock(RuleParser::RulesBlockContext *ctx) = 0;

  virtual void enterRuleList(RuleParser::RuleListContext *ctx) = 0;
  virtual void exitRuleList(RuleParser::RuleListContext *ctx) = 0;

  virtual void enterBasicRule(RuleParser::BasicRuleContext *ctx) = 0;
  virtual void exitBasicRule(RuleParser::BasicRuleContext *ctx) = 0;

  virtual void enterRuleName(RuleParser::RuleNameContext *ctx) = 0;
  virtual void exitRuleName(RuleParser::RuleNameContext *ctx) = 0;

  virtual void enterRuleStmtList(RuleParser::RuleStmtListContext *ctx) = 0;
  virtual void exitRuleStmtList(RuleParser::RuleStmtListContext *ctx) = 0;

  virtual void enterRuleStmt(RuleParser::RuleStmtContext *ctx) = 0;
  virtual void exitRuleStmt(RuleParser::RuleStmtContext *ctx) = 0;

  virtual void enterSimpleStmt(RuleParser::SimpleStmtContext *ctx) = 0;
  virtual void exitSimpleStmt(RuleParser::SimpleStmtContext *ctx) = 0;

  virtual void enterComplexStmt(RuleParser::ComplexStmtContext *ctx) = 0;
  virtual void exitComplexStmt(RuleParser::ComplexStmtContext *ctx) = 0;

  virtual void enterListStmt(RuleParser::ListStmtContext *ctx) = 0;
  virtual void exitListStmt(RuleParser::ListStmtContext *ctx) = 0;

  virtual void enterListExpr(RuleParser::ListExprContext *ctx) = 0;
  virtual void exitListExpr(RuleParser::ListExprContext *ctx) = 0;

  virtual void enterRelationStmt(RuleParser::RelationStmtContext *ctx) = 0;
  virtual void exitRelationStmt(RuleParser::RelationStmtContext *ctx) = 0;

  virtual void enterRelationExpr(RuleParser::RelationExprContext *ctx) = 0;
  virtual void exitRelationExpr(RuleParser::RelationExprContext *ctx) = 0;

  virtual void enterRelationOperator(RuleParser::RelationOperatorContext *ctx) = 0;
  virtual void exitRelationOperator(RuleParser::RelationOperatorContext *ctx) = 0;

  virtual void enterNumberExpr(RuleParser::NumberExprContext *ctx) = 0;
  virtual void exitNumberExpr(RuleParser::NumberExprContext *ctx) = 0;

  virtual void enterSelectorIdent(RuleParser::SelectorIdentContext *ctx) = 0;
  virtual void exitSelectorIdent(RuleParser::SelectorIdentContext *ctx) = 0;

  virtual void enterAggregationExpr(RuleParser::AggregationExprContext *ctx) = 0;
  virtual void exitAggregationExpr(RuleParser::AggregationExprContext *ctx) = 0;

  virtual void enterBooleanExpr(RuleParser::BooleanExprContext *ctx) = 0;
  virtual void exitBooleanExpr(RuleParser::BooleanExprContext *ctx) = 0;

  virtual void enterBooleanLiteral(RuleParser::BooleanLiteralContext *ctx) = 0;
  virtual void exitBooleanLiteral(RuleParser::BooleanLiteralContext *ctx) = 0;

  virtual void enterLogicalStmt(RuleParser::LogicalStmtContext *ctx) = 0;
  virtual void exitLogicalStmt(RuleParser::LogicalStmtContext *ctx) = 0;

  virtual void enterLogicalExpr(RuleParser::LogicalExprContext *ctx) = 0;
  virtual void exitLogicalExpr(RuleParser::LogicalExprContext *ctx) = 0;

  virtual void enterDefinitionStmt(RuleParser::DefinitionStmtContext *ctx) = 0;
  virtual void exitDefinitionStmt(RuleParser::DefinitionStmtContext *ctx) = 0;

  virtual void enterInstanceName(RuleParser::InstanceNameContext *ctx) = 0;
  virtual void exitInstanceName(RuleParser::InstanceNameContext *ctx) = 0;

  virtual void enterQueryExpr(RuleParser::QueryExprContext *ctx) = 0;
  virtual void exitQueryExpr(RuleParser::QueryExprContext *ctx) = 0;

  virtual void enterConditionExpr(RuleParser::ConditionExprContext *ctx) = 0;
  virtual void exitConditionExpr(RuleParser::ConditionExprContext *ctx) = 0;

  virtual void enterLogicalOperator(RuleParser::LogicalOperatorContext *ctx) = 0;
  virtual void exitLogicalOperator(RuleParser::LogicalOperatorContext *ctx) = 0;

  virtual void enterBasicCondExpr(RuleParser::BasicCondExprContext *ctx) = 0;
  virtual void exitBasicCondExpr(RuleParser::BasicCondExprContext *ctx) = 0;

  virtual void enterExpr(RuleParser::ExprContext *ctx) = 0;
  virtual void exitExpr(RuleParser::ExprContext *ctx) = 0;

  virtual void enterAssignStmt(RuleParser::AssignStmtContext *ctx) = 0;
  virtual void exitAssignStmt(RuleParser::AssignStmtContext *ctx) = 0;

  virtual void enterAssignExpr(RuleParser::AssignExprContext *ctx) = 0;
  virtual void exitAssignExpr(RuleParser::AssignExprContext *ctx) = 0;

  virtual void enterIfStmt(RuleParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(RuleParser::IfStmtContext *ctx) = 0;

  virtual void enterSequentialStmt(RuleParser::SequentialStmtContext *ctx) = 0;
  virtual void exitSequentialStmt(RuleParser::SequentialStmtContext *ctx) = 0;

  virtual void enterSequentialExpr(RuleParser::SequentialExprContext *ctx) = 0;
  virtual void exitSequentialExpr(RuleParser::SequentialExprContext *ctx) = 0;

  virtual void enterDateStmt(RuleParser::DateStmtContext *ctx) = 0;
  virtual void exitDateStmt(RuleParser::DateStmtContext *ctx) = 0;

  virtual void enterDateExpr(RuleParser::DateExprContext *ctx) = 0;
  virtual void exitDateExpr(RuleParser::DateExprContext *ctx) = 0;

  virtual void enterTimeStmt(RuleParser::TimeStmtContext *ctx) = 0;
  virtual void exitTimeStmt(RuleParser::TimeStmtContext *ctx) = 0;

  virtual void enterTimeExpr(RuleParser::TimeExprContext *ctx) = 0;
  virtual void exitTimeExpr(RuleParser::TimeExprContext *ctx) = 0;

  virtual void enterEos(RuleParser::EosContext *ctx) = 0;
  virtual void exitEos(RuleParser::EosContext *ctx) = 0;


};

