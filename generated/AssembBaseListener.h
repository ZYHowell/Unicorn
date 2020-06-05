
// Generated from Assemb.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AssembListener.h"


/**
 * This class provides an empty implementation of AssembListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  AssembBaseListener : public AssembListener {
public:

  virtual void enterFile(AssembParser::FileContext * /*ctx*/) override { }
  virtual void exitFile(AssembParser::FileContext * /*ctx*/) override { }

  virtual void enterLine(AssembParser::LineContext * /*ctx*/) override { }
  virtual void exitLine(AssembParser::LineContext * /*ctx*/) override { }

  virtual void enterInst(AssembParser::InstContext * /*ctx*/) override { }
  virtual void exitInst(AssembParser::InstContext * /*ctx*/) override { }

  virtual void enterStart(AssembParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(AssembParser::StartContext * /*ctx*/) override { }

  virtual void enterRtype(AssembParser::RtypeContext * /*ctx*/) override { }
  virtual void exitRtype(AssembParser::RtypeContext * /*ctx*/) override { }

  virtual void enterItype(AssembParser::ItypeContext * /*ctx*/) override { }
  virtual void exitItype(AssembParser::ItypeContext * /*ctx*/) override { }

  virtual void enterStype(AssembParser::StypeContext * /*ctx*/) override { }
  virtual void exitStype(AssembParser::StypeContext * /*ctx*/) override { }

  virtual void enterBtype(AssembParser::BtypeContext * /*ctx*/) override { }
  virtual void exitBtype(AssembParser::BtypeContext * /*ctx*/) override { }

  virtual void enterUtype(AssembParser::UtypeContext * /*ctx*/) override { }
  virtual void exitUtype(AssembParser::UtypeContext * /*ctx*/) override { }

  virtual void enterJtype(AssembParser::JtypeContext * /*ctx*/) override { }
  virtual void exitJtype(AssembParser::JtypeContext * /*ctx*/) override { }

  virtual void enterLtype(AssembParser::LtypeContext * /*ctx*/) override { }
  virtual void exitLtype(AssembParser::LtypeContext * /*ctx*/) override { }

  virtual void enterMv(AssembParser::MvContext * /*ctx*/) override { }
  virtual void exitMv(AssembParser::MvContext * /*ctx*/) override { }

  virtual void enterLi(AssembParser::LiContext * /*ctx*/) override { }
  virtual void exitLi(AssembParser::LiContext * /*ctx*/) override { }

  virtual void enterRet(AssembParser::RetContext * /*ctx*/) override { }
  virtual void exitRet(AssembParser::RetContext * /*ctx*/) override { }

  virtual void enterJp(AssembParser::JpContext * /*ctx*/) override { }
  virtual void exitJp(AssembParser::JpContext * /*ctx*/) override { }

  virtual void enterLd(AssembParser::LdContext * /*ctx*/) override { }
  virtual void exitLd(AssembParser::LdContext * /*ctx*/) override { }

  virtual void enterLa(AssembParser::LaContext * /*ctx*/) override { }
  virtual void exitLa(AssembParser::LaContext * /*ctx*/) override { }

  virtual void enterCall(AssembParser::CallContext * /*ctx*/) override { }
  virtual void exitCall(AssembParser::CallContext * /*ctx*/) override { }

  virtual void enterSz(AssembParser::SzContext * /*ctx*/) override { }
  virtual void exitSz(AssembParser::SzContext * /*ctx*/) override { }

  virtual void enterBz(AssembParser::BzContext * /*ctx*/) override { }
  virtual void exitBz(AssembParser::BzContext * /*ctx*/) override { }

  virtual void enterSection(AssembParser::SectionContext * /*ctx*/) override { }
  virtual void exitSection(AssembParser::SectionContext * /*ctx*/) override { }

  virtual void enterGlobl(AssembParser::GloblContext * /*ctx*/) override { }
  virtual void exitGlobl(AssembParser::GloblContext * /*ctx*/) override { }

  virtual void enterType(AssembParser::TypeContext * /*ctx*/) override { }
  virtual void exitType(AssembParser::TypeContext * /*ctx*/) override { }

  virtual void enterAlign(AssembParser::AlignContext * /*ctx*/) override { }
  virtual void exitAlign(AssembParser::AlignContext * /*ctx*/) override { }

  virtual void enterWord(AssembParser::WordContext * /*ctx*/) override { }
  virtual void exitWord(AssembParser::WordContext * /*ctx*/) override { }

  virtual void enterAsciz(AssembParser::AscizContext * /*ctx*/) override { }
  virtual void exitAsciz(AssembParser::AscizContext * /*ctx*/) override { }

  virtual void enterFilename(AssembParser::FilenameContext * /*ctx*/) override { }
  virtual void exitFilename(AssembParser::FilenameContext * /*ctx*/) override { }

  virtual void enterIgnore(AssembParser::IgnoreContext * /*ctx*/) override { }
  virtual void exitIgnore(AssembParser::IgnoreContext * /*ctx*/) override { }

  virtual void enterImm(AssembParser::ImmContext * /*ctx*/) override { }
  virtual void exitImm(AssembParser::ImmContext * /*ctx*/) override { }

  virtual void enterRelocation(AssembParser::RelocationContext * /*ctx*/) override { }
  virtual void exitRelocation(AssembParser::RelocationContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

