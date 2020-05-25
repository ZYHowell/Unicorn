
// Generated from Assemb.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "AssembParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by AssembParser.
 */
class  AssembVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by AssembParser.
   */
    virtual antlrcpp::Any visitFile(AssembParser::FileContext *context) = 0;

    virtual antlrcpp::Any visitLine(AssembParser::LineContext *context) = 0;

    virtual antlrcpp::Any visitInst(AssembParser::InstContext *context) = 0;

    virtual antlrcpp::Any visitRtype(AssembParser::RtypeContext *context) = 0;

    virtual antlrcpp::Any visitItype(AssembParser::ItypeContext *context) = 0;

    virtual antlrcpp::Any visitStype(AssembParser::StypeContext *context) = 0;

    virtual antlrcpp::Any visitBtype(AssembParser::BtypeContext *context) = 0;

    virtual antlrcpp::Any visitUtype(AssembParser::UtypeContext *context) = 0;

    virtual antlrcpp::Any visitJtype(AssembParser::JtypeContext *context) = 0;

    virtual antlrcpp::Any visitMv(AssembParser::MvContext *context) = 0;

    virtual antlrcpp::Any visitLi(AssembParser::LiContext *context) = 0;

    virtual antlrcpp::Any visitRet(AssembParser::RetContext *context) = 0;

    virtual antlrcpp::Any visitJp(AssembParser::JpContext *context) = 0;

    virtual antlrcpp::Any visitLd(AssembParser::LdContext *context) = 0;

    virtual antlrcpp::Any visitLa(AssembParser::LaContext *context) = 0;

    virtual antlrcpp::Any visitCall(AssembParser::CallContext *context) = 0;

    virtual antlrcpp::Any visitSz(AssembParser::SzContext *context) = 0;

    virtual antlrcpp::Any visitBz(AssembParser::BzContext *context) = 0;

    virtual antlrcpp::Any visitSection(AssembParser::SectionContext *context) = 0;

    virtual antlrcpp::Any visitType(AssembParser::TypeContext *context) = 0;

    virtual antlrcpp::Any visitAlign(AssembParser::AlignContext *context) = 0;

    virtual antlrcpp::Any visitSize(AssembParser::SizeContext *context) = 0;

    virtual antlrcpp::Any visitAsciz(AssembParser::AscizContext *context) = 0;

    virtual antlrcpp::Any visitIgnore(AssembParser::IgnoreContext *context) = 0;


};

