
// Generated from Assemb.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AssembVisitor.h"


/**
 * This class provides an empty implementation of AssembVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  AssembBaseVisitor : public AssembVisitor {
public:

  virtual antlrcpp::Any visitFile(AssembParser::FileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLine(AssembParser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitInst(AssembParser::InstContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStart(AssembParser::StartContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRtype(AssembParser::RtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitItype(AssembParser::ItypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStype(AssembParser::StypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBtype(AssembParser::BtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUtype(AssembParser::UtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJtype(AssembParser::JtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLtype(AssembParser::LtypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMv(AssembParser::MvContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLi(AssembParser::LiContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRet(AssembParser::RetContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJp(AssembParser::JpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLd(AssembParser::LdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLa(AssembParser::LaContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCall(AssembParser::CallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSz(AssembParser::SzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBz(AssembParser::BzContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSection(AssembParser::SectionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGlobl(AssembParser::GloblContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType(AssembParser::TypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAlign(AssembParser::AlignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWord(AssembParser::WordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAsciz(AssembParser::AscizContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFilename(AssembParser::FilenameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImm(AssembParser::ImmContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelocation(AssembParser::RelocationContext *ctx) override {
    return visitChildren(ctx);
  }


};

