
// Generated from Assemb.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AssembParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, T__25 = 26, 
    IgnoreDirective = 27, Section = 28, Type = 29, Rop = 30, Iop = 31, Sop = 32, 
    Bop = 33, Uop = 34, Jop = 35, Reg = 36, Symbol = 37, Label = 38, StringLiteral = 39, 
    Imm = 40, Relocation = 41, Integer = 42, DecimalInteger = 43, Whitespace = 44, 
    Newline = 45, LineComment = 46
  };

  enum {
    RuleFile = 0, RuleLine = 1, RuleInst = 2, RuleRtype = 3, RuleItype = 4, 
    RuleStype = 5, RuleBtype = 6, RuleUtype = 7, RuleJtype = 8, RulePseudoInst = 9, 
    RuleDerictive = 10
  };

  AssembParser(antlr4::TokenStream *input);
  ~AssembParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class FileContext;
  class LineContext;
  class InstContext;
  class RtypeContext;
  class ItypeContext;
  class StypeContext;
  class BtypeContext;
  class UtypeContext;
  class JtypeContext;
  class PseudoInstContext;
  class DerictiveContext; 

  class  FileContext : public antlr4::ParserRuleContext {
  public:
    FileContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *EOF();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FileContext* file();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    InstContext *inst();
    PseudoInstContext *pseudoInst();
    DerictiveContext *derictive();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  InstContext : public antlr4::ParserRuleContext {
  public:
    InstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    RtypeContext *rtype();
    ItypeContext *itype();
    StypeContext *stype();
    BtypeContext *btype();
    UtypeContext *utype();
    JtypeContext *jtype();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstContext* inst();

  class  RtypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rd = nullptr;;
    antlr4::Token *src1 = nullptr;;
    antlr4::Token *src2 = nullptr;;
    RtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Rop();
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RtypeContext* rtype();

  class  ItypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rd = nullptr;;
    antlr4::Token *src = nullptr;;
    antlr4::Token *imm = nullptr;;
    ItypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Iop();
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    antlr4::tree::TerminalNode *Imm();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ItypeContext* itype();

  class  StypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *value = nullptr;;
    antlr4::Token *offset = nullptr;;
    antlr4::Token *addr = nullptr;;
    StypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Sop();
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    antlr4::tree::TerminalNode *Integer();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StypeContext* stype();

  class  BtypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *src1 = nullptr;;
    antlr4::Token *src2 = nullptr;;
    antlr4::Token *label = nullptr;;
    BtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Bop();
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    antlr4::tree::TerminalNode *Label();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BtypeContext* btype();

  class  UtypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rd = nullptr;;
    antlr4::Token *imm = nullptr;;
    UtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Uop();
    antlr4::tree::TerminalNode *Reg();
    antlr4::tree::TerminalNode *Imm();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UtypeContext* utype();

  class  JtypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rd = nullptr;;
    antlr4::Token *imm = nullptr;;
    JtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Jop();
    antlr4::tree::TerminalNode *Reg();
    antlr4::tree::TerminalNode *Imm();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  JtypeContext* jtype();

  class  PseudoInstContext : public antlr4::ParserRuleContext {
  public:
    PseudoInstContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PseudoInstContext() = default;
    void copyFrom(PseudoInstContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  RetContext : public PseudoInstContext {
  public:
    RetContext(PseudoInstContext *ctx);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CallContext : public PseudoInstContext {
  public:
    CallContext(PseudoInstContext *ctx);

    antlr4::tree::TerminalNode *Symbol();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LaContext : public PseudoInstContext {
  public:
    LaContext(PseudoInstContext *ctx);

    antlr4::Token *rd = nullptr;
    antlr4::Token *src = nullptr;
    antlr4::tree::TerminalNode *Reg();
    antlr4::tree::TerminalNode *Symbol();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  JpContext : public PseudoInstContext {
  public:
    JpContext(PseudoInstContext *ctx);

    antlr4::Token *label = nullptr;
    antlr4::tree::TerminalNode *Label();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SzContext : public PseudoInstContext {
  public:
    SzContext(PseudoInstContext *ctx);

    antlr4::Token *rd = nullptr;
    antlr4::Token *src = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LdContext : public PseudoInstContext {
  public:
    LdContext(PseudoInstContext *ctx);

    antlr4::Token *rd = nullptr;
    antlr4::Token *src = nullptr;
    antlr4::tree::TerminalNode *Reg();
    antlr4::tree::TerminalNode *Symbol();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BzContext : public PseudoInstContext {
  public:
    BzContext(PseudoInstContext *ctx);

    antlr4::Token *src = nullptr;
    antlr4::Token *label = nullptr;
    antlr4::tree::TerminalNode *Reg();
    antlr4::tree::TerminalNode *Label();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MvContext : public PseudoInstContext {
  public:
    MvContext(PseudoInstContext *ctx);

    antlr4::Token *rd = nullptr;
    antlr4::Token *src = nullptr;
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LiContext : public PseudoInstContext {
  public:
    LiContext(PseudoInstContext *ctx);

    antlr4::Token *rd = nullptr;
    antlr4::Token *src = nullptr;
    antlr4::tree::TerminalNode *Reg();
    antlr4::tree::TerminalNode *Imm();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PseudoInstContext* pseudoInst();

  class  DerictiveContext : public antlr4::ParserRuleContext {
  public:
    DerictiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DerictiveContext() = default;
    void copyFrom(DerictiveContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SizeContext : public DerictiveContext {
  public:
    SizeContext(DerictiveContext *ctx);

    antlr4::tree::TerminalNode *Integer();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IgnoreContext : public DerictiveContext {
  public:
    IgnoreContext(DerictiveContext *ctx);

    antlr4::tree::TerminalNode *IgnoreDirective();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SectionContext : public DerictiveContext {
  public:
    SectionContext(DerictiveContext *ctx);

    antlr4::tree::TerminalNode *Section();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeContext : public DerictiveContext {
  public:
    TypeContext(DerictiveContext *ctx);

    antlr4::Token *symbol = nullptr;
    antlr4::tree::TerminalNode *Type();
    antlr4::tree::TerminalNode *Symbol();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AlignContext : public DerictiveContext {
  public:
    AlignContext(DerictiveContext *ctx);

    antlr4::tree::TerminalNode *Integer();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AscizContext : public DerictiveContext {
  public:
    AscizContext(DerictiveContext *ctx);

    antlr4::tree::TerminalNode *StringLiteral();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DerictiveContext* derictive();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

