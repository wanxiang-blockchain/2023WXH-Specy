
// Generated from RuleLexer.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  RuleLexer : public antlr4::Lexer {
public:
  enum {
    TASK = 1, ENTITIES = 2, RULES = 3, INPUT = 4, OUTPUT = 5, EXECUTE = 6, 
    REFERENCES = 7, ENTITY = 8, UNIQUE = 9, ARTICLE = 10, RULE = 11, NUMBER = 12, 
    STRING = 13, BOOLEAN = 14, DATE = 15, SET = 16, LIST = 17, YEAR = 18, 
    MONTH = 19, DAY = 20, HOUR = 21, MINUTE = 22, SECOND = 23, ALIAS = 24, 
    STATE = 25, EVENT = 26, TRUE = 27, FALSE = 28, SELECT = 29, COLLECT = 30, 
    CHECK = 31, ELSE = 32, IF = 33, THEN = 34, L_PAREN = 35, R_PAREN = 36, 
    L_CURLY = 37, R_CURLY = 38, L_BRACKET = 39, R_BRACKET = 40, ASSIGN = 41, 
    COMMA = 42, SEMI = 43, COLON = 44, DOT = 45, LOGICAL_OR = 46, LOGICAL_AND = 47, 
    LOGICAL_NOT = 48, SET_IN = 49, SET_NOT_IN = 50, SET_UNION = 51, SET_INTERSECT = 52, 
    EQUALS = 53, NOT_EQUALS = 54, LESS_THAN = 55, LESS_OR_EQUALS = 56, GREATER_THAN = 57, 
    GREATER_OR_EQUALS = 58, PLUS = 59, MINUS = 60, MULTIPLY = 61, DIVIDE = 62, 
    MODULO = 63, IS = 64, WITHIN = 65, BEFORE = 66, AFTER = 67, FOLLOW = 68, 
    ACCUMULATE = 69, COUNT = 70, ON = 71, PROVIDED = 72, WHERE = 73, DECIMAL_LIT = 74, 
    DECIMAL_FLOAT_LIT = 75, DATE_LIT = 76, TIME_LIT = 77, RUNE_LIT = 78, 
    BYTE_VALUE = 79, OCTAL_BYTE_VALUE = 80, HEX_BYTE_VALUE = 81, LITTLE_U_VALUE = 82, 
    BIG_U_VALUE = 83, RAW_STRING_LIT = 84, INTERPRETED_STRING_LIT = 85, 
    IDENTIFIER = 86, WS = 87, COMMENT = 88, TERMINATOR = 89, LINE_COMMENT = 90
  };

  explicit RuleLexer(antlr4::CharStream *input);
  ~RuleLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

