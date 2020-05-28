#ifndef Unicorn_Visitor_H
#define Unicorn_Visitor_H
#include "includes.h"
#include "AssembBaseVisitor.h"
using namespace Unicorn;
class EvalVisitor: public AssembBaseVisitor {
private:
    struct section_t{
      Elf32_Shdr header;
      std::vector<std::byte> contents;
      section_t(): header(), contents(){}
    };
    struct symbol_t{
      Elf32_Sym info;
      Elf32_Byte bind = STB_LOCAL;
      Elf32_Byte type = STT_NOTYPE;
    };

    std::map<std::string, section_t*> sections = std::map<std::string, section_t*>();
    std::map<std::string, symbol_t*> symbols = std::map<std::string, symbol_t*>();
    std::map<size_t, Elf32_Rela> relocations = std::map<size_t, Elf32_Rela>();
    using Any = antlrcpp::Any;
    std::string cur_sec_name = ".text";
    section_t* cur_sec;
    symbol_t* cur_sym;

    bool isText = true;
    int pass;

    Elf32_Word getIInst(std::string op, std::string rd, 
                        std::string src, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src]);
      inst = addIImm(inst, imm);
      return getLittleEdian(inst);
    }
    Elf32_Word getRInst(std::string op, std::string rd, 
                        std::string src1, std::string src2) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      return getLittleEdian(inst);
    }
    Elf32_Word getSInst(std::string op, std::string src1, std::string src2, 
                        Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      inst = addSImm(inst, imm);
      return getLittleEdian(inst);
    }

    Elf32_Word getUInst(std::string op, std::string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addUImm(inst, imm);
      return getLittleEdian(inst);
    }
    Elf32_Word getJInst(std::string op, std::string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addJImm(inst, imm);
      return getLittleEdian(inst);
    }
public: 

  antlrcpp::Any visitFile(AssembParser::FileContext *ctx) override {
    pass = 1;
    for (auto line : ctx->line()) visit(line);
    pass = 2;
    for (auto line : ctx->line()) visit(line);
    return 0;
  }

  antlrcpp::Any visitLine(AssembParser::LineContext *ctx) override {
    if (ctx->pseudoInst() != nullptr) visit(ctx->pseudoInst());
    else if (ctx->inst() != nullptr) visit(ctx->inst());
    else if (ctx->directive() != nullptr) visit(ctx->directive());
    else if (ctx->start() != nullptr) visit(ctx->start());
    else assert(false);
    return 0;
  }

  antlrcpp::Any visitInst(AssembParser::InstContext *ctx) override {
    if (ctx->rtype() != nullptr) visit(ctx->rtype());
    else if (ctx->itype() != nullptr) visit(ctx->itype());
    else if (ctx->stype() != nullptr) visit(ctx->stype());
    else if (ctx->btype() != nullptr) visit(ctx->btype());
    else if (ctx->utype() != nullptr) visit(ctx->utype());
    else if (ctx->jtype() != nullptr) visit(ctx->jtype());
    else if (ctx->ltype() != nullptr) visit(ctx->ltype());
    else assert(false);
    return 0;
  }

  antlrcpp::Any visitStart(AssembParser::StartContext *ctx) override {
    if (pass == 1) {
      symbol_t *symbol = new symbol_t();
      symbols.insert(std::pair<std::string, symbol_t*>(
                      ctx->Symbol()->toString(), symbol
                    ));
      cur_sym = symbol;
    } else {
      //todo
      cur_sym = symbols[ctx->Symbol()->toString()];
    }
    return 0;
  }

  antlrcpp::Any visitRtype(AssembParser::RtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);

      *(Elf32_Word*)(cur_sec->contents.data() + size) = 
        getRInst(ctx->Rop()->toString(), ctx->Reg(0)->toString(), 
        ctx->Reg(1)->toString(), ctx->Reg(2)->toString());
    }
    return 0;
  }

  antlrcpp::Any visitItype(AssembParser::ItypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);

      *(Elf32_Word*)(cur_sec->contents.data() + size) = 
        getIInst(ctx->Iop()->toString(), ctx->Reg(0)->toString(), 
                ctx->Reg(1)->toString(), visit(ctx->imm()).as<Elf32_Word>()); 
    }
    return 0;
  }

  antlrcpp::Any visitStype(AssembParser::StypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 
        getSInst(ctx->Sop()->toString(), ctx->Reg(1)->toString(), 
        ctx->Reg(0)->toString(), visit(ctx->imm()).as<Elf32_Word>());
    }
    return 0;
  }

  antlrcpp::Any visitBtype(AssembParser::BtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
      //todo: add relocation here
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitUtype(AssembParser::UtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);

      *(Elf32_Word*)(cur_sec->contents.data() + size) = 
        getUInst(ctx->Uop()->toString(), ctx->Reg()->toString(), 
        visit(ctx->imm()).as<Elf32_Word>());
    }
    return 0;
  }

  antlrcpp::Any visitJtype(AssembParser::JtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);

      *(Elf32_Word*)(cur_sec->contents.data() + size) = 
        getJInst(ctx->Jop()->toString(), ctx->Reg()->toString(), 
        visit(ctx->imm()).as<Elf32_Word>());
    }
    return 0;
  }

  antlrcpp::Any visitLtype(AssembParser::LtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitMv(AssembParser::MvContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitLi(AssembParser::LiContext *ctx) override {
    assert(isText);
    if (pass == 1) {}
    return visitChildren(ctx);
  }

  antlrcpp::Any visitRet(AssembParser::RetContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitJp(AssembParser::JpContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitLd(AssembParser::LdContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitLa(AssembParser::LaContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitCall(AssembParser::CallContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitSz(AssembParser::SzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitBz(AssembParser::BzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      size_t size = cur_sec->contents.size();
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      *(Elf32_Word*)(cur_sec->contents.data() + size) = 0;  //todo
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitSection(AssembParser::SectionContext *ctx) override {
    if (sections.count(ctx->Section()->toString()))
      cur_sec = sections[ctx->Section()->toString()];
    else {
      cur_sec = new section_t();
      sections.insert(std::pair<std::string, section_t*>(
                                ctx->Section()->toString(), cur_sec
                                ));
    }
    if (cur_sec_name == ".text") isText = true;
    else isText = false;
    return 0;
  }

  antlrcpp::Any visitType(AssembParser::TypeContext *ctx) override {

    return visitChildren(ctx);
  }

  antlrcpp::Any visitAlign(AssembParser::AlignContext *ctx) override {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitSize(AssembParser::SizeContext *ctx) override {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitAsciz(AssembParser::AscizContext *ctx) override {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitIgnore(AssembParser::IgnoreContext *ctx) override {
    if (pass == 1) 
      std::cout << "ignore directive: " << ctx->IgnoreDirective()->toString();
    return 0;
  }

  antlrcpp::Any visitImm(AssembParser::ImmContext *ctx) override {
    assert(isText);
    if (ctx->Integer() != nullptr) {
      return (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
    }
    else if (ctx->Relocation() != nullptr) {
      //todo
      return (Elf32_Word)0;
    }
    return 0;
  }

};
#endif