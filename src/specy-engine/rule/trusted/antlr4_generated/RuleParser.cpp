
// Generated from RuleParser.g4 by ANTLR 4.9.1


#include "RuleParserListener.h"
#include "RuleParserVisitor.h"

#include "RuleParser.h"


using namespace antlrcpp;
using namespace antlr4;

RuleParser::RuleParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

RuleParser::~RuleParser() {
  delete _interpreter;
}

std::string RuleParser::getGrammarFileName() const {
  return "RuleParser.g4";
}

const std::vector<std::string>& RuleParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& RuleParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- RootContext ------------------------------------------------------------------

RuleParser::RootContext::RootContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::TaskDeclContext* RuleParser::RootContext::taskDecl() {
  return getRuleContext<RuleParser::TaskDeclContext>(0);
}

RuleParser::EntitiesBlockContext* RuleParser::RootContext::entitiesBlock() {
  return getRuleContext<RuleParser::EntitiesBlockContext>(0);
}

RuleParser::RulesBlockContext* RuleParser::RootContext::rulesBlock() {
  return getRuleContext<RuleParser::RulesBlockContext>(0);
}

RuleParser::ExecutionBlockContext* RuleParser::RootContext::executionBlock() {
  return getRuleContext<RuleParser::ExecutionBlockContext>(0);
}

tree::TerminalNode* RuleParser::RootContext::EOF() {
  return getToken(RuleParser::EOF, 0);
}

RuleParser::InputBlockContext* RuleParser::RootContext::inputBlock() {
  return getRuleContext<RuleParser::InputBlockContext>(0);
}

RuleParser::OutputBlockContext* RuleParser::RootContext::outputBlock() {
  return getRuleContext<RuleParser::OutputBlockContext>(0);
}


size_t RuleParser::RootContext::getRuleIndex() const {
  return RuleParser::RuleRoot;
}

void RuleParser::RootContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoot(this);
}

void RuleParser::RootContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoot(this);
}


antlrcpp::Any RuleParser::RootContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRoot(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RootContext* RuleParser::root() {
  RootContext *_localctx = _tracker.createInstance<RootContext>(_ctx, getState());
  enterRule(_localctx, 0, RuleParser::RuleRoot);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(132);
    taskDecl();
    setState(133);
    entitiesBlock();
    setState(135);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::INPUT) {
      setState(134);
      inputBlock();
    }
    setState(138);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::OUTPUT) {
      setState(137);
      outputBlock();
    }
    setState(140);
    rulesBlock();
    setState(141);
    executionBlock();
    setState(142);
    match(RuleParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TaskDeclContext ------------------------------------------------------------------

RuleParser::TaskDeclContext::TaskDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::TaskDeclContext::TASK() {
  return getToken(RuleParser::TASK, 0);
}

std::vector<tree::TerminalNode *> RuleParser::TaskDeclContext::IDENTIFIER() {
  return getTokens(RuleParser::IDENTIFIER);
}

tree::TerminalNode* RuleParser::TaskDeclContext::IDENTIFIER(size_t i) {
  return getToken(RuleParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> RuleParser::TaskDeclContext::DOT() {
  return getTokens(RuleParser::DOT);
}

tree::TerminalNode* RuleParser::TaskDeclContext::DOT(size_t i) {
  return getToken(RuleParser::DOT, i);
}


size_t RuleParser::TaskDeclContext::getRuleIndex() const {
  return RuleParser::RuleTaskDecl;
}

void RuleParser::TaskDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTaskDecl(this);
}

void RuleParser::TaskDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTaskDecl(this);
}


antlrcpp::Any RuleParser::TaskDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitTaskDecl(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::TaskDeclContext* RuleParser::taskDecl() {
  TaskDeclContext *_localctx = _tracker.createInstance<TaskDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, RuleParser::RuleTaskDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(RuleParser::TASK);
    setState(145);
    match(RuleParser::IDENTIFIER);
    setState(150);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RuleParser::DOT) {
      setState(146);
      match(RuleParser::DOT);
      setState(147);
      match(RuleParser::IDENTIFIER);
      setState(152);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InputBlockContext ------------------------------------------------------------------

RuleParser::InputBlockContext::InputBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::InputBlockContext::INPUT() {
  return getToken(RuleParser::INPUT, 0);
}

tree::TerminalNode* RuleParser::InputBlockContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::AttributeListContext* RuleParser::InputBlockContext::attributeList() {
  return getRuleContext<RuleParser::AttributeListContext>(0);
}

tree::TerminalNode* RuleParser::InputBlockContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::InputBlockContext::getRuleIndex() const {
  return RuleParser::RuleInputBlock;
}

void RuleParser::InputBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInputBlock(this);
}

void RuleParser::InputBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInputBlock(this);
}


antlrcpp::Any RuleParser::InputBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitInputBlock(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::InputBlockContext* RuleParser::inputBlock() {
  InputBlockContext *_localctx = _tracker.createInstance<InputBlockContext>(_ctx, getState());
  enterRule(_localctx, 4, RuleParser::RuleInputBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    match(RuleParser::INPUT);
    setState(154);
    match(RuleParser::L_CURLY);
    setState(155);
    attributeList();
    setState(156);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputBlockContext ------------------------------------------------------------------

RuleParser::OutputBlockContext::OutputBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::OutputBlockContext::OUTPUT() {
  return getToken(RuleParser::OUTPUT, 0);
}

tree::TerminalNode* RuleParser::OutputBlockContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

tree::TerminalNode* RuleParser::OutputBlockContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}

std::vector<RuleParser::OutputDeclContext *> RuleParser::OutputBlockContext::outputDecl() {
  return getRuleContexts<RuleParser::OutputDeclContext>();
}

RuleParser::OutputDeclContext* RuleParser::OutputBlockContext::outputDecl(size_t i) {
  return getRuleContext<RuleParser::OutputDeclContext>(i);
}


size_t RuleParser::OutputBlockContext::getRuleIndex() const {
  return RuleParser::RuleOutputBlock;
}

void RuleParser::OutputBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutputBlock(this);
}

void RuleParser::OutputBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutputBlock(this);
}


antlrcpp::Any RuleParser::OutputBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitOutputBlock(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::OutputBlockContext* RuleParser::outputBlock() {
  OutputBlockContext *_localctx = _tracker.createInstance<OutputBlockContext>(_ctx, getState());
  enterRule(_localctx, 6, RuleParser::RuleOutputBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    match(RuleParser::OUTPUT);
    setState(159);
    match(RuleParser::L_CURLY);
    setState(161); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(160);
      outputDecl();
      setState(163); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::IDENTIFIER);
    setState(165);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputDeclContext ------------------------------------------------------------------

RuleParser::OutputDeclContext::OutputDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::OutputAttributeContext* RuleParser::OutputDeclContext::outputAttribute() {
  return getRuleContext<RuleParser::OutputAttributeContext>(0);
}

RuleParser::OutputObjectContext* RuleParser::OutputDeclContext::outputObject() {
  return getRuleContext<RuleParser::OutputObjectContext>(0);
}


size_t RuleParser::OutputDeclContext::getRuleIndex() const {
  return RuleParser::RuleOutputDecl;
}

void RuleParser::OutputDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutputDecl(this);
}

void RuleParser::OutputDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutputDecl(this);
}


antlrcpp::Any RuleParser::OutputDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitOutputDecl(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::OutputDeclContext* RuleParser::outputDecl() {
  OutputDeclContext *_localctx = _tracker.createInstance<OutputDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, RuleParser::RuleOutputDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(169);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(167);
      outputAttribute();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(168);
      outputObject();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputAttributeContext ------------------------------------------------------------------

RuleParser::OutputAttributeContext::OutputAttributeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::AttributeNameContext* RuleParser::OutputAttributeContext::attributeName() {
  return getRuleContext<RuleParser::AttributeNameContext>(0);
}

tree::TerminalNode* RuleParser::OutputAttributeContext::IS() {
  return getToken(RuleParser::IS, 0);
}

RuleParser::TypeAnnoContext* RuleParser::OutputAttributeContext::typeAnno() {
  return getRuleContext<RuleParser::TypeAnnoContext>(0);
}


size_t RuleParser::OutputAttributeContext::getRuleIndex() const {
  return RuleParser::RuleOutputAttribute;
}

void RuleParser::OutputAttributeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutputAttribute(this);
}

void RuleParser::OutputAttributeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutputAttribute(this);
}


antlrcpp::Any RuleParser::OutputAttributeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitOutputAttribute(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::OutputAttributeContext* RuleParser::outputAttribute() {
  OutputAttributeContext *_localctx = _tracker.createInstance<OutputAttributeContext>(_ctx, getState());
  enterRule(_localctx, 10, RuleParser::RuleOutputAttribute);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    attributeName();
    setState(172);
    match(RuleParser::IS);
    setState(173);
    typeAnno();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OutputObjectContext ------------------------------------------------------------------

RuleParser::OutputObjectContext::OutputObjectContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::ObjectNameContext* RuleParser::OutputObjectContext::objectName() {
  return getRuleContext<RuleParser::ObjectNameContext>(0);
}

tree::TerminalNode* RuleParser::OutputObjectContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

tree::TerminalNode* RuleParser::OutputObjectContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}

std::vector<RuleParser::OutputDeclContext *> RuleParser::OutputObjectContext::outputDecl() {
  return getRuleContexts<RuleParser::OutputDeclContext>();
}

RuleParser::OutputDeclContext* RuleParser::OutputObjectContext::outputDecl(size_t i) {
  return getRuleContext<RuleParser::OutputDeclContext>(i);
}


size_t RuleParser::OutputObjectContext::getRuleIndex() const {
  return RuleParser::RuleOutputObject;
}

void RuleParser::OutputObjectContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOutputObject(this);
}

void RuleParser::OutputObjectContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOutputObject(this);
}


antlrcpp::Any RuleParser::OutputObjectContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitOutputObject(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::OutputObjectContext* RuleParser::outputObject() {
  OutputObjectContext *_localctx = _tracker.createInstance<OutputObjectContext>(_ctx, getState());
  enterRule(_localctx, 12, RuleParser::RuleOutputObject);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(175);
    objectName();
    setState(176);
    match(RuleParser::L_CURLY);
    setState(178); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(177);
      outputDecl();
      setState(180); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::IDENTIFIER);
    setState(182);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ObjectNameContext ------------------------------------------------------------------

RuleParser::ObjectNameContext::ObjectNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::ObjectNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::ObjectNameContext::getRuleIndex() const {
  return RuleParser::RuleObjectName;
}

void RuleParser::ObjectNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterObjectName(this);
}

void RuleParser::ObjectNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitObjectName(this);
}


antlrcpp::Any RuleParser::ObjectNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitObjectName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ObjectNameContext* RuleParser::objectName() {
  ObjectNameContext *_localctx = _tracker.createInstance<ObjectNameContext>(_ctx, getState());
  enterRule(_localctx, 14, RuleParser::RuleObjectName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(184);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntitiesBlockContext ------------------------------------------------------------------

RuleParser::EntitiesBlockContext::EntitiesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::EntitiesBlockContext::ENTITIES() {
  return getToken(RuleParser::ENTITIES, 0);
}

tree::TerminalNode* RuleParser::EntitiesBlockContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}

tree::TerminalNode* RuleParser::EntitiesBlockContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::EntityListContext* RuleParser::EntitiesBlockContext::entityList() {
  return getRuleContext<RuleParser::EntityListContext>(0);
}

tree::TerminalNode* RuleParser::EntitiesBlockContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::EntitiesBlockContext::getRuleIndex() const {
  return RuleParser::RuleEntitiesBlock;
}

void RuleParser::EntitiesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntitiesBlock(this);
}

void RuleParser::EntitiesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntitiesBlock(this);
}


antlrcpp::Any RuleParser::EntitiesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntitiesBlock(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntitiesBlockContext* RuleParser::entitiesBlock() {
  EntitiesBlockContext *_localctx = _tracker.createInstance<EntitiesBlockContext>(_ctx, getState());
  enterRule(_localctx, 16, RuleParser::RuleEntitiesBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(186);
    match(RuleParser::ENTITIES);
    setState(187);
    match(RuleParser::IDENTIFIER);
    setState(188);
    match(RuleParser::L_CURLY);
    setState(189);
    entityList();
    setState(190);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntityListContext ------------------------------------------------------------------

RuleParser::EntityListContext::EntityListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::EntityDeclContext *> RuleParser::EntityListContext::entityDecl() {
  return getRuleContexts<RuleParser::EntityDeclContext>();
}

RuleParser::EntityDeclContext* RuleParser::EntityListContext::entityDecl(size_t i) {
  return getRuleContext<RuleParser::EntityDeclContext>(i);
}


size_t RuleParser::EntityListContext::getRuleIndex() const {
  return RuleParser::RuleEntityList;
}

void RuleParser::EntityListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntityList(this);
}

void RuleParser::EntityListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntityList(this);
}


antlrcpp::Any RuleParser::EntityListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntityList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntityListContext* RuleParser::entityList() {
  EntityListContext *_localctx = _tracker.createInstance<EntityListContext>(_ctx, getState());
  enterRule(_localctx, 18, RuleParser::RuleEntityList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(193); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(192);
      entityDecl();
      setState(195); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::ENTITY

    || _la == RuleParser::UNIQUE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntityDeclContext ------------------------------------------------------------------

RuleParser::EntityDeclContext::EntityDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::EntityDeclContext::ENTITY() {
  return getToken(RuleParser::ENTITY, 0);
}

RuleParser::EntityNameContext* RuleParser::EntityDeclContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

tree::TerminalNode* RuleParser::EntityDeclContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::AttributeListContext* RuleParser::EntityDeclContext::attributeList() {
  return getRuleContext<RuleParser::AttributeListContext>(0);
}

tree::TerminalNode* RuleParser::EntityDeclContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}

tree::TerminalNode* RuleParser::EntityDeclContext::UNIQUE() {
  return getToken(RuleParser::UNIQUE, 0);
}


size_t RuleParser::EntityDeclContext::getRuleIndex() const {
  return RuleParser::RuleEntityDecl;
}

void RuleParser::EntityDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntityDecl(this);
}

void RuleParser::EntityDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntityDecl(this);
}


antlrcpp::Any RuleParser::EntityDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntityDecl(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntityDeclContext* RuleParser::entityDecl() {
  EntityDeclContext *_localctx = _tracker.createInstance<EntityDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, RuleParser::RuleEntityDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::UNIQUE) {
      setState(197);
      match(RuleParser::UNIQUE);
    }
    setState(200);
    match(RuleParser::ENTITY);
    setState(201);
    entityName();
    setState(202);
    match(RuleParser::L_CURLY);
    setState(203);
    attributeList();
    setState(204);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EntityNameContext ------------------------------------------------------------------

RuleParser::EntityNameContext::EntityNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::EntityNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::EntityNameContext::getRuleIndex() const {
  return RuleParser::RuleEntityName;
}

void RuleParser::EntityNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEntityName(this);
}

void RuleParser::EntityNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEntityName(this);
}


antlrcpp::Any RuleParser::EntityNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEntityName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EntityNameContext* RuleParser::entityName() {
  EntityNameContext *_localctx = _tracker.createInstance<EntityNameContext>(_ctx, getState());
  enterRule(_localctx, 22, RuleParser::RuleEntityName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeListContext ------------------------------------------------------------------

RuleParser::AttributeListContext::AttributeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::AttributeDeclContext *> RuleParser::AttributeListContext::attributeDecl() {
  return getRuleContexts<RuleParser::AttributeDeclContext>();
}

RuleParser::AttributeDeclContext* RuleParser::AttributeListContext::attributeDecl(size_t i) {
  return getRuleContext<RuleParser::AttributeDeclContext>(i);
}


size_t RuleParser::AttributeListContext::getRuleIndex() const {
  return RuleParser::RuleAttributeList;
}

void RuleParser::AttributeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeList(this);
}

void RuleParser::AttributeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeList(this);
}


antlrcpp::Any RuleParser::AttributeListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAttributeList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AttributeListContext* RuleParser::attributeList() {
  AttributeListContext *_localctx = _tracker.createInstance<AttributeListContext>(_ctx, getState());
  enterRule(_localctx, 24, RuleParser::RuleAttributeList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(208);
      attributeDecl();
      setState(211); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeDeclContext ------------------------------------------------------------------

RuleParser::AttributeDeclContext::AttributeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::AttributeNameContext* RuleParser::AttributeDeclContext::attributeName() {
  return getRuleContext<RuleParser::AttributeNameContext>(0);
}

tree::TerminalNode* RuleParser::AttributeDeclContext::IS() {
  return getToken(RuleParser::IS, 0);
}

RuleParser::TypeAnnoContext* RuleParser::AttributeDeclContext::typeAnno() {
  return getRuleContext<RuleParser::TypeAnnoContext>(0);
}


size_t RuleParser::AttributeDeclContext::getRuleIndex() const {
  return RuleParser::RuleAttributeDecl;
}

void RuleParser::AttributeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeDecl(this);
}

void RuleParser::AttributeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeDecl(this);
}


antlrcpp::Any RuleParser::AttributeDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAttributeDecl(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AttributeDeclContext* RuleParser::attributeDecl() {
  AttributeDeclContext *_localctx = _tracker.createInstance<AttributeDeclContext>(_ctx, getState());
  enterRule(_localctx, 26, RuleParser::RuleAttributeDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    attributeName();
    setState(216);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::IS) {
      setState(214);
      match(RuleParser::IS);
      setState(215);
      typeAnno();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AttributeNameContext ------------------------------------------------------------------

RuleParser::AttributeNameContext::AttributeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::AttributeNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::AttributeNameContext::getRuleIndex() const {
  return RuleParser::RuleAttributeName;
}

void RuleParser::AttributeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAttributeName(this);
}

void RuleParser::AttributeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAttributeName(this);
}


antlrcpp::Any RuleParser::AttributeNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAttributeName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AttributeNameContext* RuleParser::attributeName() {
  AttributeNameContext *_localctx = _tracker.createInstance<AttributeNameContext>(_ctx, getState());
  enterRule(_localctx, 28, RuleParser::RuleAttributeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAnnoContext ------------------------------------------------------------------

RuleParser::TypeAnnoContext::TypeAnnoContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::CompositeTypeContext* RuleParser::TypeAnnoContext::compositeType() {
  return getRuleContext<RuleParser::CompositeTypeContext>(0);
}

RuleParser::BasicTypeContext* RuleParser::TypeAnnoContext::basicType() {
  return getRuleContext<RuleParser::BasicTypeContext>(0);
}


size_t RuleParser::TypeAnnoContext::getRuleIndex() const {
  return RuleParser::RuleTypeAnno;
}

void RuleParser::TypeAnnoContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeAnno(this);
}

void RuleParser::TypeAnnoContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeAnno(this);
}


antlrcpp::Any RuleParser::TypeAnnoContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitTypeAnno(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::TypeAnnoContext* RuleParser::typeAnno() {
  TypeAnnoContext *_localctx = _tracker.createInstance<TypeAnnoContext>(_ctx, getState());
  enterRule(_localctx, 30, RuleParser::RuleTypeAnno);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(222);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::LIST: {
        enterOuterAlt(_localctx, 1);
        setState(220);
        compositeType();
        break;
      }

      case RuleParser::NUMBER:
      case RuleParser::STRING:
      case RuleParser::BOOLEAN:
      case RuleParser::DATE: {
        enterOuterAlt(_localctx, 2);
        setState(221);
        basicType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicTypeContext ------------------------------------------------------------------

RuleParser::BasicTypeContext::BasicTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::BasicTypeContext::NUMBER() {
  return getToken(RuleParser::NUMBER, 0);
}

tree::TerminalNode* RuleParser::BasicTypeContext::STRING() {
  return getToken(RuleParser::STRING, 0);
}

tree::TerminalNode* RuleParser::BasicTypeContext::DATE() {
  return getToken(RuleParser::DATE, 0);
}

tree::TerminalNode* RuleParser::BasicTypeContext::BOOLEAN() {
  return getToken(RuleParser::BOOLEAN, 0);
}


size_t RuleParser::BasicTypeContext::getRuleIndex() const {
  return RuleParser::RuleBasicType;
}

void RuleParser::BasicTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicType(this);
}

void RuleParser::BasicTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicType(this);
}


antlrcpp::Any RuleParser::BasicTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBasicType(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BasicTypeContext* RuleParser::basicType() {
  BasicTypeContext *_localctx = _tracker.createInstance<BasicTypeContext>(_ctx, getState());
  enterRule(_localctx, 32, RuleParser::RuleBasicType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RuleParser::NUMBER)
      | (1ULL << RuleParser::STRING)
      | (1ULL << RuleParser::BOOLEAN)
      | (1ULL << RuleParser::DATE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositeTypeContext ------------------------------------------------------------------

RuleParser::CompositeTypeContext::CompositeTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::ListTypeContext* RuleParser::CompositeTypeContext::listType() {
  return getRuleContext<RuleParser::ListTypeContext>(0);
}


size_t RuleParser::CompositeTypeContext::getRuleIndex() const {
  return RuleParser::RuleCompositeType;
}

void RuleParser::CompositeTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompositeType(this);
}

void RuleParser::CompositeTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompositeType(this);
}


antlrcpp::Any RuleParser::CompositeTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitCompositeType(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::CompositeTypeContext* RuleParser::compositeType() {
  CompositeTypeContext *_localctx = _tracker.createInstance<CompositeTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, RuleParser::RuleCompositeType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(226);
    listType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListTypeContext ------------------------------------------------------------------

RuleParser::ListTypeContext::ListTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::ListTypeContext::LIST() {
  return getToken(RuleParser::LIST, 0);
}

tree::TerminalNode* RuleParser::ListTypeContext::L_BRACKET() {
  return getToken(RuleParser::L_BRACKET, 0);
}

tree::TerminalNode* RuleParser::ListTypeContext::R_BRACKET() {
  return getToken(RuleParser::R_BRACKET, 0);
}

RuleParser::BasicTypeContext* RuleParser::ListTypeContext::basicType() {
  return getRuleContext<RuleParser::BasicTypeContext>(0);
}

tree::TerminalNode* RuleParser::ListTypeContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::ListTypeContext::getRuleIndex() const {
  return RuleParser::RuleListType;
}

void RuleParser::ListTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListType(this);
}

void RuleParser::ListTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListType(this);
}


antlrcpp::Any RuleParser::ListTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitListType(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ListTypeContext* RuleParser::listType() {
  ListTypeContext *_localctx = _tracker.createInstance<ListTypeContext>(_ctx, getState());
  enterRule(_localctx, 36, RuleParser::RuleListType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(228);
    match(RuleParser::LIST);
    setState(229);
    match(RuleParser::L_BRACKET);
    setState(232);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::NUMBER:
      case RuleParser::STRING:
      case RuleParser::BOOLEAN:
      case RuleParser::DATE: {
        setState(230);
        basicType();
        break;
      }

      case RuleParser::IDENTIFIER: {
        setState(231);
        match(RuleParser::IDENTIFIER);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(234);
    match(RuleParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecutionBlockContext ------------------------------------------------------------------

RuleParser::ExecutionBlockContext::ExecutionBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::ExecutionBlockContext::EXECUTE() {
  return getToken(RuleParser::EXECUTE, 0);
}

tree::TerminalNode* RuleParser::ExecutionBlockContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::ExecutionStmtContext* RuleParser::ExecutionBlockContext::executionStmt() {
  return getRuleContext<RuleParser::ExecutionStmtContext>(0);
}

tree::TerminalNode* RuleParser::ExecutionBlockContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::ExecutionBlockContext::getRuleIndex() const {
  return RuleParser::RuleExecutionBlock;
}

void RuleParser::ExecutionBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecutionBlock(this);
}

void RuleParser::ExecutionBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecutionBlock(this);
}


antlrcpp::Any RuleParser::ExecutionBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitExecutionBlock(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ExecutionBlockContext* RuleParser::executionBlock() {
  ExecutionBlockContext *_localctx = _tracker.createInstance<ExecutionBlockContext>(_ctx, getState());
  enterRule(_localctx, 38, RuleParser::RuleExecutionBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(236);
    match(RuleParser::EXECUTE);
    setState(237);
    match(RuleParser::L_CURLY);
    setState(238);
    executionStmt();
    setState(239);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecutionStmtContext ------------------------------------------------------------------

RuleParser::ExecutionStmtContext::ExecutionStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::ExecutionStmtContext::CHECK() {
  return getToken(RuleParser::CHECK, 0);
}

tree::TerminalNode* RuleParser::ExecutionStmtContext::RULE() {
  return getToken(RuleParser::RULE, 0);
}

RuleParser::ExecuteRuleDefContext* RuleParser::ExecutionStmtContext::executeRuleDef() {
  return getRuleContext<RuleParser::ExecuteRuleDefContext>(0);
}

RuleParser::RuleNameContext* RuleParser::ExecutionStmtContext::ruleName() {
  return getRuleContext<RuleParser::RuleNameContext>(0);
}


size_t RuleParser::ExecutionStmtContext::getRuleIndex() const {
  return RuleParser::RuleExecutionStmt;
}

void RuleParser::ExecutionStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecutionStmt(this);
}

void RuleParser::ExecutionStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecutionStmt(this);
}


antlrcpp::Any RuleParser::ExecutionStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitExecutionStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ExecutionStmtContext* RuleParser::executionStmt() {
  ExecutionStmtContext *_localctx = _tracker.createInstance<ExecutionStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, RuleParser::RuleExecutionStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(247);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(241);
      match(RuleParser::CHECK);
      setState(242);
      match(RuleParser::RULE);
      setState(243);
      executeRuleDef();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(244);
      match(RuleParser::CHECK);
      setState(245);
      match(RuleParser::RULE);
      setState(246);
      ruleName();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecuteRuleDefContext ------------------------------------------------------------------

RuleParser::ExecuteRuleDefContext::ExecuteRuleDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::RuleNameContext* RuleParser::ExecuteRuleDefContext::ruleName() {
  return getRuleContext<RuleParser::RuleNameContext>(0);
}

RuleParser::ExecutionTrueStmtContext* RuleParser::ExecuteRuleDefContext::executionTrueStmt() {
  return getRuleContext<RuleParser::ExecutionTrueStmtContext>(0);
}

RuleParser::ExecutionFalseStmtContext* RuleParser::ExecuteRuleDefContext::executionFalseStmt() {
  return getRuleContext<RuleParser::ExecutionFalseStmtContext>(0);
}


size_t RuleParser::ExecuteRuleDefContext::getRuleIndex() const {
  return RuleParser::RuleExecuteRuleDef;
}

void RuleParser::ExecuteRuleDefContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecuteRuleDef(this);
}

void RuleParser::ExecuteRuleDefContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecuteRuleDef(this);
}


antlrcpp::Any RuleParser::ExecuteRuleDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitExecuteRuleDef(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ExecuteRuleDefContext* RuleParser::executeRuleDef() {
  ExecuteRuleDefContext *_localctx = _tracker.createInstance<ExecuteRuleDefContext>(_ctx, getState());
  enterRule(_localctx, 42, RuleParser::RuleExecuteRuleDef);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    ruleName();
    setState(251);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::TRUE) {
      setState(250);
      executionTrueStmt();
    }
    setState(254);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      setState(253);
      executionFalseStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecutionTrueStmtContext ------------------------------------------------------------------

RuleParser::ExecutionTrueStmtContext::ExecutionTrueStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::ExecutionTrueStmtContext::TRUE() {
  return getToken(RuleParser::TRUE, 0);
}

tree::TerminalNode* RuleParser::ExecutionTrueStmtContext::COLON() {
  return getToken(RuleParser::COLON, 0);
}

RuleParser::RuleNameContext* RuleParser::ExecutionTrueStmtContext::ruleName() {
  return getRuleContext<RuleParser::RuleNameContext>(0);
}

RuleParser::ExecuteRuleDefContext* RuleParser::ExecutionTrueStmtContext::executeRuleDef() {
  return getRuleContext<RuleParser::ExecuteRuleDefContext>(0);
}


size_t RuleParser::ExecutionTrueStmtContext::getRuleIndex() const {
  return RuleParser::RuleExecutionTrueStmt;
}

void RuleParser::ExecutionTrueStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecutionTrueStmt(this);
}

void RuleParser::ExecutionTrueStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecutionTrueStmt(this);
}


antlrcpp::Any RuleParser::ExecutionTrueStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitExecutionTrueStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ExecutionTrueStmtContext* RuleParser::executionTrueStmt() {
  ExecutionTrueStmtContext *_localctx = _tracker.createInstance<ExecutionTrueStmtContext>(_ctx, getState());
  enterRule(_localctx, 44, RuleParser::RuleExecutionTrueStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(256);
      match(RuleParser::TRUE);
      setState(257);
      match(RuleParser::COLON);
      setState(258);
      ruleName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(259);
      match(RuleParser::TRUE);
      setState(260);
      match(RuleParser::COLON);
      setState(261);
      executeRuleDef();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExecutionFalseStmtContext ------------------------------------------------------------------

RuleParser::ExecutionFalseStmtContext::ExecutionFalseStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::ExecutionFalseStmtContext::FALSE() {
  return getToken(RuleParser::FALSE, 0);
}

tree::TerminalNode* RuleParser::ExecutionFalseStmtContext::COLON() {
  return getToken(RuleParser::COLON, 0);
}

RuleParser::RuleNameContext* RuleParser::ExecutionFalseStmtContext::ruleName() {
  return getRuleContext<RuleParser::RuleNameContext>(0);
}

RuleParser::ExecuteRuleDefContext* RuleParser::ExecutionFalseStmtContext::executeRuleDef() {
  return getRuleContext<RuleParser::ExecuteRuleDefContext>(0);
}


size_t RuleParser::ExecutionFalseStmtContext::getRuleIndex() const {
  return RuleParser::RuleExecutionFalseStmt;
}

void RuleParser::ExecutionFalseStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExecutionFalseStmt(this);
}

void RuleParser::ExecutionFalseStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExecutionFalseStmt(this);
}


antlrcpp::Any RuleParser::ExecutionFalseStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitExecutionFalseStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ExecutionFalseStmtContext* RuleParser::executionFalseStmt() {
  ExecutionFalseStmtContext *_localctx = _tracker.createInstance<ExecutionFalseStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, RuleParser::RuleExecutionFalseStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(270);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(264);
      match(RuleParser::FALSE);
      setState(265);
      match(RuleParser::COLON);
      setState(266);
      ruleName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(267);
      match(RuleParser::FALSE);
      setState(268);
      match(RuleParser::COLON);
      setState(269);
      executeRuleDef();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RulesBlockContext ------------------------------------------------------------------

RuleParser::RulesBlockContext::RulesBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RulesBlockContext::RULES() {
  return getToken(RuleParser::RULES, 0);
}

tree::TerminalNode* RuleParser::RulesBlockContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::RuleListContext* RuleParser::RulesBlockContext::ruleList() {
  return getRuleContext<RuleParser::RuleListContext>(0);
}

tree::TerminalNode* RuleParser::RulesBlockContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::RulesBlockContext::getRuleIndex() const {
  return RuleParser::RuleRulesBlock;
}

void RuleParser::RulesBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRulesBlock(this);
}

void RuleParser::RulesBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRulesBlock(this);
}


antlrcpp::Any RuleParser::RulesBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRulesBlock(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RulesBlockContext* RuleParser::rulesBlock() {
  RulesBlockContext *_localctx = _tracker.createInstance<RulesBlockContext>(_ctx, getState());
  enterRule(_localctx, 48, RuleParser::RuleRulesBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(272);
    match(RuleParser::RULES);
    setState(273);
    match(RuleParser::L_CURLY);
    setState(274);
    ruleList();
    setState(275);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleListContext ------------------------------------------------------------------

RuleParser::RuleListContext::RuleListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::BasicRuleContext *> RuleParser::RuleListContext::basicRule() {
  return getRuleContexts<RuleParser::BasicRuleContext>();
}

RuleParser::BasicRuleContext* RuleParser::RuleListContext::basicRule(size_t i) {
  return getRuleContext<RuleParser::BasicRuleContext>(i);
}


size_t RuleParser::RuleListContext::getRuleIndex() const {
  return RuleParser::RuleRuleList;
}

void RuleParser::RuleListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleList(this);
}

void RuleParser::RuleListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleList(this);
}


antlrcpp::Any RuleParser::RuleListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleListContext* RuleParser::ruleList() {
  RuleListContext *_localctx = _tracker.createInstance<RuleListContext>(_ctx, getState());
  enterRule(_localctx, 50, RuleParser::RuleRuleList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(277);
      basicRule();
      setState(280); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == RuleParser::RULE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicRuleContext ------------------------------------------------------------------

RuleParser::BasicRuleContext::BasicRuleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::BasicRuleContext::RULE() {
  return getToken(RuleParser::RULE, 0);
}

RuleParser::RuleNameContext* RuleParser::BasicRuleContext::ruleName() {
  return getRuleContext<RuleParser::RuleNameContext>(0);
}

tree::TerminalNode* RuleParser::BasicRuleContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

RuleParser::RuleStmtListContext* RuleParser::BasicRuleContext::ruleStmtList() {
  return getRuleContext<RuleParser::RuleStmtListContext>(0);
}

tree::TerminalNode* RuleParser::BasicRuleContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}


size_t RuleParser::BasicRuleContext::getRuleIndex() const {
  return RuleParser::RuleBasicRule;
}

void RuleParser::BasicRuleContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicRule(this);
}

void RuleParser::BasicRuleContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicRule(this);
}


antlrcpp::Any RuleParser::BasicRuleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBasicRule(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BasicRuleContext* RuleParser::basicRule() {
  BasicRuleContext *_localctx = _tracker.createInstance<BasicRuleContext>(_ctx, getState());
  enterRule(_localctx, 52, RuleParser::RuleBasicRule);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(282);
    match(RuleParser::RULE);
    setState(283);
    ruleName();
    setState(284);
    match(RuleParser::L_CURLY);
    setState(285);
    ruleStmtList();
    setState(286);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleNameContext ------------------------------------------------------------------

RuleParser::RuleNameContext::RuleNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RuleNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::RuleNameContext::getRuleIndex() const {
  return RuleParser::RuleRuleName;
}

void RuleParser::RuleNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleName(this);
}

void RuleParser::RuleNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleName(this);
}


antlrcpp::Any RuleParser::RuleNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleNameContext* RuleParser::ruleName() {
  RuleNameContext *_localctx = _tracker.createInstance<RuleNameContext>(_ctx, getState());
  enterRule(_localctx, 54, RuleParser::RuleRuleName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleStmtListContext ------------------------------------------------------------------

RuleParser::RuleStmtListContext::RuleStmtListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::RuleStmtContext *> RuleParser::RuleStmtListContext::ruleStmt() {
  return getRuleContexts<RuleParser::RuleStmtContext>();
}

RuleParser::RuleStmtContext* RuleParser::RuleStmtListContext::ruleStmt(size_t i) {
  return getRuleContext<RuleParser::RuleStmtContext>(i);
}


size_t RuleParser::RuleStmtListContext::getRuleIndex() const {
  return RuleParser::RuleRuleStmtList;
}

void RuleParser::RuleStmtListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleStmtList(this);
}

void RuleParser::RuleStmtListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleStmtList(this);
}


antlrcpp::Any RuleParser::RuleStmtListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleStmtList(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleStmtListContext* RuleParser::ruleStmtList() {
  RuleStmtListContext *_localctx = _tracker.createInstance<RuleStmtListContext>(_ctx, getState());
  enterRule(_localctx, 56, RuleParser::RuleRuleStmtList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(291); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(290);
      ruleStmt();
      setState(293); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RuleParser::OUTPUT)
      | (1ULL << RuleParser::TRUE)
      | (1ULL << RuleParser::FALSE)
      | (1ULL << RuleParser::IF)
      | (1ULL << RuleParser::L_PAREN)
      | (1ULL << RuleParser::LOGICAL_NOT)
      | (1ULL << RuleParser::MINUS))) != 0) || ((((_la - 69) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 69)) & ((1ULL << (RuleParser::ACCUMULATE - 69))
      | (1ULL << (RuleParser::COUNT - 69))
      | (1ULL << (RuleParser::DECIMAL_LIT - 69))
      | (1ULL << (RuleParser::DECIMAL_FLOAT_LIT - 69))
      | (1ULL << (RuleParser::INTERPRETED_STRING_LIT - 69))
      | (1ULL << (RuleParser::IDENTIFIER - 69)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RuleStmtContext ------------------------------------------------------------------

RuleParser::RuleStmtContext::RuleStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::SimpleStmtContext* RuleParser::RuleStmtContext::simpleStmt() {
  return getRuleContext<RuleParser::SimpleStmtContext>(0);
}

RuleParser::ComplexStmtContext* RuleParser::RuleStmtContext::complexStmt() {
  return getRuleContext<RuleParser::ComplexStmtContext>(0);
}


size_t RuleParser::RuleStmtContext::getRuleIndex() const {
  return RuleParser::RuleRuleStmt;
}

void RuleParser::RuleStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRuleStmt(this);
}

void RuleParser::RuleStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRuleStmt(this);
}


antlrcpp::Any RuleParser::RuleStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRuleStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RuleStmtContext* RuleParser::ruleStmt() {
  RuleStmtContext *_localctx = _tracker.createInstance<RuleStmtContext>(_ctx, getState());
  enterRule(_localctx, 58, RuleParser::RuleRuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(297);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(295);
      simpleStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(296);
      complexStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStmtContext ------------------------------------------------------------------

RuleParser::SimpleStmtContext::SimpleStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::ListStmtContext* RuleParser::SimpleStmtContext::listStmt() {
  return getRuleContext<RuleParser::ListStmtContext>(0);
}

RuleParser::RelationStmtContext* RuleParser::SimpleStmtContext::relationStmt() {
  return getRuleContext<RuleParser::RelationStmtContext>(0);
}

RuleParser::LogicalStmtContext* RuleParser::SimpleStmtContext::logicalStmt() {
  return getRuleContext<RuleParser::LogicalStmtContext>(0);
}

RuleParser::DefinitionStmtContext* RuleParser::SimpleStmtContext::definitionStmt() {
  return getRuleContext<RuleParser::DefinitionStmtContext>(0);
}

RuleParser::AssignStmtContext* RuleParser::SimpleStmtContext::assignStmt() {
  return getRuleContext<RuleParser::AssignStmtContext>(0);
}


size_t RuleParser::SimpleStmtContext::getRuleIndex() const {
  return RuleParser::RuleSimpleStmt;
}

void RuleParser::SimpleStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleStmt(this);
}

void RuleParser::SimpleStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleStmt(this);
}


antlrcpp::Any RuleParser::SimpleStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSimpleStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SimpleStmtContext* RuleParser::simpleStmt() {
  SimpleStmtContext *_localctx = _tracker.createInstance<SimpleStmtContext>(_ctx, getState());
  enterRule(_localctx, 60, RuleParser::RuleSimpleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(304);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(299);
      listStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(300);
      relationStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(301);
      logicalStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(302);
      definitionStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(303);
      assignStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ComplexStmtContext ------------------------------------------------------------------

RuleParser::ComplexStmtContext::ComplexStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::IfStmtContext* RuleParser::ComplexStmtContext::ifStmt() {
  return getRuleContext<RuleParser::IfStmtContext>(0);
}

RuleParser::SequentialStmtContext* RuleParser::ComplexStmtContext::sequentialStmt() {
  return getRuleContext<RuleParser::SequentialStmtContext>(0);
}

RuleParser::DateStmtContext* RuleParser::ComplexStmtContext::dateStmt() {
  return getRuleContext<RuleParser::DateStmtContext>(0);
}

RuleParser::TimeStmtContext* RuleParser::ComplexStmtContext::timeStmt() {
  return getRuleContext<RuleParser::TimeStmtContext>(0);
}


size_t RuleParser::ComplexStmtContext::getRuleIndex() const {
  return RuleParser::RuleComplexStmt;
}

void RuleParser::ComplexStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterComplexStmt(this);
}

void RuleParser::ComplexStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitComplexStmt(this);
}


antlrcpp::Any RuleParser::ComplexStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitComplexStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ComplexStmtContext* RuleParser::complexStmt() {
  ComplexStmtContext *_localctx = _tracker.createInstance<ComplexStmtContext>(_ctx, getState());
  enterRule(_localctx, 62, RuleParser::RuleComplexStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(310);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(306);
      ifStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(307);
      sequentialStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(308);
      dateStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(309);
      timeStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListStmtContext ------------------------------------------------------------------

RuleParser::ListStmtContext::ListStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::ListExprContext* RuleParser::ListStmtContext::listExpr() {
  return getRuleContext<RuleParser::ListExprContext>(0);
}


size_t RuleParser::ListStmtContext::getRuleIndex() const {
  return RuleParser::RuleListStmt;
}

void RuleParser::ListStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListStmt(this);
}

void RuleParser::ListStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListStmt(this);
}


antlrcpp::Any RuleParser::ListStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitListStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ListStmtContext* RuleParser::listStmt() {
  ListStmtContext *_localctx = _tracker.createInstance<ListStmtContext>(_ctx, getState());
  enterRule(_localctx, 64, RuleParser::RuleListStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    listExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListExprContext ------------------------------------------------------------------

RuleParser::ListExprContext::ListExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::ListExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

RuleParser::ListExprContext* RuleParser::ListExprContext::listExpr() {
  return getRuleContext<RuleParser::ListExprContext>(0);
}

tree::TerminalNode* RuleParser::ListExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

RuleParser::ListFirstExprContext* RuleParser::ListExprContext::listFirstExpr() {
  return getRuleContext<RuleParser::ListFirstExprContext>(0);
}

RuleParser::ListSecondExprContext* RuleParser::ListExprContext::listSecondExpr() {
  return getRuleContext<RuleParser::ListSecondExprContext>(0);
}

tree::TerminalNode* RuleParser::ListExprContext::SET_IN() {
  return getToken(RuleParser::SET_IN, 0);
}

tree::TerminalNode* RuleParser::ListExprContext::SET_NOT_IN() {
  return getToken(RuleParser::SET_NOT_IN, 0);
}


size_t RuleParser::ListExprContext::getRuleIndex() const {
  return RuleParser::RuleListExpr;
}

void RuleParser::ListExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListExpr(this);
}

void RuleParser::ListExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListExpr(this);
}


antlrcpp::Any RuleParser::ListExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitListExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ListExprContext* RuleParser::listExpr() {
  ListExprContext *_localctx = _tracker.createInstance<ListExprContext>(_ctx, getState());
  enterRule(_localctx, 66, RuleParser::RuleListExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(322);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::L_PAREN: {
        enterOuterAlt(_localctx, 1);
        setState(314);
        match(RuleParser::L_PAREN);
        setState(315);
        listExpr();
        setState(316);
        match(RuleParser::R_PAREN);
        break;
      }

      case RuleParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(318);
        listFirstExpr();
        setState(319);
        _la = _input->LA(1);
        if (!(_la == RuleParser::SET_IN

        || _la == RuleParser::SET_NOT_IN)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(320);
        listSecondExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListFirstExprContext ------------------------------------------------------------------

RuleParser::ListFirstExprContext::ListFirstExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::InstanceNameContext* RuleParser::ListFirstExprContext::instanceName() {
  return getRuleContext<RuleParser::InstanceNameContext>(0);
}

RuleParser::SelectorIdentContext* RuleParser::ListFirstExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}


size_t RuleParser::ListFirstExprContext::getRuleIndex() const {
  return RuleParser::RuleListFirstExpr;
}

void RuleParser::ListFirstExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListFirstExpr(this);
}

void RuleParser::ListFirstExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListFirstExpr(this);
}


antlrcpp::Any RuleParser::ListFirstExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitListFirstExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ListFirstExprContext* RuleParser::listFirstExpr() {
  ListFirstExprContext *_localctx = _tracker.createInstance<ListFirstExprContext>(_ctx, getState());
  enterRule(_localctx, 68, RuleParser::RuleListFirstExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(326);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(324);
      instanceName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(325);
      selectorIdent();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ListSecondExprContext ------------------------------------------------------------------

RuleParser::ListSecondExprContext::ListSecondExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::InstanceNameContext* RuleParser::ListSecondExprContext::instanceName() {
  return getRuleContext<RuleParser::InstanceNameContext>(0);
}

RuleParser::SelectorIdentContext* RuleParser::ListSecondExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}


size_t RuleParser::ListSecondExprContext::getRuleIndex() const {
  return RuleParser::RuleListSecondExpr;
}

void RuleParser::ListSecondExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterListSecondExpr(this);
}

void RuleParser::ListSecondExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitListSecondExpr(this);
}


antlrcpp::Any RuleParser::ListSecondExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitListSecondExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ListSecondExprContext* RuleParser::listSecondExpr() {
  ListSecondExprContext *_localctx = _tracker.createInstance<ListSecondExprContext>(_ctx, getState());
  enterRule(_localctx, 70, RuleParser::RuleListSecondExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(330);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(328);
      instanceName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(329);
      selectorIdent();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationStmtContext ------------------------------------------------------------------

RuleParser::RelationStmtContext::RelationStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::RelationExprContext* RuleParser::RelationStmtContext::relationExpr() {
  return getRuleContext<RuleParser::RelationExprContext>(0);
}


size_t RuleParser::RelationStmtContext::getRuleIndex() const {
  return RuleParser::RuleRelationStmt;
}

void RuleParser::RelationStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationStmt(this);
}

void RuleParser::RelationStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationStmt(this);
}


antlrcpp::Any RuleParser::RelationStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRelationStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RelationStmtContext* RuleParser::relationStmt() {
  RelationStmtContext *_localctx = _tracker.createInstance<RelationStmtContext>(_ctx, getState());
  enterRule(_localctx, 72, RuleParser::RuleRelationStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    relationExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationExprContext ------------------------------------------------------------------

RuleParser::RelationExprContext::RelationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RelationExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

RuleParser::RelationExprContext* RuleParser::RelationExprContext::relationExpr() {
  return getRuleContext<RuleParser::RelationExprContext>(0);
}

tree::TerminalNode* RuleParser::RelationExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

std::vector<RuleParser::NumberExprContext *> RuleParser::RelationExprContext::numberExpr() {
  return getRuleContexts<RuleParser::NumberExprContext>();
}

RuleParser::NumberExprContext* RuleParser::RelationExprContext::numberExpr(size_t i) {
  return getRuleContext<RuleParser::NumberExprContext>(i);
}

RuleParser::RelationOperatorContext* RuleParser::RelationExprContext::relationOperator() {
  return getRuleContext<RuleParser::RelationOperatorContext>(0);
}

std::vector<RuleParser::StringExprContext *> RuleParser::RelationExprContext::stringExpr() {
  return getRuleContexts<RuleParser::StringExprContext>();
}

RuleParser::StringExprContext* RuleParser::RelationExprContext::stringExpr(size_t i) {
  return getRuleContext<RuleParser::StringExprContext>(i);
}

RuleParser::CompareOperatorContext* RuleParser::RelationExprContext::compareOperator() {
  return getRuleContext<RuleParser::CompareOperatorContext>(0);
}


size_t RuleParser::RelationExprContext::getRuleIndex() const {
  return RuleParser::RuleRelationExpr;
}

void RuleParser::RelationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationExpr(this);
}

void RuleParser::RelationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationExpr(this);
}


antlrcpp::Any RuleParser::RelationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRelationExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RelationExprContext* RuleParser::relationExpr() {
  RelationExprContext *_localctx = _tracker.createInstance<RelationExprContext>(_ctx, getState());
  enterRule(_localctx, 74, RuleParser::RuleRelationExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(346);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(334);
      match(RuleParser::L_PAREN);
      setState(335);
      relationExpr();
      setState(336);
      match(RuleParser::R_PAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(338);
      numberExpr(0);
      setState(339);
      relationOperator();
      setState(340);
      numberExpr(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(342);
      stringExpr();
      setState(343);
      compareOperator();
      setState(344);
      stringExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringExprContext ------------------------------------------------------------------

RuleParser::StringExprContext::StringExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::InstanceNameContext* RuleParser::StringExprContext::instanceName() {
  return getRuleContext<RuleParser::InstanceNameContext>(0);
}

RuleParser::SelectorIdentContext* RuleParser::StringExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}

tree::TerminalNode* RuleParser::StringExprContext::INTERPRETED_STRING_LIT() {
  return getToken(RuleParser::INTERPRETED_STRING_LIT, 0);
}


size_t RuleParser::StringExprContext::getRuleIndex() const {
  return RuleParser::RuleStringExpr;
}

void RuleParser::StringExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringExpr(this);
}

void RuleParser::StringExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringExpr(this);
}


antlrcpp::Any RuleParser::StringExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitStringExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::StringExprContext* RuleParser::stringExpr() {
  StringExprContext *_localctx = _tracker.createInstance<StringExprContext>(_ctx, getState());
  enterRule(_localctx, 76, RuleParser::RuleStringExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(351);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(348);
      instanceName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(349);
      selectorIdent();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(350);
      match(RuleParser::INTERPRETED_STRING_LIT);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompareOperatorContext ------------------------------------------------------------------

RuleParser::CompareOperatorContext::CompareOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::CompareOperatorContext::EQUALS() {
  return getToken(RuleParser::EQUALS, 0);
}

tree::TerminalNode* RuleParser::CompareOperatorContext::NOT_EQUALS() {
  return getToken(RuleParser::NOT_EQUALS, 0);
}


size_t RuleParser::CompareOperatorContext::getRuleIndex() const {
  return RuleParser::RuleCompareOperator;
}

void RuleParser::CompareOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompareOperator(this);
}

void RuleParser::CompareOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompareOperator(this);
}


antlrcpp::Any RuleParser::CompareOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitCompareOperator(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::CompareOperatorContext* RuleParser::compareOperator() {
  CompareOperatorContext *_localctx = _tracker.createInstance<CompareOperatorContext>(_ctx, getState());
  enterRule(_localctx, 78, RuleParser::RuleCompareOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    _la = _input->LA(1);
    if (!(_la == RuleParser::EQUALS

    || _la == RuleParser::NOT_EQUALS)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationOperatorContext ------------------------------------------------------------------

RuleParser::RelationOperatorContext::RelationOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::RelationOperatorContext::EQUALS() {
  return getToken(RuleParser::EQUALS, 0);
}

tree::TerminalNode* RuleParser::RelationOperatorContext::NOT_EQUALS() {
  return getToken(RuleParser::NOT_EQUALS, 0);
}

tree::TerminalNode* RuleParser::RelationOperatorContext::LESS_THAN() {
  return getToken(RuleParser::LESS_THAN, 0);
}

tree::TerminalNode* RuleParser::RelationOperatorContext::LESS_OR_EQUALS() {
  return getToken(RuleParser::LESS_OR_EQUALS, 0);
}

tree::TerminalNode* RuleParser::RelationOperatorContext::GREATER_THAN() {
  return getToken(RuleParser::GREATER_THAN, 0);
}

tree::TerminalNode* RuleParser::RelationOperatorContext::GREATER_OR_EQUALS() {
  return getToken(RuleParser::GREATER_OR_EQUALS, 0);
}


size_t RuleParser::RelationOperatorContext::getRuleIndex() const {
  return RuleParser::RuleRelationOperator;
}

void RuleParser::RelationOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationOperator(this);
}

void RuleParser::RelationOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationOperator(this);
}


antlrcpp::Any RuleParser::RelationOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitRelationOperator(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::RelationOperatorContext* RuleParser::relationOperator() {
  RelationOperatorContext *_localctx = _tracker.createInstance<RelationOperatorContext>(_ctx, getState());
  enterRule(_localctx, 80, RuleParser::RuleRelationOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << RuleParser::EQUALS)
      | (1ULL << RuleParser::NOT_EQUALS)
      | (1ULL << RuleParser::LESS_THAN)
      | (1ULL << RuleParser::LESS_OR_EQUALS)
      | (1ULL << RuleParser::GREATER_THAN)
      | (1ULL << RuleParser::GREATER_OR_EQUALS))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberExprContext ------------------------------------------------------------------

RuleParser::NumberExprContext::NumberExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::NumberExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

std::vector<RuleParser::NumberExprContext *> RuleParser::NumberExprContext::numberExpr() {
  return getRuleContexts<RuleParser::NumberExprContext>();
}

RuleParser::NumberExprContext* RuleParser::NumberExprContext::numberExpr(size_t i) {
  return getRuleContext<RuleParser::NumberExprContext>(i);
}

tree::TerminalNode* RuleParser::NumberExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::MINUS() {
  return getToken(RuleParser::MINUS, 0);
}

RuleParser::SelectorIdentContext* RuleParser::NumberExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}

tree::TerminalNode* RuleParser::NumberExprContext::DECIMAL_LIT() {
  return getToken(RuleParser::DECIMAL_LIT, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::DECIMAL_FLOAT_LIT() {
  return getToken(RuleParser::DECIMAL_FLOAT_LIT, 0);
}

RuleParser::AggregationExprContext* RuleParser::NumberExprContext::aggregationExpr() {
  return getRuleContext<RuleParser::AggregationExprContext>(0);
}

tree::TerminalNode* RuleParser::NumberExprContext::MULTIPLY() {
  return getToken(RuleParser::MULTIPLY, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::DIVIDE() {
  return getToken(RuleParser::DIVIDE, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::MODULO() {
  return getToken(RuleParser::MODULO, 0);
}

tree::TerminalNode* RuleParser::NumberExprContext::PLUS() {
  return getToken(RuleParser::PLUS, 0);
}


size_t RuleParser::NumberExprContext::getRuleIndex() const {
  return RuleParser::RuleNumberExpr;
}

void RuleParser::NumberExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberExpr(this);
}

void RuleParser::NumberExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberExpr(this);
}


antlrcpp::Any RuleParser::NumberExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitNumberExpr(this);
  else
    return visitor->visitChildren(this);
}


RuleParser::NumberExprContext* RuleParser::numberExpr() {
   return numberExpr(0);
}

RuleParser::NumberExprContext* RuleParser::numberExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RuleParser::NumberExprContext *_localctx = _tracker.createInstance<NumberExprContext>(_ctx, parentState);
  RuleParser::NumberExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 82;
  enterRecursionRule(_localctx, 82, RuleParser::RuleNumberExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(370);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::L_PAREN: {
        setState(358);
        match(RuleParser::L_PAREN);
        setState(359);
        numberExpr(0);
        setState(360);
        match(RuleParser::R_PAREN);
        break;
      }

      case RuleParser::MINUS: {
        setState(362);
        match(RuleParser::MINUS);
        setState(363);
        numberExpr(5);
        break;
      }

      case RuleParser::DECIMAL_LIT:
      case RuleParser::DECIMAL_FLOAT_LIT:
      case RuleParser::IDENTIFIER: {
        setState(367);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case RuleParser::IDENTIFIER: {
            setState(364);
            selectorIdent();
            break;
          }

          case RuleParser::DECIMAL_LIT: {
            setState(365);
            match(RuleParser::DECIMAL_LIT);
            break;
          }

          case RuleParser::DECIMAL_FLOAT_LIT: {
            setState(366);
            match(RuleParser::DECIMAL_FLOAT_LIT);
            break;
          }

        default:
          throw NoViableAltException(this);
        }
        break;
      }

      case RuleParser::ACCUMULATE:
      case RuleParser::COUNT: {
        setState(369);
        aggregationExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(380);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(378);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<NumberExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumberExpr);
          setState(372);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(373);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << RuleParser::MULTIPLY)
            | (1ULL << RuleParser::DIVIDE)
            | (1ULL << RuleParser::MODULO))) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(374);
          numberExpr(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<NumberExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleNumberExpr);
          setState(375);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(376);
          _la = _input->LA(1);
          if (!(_la == RuleParser::PLUS

          || _la == RuleParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(377);
          numberExpr(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(382);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- SelectorIdentContext ------------------------------------------------------------------

RuleParser::SelectorIdentContext::SelectorIdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::EntityNameContext* RuleParser::SelectorIdentContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

tree::TerminalNode* RuleParser::SelectorIdentContext::DOT() {
  return getToken(RuleParser::DOT, 0);
}

RuleParser::AttributeNameContext* RuleParser::SelectorIdentContext::attributeName() {
  return getRuleContext<RuleParser::AttributeNameContext>(0);
}


size_t RuleParser::SelectorIdentContext::getRuleIndex() const {
  return RuleParser::RuleSelectorIdent;
}

void RuleParser::SelectorIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectorIdent(this);
}

void RuleParser::SelectorIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectorIdent(this);
}


antlrcpp::Any RuleParser::SelectorIdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSelectorIdent(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SelectorIdentContext* RuleParser::selectorIdent() {
  SelectorIdentContext *_localctx = _tracker.createInstance<SelectorIdentContext>(_ctx, getState());
  enterRule(_localctx, 84, RuleParser::RuleSelectorIdent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    entityName();
    setState(384);
    match(RuleParser::DOT);
    setState(385);
    attributeName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AggregationExprContext ------------------------------------------------------------------

RuleParser::AggregationExprContext::AggregationExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::AggregationExprContext::ACCUMULATE() {
  return getToken(RuleParser::ACCUMULATE, 0);
}

RuleParser::NumberExprContext* RuleParser::AggregationExprContext::numberExpr() {
  return getRuleContext<RuleParser::NumberExprContext>(0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::ON() {
  return getToken(RuleParser::ON, 0);
}

RuleParser::EntityNameContext* RuleParser::AggregationExprContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::PROVIDED() {
  return getToken(RuleParser::PROVIDED, 0);
}

std::vector<RuleParser::SelectorIdentContext *> RuleParser::AggregationExprContext::selectorIdent() {
  return getRuleContexts<RuleParser::SelectorIdentContext>();
}

RuleParser::SelectorIdentContext* RuleParser::AggregationExprContext::selectorIdent(size_t i) {
  return getRuleContext<RuleParser::SelectorIdentContext>(i);
}

tree::TerminalNode* RuleParser::AggregationExprContext::WHERE() {
  return getToken(RuleParser::WHERE, 0);
}

RuleParser::LogicalExprContext* RuleParser::AggregationExprContext::logicalExpr() {
  return getRuleContext<RuleParser::LogicalExprContext>(0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::DATE_LIT() {
  return getToken(RuleParser::DATE_LIT, 0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::WITHIN() {
  return getToken(RuleParser::WITHIN, 0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::TIME_LIT() {
  return getToken(RuleParser::TIME_LIT, 0);
}

std::vector<tree::TerminalNode *> RuleParser::AggregationExprContext::LOGICAL_AND() {
  return getTokens(RuleParser::LOGICAL_AND);
}

tree::TerminalNode* RuleParser::AggregationExprContext::LOGICAL_AND(size_t i) {
  return getToken(RuleParser::LOGICAL_AND, i);
}

tree::TerminalNode* RuleParser::AggregationExprContext::BEFORE() {
  return getToken(RuleParser::BEFORE, 0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::AFTER() {
  return getToken(RuleParser::AFTER, 0);
}

tree::TerminalNode* RuleParser::AggregationExprContext::COUNT() {
  return getToken(RuleParser::COUNT, 0);
}


size_t RuleParser::AggregationExprContext::getRuleIndex() const {
  return RuleParser::RuleAggregationExpr;
}

void RuleParser::AggregationExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAggregationExpr(this);
}

void RuleParser::AggregationExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAggregationExpr(this);
}


antlrcpp::Any RuleParser::AggregationExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAggregationExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AggregationExprContext* RuleParser::aggregationExpr() {
  AggregationExprContext *_localctx = _tracker.createInstance<AggregationExprContext>(_ctx, getState());
  enterRule(_localctx, 86, RuleParser::RuleAggregationExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(436);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::ACCUMULATE: {
        enterOuterAlt(_localctx, 1);
        setState(387);
        match(RuleParser::ACCUMULATE);
        setState(388);
        numberExpr(0);
        setState(389);
        match(RuleParser::ON);
        setState(390);
        entityName();
        setState(400);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          setState(391);
          match(RuleParser::PROVIDED);
          setState(392);
          selectorIdent();
          setState(397);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(393);
              match(RuleParser::LOGICAL_AND);
              setState(394);
              selectorIdent(); 
            }
            setState(399);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx);
          }
          break;
        }

        default:
          break;
        }
        setState(404);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
        case 1: {
          setState(402);
          match(RuleParser::WHERE);
          setState(403);
          logicalExpr(0);
          break;
        }

        default:
          break;
        }
        setState(410);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
        case 1: {
          setState(406);
          _la = _input->LA(1);
          if (!(_la == RuleParser::BEFORE

          || _la == RuleParser::AFTER)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(407);
          match(RuleParser::DATE_LIT);
          break;
        }

        case 2: {
          setState(408);
          match(RuleParser::WITHIN);
          setState(409);
          match(RuleParser::TIME_LIT);
          break;
        }

        default:
          break;
        }
        break;
      }

      case RuleParser::COUNT: {
        enterOuterAlt(_localctx, 2);
        setState(412);
        match(RuleParser::COUNT);
        setState(413);
        match(RuleParser::ON);
        setState(414);
        entityName();
        setState(424);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
        case 1: {
          setState(415);
          match(RuleParser::PROVIDED);
          setState(416);
          selectorIdent();
          setState(421);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
          while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
            if (alt == 1) {
              setState(417);
              match(RuleParser::LOGICAL_AND);
              setState(418);
              selectorIdent(); 
            }
            setState(423);
            _errHandler->sync(this);
            alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx);
          }
          break;
        }

        default:
          break;
        }
        setState(428);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
        case 1: {
          setState(426);
          match(RuleParser::WHERE);
          setState(427);
          logicalExpr(0);
          break;
        }

        default:
          break;
        }
        setState(434);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
        case 1: {
          setState(430);
          _la = _input->LA(1);
          if (!(_la == RuleParser::BEFORE

          || _la == RuleParser::AFTER)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(431);
          match(RuleParser::DATE_LIT);
          break;
        }

        case 2: {
          setState(432);
          match(RuleParser::WITHIN);
          setState(433);
          match(RuleParser::TIME_LIT);
          break;
        }

        default:
          break;
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanExprContext ------------------------------------------------------------------

RuleParser::BooleanExprContext::BooleanExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::BooleanExprContext::L_PAREN() {
  return getToken(RuleParser::L_PAREN, 0);
}

RuleParser::BooleanExprContext* RuleParser::BooleanExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::BooleanExprContext::R_PAREN() {
  return getToken(RuleParser::R_PAREN, 0);
}

RuleParser::BooleanLiteralContext* RuleParser::BooleanExprContext::booleanLiteral() {
  return getRuleContext<RuleParser::BooleanLiteralContext>(0);
}

RuleParser::SelectorIdentContext* RuleParser::BooleanExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}

RuleParser::ListExprContext* RuleParser::BooleanExprContext::listExpr() {
  return getRuleContext<RuleParser::ListExprContext>(0);
}

RuleParser::RelationExprContext* RuleParser::BooleanExprContext::relationExpr() {
  return getRuleContext<RuleParser::RelationExprContext>(0);
}

RuleParser::InstanceNameContext* RuleParser::BooleanExprContext::instanceName() {
  return getRuleContext<RuleParser::InstanceNameContext>(0);
}


size_t RuleParser::BooleanExprContext::getRuleIndex() const {
  return RuleParser::RuleBooleanExpr;
}

void RuleParser::BooleanExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanExpr(this);
}

void RuleParser::BooleanExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanExpr(this);
}


antlrcpp::Any RuleParser::BooleanExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBooleanExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BooleanExprContext* RuleParser::booleanExpr() {
  BooleanExprContext *_localctx = _tracker.createInstance<BooleanExprContext>(_ctx, getState());
  enterRule(_localctx, 88, RuleParser::RuleBooleanExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(447);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 40, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(438);
      match(RuleParser::L_PAREN);
      setState(439);
      booleanExpr();
      setState(440);
      match(RuleParser::R_PAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(442);
      booleanLiteral();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(443);
      selectorIdent();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(444);
      listExpr();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(445);
      relationExpr();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(446);
      instanceName();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanLiteralContext ------------------------------------------------------------------

RuleParser::BooleanLiteralContext::BooleanLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::BooleanLiteralContext::TRUE() {
  return getToken(RuleParser::TRUE, 0);
}

tree::TerminalNode* RuleParser::BooleanLiteralContext::FALSE() {
  return getToken(RuleParser::FALSE, 0);
}


size_t RuleParser::BooleanLiteralContext::getRuleIndex() const {
  return RuleParser::RuleBooleanLiteral;
}

void RuleParser::BooleanLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanLiteral(this);
}

void RuleParser::BooleanLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanLiteral(this);
}


antlrcpp::Any RuleParser::BooleanLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBooleanLiteral(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BooleanLiteralContext* RuleParser::booleanLiteral() {
  BooleanLiteralContext *_localctx = _tracker.createInstance<BooleanLiteralContext>(_ctx, getState());
  enterRule(_localctx, 90, RuleParser::RuleBooleanLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(449);
    _la = _input->LA(1);
    if (!(_la == RuleParser::TRUE

    || _la == RuleParser::FALSE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalStmtContext ------------------------------------------------------------------

RuleParser::LogicalStmtContext::LogicalStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::LogicalExprContext* RuleParser::LogicalStmtContext::logicalExpr() {
  return getRuleContext<RuleParser::LogicalExprContext>(0);
}


size_t RuleParser::LogicalStmtContext::getRuleIndex() const {
  return RuleParser::RuleLogicalStmt;
}

void RuleParser::LogicalStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalStmt(this);
}

void RuleParser::LogicalStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalStmt(this);
}


antlrcpp::Any RuleParser::LogicalStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitLogicalStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::LogicalStmtContext* RuleParser::logicalStmt() {
  LogicalStmtContext *_localctx = _tracker.createInstance<LogicalStmtContext>(_ctx, getState());
  enterRule(_localctx, 92, RuleParser::RuleLogicalStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    logicalExpr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalExprContext ------------------------------------------------------------------

RuleParser::LogicalExprContext::LogicalExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::LogicalExprContext::LOGICAL_NOT() {
  return getToken(RuleParser::LOGICAL_NOT, 0);
}

std::vector<RuleParser::LogicalExprContext *> RuleParser::LogicalExprContext::logicalExpr() {
  return getRuleContexts<RuleParser::LogicalExprContext>();
}

RuleParser::LogicalExprContext* RuleParser::LogicalExprContext::logicalExpr(size_t i) {
  return getRuleContext<RuleParser::LogicalExprContext>(i);
}

RuleParser::BooleanExprContext* RuleParser::LogicalExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::LogicalExprContext::LOGICAL_AND() {
  return getToken(RuleParser::LOGICAL_AND, 0);
}

tree::TerminalNode* RuleParser::LogicalExprContext::LOGICAL_OR() {
  return getToken(RuleParser::LOGICAL_OR, 0);
}


size_t RuleParser::LogicalExprContext::getRuleIndex() const {
  return RuleParser::RuleLogicalExpr;
}

void RuleParser::LogicalExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalExpr(this);
}

void RuleParser::LogicalExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalExpr(this);
}


antlrcpp::Any RuleParser::LogicalExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitLogicalExpr(this);
  else
    return visitor->visitChildren(this);
}


RuleParser::LogicalExprContext* RuleParser::logicalExpr() {
   return logicalExpr(0);
}

RuleParser::LogicalExprContext* RuleParser::logicalExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  RuleParser::LogicalExprContext *_localctx = _tracker.createInstance<LogicalExprContext>(_ctx, parentState);
  RuleParser::LogicalExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 94;
  enterRecursionRule(_localctx, 94, RuleParser::RuleLogicalExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(457);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case RuleParser::LOGICAL_NOT: {
        setState(454);
        match(RuleParser::LOGICAL_NOT);
        setState(455);
        logicalExpr(4);
        break;
      }

      case RuleParser::TRUE:
      case RuleParser::FALSE:
      case RuleParser::L_PAREN:
      case RuleParser::MINUS:
      case RuleParser::ACCUMULATE:
      case RuleParser::COUNT:
      case RuleParser::DECIMAL_LIT:
      case RuleParser::DECIMAL_FLOAT_LIT:
      case RuleParser::INTERPRETED_STRING_LIT:
      case RuleParser::IDENTIFIER: {
        setState(456);
        booleanExpr();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(467);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(465);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 42, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<LogicalExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalExpr);
          setState(459);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(460);
          match(RuleParser::LOGICAL_AND);
          setState(461);
          logicalExpr(4);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<LogicalExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleLogicalExpr);
          setState(462);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(463);
          match(RuleParser::LOGICAL_OR);
          setState(464);
          logicalExpr(3);
          break;
        }

        default:
          break;
        } 
      }
      setState(469);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- DefinitionStmtContext ------------------------------------------------------------------

RuleParser::DefinitionStmtContext::DefinitionStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::InstanceNameContext* RuleParser::DefinitionStmtContext::instanceName() {
  return getRuleContext<RuleParser::InstanceNameContext>(0);
}

tree::TerminalNode* RuleParser::DefinitionStmtContext::ASSIGN() {
  return getToken(RuleParser::ASSIGN, 0);
}

RuleParser::ExprContext* RuleParser::DefinitionStmtContext::expr() {
  return getRuleContext<RuleParser::ExprContext>(0);
}

RuleParser::SelectorIdentContext* RuleParser::DefinitionStmtContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}

RuleParser::AssignElementContext* RuleParser::DefinitionStmtContext::assignElement() {
  return getRuleContext<RuleParser::AssignElementContext>(0);
}


size_t RuleParser::DefinitionStmtContext::getRuleIndex() const {
  return RuleParser::RuleDefinitionStmt;
}

void RuleParser::DefinitionStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDefinitionStmt(this);
}

void RuleParser::DefinitionStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDefinitionStmt(this);
}


antlrcpp::Any RuleParser::DefinitionStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitDefinitionStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::DefinitionStmtContext* RuleParser::definitionStmt() {
  DefinitionStmtContext *_localctx = _tracker.createInstance<DefinitionStmtContext>(_ctx, getState());
  enterRule(_localctx, 96, RuleParser::RuleDefinitionStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(478);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(470);
      instanceName();
      setState(471);
      match(RuleParser::ASSIGN);
      setState(472);
      expr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(474);
      selectorIdent();
      setState(475);
      match(RuleParser::ASSIGN);
      setState(476);
      assignElement();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignElementContext ------------------------------------------------------------------

RuleParser::AssignElementContext::AssignElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::InstanceNameContext* RuleParser::AssignElementContext::instanceName() {
  return getRuleContext<RuleParser::InstanceNameContext>(0);
}

RuleParser::SelectorIdentContext* RuleParser::AssignElementContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}


size_t RuleParser::AssignElementContext::getRuleIndex() const {
  return RuleParser::RuleAssignElement;
}

void RuleParser::AssignElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignElement(this);
}

void RuleParser::AssignElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignElement(this);
}


antlrcpp::Any RuleParser::AssignElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAssignElement(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AssignElementContext* RuleParser::assignElement() {
  AssignElementContext *_localctx = _tracker.createInstance<AssignElementContext>(_ctx, getState());
  enterRule(_localctx, 98, RuleParser::RuleAssignElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(482);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(480);
      instanceName();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(481);
      selectorIdent();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstanceNameContext ------------------------------------------------------------------

RuleParser::InstanceNameContext::InstanceNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::InstanceNameContext::IDENTIFIER() {
  return getToken(RuleParser::IDENTIFIER, 0);
}


size_t RuleParser::InstanceNameContext::getRuleIndex() const {
  return RuleParser::RuleInstanceName;
}

void RuleParser::InstanceNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInstanceName(this);
}

void RuleParser::InstanceNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInstanceName(this);
}


antlrcpp::Any RuleParser::InstanceNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitInstanceName(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::InstanceNameContext* RuleParser::instanceName() {
  InstanceNameContext *_localctx = _tracker.createInstance<InstanceNameContext>(_ctx, getState());
  enterRule(_localctx, 100, RuleParser::RuleInstanceName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(RuleParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QueryExprContext ------------------------------------------------------------------

RuleParser::QueryExprContext::QueryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::QueryExprContext::WHERE() {
  return getToken(RuleParser::WHERE, 0);
}

RuleParser::ConditionExprContext* RuleParser::QueryExprContext::conditionExpr() {
  return getRuleContext<RuleParser::ConditionExprContext>(0);
}

tree::TerminalNode* RuleParser::QueryExprContext::SELECT() {
  return getToken(RuleParser::SELECT, 0);
}

tree::TerminalNode* RuleParser::QueryExprContext::COLLECT() {
  return getToken(RuleParser::COLLECT, 0);
}

RuleParser::EntityNameContext* RuleParser::QueryExprContext::entityName() {
  return getRuleContext<RuleParser::EntityNameContext>(0);
}

RuleParser::SelectorIdentContext* RuleParser::QueryExprContext::selectorIdent() {
  return getRuleContext<RuleParser::SelectorIdentContext>(0);
}


size_t RuleParser::QueryExprContext::getRuleIndex() const {
  return RuleParser::RuleQueryExpr;
}

void RuleParser::QueryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQueryExpr(this);
}

void RuleParser::QueryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQueryExpr(this);
}


antlrcpp::Any RuleParser::QueryExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitQueryExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::QueryExprContext* RuleParser::queryExpr() {
  QueryExprContext *_localctx = _tracker.createInstance<QueryExprContext>(_ctx, getState());
  enterRule(_localctx, 102, RuleParser::RuleQueryExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(486);
    _la = _input->LA(1);
    if (!(_la == RuleParser::SELECT

    || _la == RuleParser::COLLECT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(489);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 46, _ctx)) {
    case 1: {
      setState(487);
      entityName();
      break;
    }

    case 2: {
      setState(488);
      selectorIdent();
      break;
    }

    default:
      break;
    }
    setState(491);
    match(RuleParser::WHERE);
    setState(492);
    conditionExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionExprContext ------------------------------------------------------------------

RuleParser::ConditionExprContext::ConditionExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::BasicCondExprContext *> RuleParser::ConditionExprContext::basicCondExpr() {
  return getRuleContexts<RuleParser::BasicCondExprContext>();
}

RuleParser::BasicCondExprContext* RuleParser::ConditionExprContext::basicCondExpr(size_t i) {
  return getRuleContext<RuleParser::BasicCondExprContext>(i);
}

std::vector<RuleParser::LogicalOperatorContext *> RuleParser::ConditionExprContext::logicalOperator() {
  return getRuleContexts<RuleParser::LogicalOperatorContext>();
}

RuleParser::LogicalOperatorContext* RuleParser::ConditionExprContext::logicalOperator(size_t i) {
  return getRuleContext<RuleParser::LogicalOperatorContext>(i);
}


size_t RuleParser::ConditionExprContext::getRuleIndex() const {
  return RuleParser::RuleConditionExpr;
}

void RuleParser::ConditionExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionExpr(this);
}

void RuleParser::ConditionExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionExpr(this);
}


antlrcpp::Any RuleParser::ConditionExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitConditionExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ConditionExprContext* RuleParser::conditionExpr() {
  ConditionExprContext *_localctx = _tracker.createInstance<ConditionExprContext>(_ctx, getState());
  enterRule(_localctx, 104, RuleParser::RuleConditionExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(494);
    basicCondExpr();
    setState(500);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RuleParser::LOGICAL_OR

    || _la == RuleParser::LOGICAL_AND) {
      setState(495);
      logicalOperator();
      setState(496);
      basicCondExpr();
      setState(502);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalOperatorContext ------------------------------------------------------------------

RuleParser::LogicalOperatorContext::LogicalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::LogicalOperatorContext::LOGICAL_AND() {
  return getToken(RuleParser::LOGICAL_AND, 0);
}

tree::TerminalNode* RuleParser::LogicalOperatorContext::LOGICAL_OR() {
  return getToken(RuleParser::LOGICAL_OR, 0);
}


size_t RuleParser::LogicalOperatorContext::getRuleIndex() const {
  return RuleParser::RuleLogicalOperator;
}

void RuleParser::LogicalOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOperator(this);
}

void RuleParser::LogicalOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOperator(this);
}


antlrcpp::Any RuleParser::LogicalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitLogicalOperator(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::LogicalOperatorContext* RuleParser::logicalOperator() {
  LogicalOperatorContext *_localctx = _tracker.createInstance<LogicalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 106, RuleParser::RuleLogicalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(503);
    _la = _input->LA(1);
    if (!(_la == RuleParser::LOGICAL_OR

    || _la == RuleParser::LOGICAL_AND)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicCondExprContext ------------------------------------------------------------------

RuleParser::BasicCondExprContext::BasicCondExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::RelationExprContext* RuleParser::BasicCondExprContext::relationExpr() {
  return getRuleContext<RuleParser::RelationExprContext>(0);
}

RuleParser::ListExprContext* RuleParser::BasicCondExprContext::listExpr() {
  return getRuleContext<RuleParser::ListExprContext>(0);
}


size_t RuleParser::BasicCondExprContext::getRuleIndex() const {
  return RuleParser::RuleBasicCondExpr;
}

void RuleParser::BasicCondExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicCondExpr(this);
}

void RuleParser::BasicCondExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicCondExpr(this);
}


antlrcpp::Any RuleParser::BasicCondExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitBasicCondExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::BasicCondExprContext* RuleParser::basicCondExpr() {
  BasicCondExprContext *_localctx = _tracker.createInstance<BasicCondExprContext>(_ctx, getState());
  enterRule(_localctx, 108, RuleParser::RuleBasicCondExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(507);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(505);
      relationExpr();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(506);
      listExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

RuleParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::LogicalExprContext* RuleParser::ExprContext::logicalExpr() {
  return getRuleContext<RuleParser::LogicalExprContext>(0);
}

RuleParser::NumberExprContext* RuleParser::ExprContext::numberExpr() {
  return getRuleContext<RuleParser::NumberExprContext>(0);
}

RuleParser::QueryExprContext* RuleParser::ExprContext::queryExpr() {
  return getRuleContext<RuleParser::QueryExprContext>(0);
}


size_t RuleParser::ExprContext::getRuleIndex() const {
  return RuleParser::RuleExpr;
}

void RuleParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void RuleParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any RuleParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::ExprContext* RuleParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 110, RuleParser::RuleExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(512);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(509);
      logicalExpr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(510);
      numberExpr(0);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(511);
      queryExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignStmtContext ------------------------------------------------------------------

RuleParser::AssignStmtContext::AssignStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::AssignStmtContext::OUTPUT() {
  return getToken(RuleParser::OUTPUT, 0);
}

tree::TerminalNode* RuleParser::AssignStmtContext::ASSIGN() {
  return getToken(RuleParser::ASSIGN, 0);
}

tree::TerminalNode* RuleParser::AssignStmtContext::L_CURLY() {
  return getToken(RuleParser::L_CURLY, 0);
}

std::vector<RuleParser::AssignExprContext *> RuleParser::AssignStmtContext::assignExpr() {
  return getRuleContexts<RuleParser::AssignExprContext>();
}

RuleParser::AssignExprContext* RuleParser::AssignStmtContext::assignExpr(size_t i) {
  return getRuleContext<RuleParser::AssignExprContext>(i);
}

tree::TerminalNode* RuleParser::AssignStmtContext::R_CURLY() {
  return getToken(RuleParser::R_CURLY, 0);
}

std::vector<tree::TerminalNode *> RuleParser::AssignStmtContext::COMMA() {
  return getTokens(RuleParser::COMMA);
}

tree::TerminalNode* RuleParser::AssignStmtContext::COMMA(size_t i) {
  return getToken(RuleParser::COMMA, i);
}


size_t RuleParser::AssignStmtContext::getRuleIndex() const {
  return RuleParser::RuleAssignStmt;
}

void RuleParser::AssignStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignStmt(this);
}

void RuleParser::AssignStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignStmt(this);
}


antlrcpp::Any RuleParser::AssignStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAssignStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AssignStmtContext* RuleParser::assignStmt() {
  AssignStmtContext *_localctx = _tracker.createInstance<AssignStmtContext>(_ctx, getState());
  enterRule(_localctx, 112, RuleParser::RuleAssignStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(514);
    match(RuleParser::OUTPUT);
    setState(515);
    match(RuleParser::ASSIGN);
    setState(516);
    match(RuleParser::L_CURLY);
    setState(517);
    assignExpr();
    setState(522);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == RuleParser::COMMA) {
      setState(518);
      match(RuleParser::COMMA);
      setState(519);
      assignExpr();
      setState(524);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(525);
    match(RuleParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignExprContext ------------------------------------------------------------------

RuleParser::AssignExprContext::AssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::AttributeNameContext* RuleParser::AssignExprContext::attributeName() {
  return getRuleContext<RuleParser::AttributeNameContext>(0);
}

tree::TerminalNode* RuleParser::AssignExprContext::COLON() {
  return getToken(RuleParser::COLON, 0);
}

RuleParser::ExprContext* RuleParser::AssignExprContext::expr() {
  return getRuleContext<RuleParser::ExprContext>(0);
}


size_t RuleParser::AssignExprContext::getRuleIndex() const {
  return RuleParser::RuleAssignExpr;
}

void RuleParser::AssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignExpr(this);
}

void RuleParser::AssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignExpr(this);
}


antlrcpp::Any RuleParser::AssignExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitAssignExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::AssignExprContext* RuleParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 114, RuleParser::RuleAssignExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(527);
    attributeName();
    setState(528);
    match(RuleParser::COLON);
    setState(529);
    expr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

RuleParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::IfStmtContext::IF() {
  return getToken(RuleParser::IF, 0);
}

RuleParser::BooleanExprContext* RuleParser::IfStmtContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::IfStmtContext::THEN() {
  return getToken(RuleParser::THEN, 0);
}

std::vector<tree::TerminalNode *> RuleParser::IfStmtContext::L_CURLY() {
  return getTokens(RuleParser::L_CURLY);
}

tree::TerminalNode* RuleParser::IfStmtContext::L_CURLY(size_t i) {
  return getToken(RuleParser::L_CURLY, i);
}

std::vector<RuleParser::RuleStmtListContext *> RuleParser::IfStmtContext::ruleStmtList() {
  return getRuleContexts<RuleParser::RuleStmtListContext>();
}

RuleParser::RuleStmtListContext* RuleParser::IfStmtContext::ruleStmtList(size_t i) {
  return getRuleContext<RuleParser::RuleStmtListContext>(i);
}

std::vector<tree::TerminalNode *> RuleParser::IfStmtContext::R_CURLY() {
  return getTokens(RuleParser::R_CURLY);
}

tree::TerminalNode* RuleParser::IfStmtContext::R_CURLY(size_t i) {
  return getToken(RuleParser::R_CURLY, i);
}

tree::TerminalNode* RuleParser::IfStmtContext::ELSE() {
  return getToken(RuleParser::ELSE, 0);
}

RuleParser::IfStmtContext* RuleParser::IfStmtContext::ifStmt() {
  return getRuleContext<RuleParser::IfStmtContext>(0);
}


size_t RuleParser::IfStmtContext::getRuleIndex() const {
  return RuleParser::RuleIfStmt;
}

void RuleParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void RuleParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}


antlrcpp::Any RuleParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::IfStmtContext* RuleParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 116, RuleParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(531);
    match(RuleParser::IF);
    setState(532);
    booleanExpr();
    setState(533);
    match(RuleParser::THEN);
    setState(534);
    match(RuleParser::L_CURLY);
    setState(535);
    ruleStmtList();
    setState(536);
    match(RuleParser::R_CURLY);
    setState(545);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == RuleParser::ELSE) {
      setState(537);
      match(RuleParser::ELSE);
      setState(543);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case RuleParser::IF: {
          setState(538);
          ifStmt();
          break;
        }

        case RuleParser::L_CURLY: {
          setState(539);
          match(RuleParser::L_CURLY);
          setState(540);
          ruleStmtList();
          setState(541);
          match(RuleParser::R_CURLY);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequentialStmtContext ------------------------------------------------------------------

RuleParser::SequentialStmtContext::SequentialStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::SequentialExprContext* RuleParser::SequentialStmtContext::sequentialExpr() {
  return getRuleContext<RuleParser::SequentialExprContext>(0);
}


size_t RuleParser::SequentialStmtContext::getRuleIndex() const {
  return RuleParser::RuleSequentialStmt;
}

void RuleParser::SequentialStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequentialStmt(this);
}

void RuleParser::SequentialStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequentialStmt(this);
}


antlrcpp::Any RuleParser::SequentialStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSequentialStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SequentialStmtContext* RuleParser::sequentialStmt() {
  SequentialStmtContext *_localctx = _tracker.createInstance<SequentialStmtContext>(_ctx, getState());
  enterRule(_localctx, 118, RuleParser::RuleSequentialStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    sequentialExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SequentialExprContext ------------------------------------------------------------------

RuleParser::SequentialExprContext::SequentialExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<RuleParser::EntityNameContext *> RuleParser::SequentialExprContext::entityName() {
  return getRuleContexts<RuleParser::EntityNameContext>();
}

RuleParser::EntityNameContext* RuleParser::SequentialExprContext::entityName(size_t i) {
  return getRuleContext<RuleParser::EntityNameContext>(i);
}

tree::TerminalNode* RuleParser::SequentialExprContext::BEFORE() {
  return getToken(RuleParser::BEFORE, 0);
}

tree::TerminalNode* RuleParser::SequentialExprContext::AFTER() {
  return getToken(RuleParser::AFTER, 0);
}

tree::TerminalNode* RuleParser::SequentialExprContext::FOLLOW() {
  return getToken(RuleParser::FOLLOW, 0);
}


size_t RuleParser::SequentialExprContext::getRuleIndex() const {
  return RuleParser::RuleSequentialExpr;
}

void RuleParser::SequentialExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSequentialExpr(this);
}

void RuleParser::SequentialExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSequentialExpr(this);
}


antlrcpp::Any RuleParser::SequentialExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitSequentialExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::SequentialExprContext* RuleParser::sequentialExpr() {
  SequentialExprContext *_localctx = _tracker.createInstance<SequentialExprContext>(_ctx, getState());
  enterRule(_localctx, 120, RuleParser::RuleSequentialExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(549);
    entityName();
    setState(550);
    _la = _input->LA(1);
    if (!(((((_la - 66) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 66)) & ((1ULL << (RuleParser::BEFORE - 66))
      | (1ULL << (RuleParser::AFTER - 66))
      | (1ULL << (RuleParser::FOLLOW - 66)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(551);
    entityName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateStmtContext ------------------------------------------------------------------

RuleParser::DateStmtContext::DateStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::DateExprContext* RuleParser::DateStmtContext::dateExpr() {
  return getRuleContext<RuleParser::DateExprContext>(0);
}


size_t RuleParser::DateStmtContext::getRuleIndex() const {
  return RuleParser::RuleDateStmt;
}

void RuleParser::DateStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDateStmt(this);
}

void RuleParser::DateStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDateStmt(this);
}


antlrcpp::Any RuleParser::DateStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitDateStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::DateStmtContext* RuleParser::dateStmt() {
  DateStmtContext *_localctx = _tracker.createInstance<DateStmtContext>(_ctx, getState());
  enterRule(_localctx, 122, RuleParser::RuleDateStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    dateExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DateExprContext ------------------------------------------------------------------

RuleParser::DateExprContext::DateExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::BooleanExprContext* RuleParser::DateExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::DateExprContext::DATE_LIT() {
  return getToken(RuleParser::DATE_LIT, 0);
}

tree::TerminalNode* RuleParser::DateExprContext::BEFORE() {
  return getToken(RuleParser::BEFORE, 0);
}

tree::TerminalNode* RuleParser::DateExprContext::AFTER() {
  return getToken(RuleParser::AFTER, 0);
}


size_t RuleParser::DateExprContext::getRuleIndex() const {
  return RuleParser::RuleDateExpr;
}

void RuleParser::DateExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDateExpr(this);
}

void RuleParser::DateExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDateExpr(this);
}


antlrcpp::Any RuleParser::DateExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitDateExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::DateExprContext* RuleParser::dateExpr() {
  DateExprContext *_localctx = _tracker.createInstance<DateExprContext>(_ctx, getState());
  enterRule(_localctx, 124, RuleParser::RuleDateExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(555);
    booleanExpr();
    setState(556);
    _la = _input->LA(1);
    if (!(_la == RuleParser::BEFORE

    || _la == RuleParser::AFTER)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(557);
    match(RuleParser::DATE_LIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeStmtContext ------------------------------------------------------------------

RuleParser::TimeStmtContext::TimeStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::TimeExprContext* RuleParser::TimeStmtContext::timeExpr() {
  return getRuleContext<RuleParser::TimeExprContext>(0);
}


size_t RuleParser::TimeStmtContext::getRuleIndex() const {
  return RuleParser::RuleTimeStmt;
}

void RuleParser::TimeStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeStmt(this);
}

void RuleParser::TimeStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeStmt(this);
}


antlrcpp::Any RuleParser::TimeStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitTimeStmt(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::TimeStmtContext* RuleParser::timeStmt() {
  TimeStmtContext *_localctx = _tracker.createInstance<TimeStmtContext>(_ctx, getState());
  enterRule(_localctx, 126, RuleParser::RuleTimeStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(559);
    timeExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TimeExprContext ------------------------------------------------------------------

RuleParser::TimeExprContext::TimeExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

RuleParser::BooleanExprContext* RuleParser::TimeExprContext::booleanExpr() {
  return getRuleContext<RuleParser::BooleanExprContext>(0);
}

tree::TerminalNode* RuleParser::TimeExprContext::WITHIN() {
  return getToken(RuleParser::WITHIN, 0);
}

tree::TerminalNode* RuleParser::TimeExprContext::TIME_LIT() {
  return getToken(RuleParser::TIME_LIT, 0);
}


size_t RuleParser::TimeExprContext::getRuleIndex() const {
  return RuleParser::RuleTimeExpr;
}

void RuleParser::TimeExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTimeExpr(this);
}

void RuleParser::TimeExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTimeExpr(this);
}


antlrcpp::Any RuleParser::TimeExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitTimeExpr(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::TimeExprContext* RuleParser::timeExpr() {
  TimeExprContext *_localctx = _tracker.createInstance<TimeExprContext>(_ctx, getState());
  enterRule(_localctx, 128, RuleParser::RuleTimeExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(561);
    booleanExpr();
    setState(562);
    match(RuleParser::WITHIN);
    setState(563);
    match(RuleParser::TIME_LIT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EosContext ------------------------------------------------------------------

RuleParser::EosContext::EosContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* RuleParser::EosContext::SEMI() {
  return getToken(RuleParser::SEMI, 0);
}

tree::TerminalNode* RuleParser::EosContext::TERMINATOR() {
  return getToken(RuleParser::TERMINATOR, 0);
}

tree::TerminalNode* RuleParser::EosContext::EOF() {
  return getToken(RuleParser::EOF, 0);
}


size_t RuleParser::EosContext::getRuleIndex() const {
  return RuleParser::RuleEos;
}

void RuleParser::EosContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEos(this);
}

void RuleParser::EosContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<RuleParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEos(this);
}


antlrcpp::Any RuleParser::EosContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<RuleParserVisitor*>(visitor))
    return parserVisitor->visitEos(this);
  else
    return visitor->visitChildren(this);
}

RuleParser::EosContext* RuleParser::eos() {
  EosContext *_localctx = _tracker.createInstance<EosContext>(_ctx, getState());
  enterRule(_localctx, 130, RuleParser::RuleEos);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(569);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 53, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(565);
      match(RuleParser::SEMI);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(566);
      match(RuleParser::TERMINATOR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);

      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(568);
      match(RuleParser::EOF);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    // _localctx->exception = std::current_exception();
    // _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool RuleParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 41: return numberExprSempred(dynamic_cast<NumberExprContext *>(context), predicateIndex);
    case 47: return logicalExprSempred(dynamic_cast<LogicalExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool RuleParser::numberExprSempred(NumberExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 3);
    case 1: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool RuleParser::logicalExprSempred(LogicalExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> RuleParser::_decisionToDFA;
atn::PredictionContextCache RuleParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN RuleParser::_atn;
std::vector<uint16_t> RuleParser::_serializedATN;

std::vector<std::string> RuleParser::_ruleNames = {
  "root", "taskDecl", "inputBlock", "outputBlock", "outputDecl", "outputAttribute", 
  "outputObject", "objectName", "entitiesBlock", "entityList", "entityDecl", 
  "entityName", "attributeList", "attributeDecl", "attributeName", "typeAnno", 
  "basicType", "compositeType", "listType", "executionBlock", "executionStmt", 
  "executeRuleDef", "executionTrueStmt", "executionFalseStmt", "rulesBlock", 
  "ruleList", "basicRule", "ruleName", "ruleStmtList", "ruleStmt", "simpleStmt", 
  "complexStmt", "listStmt", "listExpr", "listFirstExpr", "listSecondExpr", 
  "relationStmt", "relationExpr", "stringExpr", "compareOperator", "relationOperator", 
  "numberExpr", "selectorIdent", "aggregationExpr", "booleanExpr", "booleanLiteral", 
  "logicalStmt", "logicalExpr", "definitionStmt", "assignElement", "instanceName", 
  "queryExpr", "conditionExpr", "logicalOperator", "basicCondExpr", "expr", 
  "assignStmt", "assignExpr", "ifStmt", "sequentialStmt", "sequentialExpr", 
  "dateStmt", "dateExpr", "timeStmt", "timeExpr", "eos"
};

std::vector<std::string> RuleParser::_literalNames = {
  "", "'task'", "'entities'", "'rules'", "'input'", "'output'", "'execute'", 
  "'references'", "'entity'", "'unique'", "'article'", "'rule'", "'number'", 
  "'string'", "'boolean'", "'date'", "'set'", "'list'", "", "", "", "", 
  "", "", "'alias'", "'state'", "'event'", "'true'", "'false'", "'select'", 
  "'collect'", "'check'", "'else'", "'if'", "'then'", "'('", "')'", "'{'", 
  "'}'", "'['", "']'", "'='", "','", "';'", "':'", "'.'", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "'is'", "'within'", 
  "'before'", "'after'", "'follow'", "'accumulate'", "'count'", "'on'", 
  "'provided'", "'where'"
};

std::vector<std::string> RuleParser::_symbolicNames = {
  "", "TASK", "ENTITIES", "RULES", "INPUT", "OUTPUT", "EXECUTE", "REFERENCES", 
  "ENTITY", "UNIQUE", "ARTICLE", "RULE", "NUMBER", "STRING", "BOOLEAN", 
  "DATE", "SET", "LIST", "YEAR", "MONTH", "DAY", "HOUR", "MINUTE", "SECOND", 
  "ALIAS", "STATE", "EVENT", "TRUE", "FALSE", "SELECT", "COLLECT", "CHECK", 
  "ELSE", "IF", "THEN", "L_PAREN", "R_PAREN", "L_CURLY", "R_CURLY", "L_BRACKET", 
  "R_BRACKET", "ASSIGN", "COMMA", "SEMI", "COLON", "DOT", "LOGICAL_OR", 
  "LOGICAL_AND", "LOGICAL_NOT", "SET_IN", "SET_NOT_IN", "SET_UNION", "SET_INTERSECT", 
  "EQUALS", "NOT_EQUALS", "LESS_THAN", "LESS_OR_EQUALS", "GREATER_THAN", 
  "GREATER_OR_EQUALS", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", 
  "IS", "WITHIN", "BEFORE", "AFTER", "FOLLOW", "ACCUMULATE", "COUNT", "ON", 
  "PROVIDED", "WHERE", "DECIMAL_LIT", "DECIMAL_FLOAT_LIT", "DATE_LIT", "TIME_LIT", 
  "RUNE_LIT", "BYTE_VALUE", "OCTAL_BYTE_VALUE", "HEX_BYTE_VALUE", "LITTLE_U_VALUE", 
  "BIG_U_VALUE", "RAW_STRING_LIT", "INTERPRETED_STRING_LIT", "IDENTIFIER", 
  "WS", "COMMENT", "TERMINATOR", "LINE_COMMENT"
};

dfa::Vocabulary RuleParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> RuleParser::_tokenNames;

RuleParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x5c, 0x23e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x4, 
    0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 0x9, 0x3b, 0x4, 0x3c, 
    0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 0x9, 0x3e, 0x4, 0x3f, 0x9, 
    0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 
    0x4, 0x43, 0x9, 0x43, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x8a, 
    0xa, 0x2, 0x3, 0x2, 0x5, 0x2, 0x8d, 0xa, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x97, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x9a, 0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x6, 0x5, 0xa4, 
    0xa, 0x5, 0xd, 0x5, 0xe, 0x5, 0xa5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x5, 0x6, 0xac, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x6, 0x8, 0xb5, 0xa, 0x8, 0xd, 0x8, 0xe, 
    0x8, 0xb6, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x6, 0xb, 0xc4, 0xa, 
    0xb, 0xd, 0xb, 0xe, 0xb, 0xc5, 0x3, 0xc, 0x5, 0xc, 0xc9, 0xa, 0xc, 0x3, 
    0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xe, 0x6, 0xe, 0xd4, 0xa, 0xe, 0xd, 0xe, 0xe, 0xe, 0xd5, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xdb, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0xe1, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x5, 
    0x14, 0xeb, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
    0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0xfa, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 
    0x5, 0x17, 0xfe, 0xa, 0x17, 0x3, 0x17, 0x5, 0x17, 0x101, 0xa, 0x17, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x5, 
    0x18, 0x109, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x111, 0xa, 0x19, 0x3, 0x1a, 0x3, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x6, 0x1b, 0x119, 0xa, 0x1b, 
    0xd, 0x1b, 0xe, 0x1b, 0x11a, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x6, 0x1e, 0x126, 
    0xa, 0x1e, 0xd, 0x1e, 0xe, 0x1e, 0x127, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
    0x12c, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
    0x5, 0x20, 0x133, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x5, 0x21, 0x139, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x5, 
    0x23, 0x145, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x149, 0xa, 
    0x24, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x14d, 0xa, 0x25, 0x3, 0x26, 
    0x3, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 
    0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 
    0x5, 0x27, 0x15d, 0xa, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 
    0x162, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x5, 0x2b, 0x172, 0xa, 0x2b, 0x3, 0x2b, 
    0x5, 0x2b, 0x175, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x3, 0x2b, 0x7, 0x2b, 0x17d, 0xa, 0x2b, 0xc, 0x2b, 0xe, 0x2b, 
    0x180, 0xb, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x7, 0x2d, 0x18e, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 0x191, 0xb, 
    0x2d, 0x5, 0x2d, 0x193, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
    0x197, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x5, 0x2d, 
    0x19d, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x7, 0x2d, 0x1a6, 0xa, 0x2d, 0xc, 0x2d, 0xe, 0x2d, 
    0x1a9, 0xb, 0x2d, 0x5, 0x2d, 0x1ab, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x5, 0x2d, 0x1af, 0xa, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x5, 0x2d, 0x1b5, 0xa, 0x2d, 0x5, 0x2d, 0x1b7, 0xa, 0x2d, 0x3, 0x2e, 
    0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
    0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1c2, 0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 
    0x31, 0x1cc, 0xa, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x7, 0x31, 0x1d4, 0xa, 0x31, 0xc, 0x31, 0xe, 0x31, 
    0x1d7, 0xb, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x1e1, 0xa, 0x32, 0x3, 0x33, 
    0x3, 0x33, 0x5, 0x33, 0x1e5, 0xa, 0x33, 0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x1ec, 0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 
    0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 0x7, 0x36, 0x1f5, 
    0xa, 0x36, 0xc, 0x36, 0xe, 0x36, 0x1f8, 0xb, 0x36, 0x3, 0x37, 0x3, 0x37, 
    0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x1fe, 0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 
    0x3, 0x39, 0x5, 0x39, 0x203, 0xa, 0x39, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 
    0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x7, 0x3a, 0x20b, 0xa, 0x3a, 0xc, 0x3a, 
    0xe, 0x3a, 0x20e, 0xb, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 0x3b, 
    0x3, 0x3b, 0x3, 0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 
    0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3c, 
    0x3, 0x3c, 0x5, 0x3c, 0x222, 0xa, 0x3c, 0x5, 0x3c, 0x224, 0xa, 0x3c, 
    0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 
    0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 
    0x3, 0x41, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x43, 0x3, 
    0x43, 0x3, 0x43, 0x3, 0x43, 0x5, 0x43, 0x23c, 0xa, 0x43, 0x3, 0x43, 
    0x2, 0x4, 0x54, 0x60, 0x44, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 
    0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 
    0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 
    0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 
    0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 
    0x72, 0x74, 0x76, 0x78, 0x7a, 0x7c, 0x7e, 0x80, 0x82, 0x84, 0x2, 0xd, 
    0x3, 0x2, 0xe, 0x11, 0x3, 0x2, 0x33, 0x34, 0x3, 0x2, 0x37, 0x38, 0x3, 
    0x2, 0x37, 0x3c, 0x3, 0x2, 0x3f, 0x41, 0x3, 0x2, 0x3d, 0x3e, 0x3, 0x2, 
    0x44, 0x45, 0x3, 0x2, 0x1d, 0x1e, 0x3, 0x2, 0x1f, 0x20, 0x3, 0x2, 0x30, 
    0x31, 0x3, 0x2, 0x44, 0x46, 0x2, 0x244, 0x2, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0x92, 0x3, 0x2, 0x2, 0x2, 0x6, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x8, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0xab, 0x3, 0x2, 0x2, 0x2, 0xc, 0xad, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x10, 0xba, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x14, 0xc3, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0xc8, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd0, 0x3, 0x2, 0x2, 0x2, 0x1a, 
    0xd3, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xd7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xdc, 
    0x3, 0x2, 0x2, 0x2, 0x20, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x22, 0xe2, 0x3, 
    0x2, 0x2, 0x2, 0x24, 0xe4, 0x3, 0x2, 0x2, 0x2, 0x26, 0xe6, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0xee, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xf9, 0x3, 0x2, 0x2, 
    0x2, 0x2c, 0xfb, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x108, 0x3, 0x2, 0x2, 0x2, 
    0x30, 0x110, 0x3, 0x2, 0x2, 0x2, 0x32, 0x112, 0x3, 0x2, 0x2, 0x2, 0x34, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x36, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x38, 0x122, 
    0x3, 0x2, 0x2, 0x2, 0x3a, 0x125, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x12b, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x132, 0x3, 0x2, 0x2, 0x2, 0x40, 0x138, 0x3, 0x2, 
    0x2, 0x2, 0x42, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x44, 0x144, 0x3, 0x2, 0x2, 
    0x2, 0x46, 0x148, 0x3, 0x2, 0x2, 0x2, 0x48, 0x14c, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x4e, 
    0x161, 0x3, 0x2, 0x2, 0x2, 0x50, 0x163, 0x3, 0x2, 0x2, 0x2, 0x52, 0x165, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x174, 0x3, 0x2, 0x2, 0x2, 0x56, 0x181, 0x3, 
    0x2, 0x2, 0x2, 0x58, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x1c1, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1c5, 0x3, 0x2, 0x2, 
    0x2, 0x60, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1e0, 0x3, 0x2, 0x2, 0x2, 
    0x64, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x1e8, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x1f9, 
    0x3, 0x2, 0x2, 0x2, 0x6e, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x70, 0x202, 0x3, 
    0x2, 0x2, 0x2, 0x72, 0x204, 0x3, 0x2, 0x2, 0x2, 0x74, 0x211, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x215, 0x3, 0x2, 0x2, 0x2, 0x78, 0x225, 0x3, 0x2, 0x2, 
    0x2, 0x7a, 0x227, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x22b, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x22d, 0x3, 0x2, 0x2, 0x2, 0x80, 0x231, 0x3, 0x2, 0x2, 0x2, 0x82, 
    0x233, 0x3, 0x2, 0x2, 0x2, 0x84, 0x23b, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 
    0x5, 0x4, 0x3, 0x2, 0x87, 0x89, 0x5, 0x12, 0xa, 0x2, 0x88, 0x8a, 0x5, 
    0x6, 0x4, 0x2, 0x89, 0x88, 0x3, 0x2, 0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 
    0x2, 0x2, 0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x8, 0x5, 
    0x2, 0x8c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0x32, 0x1a, 0x2, 0x8f, 
    0x90, 0x5, 0x28, 0x15, 0x2, 0x90, 0x91, 0x7, 0x2, 0x2, 0x3, 0x91, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x7, 0x3, 0x2, 0x2, 0x93, 0x98, 0x7, 
    0x58, 0x2, 0x2, 0x94, 0x95, 0x7, 0x2f, 0x2, 0x2, 0x95, 0x97, 0x7, 0x58, 
    0x2, 0x2, 0x96, 0x94, 0x3, 0x2, 0x2, 0x2, 0x97, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x99, 0x5, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x9c, 0x7, 0x6, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x27, 0x2, 0x2, 0x9d, 0x9e, 
    0x5, 0x1a, 0xe, 0x2, 0x9e, 0x9f, 0x7, 0x28, 0x2, 0x2, 0x9f, 0x7, 0x3, 
    0x2, 0x2, 0x2, 0xa0, 0xa1, 0x7, 0x7, 0x2, 0x2, 0xa1, 0xa3, 0x7, 0x27, 
    0x2, 0x2, 0xa2, 0xa4, 0x5, 0xa, 0x6, 0x2, 0xa3, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 0x3, 0x2, 0x2, 0x2, 
    0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 
    0xa8, 0x7, 0x28, 0x2, 0x2, 0xa8, 0x9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xac, 
    0x5, 0xc, 0x7, 0x2, 0xaa, 0xac, 0x5, 0xe, 0x8, 0x2, 0xab, 0xa9, 0x3, 
    0x2, 0x2, 0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0xad, 0xae, 0x5, 0x1e, 0x10, 0x2, 0xae, 0xaf, 0x7, 0x42, 0x2, 
    0x2, 0xaf, 0xb0, 0x5, 0x20, 0x11, 0x2, 0xb0, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb2, 0x5, 0x10, 0x9, 0x2, 0xb2, 0xb4, 0x7, 0x27, 0x2, 0x2, 0xb3, 
    0xb5, 0x5, 0xa, 0x6, 0x2, 0xb4, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 
    0x3, 0x2, 0x2, 0x2, 0xb6, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x28, 
    0x2, 0x2, 0xb9, 0xf, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x7, 0x58, 0x2, 
    0x2, 0xbb, 0x11, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x4, 0x2, 0x2, 
    0xbd, 0xbe, 0x7, 0x58, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x27, 0x2, 0x2, 0xbf, 
    0xc0, 0x5, 0x14, 0xb, 0x2, 0xc0, 0xc1, 0x7, 0x28, 0x2, 0x2, 0xc1, 0x13, 
    0x3, 0x2, 0x2, 0x2, 0xc2, 0xc4, 0x5, 0x16, 0xc, 0x2, 0xc3, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xc4, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc3, 0x3, 0x2, 
    0x2, 0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0xc7, 0xc9, 0x7, 0xb, 0x2, 0x2, 0xc8, 0xc7, 0x3, 0x2, 0x2, 0x2, 
    0xc8, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 0x2, 0xca, 
    0xcb, 0x7, 0xa, 0x2, 0x2, 0xcb, 0xcc, 0x5, 0x18, 0xd, 0x2, 0xcc, 0xcd, 
    0x7, 0x27, 0x2, 0x2, 0xcd, 0xce, 0x5, 0x1a, 0xe, 0x2, 0xce, 0xcf, 0x7, 
    0x28, 0x2, 0x2, 0xcf, 0x17, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x58, 
    0x2, 0x2, 0xd1, 0x19, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x1c, 0xf, 
    0x2, 0xd3, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 
    0x1b, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xda, 0x5, 0x1e, 0x10, 0x2, 0xd8, 0xd9, 
    0x7, 0x42, 0x2, 0x2, 0xd9, 0xdb, 0x5, 0x20, 0x11, 0x2, 0xda, 0xd8, 0x3, 
    0x2, 0x2, 0x2, 0xda, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdb, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0xdc, 0xdd, 0x7, 0x58, 0x2, 0x2, 0xdd, 0x1f, 0x3, 0x2, 0x2, 
    0x2, 0xde, 0xe1, 0x5, 0x24, 0x13, 0x2, 0xdf, 0xe1, 0x5, 0x22, 0x12, 
    0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xdf, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0x21, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x9, 0x2, 0x2, 0x2, 0xe3, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 0x5, 0x26, 0x14, 0x2, 0xe5, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0xe6, 0xe7, 0x7, 0x13, 0x2, 0x2, 0xe7, 0xea, 0x7, 
    0x29, 0x2, 0x2, 0xe8, 0xeb, 0x5, 0x22, 0x12, 0x2, 0xe9, 0xeb, 0x7, 0x58, 
    0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 
    0x2, 0xeb, 0xec, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x2a, 0x2, 0x2, 
    0xed, 0x27, 0x3, 0x2, 0x2, 0x2, 0xee, 0xef, 0x7, 0x8, 0x2, 0x2, 0xef, 
    0xf0, 0x7, 0x27, 0x2, 0x2, 0xf0, 0xf1, 0x5, 0x2a, 0x16, 0x2, 0xf1, 0xf2, 
    0x7, 0x28, 0x2, 0x2, 0xf2, 0x29, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x7, 
    0x21, 0x2, 0x2, 0xf4, 0xf5, 0x7, 0xd, 0x2, 0x2, 0xf5, 0xfa, 0x5, 0x2c, 
    0x17, 0x2, 0xf6, 0xf7, 0x7, 0x21, 0x2, 0x2, 0xf7, 0xf8, 0x7, 0xd, 0x2, 
    0x2, 0xf8, 0xfa, 0x5, 0x38, 0x1d, 0x2, 0xf9, 0xf3, 0x3, 0x2, 0x2, 0x2, 
    0xf9, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xfa, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xfb, 
    0xfd, 0x5, 0x38, 0x1d, 0x2, 0xfc, 0xfe, 0x5, 0x2e, 0x18, 0x2, 0xfd, 
    0xfc, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0x101, 0x5, 0x30, 0x19, 0x2, 0x100, 0xff, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x102, 0x103, 0x7, 0x1d, 0x2, 0x2, 0x103, 0x104, 0x7, 
    0x2e, 0x2, 0x2, 0x104, 0x109, 0x5, 0x38, 0x1d, 0x2, 0x105, 0x106, 0x7, 
    0x1d, 0x2, 0x2, 0x106, 0x107, 0x7, 0x2e, 0x2, 0x2, 0x107, 0x109, 0x5, 
    0x2c, 0x17, 0x2, 0x108, 0x102, 0x3, 0x2, 0x2, 0x2, 0x108, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x109, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x1e, 
    0x2, 0x2, 0x10b, 0x10c, 0x7, 0x2e, 0x2, 0x2, 0x10c, 0x111, 0x5, 0x38, 
    0x1d, 0x2, 0x10d, 0x10e, 0x7, 0x1e, 0x2, 0x2, 0x10e, 0x10f, 0x7, 0x2e, 
    0x2, 0x2, 0x10f, 0x111, 0x5, 0x2c, 0x17, 0x2, 0x110, 0x10a, 0x3, 0x2, 
    0x2, 0x2, 0x110, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x111, 0x31, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x113, 0x7, 0x5, 0x2, 0x2, 0x113, 0x114, 0x7, 0x27, 0x2, 
    0x2, 0x114, 0x115, 0x5, 0x34, 0x1b, 0x2, 0x115, 0x116, 0x7, 0x28, 0x2, 
    0x2, 0x116, 0x33, 0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 0x5, 0x36, 0x1c, 
    0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 
    0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x3, 0x2, 0x2, 
    0x2, 0x11b, 0x35, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x7, 0xd, 0x2, 0x2, 
    0x11d, 0x11e, 0x5, 0x38, 0x1d, 0x2, 0x11e, 0x11f, 0x7, 0x27, 0x2, 0x2, 
    0x11f, 0x120, 0x5, 0x3a, 0x1e, 0x2, 0x120, 0x121, 0x7, 0x28, 0x2, 0x2, 
    0x121, 0x37, 0x3, 0x2, 0x2, 0x2, 0x122, 0x123, 0x7, 0x58, 0x2, 0x2, 
    0x123, 0x39, 0x3, 0x2, 0x2, 0x2, 0x124, 0x126, 0x5, 0x3c, 0x1f, 0x2, 
    0x125, 0x124, 0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 
    0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 
    0x128, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12c, 0x5, 0x3e, 0x20, 0x2, 
    0x12a, 0x12c, 0x5, 0x40, 0x21, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 
    0x12b, 0x12a, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x12d, 
    0x133, 0x5, 0x42, 0x22, 0x2, 0x12e, 0x133, 0x5, 0x4a, 0x26, 0x2, 0x12f, 
    0x133, 0x5, 0x5e, 0x30, 0x2, 0x130, 0x133, 0x5, 0x62, 0x32, 0x2, 0x131, 
    0x133, 0x5, 0x72, 0x3a, 0x2, 0x132, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x12e, 0x3, 0x2, 0x2, 0x2, 0x132, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x132, 
    0x130, 0x3, 0x2, 0x2, 0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 
    0x3f, 0x3, 0x2, 0x2, 0x2, 0x134, 0x139, 0x5, 0x76, 0x3c, 0x2, 0x135, 
    0x139, 0x5, 0x78, 0x3d, 0x2, 0x136, 0x139, 0x5, 0x7c, 0x3f, 0x2, 0x137, 
    0x139, 0x5, 0x80, 0x41, 0x2, 0x138, 0x134, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x135, 0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 
    0x137, 0x3, 0x2, 0x2, 0x2, 0x139, 0x41, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13b, 
    0x5, 0x44, 0x23, 0x2, 0x13b, 0x43, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x13d, 
    0x7, 0x25, 0x2, 0x2, 0x13d, 0x13e, 0x5, 0x44, 0x23, 0x2, 0x13e, 0x13f, 
    0x7, 0x26, 0x2, 0x2, 0x13f, 0x145, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 
    0x5, 0x46, 0x24, 0x2, 0x141, 0x142, 0x9, 0x3, 0x2, 0x2, 0x142, 0x143, 
    0x5, 0x48, 0x25, 0x2, 0x143, 0x145, 0x3, 0x2, 0x2, 0x2, 0x144, 0x13c, 
    0x3, 0x2, 0x2, 0x2, 0x144, 0x140, 0x3, 0x2, 0x2, 0x2, 0x145, 0x45, 0x3, 
    0x2, 0x2, 0x2, 0x146, 0x149, 0x5, 0x66, 0x34, 0x2, 0x147, 0x149, 0x5, 
    0x56, 0x2c, 0x2, 0x148, 0x146, 0x3, 0x2, 0x2, 0x2, 0x148, 0x147, 0x3, 
    0x2, 0x2, 0x2, 0x149, 0x47, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14d, 0x5, 0x66, 
    0x34, 0x2, 0x14b, 0x14d, 0x5, 0x56, 0x2c, 0x2, 0x14c, 0x14a, 0x3, 0x2, 
    0x2, 0x2, 0x14c, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x14e, 0x14f, 0x5, 0x4c, 0x27, 0x2, 0x14f, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x150, 0x151, 0x7, 0x25, 0x2, 0x2, 0x151, 0x152, 0x5, 0x4c, 0x27, 
    0x2, 0x152, 0x153, 0x7, 0x26, 0x2, 0x2, 0x153, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x154, 0x155, 0x5, 0x54, 0x2b, 0x2, 0x155, 0x156, 0x5, 0x52, 0x2a, 
    0x2, 0x156, 0x157, 0x5, 0x54, 0x2b, 0x2, 0x157, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x158, 0x159, 0x5, 0x4e, 0x28, 0x2, 0x159, 0x15a, 0x5, 0x50, 0x29, 
    0x2, 0x15a, 0x15b, 0x5, 0x4e, 0x28, 0x2, 0x15b, 0x15d, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x150, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x154, 0x3, 0x2, 0x2, 
    0x2, 0x15c, 0x158, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x15e, 0x162, 0x5, 0x66, 0x34, 0x2, 0x15f, 0x162, 0x5, 0x56, 0x2c, 0x2, 
    0x160, 0x162, 0x7, 0x57, 0x2, 0x2, 0x161, 0x15e, 0x3, 0x2, 0x2, 0x2, 
    0x161, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x161, 0x160, 0x3, 0x2, 0x2, 0x2, 
    0x162, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x9, 0x4, 0x2, 0x2, 0x164, 
    0x51, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x9, 0x5, 0x2, 0x2, 0x166, 0x53, 
    0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x8, 0x2b, 0x1, 0x2, 0x168, 0x169, 
    0x7, 0x25, 0x2, 0x2, 0x169, 0x16a, 0x5, 0x54, 0x2b, 0x2, 0x16a, 0x16b, 
    0x7, 0x26, 0x2, 0x2, 0x16b, 0x175, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 
    0x7, 0x3e, 0x2, 0x2, 0x16d, 0x175, 0x5, 0x54, 0x2b, 0x7, 0x16e, 0x172, 
    0x5, 0x56, 0x2c, 0x2, 0x16f, 0x172, 0x7, 0x4c, 0x2, 0x2, 0x170, 0x172, 
    0x7, 0x4d, 0x2, 0x2, 0x171, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x171, 0x16f, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x170, 0x3, 0x2, 0x2, 0x2, 0x172, 0x175, 
    0x3, 0x2, 0x2, 0x2, 0x173, 0x175, 0x5, 0x58, 0x2d, 0x2, 0x174, 0x167, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x16c, 0x3, 0x2, 0x2, 0x2, 0x174, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x174, 0x173, 0x3, 0x2, 0x2, 0x2, 0x175, 0x17e, 
    0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0xc, 0x5, 0x2, 0x2, 0x177, 0x178, 
    0x9, 0x6, 0x2, 0x2, 0x178, 0x17d, 0x5, 0x54, 0x2b, 0x6, 0x179, 0x17a, 
    0xc, 0x4, 0x2, 0x2, 0x17a, 0x17b, 0x9, 0x7, 0x2, 0x2, 0x17b, 0x17d, 
    0x5, 0x54, 0x2b, 0x5, 0x17c, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17c, 0x179, 
    0x3, 0x2, 0x2, 0x2, 0x17d, 0x180, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17c, 
    0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x55, 0x3, 
    0x2, 0x2, 0x2, 0x180, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x5, 
    0x18, 0xd, 0x2, 0x182, 0x183, 0x7, 0x2f, 0x2, 0x2, 0x183, 0x184, 0x5, 
    0x1e, 0x10, 0x2, 0x184, 0x57, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x7, 
    0x47, 0x2, 0x2, 0x186, 0x187, 0x5, 0x54, 0x2b, 0x2, 0x187, 0x188, 0x7, 
    0x49, 0x2, 0x2, 0x188, 0x192, 0x5, 0x18, 0xd, 0x2, 0x189, 0x18a, 0x7, 
    0x4a, 0x2, 0x2, 0x18a, 0x18f, 0x5, 0x56, 0x2c, 0x2, 0x18b, 0x18c, 0x7, 
    0x31, 0x2, 0x2, 0x18c, 0x18e, 0x5, 0x56, 0x2c, 0x2, 0x18d, 0x18b, 0x3, 
    0x2, 0x2, 0x2, 0x18e, 0x191, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x18d, 0x3, 
    0x2, 0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 0x190, 0x193, 0x3, 
    0x2, 0x2, 0x2, 0x191, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x192, 0x189, 0x3, 
    0x2, 0x2, 0x2, 0x192, 0x193, 0x3, 0x2, 0x2, 0x2, 0x193, 0x196, 0x3, 
    0x2, 0x2, 0x2, 0x194, 0x195, 0x7, 0x4b, 0x2, 0x2, 0x195, 0x197, 0x5, 
    0x60, 0x31, 0x2, 0x196, 0x194, 0x3, 0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 
    0x2, 0x2, 0x2, 0x197, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x198, 0x199, 0x9, 
    0x8, 0x2, 0x2, 0x199, 0x19d, 0x7, 0x4e, 0x2, 0x2, 0x19a, 0x19b, 0x7, 
    0x43, 0x2, 0x2, 0x19b, 0x19d, 0x7, 0x4f, 0x2, 0x2, 0x19c, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 0x3, 
    0x2, 0x2, 0x2, 0x19d, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 
    0x48, 0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x49, 0x2, 0x2, 0x1a0, 0x1aa, 0x5, 
    0x18, 0xd, 0x2, 0x1a1, 0x1a2, 0x7, 0x4a, 0x2, 0x2, 0x1a2, 0x1a7, 0x5, 
    0x56, 0x2c, 0x2, 0x1a3, 0x1a4, 0x7, 0x31, 0x2, 0x2, 0x1a4, 0x1a6, 0x5, 
    0x56, 0x2c, 0x2, 0x1a5, 0x1a3, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a9, 0x3, 
    0x2, 0x2, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 
    0x2, 0x2, 0x2, 0x1a8, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a7, 0x3, 
    0x2, 0x2, 0x2, 0x1aa, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 
    0x2, 0x2, 0x2, 0x1ab, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 
    0x4b, 0x2, 0x2, 0x1ad, 0x1af, 0x5, 0x60, 0x31, 0x2, 0x1ae, 0x1ac, 0x3, 
    0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b4, 0x3, 
    0x2, 0x2, 0x2, 0x1b0, 0x1b1, 0x9, 0x8, 0x2, 0x2, 0x1b1, 0x1b5, 0x7, 
    0x4e, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0x43, 0x2, 0x2, 0x1b3, 0x1b5, 0x7, 
    0x4f, 0x2, 0x2, 0x1b4, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b2, 0x3, 
    0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b7, 0x3, 
    0x2, 0x2, 0x2, 0x1b6, 0x185, 0x3, 0x2, 0x2, 0x2, 0x1b6, 0x19e, 0x3, 
    0x2, 0x2, 0x2, 0x1b7, 0x59, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x25, 
    0x2, 0x2, 0x1b9, 0x1ba, 0x5, 0x5a, 0x2e, 0x2, 0x1ba, 0x1bb, 0x7, 0x26, 
    0x2, 0x2, 0x1bb, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1c2, 0x5, 0x5c, 
    0x2f, 0x2, 0x1bd, 0x1c2, 0x5, 0x56, 0x2c, 0x2, 0x1be, 0x1c2, 0x5, 0x44, 
    0x23, 0x2, 0x1bf, 0x1c2, 0x5, 0x4c, 0x27, 0x2, 0x1c0, 0x1c2, 0x5, 0x66, 
    0x34, 0x2, 0x1c1, 0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1bc, 0x3, 0x2, 
    0x2, 0x2, 0x1c1, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1be, 0x3, 0x2, 
    0x2, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c0, 0x3, 0x2, 
    0x2, 0x2, 0x1c2, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x9, 0x9, 0x2, 
    0x2, 0x1c4, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x5, 0x60, 0x31, 
    0x2, 0x1c6, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x8, 0x31, 0x1, 
    0x2, 0x1c8, 0x1c9, 0x7, 0x32, 0x2, 0x2, 0x1c9, 0x1cc, 0x5, 0x60, 0x31, 
    0x6, 0x1ca, 0x1cc, 0x5, 0x5a, 0x2e, 0x2, 0x1cb, 0x1c7, 0x3, 0x2, 0x2, 
    0x2, 0x1cb, 0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1d5, 0x3, 0x2, 0x2, 
    0x2, 0x1cd, 0x1ce, 0xc, 0x5, 0x2, 0x2, 0x1ce, 0x1cf, 0x7, 0x31, 0x2, 
    0x2, 0x1cf, 0x1d4, 0x5, 0x60, 0x31, 0x6, 0x1d0, 0x1d1, 0xc, 0x4, 0x2, 
    0x2, 0x1d1, 0x1d2, 0x7, 0x30, 0x2, 0x2, 0x1d2, 0x1d4, 0x5, 0x60, 0x31, 
    0x5, 0x1d3, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d0, 0x3, 0x2, 0x2, 
    0x2, 0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 
    0x2, 0x1d5, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x1d7, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x5, 0x66, 0x34, 0x2, 
    0x1d9, 0x1da, 0x7, 0x2b, 0x2, 0x2, 0x1da, 0x1db, 0x5, 0x70, 0x39, 0x2, 
    0x1db, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1dc, 0x1dd, 0x5, 0x56, 0x2c, 0x2, 
    0x1dd, 0x1de, 0x7, 0x2b, 0x2, 0x2, 0x1de, 0x1df, 0x5, 0x64, 0x33, 0x2, 
    0x1df, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1d8, 0x3, 0x2, 0x2, 0x2, 
    0x1e0, 0x1dc, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1e5, 0x5, 0x66, 0x34, 0x2, 0x1e3, 0x1e5, 0x5, 0x56, 0x2c, 0x2, 0x1e4, 
    0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1e5, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 0x7, 0x58, 0x2, 0x2, 0x1e7, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1eb, 0x9, 0xa, 0x2, 0x2, 0x1e9, 0x1ec, 
    0x5, 0x18, 0xd, 0x2, 0x1ea, 0x1ec, 0x5, 0x56, 0x2c, 0x2, 0x1eb, 0x1e9, 
    0x3, 0x2, 0x2, 0x2, 0x1eb, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ed, 
    0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x7, 0x4b, 0x2, 0x2, 0x1ee, 0x1ef, 
    0x5, 0x6a, 0x36, 0x2, 0x1ef, 0x69, 0x3, 0x2, 0x2, 0x2, 0x1f0, 0x1f6, 
    0x5, 0x6e, 0x38, 0x2, 0x1f1, 0x1f2, 0x5, 0x6c, 0x37, 0x2, 0x1f2, 0x1f3, 
    0x5, 0x6e, 0x38, 0x2, 0x1f3, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f1, 
    0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f4, 
    0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x1f8, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x9, 
    0xb, 0x2, 0x2, 0x1fa, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fe, 0x5, 0x4c, 
    0x27, 0x2, 0x1fc, 0x1fe, 0x5, 0x44, 0x23, 0x2, 0x1fd, 0x1fb, 0x3, 0x2, 
    0x2, 0x2, 0x1fd, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x6f, 0x3, 0x2, 0x2, 
    0x2, 0x1ff, 0x203, 0x5, 0x60, 0x31, 0x2, 0x200, 0x203, 0x5, 0x54, 0x2b, 
    0x2, 0x201, 0x203, 0x5, 0x68, 0x35, 0x2, 0x202, 0x1ff, 0x3, 0x2, 0x2, 
    0x2, 0x202, 0x200, 0x3, 0x2, 0x2, 0x2, 0x202, 0x201, 0x3, 0x2, 0x2, 
    0x2, 0x203, 0x71, 0x3, 0x2, 0x2, 0x2, 0x204, 0x205, 0x7, 0x7, 0x2, 0x2, 
    0x205, 0x206, 0x7, 0x2b, 0x2, 0x2, 0x206, 0x207, 0x7, 0x27, 0x2, 0x2, 
    0x207, 0x20c, 0x5, 0x74, 0x3b, 0x2, 0x208, 0x209, 0x7, 0x2c, 0x2, 0x2, 
    0x209, 0x20b, 0x5, 0x74, 0x3b, 0x2, 0x20a, 0x208, 0x3, 0x2, 0x2, 0x2, 
    0x20b, 0x20e, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 0x2, 
    0x20c, 0x20d, 0x3, 0x2, 0x2, 0x2, 0x20d, 0x20f, 0x3, 0x2, 0x2, 0x2, 
    0x20e, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20f, 0x210, 0x7, 0x28, 0x2, 0x2, 
    0x210, 0x73, 0x3, 0x2, 0x2, 0x2, 0x211, 0x212, 0x5, 0x1e, 0x10, 0x2, 
    0x212, 0x213, 0x7, 0x2e, 0x2, 0x2, 0x213, 0x214, 0x5, 0x70, 0x39, 0x2, 
    0x214, 0x75, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x7, 0x23, 0x2, 0x2, 
    0x216, 0x217, 0x5, 0x5a, 0x2e, 0x2, 0x217, 0x218, 0x7, 0x24, 0x2, 0x2, 
    0x218, 0x219, 0x7, 0x27, 0x2, 0x2, 0x219, 0x21a, 0x5, 0x3a, 0x1e, 0x2, 
    0x21a, 0x223, 0x7, 0x28, 0x2, 0x2, 0x21b, 0x221, 0x7, 0x22, 0x2, 0x2, 
    0x21c, 0x222, 0x5, 0x76, 0x3c, 0x2, 0x21d, 0x21e, 0x7, 0x27, 0x2, 0x2, 
    0x21e, 0x21f, 0x5, 0x3a, 0x1e, 0x2, 0x21f, 0x220, 0x7, 0x28, 0x2, 0x2, 
    0x220, 0x222, 0x3, 0x2, 0x2, 0x2, 0x221, 0x21c, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x21d, 0x3, 0x2, 0x2, 0x2, 0x222, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x223, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x223, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x224, 0x77, 0x3, 0x2, 0x2, 0x2, 0x225, 0x226, 0x5, 0x7a, 0x3e, 0x2, 
    0x226, 0x79, 0x3, 0x2, 0x2, 0x2, 0x227, 0x228, 0x5, 0x18, 0xd, 0x2, 
    0x228, 0x229, 0x9, 0xc, 0x2, 0x2, 0x229, 0x22a, 0x5, 0x18, 0xd, 0x2, 
    0x22a, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22c, 0x5, 0x7e, 0x40, 0x2, 
    0x22c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x22e, 0x5, 0x5a, 0x2e, 0x2, 
    0x22e, 0x22f, 0x9, 0x8, 0x2, 0x2, 0x22f, 0x230, 0x7, 0x4e, 0x2, 0x2, 
    0x230, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x231, 0x232, 0x5, 0x82, 0x42, 0x2, 
    0x232, 0x81, 0x3, 0x2, 0x2, 0x2, 0x233, 0x234, 0x5, 0x5a, 0x2e, 0x2, 
    0x234, 0x235, 0x7, 0x43, 0x2, 0x2, 0x235, 0x236, 0x7, 0x4f, 0x2, 0x2, 
    0x236, 0x83, 0x3, 0x2, 0x2, 0x2, 0x237, 0x23c, 0x7, 0x2d, 0x2, 0x2, 
    0x238, 0x23c, 0x7, 0x5b, 0x2, 0x2, 0x239, 0x23c, 0x3, 0x2, 0x2, 0x2, 
    0x23a, 0x23c, 0x7, 0x2, 0x2, 0x3, 0x23b, 0x237, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x238, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x239, 0x3, 0x2, 0x2, 0x2, 
    0x23b, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x85, 0x3, 0x2, 0x2, 0x2, 0x38, 
    0x89, 0x8c, 0x98, 0xa5, 0xab, 0xb6, 0xc5, 0xc8, 0xd5, 0xda, 0xe0, 0xea, 
    0xf9, 0xfd, 0x100, 0x108, 0x110, 0x11a, 0x127, 0x12b, 0x132, 0x138, 
    0x144, 0x148, 0x14c, 0x15c, 0x161, 0x171, 0x174, 0x17c, 0x17e, 0x18f, 
    0x192, 0x196, 0x19c, 0x1a7, 0x1aa, 0x1ae, 0x1b4, 0x1b6, 0x1c1, 0x1cb, 
    0x1d3, 0x1d5, 0x1e0, 0x1e4, 0x1eb, 0x1f6, 0x1fd, 0x202, 0x20c, 0x221, 
    0x223, 0x23b, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

RuleParser::Initializer RuleParser::_init;
