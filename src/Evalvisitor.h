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
      Elf32_Off offset = 0;
      bool hasOffset = false;
      section_t* section = nullptr;
    };

    using string = std::string;
    using Any = antlrcpp::Any;
    using sec_p = std::pair<string, section_t*>;
    using sym_p = std::pair<string, symbol_t*>;
    using rela_p = std::pair<string, Elf32_Rela*>;

    std::map<string, section_t*> sections = std::map<string, section_t*>();
    std::map<string, symbol_t*> symbols = std::map<string, symbol_t*>();
    std::map<size_t, Elf32_Rela*> relocations = std::map<size_t, Elf32_Rela*>();
    std::vector<string> callee = std::vector<string>();
    string cur_sec_name = ".text";
    section_t* cur_sec = nullptr;
    symbol_t* cur_sym = nullptr;

    bool isText = true;
    int pass = 0;
    size_t currentTextOff = 0;

    inline Elf32_Word getIInst(string op, string rd, 
                              string src, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src]);
      inst = addIImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getRInst(string op, string rd, 
                              string src1, string src2) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getSInst(string op, string src1, string src2, 
                              Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      inst = addSImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getUInst(string op, string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addUImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getJInst(string op, string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addJImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline Elf32_Word getBInst(string op, string src1, 
                              string src2, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      inst = addBImm(inst, imm);
      return getLittleEdian(inst);
    }
    inline string replace(string origin, string replaced, string replaceBy) {
      string current = origin;
      size_t size = replaceBy.size();
      while ((current.find(replaced)) != -1) 
        current.replace(current.find(replaced), size, replaceBy);
      return current;
    }
    inline string parseStringLiteral(string it) {
      string ret = it.substr(1, it.size() - 2);
      for (int i = 0;i < ret.size();++i) {
        if (ret[i] == '\\') {
          if (i + 1 >= ret.size()) {
            std::cerr << "cannot parse " << it << ": meet '\\' at the end" << std::endl;
            assert(false);
          }
          switch(ret[i + 1]) {
            case 'n': 
              ret.replace(i, 2, "\n");
              break;
            case 'b': 
              ret.replace(i, 2, "\b");
              break;
            case 't': 
              ret.replace(i, 2, "\t");
              break;
            case 'r': 
              ret.replace(i, 2, "\r");
              break;
            case '\"': 
              ret.replace(i, 2, "\"");
              break;
            case '\\': 
              ret.replace(i, 2, "\\");
              break;
            case '0': 
              ret.replace(i, 2, "\0");
              break;
            default: 
              std::cerr << "cannot parse " << it << ": unknown: \\" << ret[i + 1] <<std::endl;
              assert(false);
              break;
          }
          --i;
        }
      }
      ret.push_back('\0');
      return ret;
    }
    inline void preprocess() {
      section_t* tmp;
      tmp = new section_t();
      tmp->header.sh_type = SHT_PROGBITS;
      tmp->header.sh_flags = SHF_ALLOC | SHF_EXECINSTR;
      tmp->header.sh_addralign = 4;
      sections.insert(std::pair<string, section_t*>(".text", tmp));
      tmp = new section_t();
      tmp->header.sh_type = SHT_RELA;
      tmp->header.sh_flags = SHF_INFO_LINK;
      sections.insert(std::pair<string, section_t*>(".rela.text", tmp));
      tmp = new section_t();
      tmp->header.sh_type = SHT_NOBITS;
      tmp->header.sh_flags = SHF_ALLOC | SHF_WRITE;
      sections.insert(std::pair<string, section_t*>(".bss", tmp));
      tmp = new section_t();
      tmp->header.sh_type = SHT_PROGBITS;
      tmp->header.sh_flags = SHF_ALLOC;
      sections.insert(std::pair<string, section_t*>(".rodata", tmp));
      tmp = new section_t();
      tmp->header.sh_type = SHT_PROGBITS;
      tmp->header.sh_flags = SHF_ALLOC | SHF_WRITE;
      sections.insert(std::pair<string, section_t*>(".data", tmp));
      tmp = new section_t();
      tmp->header.sh_type = SHT_PROGBITS;
      tmp->header.sh_flags = SHF_MERGE | SHF_STRINGS;
      sections.insert(std::pair<string, section_t*>(".comment", tmp));
    }
    inline void alloc() {
      // bool hasSym_tab = !symbols.empty(); todo: if not have symbol table(very rare)
      section_t *symtab, *strtab, *shstrtab;
      //todo
    }
public: 

  Any visitFile(AssembParser::FileContext *ctx) override {
    preprocess();
    /*-------------------------------------------------------------*/
    pass = 1;
    cur_sym = nullptr;
    cur_sec = sections[".text"];
    for (auto line : ctx->line()) visit(line);
    /*-------------------------------------------------------------*/
    alloc();
    /*-------------------------------------------------------------*/
    pass = 2;
    currentTextOff = 0;
    for (auto line : ctx->line()) visit(line);
    return 0;
  }

  Any visitLine(AssembParser::LineContext *ctx) override {
    if (ctx->pseudoInst() != nullptr) visit(ctx->pseudoInst());
    else if (ctx->inst() != nullptr) visit(ctx->inst());
    else if (ctx->directive() != nullptr) visit(ctx->directive());
    else if (ctx->start() != nullptr) visit(ctx->start());
    else assert(false);
    return 0;
  }

  Any visitInst(AssembParser::InstContext *ctx) override {
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

  Any visitStart(AssembParser::StartContext *ctx) override {
    if (pass == 1) {
      symbol_t *symbol;
      string name = ctx->Symbol()->toString();

      if (!symbols.count(name)) {
        symbol = new symbol_t();
        symbols.insert(sym_p(name, symbol));
      } else symbol = symbols[name];

      if (symbol->section == nullptr) symbol->section = cur_sec;
      else if (symbol->section != cur_sec) 
        std::cerr << "Error: the symbol is in multiple sections: "
                  << name <<std::endl;
      if (isText) {
        if (symbol->hasOffset)
          std::cerr << "Error: the following symbol has multiple definitions in text: " 
                  << name << std::endl;
        symbol->offset = cur_sec->contents.size();
        symbol->hasOffset = true;
      }
      cur_sym = symbol;
    } else if (pass == 2) {
      cur_sym = symbols[ctx->Symbol()->toString()];
    }
    return 0;
  }

  Any visitRtype(AssembParser::RtypeContext *ctx) override {
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

  Any visitItype(AssembParser::ItypeContext *ctx) override {
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

  Any visitStype(AssembParser::StypeContext *ctx) override {
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

  Any visitBtype(AssembParser::BtypeContext *ctx) override {
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

  Any visitUtype(AssembParser::UtypeContext *ctx) override {
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

  Any visitJtype(AssembParser::JtypeContext *ctx) override {
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

  Any visitLtype(AssembParser::LtypeContext *ctx) override {
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

  Any visitMv(AssembParser::MvContext *ctx) override {
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

  Any visitLi(AssembParser::LiContext *ctx) override {
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

  Any visitRet(AssembParser::RetContext *ctx) override {
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

  Any visitJp(AssembParser::JpContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      currentTextOff += 4;
    }
    return visitChildren(ctx);
  }

  Any visitLd(AssembParser::LdContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff + 4) = 0;  //todo
      currentTextOff += 8;
    }
    return visitChildren(ctx);
  }

  Any visitLa(AssembParser::LaContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff + 4) = 0;  //todo
      currentTextOff += 8;
    }
    return visitChildren(ctx);
  }

  Any visitCall(AssembParser::CallContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 8);
      callee.push_back(ctx->Symbol()->toString());
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff) = 0;  //todo
      *(Elf32_Word*)(cur_sec->contents.data() + currentTextOff + 4) = 0;  //todo
      currentTextOff += 8;
    }
    return visitChildren(ctx);
  }

  Any visitSz(AssembParser::SzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    }else if (pass == 2) {
      string op = ctx->Szop()->toString();
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

  Any visitBz(AssembParser::BzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      cur_sec->contents.resize(cur_sec->contents.size() + 4);
    }else if (pass == 2) {
      string op = ctx->Bzop()->toString();
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

  Any visitSection(AssembParser::SectionContext *ctx) override {
    if (sections.count(ctx->Section()->toString()))
      cur_sec = sections[ctx->Section()->toString()];
    else {
      cur_sec = new section_t();
      sections.insert(std::pair<string, section_t*>(
                                ctx->Section()->toString(), cur_sec
                                ));
    }
    if (cur_sec_name == ".text") isText = true;
    else isText = false;
    return 0;
  }

  Any visitGlobl(AssembParser::GloblContext *ctx) override {
    if (pass == 1) {
      string name = ctx->Symbol()->toString();
      symbol_t *symbol;
      if (!symbols.count(name)) 
        symbols.insert(sym_p(name, new symbol_t()));
      symbol = symbols[name];

      symbol->bind = STB_GLOBAL;

      if (symbol->section == nullptr) symbol->section = cur_sec;
      else if (symbol->section != cur_sec) 
        std::cerr << "Error: the symbol is in multiple sections: "
                  << name <<std::endl;
    }
    return 0;
  }

  Any visitType(AssembParser::TypeContext *ctx) override {
    if (pass == 1){
      string name = ctx->Symbol()->toString();
      symbol_t *symbol;
      if (!symbols.count(name)) 
        symbols.insert(sym_p(name, new symbol_t()));
      symbol = symbols[name];

      if (symbol->type != STT_NOTYPE)
        std::cerr << "Error: the symbol has multiple types: "
                  << name << std::endl;
      symbol->type = 
        (ctx->Type()->toString() == "@object") ? STT_OBJECT : STT_FUNC;

      if (symbol->section == nullptr) symbol->section = cur_sec;
      else if (symbol->section != cur_sec) 
        std::cerr << "Error: the symbol is in multiple sections: "
                  << name <<std::endl;
    }
    return 0;
  }

  Any visitAlign(AssembParser::AlignContext *ctx) override {
    Elf32_Word alignment = (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
    alignment = 1 << alignment;
    if (pass == 1) {
      Elf32_Word moveMent = cur_sec->contents.size() % alignment;
      if (moveMent != 0) {
        moveMent = alignment - moveMent;
        cur_sec->contents.resize(cur_sec->contents.size() + moveMent);
      }
      if (cur_sec->header.sh_addralign < alignment)
        cur_sec->header.sh_addralign;
    } else if (pass == 2 && isText) {
      if (currentTextOff % alignment != 0) 
        currentTextOff += alignment - (currentTextOff % alignment);
    }
    return 0;
  }

  Any visitSize(AssembParser::SizeContext *ctx) override {
    if (pass == 1){
      Elf32_Word size = (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
      if (cur_sym->type == 1 || cur_sym->type == 2) {
        cur_sym->info.st_size = size;
        if (cur_sec->header.sh_type == SHT_PROGBITS)
          cur_sec->contents.resize(cur_sec->contents.size() + size);
      }
      else std::cerr << "assign size to a symbol not an object or a function" << std::endl;
    }
    return -1;
  }

  Any visitAsciz(AssembParser::AscizContext *ctx) override {
    //todo
    assert(!isText);
    assert(cur_sym->bind == STB_LOCAL);
    string value = parseStringLiteral(ctx->StringLiteral()->toString());
    if (cur_sym->info.st_size < value.size())
      cur_sym->info.st_size = value.size();
    if (pass == 2) {
      //todo: add to contents in pass 2
    }
    return 0;
  }

  antlrcpp::Any visitFilename(AssembParser::FilenameContext *ctx) override {
    if (pass == 1) {
      string name = parseStringLiteral(ctx->StringLiteral()->toString());
      if (symbols.count(name))
        std::cerr << "Error: name of the file is a symbol as well" << std::endl;

      symbol_t *symbol = new symbol_t();
      symbol->type = STT_FILE;
      symbols.insert(sym_p(name, symbol));
    }
    return visitChildren(ctx);
  }

  Any visitIgnore(AssembParser::IgnoreContext *ctx) override {
    if (pass == 1) 
      std::cout << "warning: ignore directive: " << ctx->IgnoreDirective()->toString() << std::endl;
    return 0;
  }

  Any visitImm(AssembParser::ImmContext *ctx) override {
    assert(isText);
    if (ctx->Integer() != nullptr) {
      return (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
    }
    else if (ctx->relocation() != nullptr) {
      return visit(ctx->relocation());
    }
    return 0;
  }

  Any visitRelocation(AssembParser::RelocationContext *ctx) override {
    if (pass == 1) return (Elf32_Word)0;
    else if (pass == 2) {
      //todo
    }
    return 0;
  }
};
#endif