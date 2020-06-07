
// Generated from Assemb.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  AssembParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, Section = 20, 
    Type = 21, Rop = 22, Iop = 23, Sop = 24, Bop = 25, Uop = 26, Jop = 27, 
    Lop = 28, Szop = 29, Bzop = 30, Reg = 31, Directive = 32, Symbol = 33, 
    StringLiteral = 34, HL = 35, Integer = 36, DecimalInteger = 37, Whitespace = 38, 
    Newline = 39, LineComment = 40
  };

  enum {
    RuleFile = 0, RuleLine = 1, RuleInst = 2, RuleStart = 3, RuleRtype = 4, 
    RuleItype = 5, RuleStype = 6, RuleBtype = 7, RuleUtype = 8, RuleJtype = 9, 
    RuleLtype = 10, RulePseudoInst = 11, RuleDirective = 12, RuleImm = 13, 
    RuleRelocation = 14
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
  class StartContext;
  class RtypeContext;
  class ItypeContext;
  class StypeContext;
  class BtypeContext;
  class UtypeContext;
  class JtypeContext;
  class LtypeContext;
  class PseudoInstContext;
  class DirectiveContext;
  class ImmContext;
  class RelocationContext; 

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
    DirectiveContext *directive();
    StartContext *start();

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
    LtypeContext *ltype();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  InstContext* inst();

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StartContext* start();

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
    AssembParser::ImmContext *im = nullptr;;
    ItypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Iop();
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    ImmContext *imm();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ItypeContext* itype();

  class  StypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *value = nullptr;;
    AssembParser::ImmContext *offset = nullptr;;
    antlr4::Token *addr = nullptr;;
    StypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Sop();
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    ImmContext *imm();

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
    antlr4::tree::TerminalNode *Symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BtypeContext* btype();

  class  UtypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rd = nullptr;;
    AssembParser::ImmContext *im = nullptr;;
    UtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Uop();
    antlr4::tree::TerminalNode *Reg();
    ImmContext *imm();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UtypeContext* utype();

  class  JtypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rd = nullptr;;
    AssembParser::ImmContext *im = nullptr;;
    JtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Jop();
    antlr4::tree::TerminalNode *Reg();
    ImmContext *imm();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  JtypeContext* jtype();

  class  LtypeContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *rd = nullptr;;
    AssembParser::ImmContext *im = nullptr;;
    antlr4::Token *rs = nullptr;;
    LtypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Lop();
    std::vector<antlr4::tree::TerminalNode *> Reg();
    antlr4::tree::TerminalNode* Reg(size_t i);
    ImmContext *imm();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LtypeContext* ltype();

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
    antlr4::tree::TerminalNode *Symbol();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SzContext : public PseudoInstContext {
  public:
    SzContext(PseudoInstContext *ctx);

    antlr4::Token *rd = nullptr;
    antlr4::Token *src = nullptr;
    antlr4::tree::TerminalNode *Szop();
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
    antlr4::tree::TerminalNode *Lop();
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
    antlr4::tree::TerminalNode *Bzop();
    antlr4::tree::TerminalNode *Reg();
    antlr4::tree::TerminalNode *Symbol();
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
    AssembParser::ImmContext *src = nullptr;
    antlr4::tree::TerminalNode *Reg();
    ImmContext *imm();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PseudoInstContext* pseudoInst();

  class  DirectiveContext : public antlr4::ParserRuleContext {
  public:
    DirectiveContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DirectiveContext() = default;
    void copyFrom(DirectiveContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  FilenameContext : public DirectiveContext {
  public:
    FilenameContext(DirectiveContext *ctx);

    antlr4::Token *name = nullptr;
    antlr4::tree::TerminalNode *StringLiteral();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SectionContext : public DirectiveContext {
  public:
    SectionContext(DirectiveContext *ctx);

    antlr4::tree::TerminalNode *Section();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  GloblContext : public DirectiveContext {
  public:
    GloblContext(DirectiveContext *ctx);

    antlr4::Token *symbol = nullptr;
    antlr4::tree::TerminalNode *Symbol();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  TypeContext : public DirectiveContext {
  public:
    TypeContext(DirectiveContext *ctx);

    antlr4::Token *symbol = nullptr;
    antlr4::tree::TerminalNode *Type();
    antlr4::tree::TerminalNode *Symbol();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AlignContext : public DirectiveContext {
  public:
    AlignContext(DirectiveContext *ctx);

    antlr4::tree::TerminalNode *Integer();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WordContext : public DirectiveContext {
  public:
    WordContext(DirectiveContext *ctx);

    antlr4::tree::TerminalNode *Integer();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AscizContext : public DirectiveContext {
  public:
    AscizContext(DirectiveContext *ctx);

    antlr4::tree::TerminalNode *StringLiteral();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DirectiveContext* directive();

  class  ImmContext : public antlr4::ParserRuleContext {
  public:
    ImmContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Integer();
    RelocationContext *relocation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ImmContext* imm();

  class  RelocationContext : public antlr4::ParserRuleContext {
  public:
    RelocationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *HL();
    antlr4::tree::TerminalNode *Symbol();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelocationContext* relocation();


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

