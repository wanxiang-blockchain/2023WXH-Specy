
// Generated from RuleParser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "RuleParserListener.h"


/**
 * This class provides an empty implementation of RuleParserListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  RuleParserBaseListener : public RuleParserListener {
public:

  virtual void enterRoot(RuleParser::RootContext * /*ctx*/) override { }
  virtual void exitRoot(RuleParser::RootContext * /*ctx*/) override { }

  virtual void enterTaskDecl(RuleParser::TaskDeclContext * /*ctx*/) override { }
  virtual void exitTaskDecl(RuleParser::TaskDeclContext * /*ctx*/) override { }

  virtual void enterInputBlock(RuleParser::InputBlockContext * /*ctx*/) override { }
  virtual void exitInputBlock(RuleParser::InputBlockContext * /*ctx*/) override { }

  virtual void enterOutputBlock(RuleParser::OutputBlockContext * /*ctx*/) override { }
  virtual void exitOutputBlock(RuleParser::OutputBlockContext * /*ctx*/) override { }

  virtual void enterOutputDecl(RuleParser::OutputDeclContext * /*ctx*/) override { }
  virtual void exitOutputDecl(RuleParser::OutputDeclContext * /*ctx*/) override { }

  virtual void enterOutputAttribute(RuleParser::OutputAttributeContext * /*ctx*/) override { }
  virtual void exitOutputAttribute(RuleParser::OutputAttributeContext * /*ctx*/) override { }

  virtual void enterOutputObject(RuleParser::OutputObjectContext * /*ctx*/) override { }
  virtual void exitOutputObject(RuleParser::OutputObjectContext * /*ctx*/) override { }

  virtual void enterObjectName(RuleParser::ObjectNameContext * /*ctx*/) override { }
  virtual void exitObjectName(RuleParser::ObjectNameContext * /*ctx*/) override { }

  virtual void enterEntitiesBlock(RuleParser::EntitiesBlockContext * /*ctx*/) override { }
  virtual void exitEntitiesBlock(RuleParser::EntitiesBlockContext * /*ctx*/) override { }

  virtual void enterEntityList(RuleParser::EntityListContext * /*ctx*/) override { }
  virtual void exitEntityList(RuleParser::EntityListContext * /*ctx*/) override { }

  virtual void enterEntityDecl(RuleParser::EntityDeclContext * /*ctx*/) override { }
  virtual void exitEntityDecl(RuleParser::EntityDeclContext * /*ctx*/) override { }

  virtual void enterEntityName(RuleParser::EntityNameContext * /*ctx*/) override { }
  virtual void exitEntityName(RuleParser::EntityNameContext * /*ctx*/) override { }

  virtual void enterAttributeList(RuleParser::AttributeListContext * /*ctx*/) override { }
  virtual void exitAttributeList(RuleParser::AttributeListContext * /*ctx*/) override { }

  virtual void enterAttributeDecl(RuleParser::AttributeDeclContext * /*ctx*/) override { }
  virtual void exitAttributeDecl(RuleParser::AttributeDeclContext * /*ctx*/) override { }

  virtual void enterAttributeName(RuleParser::AttributeNameContext * /*ctx*/) override { }
  virtual void exitAttributeName(RuleParser::AttributeNameContext * /*ctx*/) override { }

  virtual void enterTypeAnno(RuleParser::TypeAnnoContext * /*ctx*/) override { }
  virtual void exitTypeAnno(RuleParser::TypeAnnoContext * /*ctx*/) override { }

  virtual void enterBasicType(RuleParser::BasicTypeContext * /*ctx*/) override { }
  virtual void exitBasicType(RuleParser::BasicTypeContext * /*ctx*/) override { }

  virtual void enterCompositeType(RuleParser::CompositeTypeContext * /*ctx*/) override { }
  virtual void exitCompositeType(RuleParser::CompositeTypeContext * /*ctx*/) override { }

  virtual void enterListType(RuleParser::ListTypeContext * /*ctx*/) override { }
  virtual void exitListType(RuleParser::ListTypeContext * /*ctx*/) override { }

  virtual void enterExecutionBlock(RuleParser::ExecutionBlockContext * /*ctx*/) override { }
  virtual void exitExecutionBlock(RuleParser::ExecutionBlockContext * /*ctx*/) override { }

  virtual void enterExecutionStmt(RuleParser::ExecutionStmtContext * /*ctx*/) override { }
  virtual void exitExecutionStmt(RuleParser::ExecutionStmtContext * /*ctx*/) override { }

  virtual void enterExecuteRuleDef(RuleParser::ExecuteRuleDefContext * /*ctx*/) override { }
  virtual void exitExecuteRuleDef(RuleParser::ExecuteRuleDefContext * /*ctx*/) override { }

  virtual void enterExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext * /*ctx*/) override { }
  virtual void exitExecutionTrueStmt(RuleParser::ExecutionTrueStmtContext * /*ctx*/) override { }

  virtual void enterExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext * /*ctx*/) override { }
  virtual void exitExecutionFalseStmt(RuleParser::ExecutionFalseStmtContext * /*ctx*/) override { }

  virtual void enterRulesBlock(RuleParser::RulesBlockContext * /*ctx*/) override { }
  virtual void exitRulesBlock(RuleParser::RulesBlockContext * /*ctx*/) override { }

  virtual void enterRuleList(RuleParser::RuleListContext * /*ctx*/) override { }
  virtual void exitRuleList(RuleParser::RuleListContext * /*ctx*/) override { }

  virtual void enterBasicRule(RuleParser::BasicRuleContext * /*ctx*/) override { }
  virtual void exitBasicRule(RuleParser::BasicRuleContext * /*ctx*/) override { }

  virtual void enterRuleName(RuleParser::RuleNameContext * /*ctx*/) override { }
  virtual void exitRuleName(RuleParser::RuleNameContext * /*ctx*/) override { }

  virtual void enterRuleStmtList(RuleParser::RuleStmtListContext * /*ctx*/) override { }
  virtual void exitRuleStmtList(RuleParser::RuleStmtListContext * /*ctx*/) override { }

  virtual void enterRuleStmt(RuleParser::RuleStmtContext * /*ctx*/) override { }
  virtual void exitRuleStmt(RuleParser::RuleStmtContext * /*ctx*/) override { }

  virtual void enterSimpleStmt(RuleParser::SimpleStmtContext * /*ctx*/) override { }
  virtual void exitSimpleStmt(RuleParser::SimpleStmtContext * /*ctx*/) override { }

  virtual void enterComplexStmt(RuleParser::ComplexStmtContext * /*ctx*/) override { }
  virtual void exitComplexStmt(RuleParser::ComplexStmtContext * /*ctx*/) override { }

  virtual void enterListStmt(RuleParser::ListStmtContext * /*ctx*/) override { }
  virtual void exitListStmt(RuleParser::ListStmtContext * /*ctx*/) override { }

  virtual void enterListExpr(RuleParser::ListExprContext * /*ctx*/) override { }
  virtual void exitListExpr(RuleParser::ListExprContext * /*ctx*/) override { }

  virtual void enterRelationStmt(RuleParser::RelationStmtContext * /*ctx*/) override { }
  virtual void exitRelationStmt(RuleParser::RelationStmtContext * /*ctx*/) override { }

  virtual void enterRelationExpr(RuleParser::RelationExprContext * /*ctx*/) override { }
  virtual void exitRelationExpr(RuleParser::RelationExprContext * /*ctx*/) override { }

  virtual void enterRelationOperator(RuleParser::RelationOperatorContext * /*ctx*/) override { }
  virtual void exitRelationOperator(RuleParser::RelationOperatorContext * /*ctx*/) override { }

  virtual void enterNumberExpr(RuleParser::NumberExprContext * /*ctx*/) override { }
  virtual void exitNumberExpr(RuleParser::NumberExprContext * /*ctx*/) override { }

  virtual void enterSelectorIdent(RuleParser::SelectorIdentContext * /*ctx*/) override { }
  virtual void exitSelectorIdent(RuleParser::SelectorIdentContext * /*ctx*/) override { }

  virtual void enterAggregationExpr(RuleParser::AggregationExprContext * /*ctx*/) override { }
  virtual void exitAggregationExpr(RuleParser::AggregationExprContext * /*ctx*/) override { }

  virtual void enterBooleanExpr(RuleParser::BooleanExprContext * /*ctx*/) override { }
  virtual void exitBooleanExpr(RuleParser::BooleanExprContext * /*ctx*/) override { }

  virtual void enterBooleanLiteral(RuleParser::BooleanLiteralContext * /*ctx*/) override { }
  virtual void exitBooleanLiteral(RuleParser::BooleanLiteralContext * /*ctx*/) override { }

  virtual void enterLogicalStmt(RuleParser::LogicalStmtContext * /*ctx*/) override { }
  virtual void exitLogicalStmt(RuleParser::LogicalStmtContext * /*ctx*/) override { }

  virtual void enterLogicalExpr(RuleParser::LogicalExprContext * /*ctx*/) override { }
  virtual void exitLogicalExpr(RuleParser::LogicalExprContext * /*ctx*/) override { }

  virtual void enterDefinitionStmt(RuleParser::DefinitionStmtContext * /*ctx*/) override { }
  virtual void exitDefinitionStmt(RuleParser::DefinitionStmtContext * /*ctx*/) override { }

  virtual void enterInstanceName(RuleParser::InstanceNameContext * /*ctx*/) override { }
  virtual void exitInstanceName(RuleParser::InstanceNameContext * /*ctx*/) override { }

  virtual void enterQueryExpr(RuleParser::QueryExprContext * /*ctx*/) override { }
  virtual void exitQueryExpr(RuleParser::QueryExprContext * /*ctx*/) override { }

  virtual void enterConditionExpr(RuleParser::ConditionExprContext * /*ctx*/) override { }
  virtual void exitConditionExpr(RuleParser::ConditionExprContext * /*ctx*/) override { }

  virtual void enterLogicalOperator(RuleParser::LogicalOperatorContext * /*ctx*/) override { }
  virtual void exitLogicalOperator(RuleParser::LogicalOperatorContext * /*ctx*/) override { }

  virtual void enterBasicCondExpr(RuleParser::BasicCondExprContext * /*ctx*/) override { }
  virtual void exitBasicCondExpr(RuleParser::BasicCondExprContext * /*ctx*/) override { }

  virtual void enterExpr(RuleParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(RuleParser::ExprContext * /*ctx*/) override { }

  virtual void enterAssignStmt(RuleParser::AssignStmtContext * /*ctx*/) override { }
  virtual void exitAssignStmt(RuleParser::AssignStmtContext * /*ctx*/) override { }

  virtual void enterAssignExpr(RuleParser::AssignExprContext * /*ctx*/) override { }
  virtual void exitAssignExpr(RuleParser::AssignExprContext * /*ctx*/) override { }

  virtual void enterIfStmt(RuleParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(RuleParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterSequentialStmt(RuleParser::SequentialStmtContext * /*ctx*/) override { }
  virtual void exitSequentialStmt(RuleParser::SequentialStmtContext * /*ctx*/) override { }

  virtual void enterSequentialExpr(RuleParser::SequentialExprContext * /*ctx*/) override { }
  virtual void exitSequentialExpr(RuleParser::SequentialExprContext * /*ctx*/) override { }

  virtual void enterDateStmt(RuleParser::DateStmtContext * /*ctx*/) override { }
  virtual void exitDateStmt(RuleParser::DateStmtContext * /*ctx*/) override { }

  virtual void enterDateExpr(RuleParser::DateExprContext * /*ctx*/) override { }
  virtual void exitDateExpr(RuleParser::DateExprContext * /*ctx*/) override { }

  virtual void enterTimeStmt(RuleParser::TimeStmtContext * /*ctx*/) override { }
  virtual void exitTimeStmt(RuleParser::TimeStmtContext * /*ctx*/) override { }

  virtual void enterTimeExpr(RuleParser::TimeExprContext * /*ctx*/) override { }
  virtual void exitTimeExpr(RuleParser::TimeExprContext * /*ctx*/) override { }

  virtual void enterEos(RuleParser::EosContext * /*ctx*/) override { }
  virtual void exitEos(RuleParser::EosContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

