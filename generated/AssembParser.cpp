
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
    setState(25);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << AssembParser::T__3)
      | (1ULL << AssembParser::T__4)
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
      | (1ULL << AssembParser::T__18)
      | (1ULL << AssembParser::T__19)
      | (1ULL << AssembParser::T__20)
      | (1ULL << AssembParser::T__21)
      | (1ULL << AssembParser::T__22)
      | (1ULL << AssembParser::T__23)
      | (1ULL << AssembParser::T__24)
      | (1ULL << AssembParser::T__25)
      | (1ULL << AssembParser::IgnoreDirective)
      | (1ULL << AssembParser::Section)
      | (1ULL << AssembParser::Rop)
      | (1ULL << AssembParser::Iop)
      | (1ULL << AssembParser::Sop)
      | (1ULL << AssembParser::Bop)
      | (1ULL << AssembParser::Uop)
      | (1ULL << AssembParser::Jop))) != 0)) {
      setState(22);
      line();
      setState(27);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(28);
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

AssembParser::DerictiveContext* AssembParser::LineContext::derictive() {
  return getRuleContext<AssembParser::DerictiveContext>(0);
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
    setState(33);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::Rop:
      case AssembParser::Iop:
      case AssembParser::Sop:
      case AssembParser::Bop:
      case AssembParser::Uop:
      case AssembParser::Jop: {
        enterOuterAlt(_localctx, 1);
        setState(30);
        inst();
        break;
      }

      case AssembParser::T__3:
      case AssembParser::T__4:
      case AssembParser::T__5:
      case AssembParser::T__6:
      case AssembParser::T__7:
      case AssembParser::T__8:
      case AssembParser::T__9:
      case AssembParser::T__10:
      case AssembParser::T__11:
      case AssembParser::T__12:
      case AssembParser::T__13:
      case AssembParser::T__14:
      case AssembParser::T__15:
      case AssembParser::T__16:
      case AssembParser::T__17:
      case AssembParser::T__18:
      case AssembParser::T__19:
      case AssembParser::T__20: {
        enterOuterAlt(_localctx, 2);
        setState(31);
        pseudoInst();
        break;
      }

      case AssembParser::T__21:
      case AssembParser::T__22:
      case AssembParser::T__23:
      case AssembParser::T__24:
      case AssembParser::T__25:
      case AssembParser::IgnoreDirective:
      case AssembParser::Section: {
        enterOuterAlt(_localctx, 3);
        setState(32);
        derictive();
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
    setState(41);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::Rop: {
        enterOuterAlt(_localctx, 1);
        setState(35);
        rtype();
        break;
      }

      case AssembParser::Iop: {
        enterOuterAlt(_localctx, 2);
        setState(36);
        itype();
        break;
      }

      case AssembParser::Sop: {
        enterOuterAlt(_localctx, 3);
        setState(37);
        stype();
        break;
      }

      case AssembParser::Bop: {
        enterOuterAlt(_localctx, 4);
        setState(38);
        btype();
        break;
      }

      case AssembParser::Uop: {
        enterOuterAlt(_localctx, 5);
        setState(39);
        utype();
        break;
      }

      case AssembParser::Jop: {
        enterOuterAlt(_localctx, 6);
        setState(40);
        jtype();
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
  enterRule(_localctx, 6, AssembParser::RuleRtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(AssembParser::Rop);
    setState(44);
    dynamic_cast<RtypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(45);
    match(AssembParser::T__0);
    setState(46);
    dynamic_cast<RtypeContext *>(_localctx)->src1 = match(AssembParser::Reg);
    setState(47);
    match(AssembParser::T__0);
    setState(48);
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

tree::TerminalNode* AssembParser::ItypeContext::Imm() {
  return getToken(AssembParser::Imm, 0);
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
  enterRule(_localctx, 8, AssembParser::RuleItype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(50);
    match(AssembParser::Iop);
    setState(51);
    dynamic_cast<ItypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(52);
    match(AssembParser::T__0);
    setState(53);
    dynamic_cast<ItypeContext *>(_localctx)->src = match(AssembParser::Reg);
    setState(54);
    match(AssembParser::T__0);
    setState(55);
    dynamic_cast<ItypeContext *>(_localctx)->imm = match(AssembParser::Imm);
   
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

tree::TerminalNode* AssembParser::StypeContext::Integer() {
  return getToken(AssembParser::Integer, 0);
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
  enterRule(_localctx, 10, AssembParser::RuleStype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(57);
    match(AssembParser::Sop);
    setState(58);
    dynamic_cast<StypeContext *>(_localctx)->value = match(AssembParser::Reg);
    setState(59);
    match(AssembParser::T__0);
    setState(60);
    dynamic_cast<StypeContext *>(_localctx)->offset = match(AssembParser::Integer);
    setState(61);
    match(AssembParser::T__1);
    setState(62);
    dynamic_cast<StypeContext *>(_localctx)->addr = match(AssembParser::Reg);
    setState(63);
    match(AssembParser::T__2);
   
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

tree::TerminalNode* AssembParser::BtypeContext::Label() {
  return getToken(AssembParser::Label, 0);
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
  enterRule(_localctx, 12, AssembParser::RuleBtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(65);
    match(AssembParser::Bop);
    setState(66);
    dynamic_cast<BtypeContext *>(_localctx)->src1 = match(AssembParser::Reg);
    setState(67);
    match(AssembParser::T__0);
    setState(68);
    dynamic_cast<BtypeContext *>(_localctx)->src2 = match(AssembParser::Reg);
    setState(69);
    match(AssembParser::T__0);
    setState(70);
    dynamic_cast<BtypeContext *>(_localctx)->label = match(AssembParser::Label);
   
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

tree::TerminalNode* AssembParser::UtypeContext::Imm() {
  return getToken(AssembParser::Imm, 0);
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
  enterRule(_localctx, 14, AssembParser::RuleUtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(72);
    match(AssembParser::Uop);
    setState(73);
    dynamic_cast<UtypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(74);
    match(AssembParser::T__0);
    setState(75);
    dynamic_cast<UtypeContext *>(_localctx)->imm = match(AssembParser::Imm);
   
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

tree::TerminalNode* AssembParser::JtypeContext::Imm() {
  return getToken(AssembParser::Imm, 0);
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
  enterRule(_localctx, 16, AssembParser::RuleJtype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(77);
    match(AssembParser::Jop);
    setState(78);
    dynamic_cast<JtypeContext *>(_localctx)->rd = match(AssembParser::Reg);
    setState(79);
    match(AssembParser::T__0);
    setState(80);
    dynamic_cast<JtypeContext *>(_localctx)->imm = match(AssembParser::Imm);
   
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

tree::TerminalNode* AssembParser::JpContext::Label() {
  return getToken(AssembParser::Label, 0);
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

tree::TerminalNode* AssembParser::BzContext::Reg() {
  return getToken(AssembParser::Reg, 0);
}

tree::TerminalNode* AssembParser::BzContext::Label() {
  return getToken(AssembParser::Label, 0);
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

tree::TerminalNode* AssembParser::LiContext::Imm() {
  return getToken(AssembParser::Imm, 0);
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
  enterRule(_localctx, 18, AssembParser::RulePseudoInst);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(111);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::T__3: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::MvContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(82);
        match(AssembParser::T__3);
        setState(83);
        dynamic_cast<MvContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(84);
        match(AssembParser::T__0);
        setState(85);
        dynamic_cast<MvContext *>(_localctx)->src = match(AssembParser::Reg);
        break;
      }

      case AssembParser::T__4: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::LiContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(86);
        match(AssembParser::T__4);
        setState(87);
        dynamic_cast<LiContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(88);
        match(AssembParser::T__0);
        setState(89);
        dynamic_cast<LiContext *>(_localctx)->src = match(AssembParser::Imm);
        break;
      }

      case AssembParser::T__5: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::RetContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(90);
        match(AssembParser::T__5);
        break;
      }

      case AssembParser::T__6: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::JpContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(91);
        match(AssembParser::T__6);
        setState(92);
        dynamic_cast<JpContext *>(_localctx)->label = match(AssembParser::Label);
        break;
      }

      case AssembParser::T__7:
      case AssembParser::T__8:
      case AssembParser::T__9: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::LdContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(93);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AssembParser::T__7)
          | (1ULL << AssembParser::T__8)
          | (1ULL << AssembParser::T__9))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(94);
        dynamic_cast<LdContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(95);
        match(AssembParser::T__0);
        setState(96);
        dynamic_cast<LdContext *>(_localctx)->src = match(AssembParser::Symbol);
        break;
      }

      case AssembParser::T__10: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::LaContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(97);
        match(AssembParser::T__10);
        setState(98);
        dynamic_cast<LaContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(99);
        match(AssembParser::T__0);
        setState(100);
        dynamic_cast<LaContext *>(_localctx)->src = match(AssembParser::Symbol);
        break;
      }

      case AssembParser::T__11: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::CallContext>(_localctx));
        enterOuterAlt(_localctx, 7);
        setState(101);
        match(AssembParser::T__11);
        setState(102);
        match(AssembParser::Symbol);
        break;
      }

      case AssembParser::T__12:
      case AssembParser::T__13:
      case AssembParser::T__14:
      case AssembParser::T__15: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::SzContext>(_localctx));
        enterOuterAlt(_localctx, 8);
        setState(103);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AssembParser::T__12)
          | (1ULL << AssembParser::T__13)
          | (1ULL << AssembParser::T__14)
          | (1ULL << AssembParser::T__15))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(104);
        dynamic_cast<SzContext *>(_localctx)->rd = match(AssembParser::Reg);
        setState(105);
        match(AssembParser::T__0);
        setState(106);
        dynamic_cast<SzContext *>(_localctx)->src = match(AssembParser::Reg);
        break;
      }

      case AssembParser::T__16:
      case AssembParser::T__17:
      case AssembParser::T__18:
      case AssembParser::T__19:
      case AssembParser::T__20: {
        _localctx = dynamic_cast<PseudoInstContext *>(_tracker.createInstance<AssembParser::BzContext>(_localctx));
        enterOuterAlt(_localctx, 9);
        setState(107);
        _la = _input->LA(1);
        if (!((((_la & ~ 0x3fULL) == 0) &&
          ((1ULL << _la) & ((1ULL << AssembParser::T__16)
          | (1ULL << AssembParser::T__17)
          | (1ULL << AssembParser::T__18)
          | (1ULL << AssembParser::T__19)
          | (1ULL << AssembParser::T__20))) != 0))) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(108);
        dynamic_cast<BzContext *>(_localctx)->src = match(AssembParser::Reg);
        setState(109);
        match(AssembParser::T__0);
        setState(110);
        dynamic_cast<BzContext *>(_localctx)->label = match(AssembParser::Label);
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

//----------------- DerictiveContext ------------------------------------------------------------------

AssembParser::DerictiveContext::DerictiveContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AssembParser::DerictiveContext::getRuleIndex() const {
  return AssembParser::RuleDerictive;
}

void AssembParser::DerictiveContext::copyFrom(DerictiveContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SizeContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::SizeContext::Integer() {
  return getToken(AssembParser::Integer, 0);
}

AssembParser::SizeContext::SizeContext(DerictiveContext *ctx) { copyFrom(ctx); }

void AssembParser::SizeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSize(this);
}
void AssembParser::SizeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<AssembListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSize(this);
}

antlrcpp::Any AssembParser::SizeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AssembVisitor*>(visitor))
    return parserVisitor->visitSize(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IgnoreContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::IgnoreContext::IgnoreDirective() {
  return getToken(AssembParser::IgnoreDirective, 0);
}

AssembParser::IgnoreContext::IgnoreContext(DerictiveContext *ctx) { copyFrom(ctx); }

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

AssembParser::SectionContext::SectionContext(DerictiveContext *ctx) { copyFrom(ctx); }

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
//----------------- TypeContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::TypeContext::Type() {
  return getToken(AssembParser::Type, 0);
}

tree::TerminalNode* AssembParser::TypeContext::Symbol() {
  return getToken(AssembParser::Symbol, 0);
}

AssembParser::TypeContext::TypeContext(DerictiveContext *ctx) { copyFrom(ctx); }

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

AssembParser::AlignContext::AlignContext(DerictiveContext *ctx) { copyFrom(ctx); }

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
//----------------- AscizContext ------------------------------------------------------------------

tree::TerminalNode* AssembParser::AscizContext::StringLiteral() {
  return getToken(AssembParser::StringLiteral, 0);
}

AssembParser::AscizContext::AscizContext(DerictiveContext *ctx) { copyFrom(ctx); }

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
AssembParser::DerictiveContext* AssembParser::derictive() {
  DerictiveContext *_localctx = _tracker.createInstance<DerictiveContext>(_ctx, getState());
  enterRule(_localctx, 20, AssembParser::RuleDerictive);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(125);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AssembParser::Section: {
        _localctx = dynamic_cast<DerictiveContext *>(_tracker.createInstance<AssembParser::SectionContext>(_localctx));
        enterOuterAlt(_localctx, 1);
        setState(113);
        match(AssembParser::Section);
        break;
      }

      case AssembParser::T__21: {
        _localctx = dynamic_cast<DerictiveContext *>(_tracker.createInstance<AssembParser::TypeContext>(_localctx));
        enterOuterAlt(_localctx, 2);
        setState(114);
        match(AssembParser::T__21);
        setState(115);
        dynamic_cast<TypeContext *>(_localctx)->symbol = match(AssembParser::Symbol);
        setState(116);
        match(AssembParser::T__0);
        setState(117);
        match(AssembParser::Type);
        break;
      }

      case AssembParser::T__22:
      case AssembParser::T__23: {
        _localctx = dynamic_cast<DerictiveContext *>(_tracker.createInstance<AssembParser::AlignContext>(_localctx));
        enterOuterAlt(_localctx, 3);
        setState(118);
        _la = _input->LA(1);
        if (!(_la == AssembParser::T__22

        || _la == AssembParser::T__23)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(119);
        match(AssembParser::Integer);
        break;
      }

      case AssembParser::T__24: {
        _localctx = dynamic_cast<DerictiveContext *>(_tracker.createInstance<AssembParser::SizeContext>(_localctx));
        enterOuterAlt(_localctx, 4);
        setState(120);
        match(AssembParser::T__24);
        setState(121);
        match(AssembParser::Integer);
        break;
      }

      case AssembParser::T__25: {
        _localctx = dynamic_cast<DerictiveContext *>(_tracker.createInstance<AssembParser::AscizContext>(_localctx));
        enterOuterAlt(_localctx, 5);
        setState(122);
        match(AssembParser::T__25);
        setState(123);
        match(AssembParser::StringLiteral);
        break;
      }

      case AssembParser::IgnoreDirective: {
        _localctx = dynamic_cast<DerictiveContext *>(_tracker.createInstance<AssembParser::IgnoreContext>(_localctx));
        enterOuterAlt(_localctx, 6);
        setState(124);
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

// Static vars and initialization.
std::vector<dfa::DFA> AssembParser::_decisionToDFA;
atn::PredictionContextCache AssembParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN AssembParser::_atn;
std::vector<uint16_t> AssembParser::_serializedATN;

std::vector<std::string> AssembParser::_ruleNames = {
  "file", "line", "inst", "rtype", "itype", "stype", "btype", "utype", "jtype", 
  "pseudoInst", "derictive"
};

std::vector<std::string> AssembParser::_literalNames = {
  "", "','", "'('", "')'", "'mv'", "'li'", "'ret'", "'j'", "'lb'", "'lh'", 
  "'lw'", "'la'", "'call'", "'seqz'", "'snez'", "'sgtz'", "'sltz'", "'beqz'", 
  "'bnez'", "'bgtz'", "'bltz'", "'blez'", "'.type'", "'.p2align'", "'.align'", 
  "'.size'", "'.asciz'", "", "", "", "", "", "", "", "", "'jal'"
};

std::vector<std::string> AssembParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "IgnoreDirective", "Section", "Type", 
  "Rop", "Iop", "Sop", "Bop", "Uop", "Jop", "Reg", "Symbol", "Label", "StringLiteral", 
  "Imm", "Relocation", "Integer", "DecimalInteger", "Whitespace", "Newline", 
  "LineComment"
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
    0x3, 0x30, 0x82, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 0x9, 
    0xb, 0x4, 0xc, 0x9, 0xc, 0x3, 0x2, 0x7, 0x2, 0x1a, 0xa, 0x2, 0xc, 0x2, 
    0xe, 0x2, 0x1d, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x24, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x2c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x72, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x80, 0xa, 0xc, 0x3, 0xc, 0x2, 
    0x2, 0xd, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x2, 0x6, 0x3, 0x2, 0xa, 0xc, 0x3, 0x2, 0xf, 0x12, 0x3, 0x2, 0x13, 0x17, 
    0x3, 0x2, 0x19, 0x1a, 0x2, 0x8b, 0x2, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x4, 
    0x23, 0x3, 0x2, 0x2, 0x2, 0x6, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x8, 0x2d, 
    0x3, 0x2, 0x2, 0x2, 0xa, 0x34, 0x3, 0x2, 0x2, 0x2, 0xc, 0x3b, 0x3, 0x2, 
    0x2, 0x2, 0xe, 0x43, 0x3, 0x2, 0x2, 0x2, 0x10, 0x4a, 0x3, 0x2, 0x2, 
    0x2, 0x12, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x14, 0x71, 0x3, 0x2, 0x2, 0x2, 
    0x16, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1a, 0x5, 0x4, 0x3, 0x2, 0x19, 
    0x18, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1e, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x2, 
    0x2, 0x3, 0x1f, 0x3, 0x3, 0x2, 0x2, 0x2, 0x20, 0x24, 0x5, 0x6, 0x4, 
    0x2, 0x21, 0x24, 0x5, 0x14, 0xb, 0x2, 0x22, 0x24, 0x5, 0x16, 0xc, 0x2, 
    0x23, 0x20, 0x3, 0x2, 0x2, 0x2, 0x23, 0x21, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x22, 0x3, 0x2, 0x2, 0x2, 0x24, 0x5, 0x3, 0x2, 0x2, 0x2, 0x25, 0x2c, 
    0x5, 0x8, 0x5, 0x2, 0x26, 0x2c, 0x5, 0xa, 0x6, 0x2, 0x27, 0x2c, 0x5, 
    0xc, 0x7, 0x2, 0x28, 0x2c, 0x5, 0xe, 0x8, 0x2, 0x29, 0x2c, 0x5, 0x10, 
    0x9, 0x2, 0x2a, 0x2c, 0x5, 0x12, 0xa, 0x2, 0x2b, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x2b, 0x26, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x2b, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x2a, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x7, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 
    0x7, 0x20, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x26, 0x2, 0x2, 0x2f, 0x30, 0x7, 
    0x3, 0x2, 0x2, 0x30, 0x31, 0x7, 0x26, 0x2, 0x2, 0x31, 0x32, 0x7, 0x3, 
    0x2, 0x2, 0x32, 0x33, 0x7, 0x26, 0x2, 0x2, 0x33, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0x35, 0x7, 0x21, 0x2, 0x2, 0x35, 0x36, 0x7, 0x26, 0x2, 0x2, 
    0x36, 0x37, 0x7, 0x3, 0x2, 0x2, 0x37, 0x38, 0x7, 0x26, 0x2, 0x2, 0x38, 
    0x39, 0x7, 0x3, 0x2, 0x2, 0x39, 0x3a, 0x7, 0x2a, 0x2, 0x2, 0x3a, 0xb, 
    0x3, 0x2, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x22, 0x2, 0x2, 0x3c, 0x3d, 0x7, 
    0x26, 0x2, 0x2, 0x3d, 0x3e, 0x7, 0x3, 0x2, 0x2, 0x3e, 0x3f, 0x7, 0x2c, 
    0x2, 0x2, 0x3f, 0x40, 0x7, 0x4, 0x2, 0x2, 0x40, 0x41, 0x7, 0x26, 0x2, 
    0x2, 0x41, 0x42, 0x7, 0x5, 0x2, 0x2, 0x42, 0xd, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x44, 0x7, 0x23, 0x2, 0x2, 0x44, 0x45, 0x7, 0x26, 0x2, 0x2, 0x45, 
    0x46, 0x7, 0x3, 0x2, 0x2, 0x46, 0x47, 0x7, 0x26, 0x2, 0x2, 0x47, 0x48, 
    0x7, 0x3, 0x2, 0x2, 0x48, 0x49, 0x7, 0x28, 0x2, 0x2, 0x49, 0xf, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x4b, 0x7, 0x24, 0x2, 0x2, 0x4b, 0x4c, 0x7, 0x26, 
    0x2, 0x2, 0x4c, 0x4d, 0x7, 0x3, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x2a, 0x2, 
    0x2, 0x4e, 0x11, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x7, 0x25, 0x2, 0x2, 
    0x50, 0x51, 0x7, 0x26, 0x2, 0x2, 0x51, 0x52, 0x7, 0x3, 0x2, 0x2, 0x52, 
    0x53, 0x7, 0x2a, 0x2, 0x2, 0x53, 0x13, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 
    0x7, 0x6, 0x2, 0x2, 0x55, 0x56, 0x7, 0x26, 0x2, 0x2, 0x56, 0x57, 0x7, 
    0x3, 0x2, 0x2, 0x57, 0x72, 0x7, 0x26, 0x2, 0x2, 0x58, 0x59, 0x7, 0x7, 
    0x2, 0x2, 0x59, 0x5a, 0x7, 0x26, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x3, 0x2, 
    0x2, 0x5b, 0x72, 0x7, 0x2a, 0x2, 0x2, 0x5c, 0x72, 0x7, 0x8, 0x2, 0x2, 
    0x5d, 0x5e, 0x7, 0x9, 0x2, 0x2, 0x5e, 0x72, 0x7, 0x28, 0x2, 0x2, 0x5f, 
    0x60, 0x9, 0x2, 0x2, 0x2, 0x60, 0x61, 0x7, 0x26, 0x2, 0x2, 0x61, 0x62, 
    0x7, 0x3, 0x2, 0x2, 0x62, 0x72, 0x7, 0x27, 0x2, 0x2, 0x63, 0x64, 0x7, 
    0xd, 0x2, 0x2, 0x64, 0x65, 0x7, 0x26, 0x2, 0x2, 0x65, 0x66, 0x7, 0x3, 
    0x2, 0x2, 0x66, 0x72, 0x7, 0x27, 0x2, 0x2, 0x67, 0x68, 0x7, 0xe, 0x2, 
    0x2, 0x68, 0x72, 0x7, 0x27, 0x2, 0x2, 0x69, 0x6a, 0x9, 0x3, 0x2, 0x2, 
    0x6a, 0x6b, 0x7, 0x26, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x3, 0x2, 0x2, 0x6c, 
    0x72, 0x7, 0x26, 0x2, 0x2, 0x6d, 0x6e, 0x9, 0x4, 0x2, 0x2, 0x6e, 0x6f, 
    0x7, 0x26, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x3, 0x2, 0x2, 0x70, 0x72, 0x7, 
    0x28, 0x2, 0x2, 0x71, 0x54, 0x3, 0x2, 0x2, 0x2, 0x71, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x71, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x71, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x71, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x71, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x67, 0x3, 0x2, 0x2, 0x2, 0x71, 0x69, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x72, 0x15, 0x3, 0x2, 0x2, 0x2, 0x73, 0x80, 
    0x7, 0x1e, 0x2, 0x2, 0x74, 0x75, 0x7, 0x18, 0x2, 0x2, 0x75, 0x76, 0x7, 
    0x27, 0x2, 0x2, 0x76, 0x77, 0x7, 0x3, 0x2, 0x2, 0x77, 0x80, 0x7, 0x1f, 
    0x2, 0x2, 0x78, 0x79, 0x9, 0x5, 0x2, 0x2, 0x79, 0x80, 0x7, 0x2c, 0x2, 
    0x2, 0x7a, 0x7b, 0x7, 0x1b, 0x2, 0x2, 0x7b, 0x80, 0x7, 0x2c, 0x2, 0x2, 
    0x7c, 0x7d, 0x7, 0x1c, 0x2, 0x2, 0x7d, 0x80, 0x7, 0x29, 0x2, 0x2, 0x7e, 
    0x80, 0x7, 0x1d, 0x2, 0x2, 0x7f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x74, 
    0x3, 0x2, 0x2, 0x2, 0x7f, 0x78, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7a, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7e, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x17, 0x3, 0x2, 0x2, 0x2, 0x7, 0x1b, 0x23, 0x2b, 0x71, 
    0x7f, 
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
