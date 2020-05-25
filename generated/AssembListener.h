
// Generated from Assemb.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AssembParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by AssembParser.
 */
class  AssembListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterFile(AssembParser::FileContext *ctx) = 0;
  virtual void exitFile(AssembParser::FileContext *ctx) = 0;

  virtual void enterLine(AssembParser::LineContext *ctx) = 0;
  virtual void exitLine(AssembParser::LineContext *ctx) = 0;

  virtual void enterInst(AssembParser::InstContext *ctx) = 0;
  virtual void exitInst(AssembParser::InstContext *ctx) = 0;

  virtual void enterRtype(AssembParser::RtypeContext *ctx) = 0;
  virtual void exitRtype(AssembParser::RtypeContext *ctx) = 0;

  virtual void enterItype(AssembParser::ItypeContext *ctx) = 0;
  virtual void exitItype(AssembParser::ItypeContext *ctx) = 0;

  virtual void enterStype(AssembParser::StypeContext *ctx) = 0;
  virtual void exitStype(AssembParser::StypeContext *ctx) = 0;

  virtual void enterBtype(AssembParser::BtypeContext *ctx) = 0;
  virtual void exitBtype(AssembParser::BtypeContext *ctx) = 0;

  virtual void enterUtype(AssembParser::UtypeContext *ctx) = 0;
  virtual void exitUtype(AssembParser::UtypeContext *ctx) = 0;

  virtual void enterJtype(AssembParser::JtypeContext *ctx) = 0;
  virtual void exitJtype(AssembParser::JtypeContext *ctx) = 0;

  virtual void enterMv(AssembParser::MvContext *ctx) = 0;
  virtual void exitMv(AssembParser::MvContext *ctx) = 0;

  virtual void enterLi(AssembParser::LiContext *ctx) = 0;
  virtual void exitLi(AssembParser::LiContext *ctx) = 0;

  virtual void enterRet(AssembParser::RetContext *ctx) = 0;
  virtual void exitRet(AssembParser::RetContext *ctx) = 0;

  virtual void enterJp(AssembParser::JpContext *ctx) = 0;
  virtual void exitJp(AssembParser::JpContext *ctx) = 0;

  virtual void enterLd(AssembParser::LdContext *ctx) = 0;
  virtual void exitLd(AssembParser::LdContext *ctx) = 0;

  virtual void enterLa(AssembParser::LaContext *ctx) = 0;
  virtual void exitLa(AssembParser::LaContext *ctx) = 0;

  virtual void enterCall(AssembParser::CallContext *ctx) = 0;
  virtual void exitCall(AssembParser::CallContext *ctx) = 0;

  virtual void enterSz(AssembParser::SzContext *ctx) = 0;
  virtual void exitSz(AssembParser::SzContext *ctx) = 0;

  virtual void enterBz(AssembParser::BzContext *ctx) = 0;
  virtual void exitBz(AssembParser::BzContext *ctx) = 0;

  virtual void enterSection(AssembParser::SectionContext *ctx) = 0;
  virtual void exitSection(AssembParser::SectionContext *ctx) = 0;

  virtual void enterType(AssembParser::TypeContext *ctx) = 0;
  virtual void exitType(AssembParser::TypeContext *ctx) = 0;

  virtual void enterAlign(AssembParser::AlignContext *ctx) = 0;
  virtual void exitAlign(AssembParser::AlignContext *ctx) = 0;

  virtual void enterSize(AssembParser::SizeContext *ctx) = 0;
  virtual void exitSize(AssembParser::SizeContext *ctx) = 0;

  virtual void enterAsciz(AssembParser::AscizContext *ctx) = 0;
  virtual void exitAsciz(AssembParser::AscizContext *ctx) = 0;

  virtual void enterIgnore(AssembParser::IgnoreContext *ctx) = 0;
  virtual void exitIgnore(AssembParser::IgnoreContext *ctx) = 0;


};

