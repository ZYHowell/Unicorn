
// Generated from Assemb.g4 by ANTLR 4.7.2


#include "AssembListener.h"
#include "AssembVisitor.h"

#include "AssembParser.h"


using namespace antlrcpp;
using namespace antlr4;

AssembParser::AssembParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

AssembParser::~AssembParser() {
  delete _interpreter;
}

std::string AssembParser::getGrammarFileName() const {
  return "Assemb.g4";
}

const std::vector<std::string>& AssembParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& AssembParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- FileContext ------------------------------------------------------------------

AssembParser::FileContext::FileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::FileContext::EOF() {
  return getToken(AssembParser::EOF, 0);
}

std::vector<AssembParser::LineContext *> AssembParser::FileContext::line() {
  return getRuleContexts<AssembParser::LineContext>();
}

AssembParser::LineContext* AssembParser::FileContext::line(size_t i) {
  return getRuleContext<AssembParser::LineContext>(i);
}


size_t AssembParser::FileContext::getRuleIndex() const {
  return AssembParser::RuleFile;
}

void AssembParser::FileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFile(this);
}

void AssembParser::FileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFile(this);
}


antlrcpp::Any AssembParser::FileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitFile(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::FileContext* AssembParser::file() {
  FileContext *_localctx = _tracker.createInstance<FileContext>(_ctx, getState());
  enterRule(_localctx, 0, AssembParser::RuleFile);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(33);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AssembParser::T__4)
      | (1ULL << AssembParser::T__5)
      | (1ULL << AssembParser::T__6)
      | (1ULL << AssembParser::T__7)
      | (1ULL << AssembParser::T__8)
      | (1ULL << AssembParser::T__9)
      | (1ULL << AssembParser::T__10)
      | (1ULL << AssembParser::T__11)
      | (1ULL << AssembParser::T__12)
      | (1ULL << AssembParser::T__13)
      | (1ULL << AssembParser::T__14)
      | (1ULL << AssembParser::T__15)
      | (1ULL << AssembParser::T__16)
      | (1ULL << AssembParser::T__17)
      | (1ULL << AssembParser::Section)
      | (1ULL << AssembParser::Rop)
      | (1ULL << AssembParser::Iop)
      | (1ULL << AssembParser::Sop)
      | (1ULL << AssembParser::Bop)
      | (1ULL << AssembParser::Uop)
      | (1ULL << AssembParser::Jop)
      | (1ULL << AssembParser::Lop)
      | (1ULL << AssembParser::Szop)
      | (1ULL << AssembParser::Bzop)
      | (1ULL << AssembParser::Symbol)
      | (1ULL << AssembParser::IgnoreDirective))) != 0)) {
      setState(30);
      line();
      setState(35);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(36);
    match(AssembParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineContext ------------------------------------------------------------------

AssembParser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssembParser::InstContext* AssembParser::LineContext::inst() {
  return getRuleContext<AssembParser::InstContext>(0);
}

AssembParser::PseudoInstContext* AssembParser::LineContext::pseudoInst() {
  return getRuleContext<AssembParser::PseudoInstContext>(0);
}

AssembParser::DirectiveContext* AssembParser::LineContext::directive() {
  return getRuleContext<AssembParser::DirectiveContext>(0);
}

AssembParser::StartContext* AssembParser::LineContext::start() {
  return getRuleContext<AssembParser::StartContext>(0);
}


size_t AssembParser::LineContext::getRuleIndex() const {
  return AssembParser::RuleLine;
}

void AssembParser::LineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLine(this);
}

void AssembParser::LineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLine(this);
}


antlrcpp::Any AssembParser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::LineContext* AssembParser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 2, AssembParser::RuleLine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(42);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(38);
      inst();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(39);
      pseudoInst();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(40);
      directive();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(41);
      start();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InstContext ------------------------------------------------------------------

AssembParser::InstContext::InstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AssembParser::RtypeContext* AssembParser::InstContext::rtype() {
  return getRuleContext<AssembParser::RtypeContext>(0);
}

AssembParser::ItypeContext* AssembParser::InstContext::itype() {
  return getRuleContext<AssembParser::ItypeContext>(0);
}

AssembParser::StypeContext* AssembParser::InstContext::stype() {
  return getRuleContext<AssembParser::StypeContext>(0);
}

AssembParser::BtypeContext* AssembParser::InstContext::btype() {
  return getRuleContext<AssembParser::BtypeContext>(0);
}

AssembParser::UtypeContext* AssembParser::InstContext::utype() {
  return getRuleContext<AssembParser::UtypeContext>(0);
}

AssembParser::JtypeContext* AssembParser::InstContext::jtype() {
  return getRuleContext<AssembParser::JtypeContext>(0);
}

AssembParser::LtypeContext* AssembParser::InstContext::ltype() {
  return getRuleContext<AssembParser::LtypeContext>(0);
}


size_t AssembParser::InstContext::getRuleIndex() const {
  return AssembParser::RuleInst;
}

void AssembParser::InstContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInst(this);
}

void AssembParser::InstContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInst(this);
}


antlrcpp::Any AssembParser::InstContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitInst(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::InstContext* AssembParser::inst() {
  InstContext *_localctx = _tracker.createInstance<InstContext>(_ctx, getState());
  enterRule(_localctx, 4, AssembParser::RuleInst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(51);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::Rop: {
        enterOuterAlt(_localctx, 1);
        setState(44);
        rtype();
        break;
      }

      case AssembParser::Iop: {
        enterOuterAlt(_localctx, 2);
        setState(45);
        itype();
        break;
      }

      case AssembParser::Sop: {
        enterOuterAlt(_localctx, 3);
        setState(46);
        stype();
        break;
      }

      case AssembParser::Bop: {
        enterOuterAlt(_localctx, 4);
        setState(47);
        btype();
        break;
      }

      case AssembParser::Uop: {
        enterOuterAlt(_localctx, 5);
        setState(48);
        utype();
        break;
      }

      case AssembParser::Jop: {
        enterOuterAlt(_localctx, 6);
        setState(49);
        jtype();
        break;
      }

      case AssembParser::Lop: {
        enterOuterAlt(_localctx, 7);
        setState(50);
        ltype();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StartContext ------------------------------------------------------------------

AssembParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::StartContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}


size_t AssembParser::StartContext::getRuleIndex() const {
  return AssembParser::RuleStart;
}

void AssembParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void AssembParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}


antlrcpp::Any AssembParser::StartContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitStart(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::StartContext* AssembParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 6, AssembParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53);
    match(AssembParser::Symbol);
    setState(54);
    match(AssembParser::T__0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RtypeContext ------------------------------------------------------------------

AssembParser::RtypeContext::RtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::RtypeContext::Rop() {
  return getToken(AssembParser::Rop, 0);
}

std::vector<tree::TerminalNode *> AssembParser::RtypeContext::Reg() {
  return getTokens(AssembParser::Reg);
}

tree::TerminalNode* AssembParser::RtypeContext::Reg(size_t i) {
  return getToken(AssembParser::Reg, i);
}


size_t AssembParser::RtypeContext::getRuleIndex() const {
  return AssembParser::RuleRtype;
}

void AssembParser::RtypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRtype(this);
}

void AssembParser::RtypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRtype(this);
}


antlrcpp::Any AssembParser::RtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitRtype(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::RtypeContext* AssembParser::rtype() {
  RtypeContext *_localctx = _tracker.createInstance<RtypeContext>(_ctx, getState());
  enterRule(_localctx, 8, AssembParser::RuleRtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(56);
    match(AssembParser::Rop);
    setState(57);
    dynamic_cast<RtypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(58);
    match(AssembParser::T__1);
    setState(59);
    dynamic_cast<RtypeContext *>(_localctx)->src1 = match(AssembParser::Reg);
    setState(60);
    match(AssembParser::T__1);
    setState(61);
    dynamic_cast<RtypeContext *>(_localctx)->src2 = match(AssembParser::Reg);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ItypeContext ------------------------------------------------------------------

AssembParser::ItypeContext::ItypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::ItypeContext::Iop() {
  return getToken(AssembParser::Iop, 0);
}

std::vector<tree::TerminalNode *> AssembParser::ItypeContext::Reg() {
  return getTokens(AssembParser::Reg);
}

tree::TerminalNode* AssembParser::ItypeContext::Reg(size_t i) {
  return getToken(AssembParser::Reg, i);
}

AssembParser::ImmContext* AssembParser::ItypeContext::imm() {
  return getRuleContext<AssembParser::ImmContext>(0);
}


size_t AssembParser::ItypeContext::getRuleIndex() const {
  return AssembParser::RuleItype;
}

void AssembParser::ItypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterItype(this);
}

void AssembParser::ItypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitItype(this);
}


antlrcpp::Any AssembParser::ItypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitItype(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::ItypeContext* AssembParser::itype() {
  ItypeContext *_localctx = _tracker.createInstance<ItypeContext>(_ctx, getState());
  enterRule(_localctx, 10, AssembParser::RuleItype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(AssembParser::Iop);
    setState(64);
    dynamic_cast<ItypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(65);
    match(AssembParser::T__1);
    setState(66);
    dynamic_cast<ItypeContext *>(_localctx)->src = match(AssembParser::Reg);
    setState(67);
    match(AssembParser::T__1);
    setState(68);
    dynamic_cast<ItypeContext *>(_localctx)->im = imm();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StypeContext ------------------------------------------------------------------

AssembParser::StypeContext::StypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::StypeContext::Sop() {
  return getToken(AssembParser::Sop, 0);
}

std::vector<tree::TerminalNode *> AssembParser::StypeContext::Reg() {
  return getTokens(AssembParser::Reg);
}

tree::TerminalNode* AssembParser::StypeContext::Reg(size_t i) {
  return getToken(AssembParser::Reg, i);
}

AssembParser::ImmContext* AssembParser::StypeContext::imm() {
  return getRuleContext<AssembParser::ImmContext>(0);
}


size_t AssembParser::StypeContext::getRuleIndex() const {
  return AssembParser::RuleStype;
}

void AssembParser::StypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStype(this);
}

void AssembParser::StypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStype(this);
}


antlrcpp::Any AssembParser::StypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitStype(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::StypeContext* AssembParser::stype() {
  StypeContext *_localctx = _tracker.createInstance<StypeContext>(_ctx, getState());
  enterRule(_localctx, 12, AssembParser::RuleStype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(70);
    match(AssembParser::Sop);
    setState(71);
    dynamic_cast<StypeContext *>(_localctx)->value = match(AssembParser::Reg);
    setState(72);
    match(AssembParser::T__1);
    setState(73);
    dynamic_cast<StypeContext *>(_localctx)->offset = imm();
    setState(74);
    match(AssembParser::T__2);
    setState(75);
    dynamic_cast<StypeContext *>(_localctx)->addr = match(AssembParser::Reg);
    setState(76);
    match(AssembParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BtypeContext ------------------------------------------------------------------

AssembParser::BtypeContext::BtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::BtypeContext::Bop() {
  return getToken(AssembParser::Bop, 0);
}

std::vector<tree::TerminalNode *> AssembParser::BtypeContext::Reg() {
  return getTokens(AssembParser::Reg);
}

tree::TerminalNode* AssembParser::BtypeContext::Reg(size_t i) {
  return getToken(AssembParser::Reg, i);
}

tree::TerminalNode* AssembParser::BtypeContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}


size_t AssembParser::BtypeContext::getRuleIndex() const {
  return AssembParser::RuleBtype;
}

void AssembParser::BtypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBtype(this);
}

void AssembParser::BtypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBtype(this);
}


antlrcpp::Any AssembParser::BtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitBtype(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::BtypeContext* AssembParser::btype() {
  BtypeContext *_localctx = _tracker.createInstance<BtypeContext>(_ctx, getState());
  enterRule(_localctx, 14, AssembParser::RuleBtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(78);
    match(AssembParser::Bop);
    setState(79);
    dynamic_cast<BtypeContext *>(_localctx)->src1 = match(AssembParser::Reg);
    setState(80);
    match(AssembParser::T__1);
    setState(81);
    dynamic_cast<BtypeContext *>(_localctx)->src2 = match(AssembParser::Reg);
    setState(82);
    match(AssembParser::T__1);
    setState(83);
    dynamic_cast<BtypeContext *>(_localctx)->label = match(AssembParser::Symbol);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UtypeContext ------------------------------------------------------------------

AssembParser::UtypeContext::UtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::UtypeContext::Uop() {
  return getToken(AssembParser::Uop, 0);
}

tree::TerminalNode* AssembParser::UtypeContext::Reg() {
  return getToken(AssembParser::Reg, 0);
}

AssembParser::ImmContext* AssembParser::UtypeContext::imm() {
  return getRuleContext<AssembParser::ImmContext>(0);
}


size_t AssembParser::UtypeContext::getRuleIndex() const {
  return AssembParser::RuleUtype;
}

void AssembParser::UtypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUtype(this);
}

void AssembParser::UtypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUtype(this);
}


antlrcpp::Any AssembParser::UtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitUtype(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::UtypeContext* AssembParser::utype() {
  UtypeContext *_localctx = _tracker.createInstance<UtypeContext>(_ctx, getState());
  enterRule(_localctx, 16, AssembParser::RuleUtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(85);
    match(AssembParser::Uop);
    setState(86);
    dynamic_cast<UtypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(87);
    match(AssembParser::T__1);
    setState(88);
    dynamic_cast<UtypeContext *>(_localctx)->im = imm();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JtypeContext ------------------------------------------------------------------

AssembParser::JtypeContext::JtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::JtypeContext::Jop() {
  return getToken(AssembParser::Jop, 0);
}

tree::TerminalNode* AssembParser::JtypeContext::Reg() {
  return getToken(AssembParser::Reg, 0);
}

AssembParser::ImmContext* AssembParser::JtypeContext::imm() {
  return getRuleContext<AssembParser::ImmContext>(0);
}


size_t AssembParser::JtypeContext::getRuleIndex() const {
  return AssembParser::RuleJtype;
}

void AssembParser::JtypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJtype(this);
}

void AssembParser::JtypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJtype(this);
}


antlrcpp::Any AssembParser::JtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitJtype(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::JtypeContext* AssembParser::jtype() {
  JtypeContext *_localctx = _tracker.createInstance<JtypeContext>(_ctx, getState());
  enterRule(_localctx, 18, AssembParser::RuleJtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(90);
    match(AssembParser::Jop);
    setState(91);
    dynamic_cast<JtypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(92);
    match(AssembParser::T__1);
    setState(93);
    dynamic_cast<JtypeContext *>(_localctx)->im = imm();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LtypeContext ------------------------------------------------------------------

AssembParser::LtypeContext::LtypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::LtypeContext::Lop() {
  return getToken(AssembParser::Lop, 0);
}

std::vector<tree::TerminalNode *> AssembParser::LtypeContext::Reg() {
  return getTokens(AssembParser::Reg);
}

tree::TerminalNode* AssembParser::LtypeContext::Reg(size_t i) {
  return getToken(AssembParser::Reg, i);
}

AssembParser::ImmContext* AssembParser::LtypeContext::imm() {
  return getRuleContext<AssembParser::ImmContext>(0);
}


size_t AssembParser::LtypeContext::getRuleIndex() const {
  return AssembParser::RuleLtype;
}

void AssembParser::LtypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLtype(this);
}

void AssembParser::LtypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLtype(this);
}


antlrcpp::Any AssembParser::LtypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitLtype(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::LtypeContext* AssembParser::ltype() {
  LtypeContext *_localctx = _tracker.createInstance<LtypeContext>(_ctx, getState());
  enterRule(_localctx, 20, AssembParser::RuleLtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(95);
    match(AssembParser::Lop);
    setState(96);
    dynamic_cast<LtypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(97);
    match(AssembParser::T__1);
    setState(98);
    dynamic_cast<LtypeContext *>(_localctx)->im = imm();
    setState(99);
    match(AssembParser::T__2);
    setState(100);
    dynamic_cast<LtypeContext *>(_localctx)->rs = match(AssembParser::Reg);
    setState(101);
    match(AssembParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PseudoInstContext ------------------------------------------------------------------

AssembParser::PseudoInstContext::PseudoInstContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssembParser::PseudoInstContext::getRuleIndex() const {
  return AssembParser::RulePseudoInst;
}

void AssembParser::PseudoInstContext::copyFrom(PseudoInstContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- RetContext ------------------------------------------------------------------

AssembParser::RetContext::RetContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::RetContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRet(this);
}
void AssembParser::RetContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRet(this);
}

antlrcpp::Any AssembParser::RetContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitRet(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CallContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::CallContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::CallContext::CallContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::CallContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCall(this);
}
void AssembParser::CallContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCall(this);
}

antlrcpp::Any AssembParser::CallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitCall(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LaContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::LaContext::Reg() {
  return getToken(AssembParser::Reg, 0);
}

tree::TerminalNode* AssembParser::LaContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::LaContext::LaContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::LaContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLa(this);
}
void AssembParser::LaContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLa(this);
}

antlrcpp::Any AssembParser::LaContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitLa(this);
  else
    return visitor->visitChildren(this);
}
//----------------- JpContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::JpContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::JpContext::JpContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::JpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJp(this);
}
void AssembParser::JpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJp(this);
}

antlrcpp::Any AssembParser::JpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitJp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SzContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::SzContext::Szop() {
  return getToken(AssembParser::Szop, 0);
}

std::vector<tree::TerminalNode *> AssembParser::SzContext::Reg() {
  return getTokens(AssembParser::Reg);
}

tree::TerminalNode* AssembParser::SzContext::Reg(size_t i) {
  return getToken(AssembParser::Reg, i);
}

AssembParser::SzContext::SzContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::SzContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSz(this);
}
void AssembParser::SzContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSz(this);
}

antlrcpp::Any AssembParser::SzContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitSz(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LdContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::LdContext::Lop() {
  return getToken(AssembParser::Lop, 0);
}

tree::TerminalNode* AssembParser::LdContext::Reg() {
  return getToken(AssembParser::Reg, 0);
}

tree::TerminalNode* AssembParser::LdContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::LdContext::LdContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::LdContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLd(this);
}
void AssembParser::LdContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLd(this);
}

antlrcpp::Any AssembParser::LdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitLd(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BzContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::BzContext::Bzop() {
  return getToken(AssembParser::Bzop, 0);
}

tree::TerminalNode* AssembParser::BzContext::Reg() {
  return getToken(AssembParser::Reg, 0);
}

tree::TerminalNode* AssembParser::BzContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::BzContext::BzContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::BzContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBz(this);
}
void AssembParser::BzContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBz(this);
}

antlrcpp::Any AssembParser::BzContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitBz(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MvContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> AssembParser::MvContext::Reg() {
  return getTokens(AssembParser::Reg);
}

tree::TerminalNode* AssembParser::MvContext::Reg(size_t i) {
  return getToken(AssembParser::Reg, i);
}

AssembParser::MvContext::MvContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::MvContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMv(this);
}
void AssembParser::MvContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMv(this);
}

antlrcpp::Any AssembParser::MvContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitMv(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LiContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::LiContext::Reg() {
  return getToken(AssembParser::Reg, 0);
}

AssembParser::ImmContext* AssembParser::LiContext::imm() {
  return getRuleContext<AssembParser::ImmContext>(0);
}

AssembParser::LiContext::LiContext(PseudoInstContext *ctx) { copyFrom(ctx); }

void AssembParser::LiContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLi(this);
}
void AssembParser::LiContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLi(this);
}

antlrcpp::Any AssembParser::LiContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitLi(this);
  else
    return visitor->visitChildren(this);
}
AssembParser::PseudoInstContext* AssembParser::pseudoInst() {
  PseudoInstContext *_localctx = _tracker.createInstance<PseudoInstContext>(_ctx, getState());
  enterRule(_localctx, 22, AssembParser::RulePseudoInst);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::T__4: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::MvContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(103);
        match(AssembParser::T__4);
        setState(104);
        dynamic_cast<MvContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(105);
        match(AssembParser::T__1);
        setState(106);
        dynamic_cast<MvContext *>(_localctx)->src = match(AssembParser::Reg);
        break;
      }

      case AssembParser::T__5: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::LiContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(107);
        match(AssembParser::T__5);
        setState(108);
        dynamic_cast<LiContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(109);
        match(AssembParser::T__1);
        setState(110);
        dynamic_cast<LiContext *>(_localctx)->src = imm();
        break;
      }

      case AssembParser::T__6: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::RetContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(111);
        match(AssembParser::T__6);
        break;
      }

      case AssembParser::T__7: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::JpContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(112);
        match(AssembParser::T__7);
        setState(113);
        dynamic_cast<JpContext *>(_localctx)->label = match(AssembParser::Symbol);
        break;
      }

      case AssembParser::Lop: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::LdContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(114);
        match(AssembParser::Lop);
        setState(115);
        dynamic_cast<LdContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(116);
        match(AssembParser::T__1);
        setState(117);
        dynamic_cast<LdContext *>(_localctx)->src = match(AssembParser::Symbol);
        break;
      }

      case AssembParser::T__8: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::LaContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(118);
        match(AssembParser::T__8);
        setState(119);
        dynamic_cast<LaContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(120);
        match(AssembParser::T__1);
        setState(121);
        dynamic_cast<LaContext *>(_localctx)->src = match(AssembParser::Symbol);
        break;
      }

      case AssembParser::T__9: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::CallContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(122);
        match(AssembParser::T__9);
        setState(123);
        match(AssembParser::Symbol);
        break;
      }

      case AssembParser::Szop: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::SzContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(124);
        match(AssembParser::Szop);
        setState(125);
        dynamic_cast<SzContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(126);
        match(AssembParser::T__1);
        setState(127);
        dynamic_cast<SzContext *>(_localctx)->src = match(AssembParser::Reg);
        break;
      }

      case AssembParser::Bzop: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::BzContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(128);
        match(AssembParser::Bzop);
        setState(129);
        dynamic_cast<BzContext *>(_localctx)->src = match(AssembParser::Reg);
        setState(130);
        match(AssembParser::T__1);
        setState(131);
        dynamic_cast<BzContext *>(_localctx)->label = match(AssembParser::Symbol);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DirectiveContext ------------------------------------------------------------------

AssembParser::DirectiveContext::DirectiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssembParser::DirectiveContext::getRuleIndex() const {
  return AssembParser::RuleDirective;
}

void AssembParser::DirectiveContext::copyFrom(DirectiveContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- FilenameContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::FilenameContext::StringLiteral() {
  return getToken(AssembParser::StringLiteral, 0);
}

AssembParser::FilenameContext::FilenameContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::FilenameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFilename(this);
}
void AssembParser::FilenameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFilename(this);
}

antlrcpp::Any AssembParser::FilenameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitFilename(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IgnoreContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::IgnoreContext::IgnoreDirective() {
  return getToken(AssembParser::IgnoreDirective, 0);
}

AssembParser::IgnoreContext::IgnoreContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::IgnoreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIgnore(this);
}
void AssembParser::IgnoreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIgnore(this);
}

antlrcpp::Any AssembParser::IgnoreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitIgnore(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SectionContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::SectionContext::Section() {
  return getToken(AssembParser::Section, 0);
}

AssembParser::SectionContext::SectionContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::SectionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSection(this);
}
void AssembParser::SectionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSection(this);
}

antlrcpp::Any AssembParser::SectionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitSection(this);
  else
    return visitor->visitChildren(this);
}
//----------------- GloblContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::GloblContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::GloblContext::GloblContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::GloblContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGlobl(this);
}
void AssembParser::GloblContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGlobl(this);
}

antlrcpp::Any AssembParser::GloblContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitGlobl(this);
  else
    return visitor->visitChildren(this);
}
//----------------- TypeContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::TypeContext::Type() {
  return getToken(AssembParser::Type, 0);
}

tree::TerminalNode* AssembParser::TypeContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::TypeContext::TypeContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}
void AssembParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

antlrcpp::Any AssembParser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AlignContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::AlignContext::Integer() {
  return getToken(AssembParser::Integer, 0);
}

AssembParser::AlignContext::AlignContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::AlignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAlign(this);
}
void AssembParser::AlignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAlign(this);
}

antlrcpp::Any AssembParser::AlignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitAlign(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WordContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::WordContext::Integer() {
  return getToken(AssembParser::Integer, 0);
}

AssembParser::WordContext::WordContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::WordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWord(this);
}
void AssembParser::WordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWord(this);
}

antlrcpp::Any AssembParser::WordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitWord(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AscizContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::AscizContext::StringLiteral() {
  return getToken(AssembParser::StringLiteral, 0);
}

AssembParser::AscizContext::AscizContext(DirectiveContext *ctx) { copyFrom(ctx); }

void AssembParser::AscizContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAsciz(this);
}
void AssembParser::AscizContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAsciz(this);
}

antlrcpp::Any AssembParser::AscizContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitAsciz(this);
  else
    return visitor->visitChildren(this);
}
AssembParser::DirectiveContext* AssembParser::directive() {
  DirectiveContext *_localctx = _tracker.createInstance<DirectiveContext>(_ctx, getState());
  enterRule(_localctx, 24, AssembParser::RuleDirective);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::Section: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::SectionContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(134);
        match(AssembParser::Section);
        break;
      }

      case AssembParser::T__10: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::GloblContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(135);
        match(AssembParser::T__10);
        setState(136);
        dynamic_cast<GloblContext *>(_localctx)->symbol = match(AssembParser::Symbol);
        break;
      }

      case AssembParser::T__11: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::TypeContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(137);
        match(AssembParser::T__11);
        setState(138);
        dynamic_cast<TypeContext *>(_localctx)->symbol = match(AssembParser::Symbol);
        setState(139);
        match(AssembParser::T__1);
        setState(140);
        match(AssembParser::Type);
        break;
      }

      case AssembParser::T__12:
      case AssembParser::T__13: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::AlignContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(141);
        _la = _input->LA(1);
        if (!(_la == AssembParser::T__12

        || _la == AssembParser::T__13)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(142);
        match(AssembParser::Integer);
        break;
      }

      case AssembParser::T__14: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::WordContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(143);
        match(AssembParser::T__14);
        setState(144);
        match(AssembParser::Integer);
        break;
      }

      case AssembParser::T__15:
      case AssembParser::T__16: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::AscizContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(145);
        _la = _input->LA(1);
        if (!(_la == AssembParser::T__15

        || _la == AssembParser::T__16)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(146);
        match(AssembParser::StringLiteral);
        break;
      }

      case AssembParser::T__17: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::FilenameContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(147);
        match(AssembParser::T__17);
        setState(148);
        dynamic_cast<FilenameContext *>(_localctx)->name = match(AssembParser::StringLiteral);
        break;
      }

      case AssembParser::IgnoreDirective: {
        _localctx = dynamic_cast<DirectiveContext *>(_tracker.createInstance<AssembParser::IgnoreContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(149);
        match(AssembParser::IgnoreDirective);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImmContext ------------------------------------------------------------------

AssembParser::ImmContext::ImmContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::ImmContext::Integer() {
  return getToken(AssembParser::Integer, 0);
}

AssembParser::RelocationContext* AssembParser::ImmContext::relocation() {
  return getRuleContext<AssembParser::RelocationContext>(0);
}


size_t AssembParser::ImmContext::getRuleIndex() const {
  return AssembParser::RuleImm;
}

void AssembParser::ImmContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImm(this);
}

void AssembParser::ImmContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImm(this);
}


antlrcpp::Any AssembParser::ImmContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitImm(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::ImmContext* AssembParser::imm() {
  ImmContext *_localctx = _tracker.createInstance<ImmContext>(_ctx, getState());
  enterRule(_localctx, 26, AssembParser::RuleImm);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(154);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::Integer: {
        enterOuterAlt(_localctx, 1);
        setState(152);
        match(AssembParser::Integer);
        break;
      }

      case AssembParser::HL: {
        enterOuterAlt(_localctx, 2);
        setState(153);
        relocation();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelocationContext ------------------------------------------------------------------

AssembParser::RelocationContext::RelocationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* AssembParser::RelocationContext::HL() {
  return getToken(AssembParser::HL, 0);
}

tree::TerminalNode* AssembParser::RelocationContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}


size_t AssembParser::RelocationContext::getRuleIndex() const {
  return AssembParser::RuleRelocation;
}

void AssembParser::RelocationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelocation(this);
}

void AssembParser::RelocationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelocation(this);
}


antlrcpp::Any AssembParser::RelocationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitRelocation(this);
  else
    return visitor->visitChildren(this);
}

AssembParser::RelocationContext* AssembParser::relocation() {
  RelocationContext *_localctx = _tracker.createInstance<RelocationContext>(_ctx, getState());
  enterRule(_localctx, 28, AssembParser::RuleRelocation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(AssembParser::HL);
    setState(157);
    match(AssembParser::T__2);
    setState(158);
    match(AssembParser::Symbol);
    setState(159);
    match(AssembParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> AssembParser::_decisionToDFA;
atn::PredictionContextCache AssembParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AssembParser::_atn;
std::vector<uint16_t> AssembParser::_serializedATN;

std::vector<std::string> AssembParser::_ruleNames = {
  "file", "line", "inst", "start", "rtype", "itype", "stype", "btype", "utype", 
  "jtype", "ltype", "pseudoInst", "directive", "imm", "relocation"
};

std::vector<std::string> AssembParser::_literalNames = {
  "", "':'", "','", "'('", "')'", "'mv'", "'li'", "'ret'", "'j'", "'la'", 
  "'call'", "'.globl'", "'.type'", "'.p2align'", "'.align'", "'.word'", 
  "'.asciz'", "'.string'", "'.file'", "", "", "", "", "", "", "", "'jal'"
};

std::vector<std::string> AssembParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "Section", "Type", "Rop", "Iop", "Sop", "Bop", "Uop", "Jop", "Lop", 
  "Szop", "Bzop", "Reg", "Symbol", "StringLiteral", "HL", "Integer", "DecimalInteger", 
  "IgnoreDirective", "Whitespace", "Newline", "LineComment"
};

dfa::Vocabulary AssembParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> AssembParser::_tokenNames;

AssembParser::Initializer::Initializer() {
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
    0x3, 0x29, 0xa4, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 0x4, 
    0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x3, 0x2, 0x7, 0x2, 0x22, 0xa, 
    0x2, 0xc, 0x2, 0xe, 0x2, 0x25, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x2d, 0xa, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x36, 
    0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x87, 0xa, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0x99, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0x9d, 0xa, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
    0x2, 0x2, 0x11, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x2, 0x4, 0x3, 0x2, 0xf, 0x10, 0x3, 0x2, 
    0x12, 0x13, 0x2, 0xae, 0x2, 0x23, 0x3, 0x2, 0x2, 0x2, 0x4, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x6, 0x35, 0x3, 0x2, 0x2, 0x2, 0x8, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0xa, 0x3a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x41, 0x3, 0x2, 0x2, 0x2, 0xe, 
    0x48, 0x3, 0x2, 0x2, 0x2, 0x10, 0x50, 0x3, 0x2, 0x2, 0x2, 0x12, 0x57, 
    0x3, 0x2, 0x2, 0x2, 0x14, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x16, 0x61, 0x3, 
    0x2, 0x2, 0x2, 0x18, 0x86, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x98, 0x3, 0x2, 
    0x2, 0x2, 0x1c, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x9e, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x22, 0x5, 0x4, 0x3, 0x2, 0x21, 0x20, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x25, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x24, 0x3, 0x2, 0x2, 0x2, 0x24, 0x26, 0x3, 0x2, 0x2, 0x2, 0x25, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x26, 0x27, 0x7, 0x2, 0x2, 0x3, 0x27, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x2d, 0x5, 0x6, 0x4, 0x2, 0x29, 0x2d, 0x5, 0x18, 
    0xd, 0x2, 0x2a, 0x2d, 0x5, 0x1a, 0xe, 0x2, 0x2b, 0x2d, 0x5, 0x8, 0x5, 
    0x2, 0x2c, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x29, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2d, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x36, 0x5, 0xa, 0x6, 0x2, 0x2f, 0x36, 
    0x5, 0xc, 0x7, 0x2, 0x30, 0x36, 0x5, 0xe, 0x8, 0x2, 0x31, 0x36, 0x5, 
    0x10, 0x9, 0x2, 0x32, 0x36, 0x5, 0x12, 0xa, 0x2, 0x33, 0x36, 0x5, 0x14, 
    0xb, 0x2, 0x34, 0x36, 0x5, 0x16, 0xc, 0x2, 0x35, 0x2e, 0x3, 0x2, 0x2, 
    0x2, 0x35, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x35, 0x30, 0x3, 0x2, 0x2, 0x2, 
    0x35, 0x31, 0x3, 0x2, 0x2, 0x2, 0x35, 0x32, 0x3, 0x2, 0x2, 0x2, 0x35, 
    0x33, 0x3, 0x2, 0x2, 0x2, 0x35, 0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x7, 
    0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x7, 0x21, 0x2, 0x2, 0x38, 0x39, 0x7, 
    0x3, 0x2, 0x2, 0x39, 0x9, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x17, 
    0x2, 0x2, 0x3b, 0x3c, 0x7, 0x20, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x4, 0x2, 
    0x2, 0x3d, 0x3e, 0x7, 0x20, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x4, 0x2, 0x2, 
    0x3f, 0x40, 0x7, 0x20, 0x2, 0x2, 0x40, 0xb, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x42, 0x7, 0x18, 0x2, 0x2, 0x42, 0x43, 0x7, 0x20, 0x2, 0x2, 0x43, 0x44, 
    0x7, 0x4, 0x2, 0x2, 0x44, 0x45, 0x7, 0x20, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0x4, 0x2, 0x2, 0x46, 0x47, 0x5, 0x1c, 0xf, 0x2, 0x47, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0x48, 0x49, 0x7, 0x19, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x20, 0x2, 
    0x2, 0x4a, 0x4b, 0x7, 0x4, 0x2, 0x2, 0x4b, 0x4c, 0x5, 0x1c, 0xf, 0x2, 
    0x4c, 0x4d, 0x7, 0x5, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x20, 0x2, 0x2, 0x4e, 
    0x4f, 0x7, 0x6, 0x2, 0x2, 0x4f, 0xf, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 
    0x7, 0x1a, 0x2, 0x2, 0x51, 0x52, 0x7, 0x20, 0x2, 0x2, 0x52, 0x53, 0x7, 
    0x4, 0x2, 0x2, 0x53, 0x54, 0x7, 0x20, 0x2, 0x2, 0x54, 0x55, 0x7, 0x4, 
    0x2, 0x2, 0x55, 0x56, 0x7, 0x21, 0x2, 0x2, 0x56, 0x11, 0x3, 0x2, 0x2, 
    0x2, 0x57, 0x58, 0x7, 0x1b, 0x2, 0x2, 0x58, 0x59, 0x7, 0x20, 0x2, 0x2, 
    0x59, 0x5a, 0x7, 0x4, 0x2, 0x2, 0x5a, 0x5b, 0x5, 0x1c, 0xf, 0x2, 0x5b, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5d, 0x7, 0x1c, 0x2, 0x2, 0x5d, 0x5e, 
    0x7, 0x20, 0x2, 0x2, 0x5e, 0x5f, 0x7, 0x4, 0x2, 0x2, 0x5f, 0x60, 0x5, 
    0x1c, 0xf, 0x2, 0x60, 0x15, 0x3, 0x2, 0x2, 0x2, 0x61, 0x62, 0x7, 0x1d, 
    0x2, 0x2, 0x62, 0x63, 0x7, 0x20, 0x2, 0x2, 0x63, 0x64, 0x7, 0x4, 0x2, 
    0x2, 0x64, 0x65, 0x5, 0x1c, 0xf, 0x2, 0x65, 0x66, 0x7, 0x5, 0x2, 0x2, 
    0x66, 0x67, 0x7, 0x20, 0x2, 0x2, 0x67, 0x68, 0x7, 0x6, 0x2, 0x2, 0x68, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x7, 0x7, 0x2, 0x2, 0x6a, 0x6b, 
    0x7, 0x20, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x4, 0x2, 0x2, 0x6c, 0x87, 0x7, 
    0x20, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x8, 0x2, 0x2, 0x6e, 0x6f, 0x7, 0x20, 
    0x2, 0x2, 0x6f, 0x70, 0x7, 0x4, 0x2, 0x2, 0x70, 0x87, 0x5, 0x1c, 0xf, 
    0x2, 0x71, 0x87, 0x7, 0x9, 0x2, 0x2, 0x72, 0x73, 0x7, 0xa, 0x2, 0x2, 
    0x73, 0x87, 0x7, 0x21, 0x2, 0x2, 0x74, 0x75, 0x7, 0x1d, 0x2, 0x2, 0x75, 
    0x76, 0x7, 0x20, 0x2, 0x2, 0x76, 0x77, 0x7, 0x4, 0x2, 0x2, 0x77, 0x87, 
    0x7, 0x21, 0x2, 0x2, 0x78, 0x79, 0x7, 0xb, 0x2, 0x2, 0x79, 0x7a, 0x7, 
    0x20, 0x2, 0x2, 0x7a, 0x7b, 0x7, 0x4, 0x2, 0x2, 0x7b, 0x87, 0x7, 0x21, 
    0x2, 0x2, 0x7c, 0x7d, 0x7, 0xc, 0x2, 0x2, 0x7d, 0x87, 0x7, 0x21, 0x2, 
    0x2, 0x7e, 0x7f, 0x7, 0x1e, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x20, 0x2, 0x2, 
    0x80, 0x81, 0x7, 0x4, 0x2, 0x2, 0x81, 0x87, 0x7, 0x20, 0x2, 0x2, 0x82, 
    0x83, 0x7, 0x1f, 0x2, 0x2, 0x83, 0x84, 0x7, 0x20, 0x2, 0x2, 0x84, 0x85, 
    0x7, 0x4, 0x2, 0x2, 0x85, 0x87, 0x7, 0x21, 0x2, 0x2, 0x86, 0x69, 0x3, 
    0x2, 0x2, 0x2, 0x86, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x86, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x86, 0x72, 0x3, 0x2, 0x2, 0x2, 0x86, 0x74, 0x3, 0x2, 0x2, 
    0x2, 0x86, 0x78, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x86, 0x82, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x19, 0x3, 0x2, 0x2, 0x2, 0x88, 0x99, 0x7, 0x15, 0x2, 0x2, 0x89, 0x8a, 
    0x7, 0xd, 0x2, 0x2, 0x8a, 0x99, 0x7, 0x21, 0x2, 0x2, 0x8b, 0x8c, 0x7, 
    0xe, 0x2, 0x2, 0x8c, 0x8d, 0x7, 0x21, 0x2, 0x2, 0x8d, 0x8e, 0x7, 0x4, 
    0x2, 0x2, 0x8e, 0x99, 0x7, 0x16, 0x2, 0x2, 0x8f, 0x90, 0x9, 0x2, 0x2, 
    0x2, 0x90, 0x99, 0x7, 0x24, 0x2, 0x2, 0x91, 0x92, 0x7, 0x11, 0x2, 0x2, 
    0x92, 0x99, 0x7, 0x24, 0x2, 0x2, 0x93, 0x94, 0x9, 0x3, 0x2, 0x2, 0x94, 
    0x99, 0x7, 0x22, 0x2, 0x2, 0x95, 0x96, 0x7, 0x14, 0x2, 0x2, 0x96, 0x99, 
    0x7, 0x22, 0x2, 0x2, 0x97, 0x99, 0x7, 0x26, 0x2, 0x2, 0x98, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x98, 0x89, 0x3, 0x2, 0x2, 0x2, 0x98, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x98, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x98, 0x91, 0x3, 0x2, 0x2, 
    0x2, 0x98, 0x93, 0x3, 0x2, 0x2, 0x2, 0x98, 0x95, 0x3, 0x2, 0x2, 0x2, 
    0x98, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x9a, 
    0x9d, 0x7, 0x24, 0x2, 0x2, 0x9b, 0x9d, 0x5, 0x1e, 0x10, 0x2, 0x9c, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x23, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x5, 
    0x2, 0x2, 0xa0, 0xa1, 0x7, 0x21, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x6, 0x2, 
    0x2, 0xa2, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x8, 0x23, 0x2c, 0x35, 0x86, 0x98, 
    0x9c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

AssembParser::Initializer AssembParser::_init;
