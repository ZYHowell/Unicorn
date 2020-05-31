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
      Elf32_Off offset;
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
    size_t currentTextOff = 0;

    inline Elf32_Word getIInst(std::string op, std::string rd, 
                              std::string src, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src]);
      inst = addIImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getRInst(std::string op, std::string rd, 
                              std::string src1, std::string src2) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getSInst(std::string op, std::string src1, std::string src2, 
                              Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      inst = addSImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getUInst(std::string op, std::string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addUImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getJInst(std::string op, std::string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addJImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getBInst(std::string op, std::string src1, 
                              std::string src2, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      inst = addBImm(inst, imm);
      return getLittleEdian(inst);
    }
public: 

  antlrcpp::Any visitFile(AssembParser::FileContext *ctx) override {
    pass = 1;
    section_t* tmp;
    tmp = new section_t();
    tmp->header.sh_type = SHT_PROGBITS;
    tmp->header.sh_flags = SHF_ALLOC | SHF_EXECINSTR;
    sections.insert(std::pair<std::string, section_t*>(".text", tmp));
    tmp = new section_t();
    tmp->header.sh_type = SHT_RELA;
    tmp->header.sh_flags = SHF_INFO_LINK;
    sections.insert(std::pair<std::string, section_t*>(".rela.text", tmp));
    tmp = new section_t();
    tmp->header.sh_type = SHT_NOBITS;
    tmp->header.sh_flags = SHF_ALLOC | SHF_WRITE;
    sections.insert(std::pair<std::string, section_t*>(".bss", tmp));
    tmp = new section_t();
    tmp->header.sh_type = SHT_PROGBITS;
    tmp->header.sh_flags = SHF_ALLOC;
    sections.insert(std::pair<std::string, section_t*>(".rodata", tmp));
    tmp = new section_t();
    tmp->header.sh_type = SHT_PROGBITS;
    tmp->header.sh_flags = SHF_ALLOC | SHF_WRITE;
    sections.insert(std::pair<std::string, section_t*>(".data", tmp));
    tmp = new section_t();
    tmp->header.sh_type = SHT_PROGBITS;
    tmp->header.sh_flags = SHF_MERGE | SHF_STRINGS;
    sections.insert(std::pair<std::string, section_t*>(".comment", tmp));

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
      symbol->offset = cur_sec->contents.size();
      symbols.insert(std::pair<std::string, symbol_t*>(
                      ctx->Symbol()->toString(), symbol
                    ));
      cur_sym = symbol;
    } else if (pass == 2) {
      //todo
      cur_sym = symbols[ctx->Symbol()->toString()];
    }
    return 0;
  }

  antlrcpp::Any visitRtype(AssembParser::RtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getRInst(ctx->Rop()->toString(), ctx->Reg(0)->toString(), 
        ctx->Reg(1)->toString(), ctx->Reg(2)->toString());
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitItype(AssembParser::ItypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getIInst(ctx->Iop()->toString(), ctx->Reg(0)->toString(), 
                ctx->Reg(1)->toString(), visit(ctx->imm()).as<Elf32_Word>()); 
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitStype(AssembParser::StypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getSInst(ctx->Sop()->toString(), ctx->Reg(1)->toString(), 
        ctx->Reg(0)->toString(), visit(ctx->imm()).as<Elf32_Word>());
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitBtype(AssembParser::BtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
      //todo: add relocation here?
    } else if (pass == 2) {
      //todo
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;
      currentTextOff += 4;
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitUtype(AssembParser::UtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getUInst(ctx->Uop()->toString(), ctx->Reg()->toString(), 
        visit(ctx->imm()).as<Elf32_Word>());
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitJtype(AssembParser::JtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getJInst(ctx->Jop()->toString(), ctx->Reg()->toString(), 
        visit(ctx->imm()).as<Elf32_Word>());
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitLtype(AssembParser::LtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getIInst(ctx->Lop()->toString(), ctx->Reg(0)->toString(), 
                ctx->Reg(1)->toString(), visit(ctx->imm()).as<Elf32_Word>()); 
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitMv(AssembParser::MvContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getIInst("addi", ctx->Reg(0)->toString(), ctx->Reg(1)->toString(), 0); 
      currentTextOff += 4;
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitLi(AssembParser::LiContext *ctx) override {
    assert(isText);
    Elf32_Word value = visit(ctx->imm()).as<Elf32_Word>();
    Elf32_Word hi = value >> 12u, lo = value & 0xfffu;
    if (pass == 1) {
      if (hi != 0) {
        cur_sec->contents.resize(cur_sec->contents.size() + 8);
      } else {
        cur_sec->contents.resize(cur_sec->contents.size() + 4);
      }
    } else if (pass == 2) {
      if (hi != 0) {
        *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
          getUInst("lui", ctx->Reg()->toString(), hi);
        *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff + 4) = 
          getIInst("ori", ctx->Reg()->toString(), 
            ctx->Reg()->toString(), lo);
      } else {
        *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
          getIInst("addi", ctx->Reg()->toString(), "zero", lo);
      }
      currentTextOff += (hi != 0) ? 8 : 4;
    }
    return 0;
  }

  antlrcpp::Any visitRet(AssembParser::RetContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
        getIInst("jalr", "zero", "ra", 0);
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitJp(AssembParser::JpContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      currentTextOff += 4;
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitLd(AssembParser::LdContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      currentTextOff += 8;
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitLa(AssembParser::LaContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      currentTextOff += 8;
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitCall(AssembParser::CallContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      currentTextOff += 8;
    }
    return visitChildren(ctx);
  }

  antlrcpp::Any visitSz(AssembParser::SzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    }else if (pass == 2) {
      std::string op = ctx->Szop()->toString();
      if (op == "seqz"){
        *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
          getIInst("sltiu", ctx->Reg(0)->toString(), 
          ctx->Reg(1)->toString(), 1);
      } else if (op == "snez") {
        *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
          getRInst("sltu", ctx->Reg(0)->toString(), 
           "zero", ctx->Reg(1)->toString());
      } else if (op == "sltz") {
        *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
          getRInst("slt", ctx->Reg(0)->toString(), 
           ctx->Reg(1)->toString(), "zero");
      } else if (op == "sgtz") {
        *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 
          getRInst("slt", ctx->Reg(0)->toString(), 
           "zero", ctx->Reg(1)->toString());
      }
      currentTextOff += 4;
    }
    return 0;
  }

  antlrcpp::Any visitBz(AssembParser::BzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    }else if (pass == 2) {
      std::string op = ctx->Bzop()->toString();
      if (op == "beqz") {
      } else if (op == "bnez") {

      } else if (op == "blez") {

      } else if (op == "bgez") {

      } else if (op == "bltz") {

      } else if (op == "bgtz") {

      }
      //todo
      currentTextOff += 4;
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
    std::string symbol = ctx->Symbol()->toString();
    if (!symbols.count(symbol)) 
      symbols.insert(std::pair<std::string, symbol_t*>(symbol, new symbol_t()));
    symbols[symbol]->type = (ctx->Type()->toString() == "@object") ? STT_OBJECT : STT_FUNC;
    return 0;
  }

  antlrcpp::Any visitAlign(AssembParser::AlignContext *ctx) override {
    Elf32_Word alignment = (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
    alignment = 1 << alignment;
    if (pass == 1) {
      Elf32_Word moveMent = cur_sec->contents.size() % alignment;
      if (moveMent != 0) {
        moveMent = alignment - moveMent;
        cur_sec->contents.resize(cur_sec->contents.size() + moveMent);
      }
    } else if (pass == 2 && isText) {
      if (currentTextOff % alignment != 0) 
        currentTextOff += alignment - (currentTextOff % alignment);
    }
    return 0;
  }

  antlrcpp::Any visitSize(AssembParser::SizeContext *ctx) override {
    if (pass == 1){
      Elf32_Word size = (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
      if (cur_sym->type == 1 || cur_sym->type == 2) {
        cur_sym->info.st_size = size;
        cur_sym->offset = cur_sec->contents.size();
        if (cur_sec_name != ".bss")
          cur_sec->contents.resize(cur_sec->contents.size() + size);
      }
      else std::cerr << "assign size to a symbol not an object or a function" << std::endl;
    }
    return -1;
  }

  antlrcpp::Any visitAsciz(AssembParser::AscizContext *ctx) override {
    return visitChildren(ctx);
  }

  antlrcpp::Any visitIgnore(AssembParser::IgnoreContext *ctx) override {
    if (pass == 1) 
      std::cout << "warning: ignore directive: " << ctx->IgnoreDirective()->toString() << std::endl;
    return 0;
  }

  antlrcpp::Any visitImm(AssembParser::ImmContext *ctx) override {
    assert(isText);
    if (ctx->Integer() != nullptr) {
      return (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
    }
    else if (ctx->Relocation() != nullptr) {
      //todo: if resolvable in pass 2, resolve it. Otherwise add it into the rela table. 
      return (Elf32_Word)0;
    }
    return 0;
  }

};
#endif