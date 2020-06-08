#ifndef Unicorn_Visitor_H
#define Unicorn_Visitor_H
#include "includes.h"
#include "AssembBaseVisitor.h"

using namespace Unicorn;

class EvalVisitor: public AssembBaseVisitor {
private:
    enum InstType {
      IType = 0, 
      RType = 1, 
      SType = 2, 
      JType = 3, 
      BType = 4, 
      UType = 5
    };
    struct section_t{
      Elf32_Shdr header;
      std::vector<std::byte> contents;
      Elf32_Off offset = 0;
      section_t(): header(), contents() {
        memset(&header, 0, sizeof(Elf32_Shdr));
        header.sh_addralign = 1;
      }
    };
    struct symbol_t{
      Elf32_Sym info;
      Elf32_Byte bind = STB_LOCAL;
      Elf32_Byte type = STT_NOTYPE;
      Elf32_Word idx = 0;
      bool hasOffset = false;
      section_t* section = nullptr;
      symbol_t(): info() {
        memset(&info, 0, sizeof(Elf32_Sym));
      }
    };

    using string = std::string;
    using Any = antlrcpp::Any;
    using sec_p = std::pair<string, section_t*>;
    using sym_p = std::pair<string, symbol_t*>;

    std::map<string, section_t*> sections;
    std::map<string, symbol_t*> symbols;
    std::vector<Elf32_Rela> relocations;
    std::vector<std::byte> storage;
    std::vector<string> section_order;
    std::set<string> relaUse, outer;
    section_t* cur_sec = nullptr;
    symbol_t* cur_sym = nullptr;

    bool isText = true;
    char instType;
    int pass = -1;
    Elf32_Off cur_sec_off = 0;
    size_t cur_align = 4;

    inline Elf32_Word getIInst(string op, string rd, 
                              string src, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src]);
      inst = addIImm(inst, imm);
      return inst;
      //return bswap32(inst);
    }
    inline Elf32_Word getRInst(string op, string rd, 
                              string src1, string src2) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      return inst;
      //return bswap32(inst);
    }
    inline Elf32_Word getSInst(string op, string src1, string src2, 
                              Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      inst = addSImm(inst, imm);
      return inst;
      //return bswap32(inst);
    }
    inline Elf32_Word getUInst(string op, string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addUImm(inst, imm);
      return inst;
      //return bswap32(inst);
    }
    inline Elf32_Word getJInst(string op, string rd, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addRd(inst, regMap[rd]);
      inst = addJImm(inst, imm);
      return inst;
      //return bswap32(inst);
    }
    inline Elf32_Word getBInst(string op, string src1, 
                              string src2, Elf32_Word imm) {
      Elf32_Word inst = instFormat[op];
      inst = addR1(inst, regMap[src1]);
      inst = addR2(inst, regMap[src2]);
      inst = addBImm(inst, imm);
      return inst;
      //return bswap32(inst);
    }
    inline string parseStringLiteral(string it, bool addTail = false) {
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
      if (addTail) ret.push_back('\0');
      return ret;
    }
    inline size_t alignOffset(size_t curOff, size_t alignment) {
      if (curOff % alignment) return curOff + (alignment - curOff % alignment);
      else return curOff;
    }
    inline void secAlign(section_t* sec, Elf32_Off move = 0) {
      sec->contents.resize(alignOffset(sec->contents.size() + move, sec->header.sh_addralign));
    }    
    template<class T>
    inline size_t argEq(const std::vector<T> &src, T tobe) {
      return std::find(src.begin(), src.end(), tobe) - src.begin();
    }
    inline Elf32_Word getRelaOf(string symbol, Elf32_Word rel_type) {
      Elf32_Rela rela;
      memset(&rela, 0, sizeof(Elf32_Rela));
      rela.r_offset = cur_sec_off;
      rela.r_info = ELF32_R_INFO(symbols[symbol]->idx, rel_type);
      relocations.emplace_back(std::move(rela));
      if ((rel_type < 29 && rel_type > 22) || rel_type == 18) {
        Elf32_Rela relax;
        memset(&relax, 0, sizeof(Elf32_Rela));
        relax.r_offset = cur_sec_off;
        relax.r_info = ELF32_R_INFO(0, R_RISCV_RELAX);
        relocations.emplace_back(std::move(relax));
      } else if (!outer.count(symbol)) {
        if (symbols[symbol]->hasOffset)
          return symbols[symbol]->info.st_value - cur_sec_off;
      }
      return 0;
    }
    /*--------------------------------------------------------*/
    inline void preprocess() {
      section_t* tmp;
      tmp = new section_t();
      tmp->header.sh_type = SHT_PROGBITS;
      tmp->header.sh_flags = SHF_ALLOC | SHF_EXECINSTR;
      tmp->header.sh_addralign = 4;
      sections.insert(std::pair<string, section_t*>(".text", tmp));
      // tmp = new section_t();
      // tmp->header.sh_type = SHT_RELA;
      // tmp->header.sh_flags = SHF_INFO_LINK;
      // sections.insert(std::pair<string, section_t*>(".rela.text", tmp));
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
      // tmp = new section_t();
      // tmp->header.sh_type = SHT_PROGBITS;
      // tmp->header.sh_flags = SHF_MERGE | SHF_STRINGS;
      // sections.insert(std::pair<string, section_t*>(".comment", tmp));
    }
    inline void alloc() {
      section_order.push_back("");
      sections.insert(sec_p("", new section_t()));
      sections[""]->header.sh_addralign = 0;
      section_order.push_back(".text");
      section_t *rela = new section_t();
      if (!relaUse.empty()) {
        section_order.push_back(".rela.text");
        rela->header.sh_type = SHT_RELA;
        rela->header.sh_flags = SHF_INFO_LINK;
        rela->header.sh_addralign = 4;
        sections.insert(sec_p(".rela.text", rela));
        rela = sections[".rela.text"];
      }
      section_order.push_back(".data");
      section_order.push_back(".bss");
      section_order.push_back(".rodata");
      for(auto iter = sections.begin(); iter != sections.end(); iter++) 
        if (std::find(section_order.begin(), section_order.end(), iter->first) == section_order.end()) 
          section_order.push_back(iter->first);

      section_t *symtab, *strtab, *shstrtab, *text;
      symtab = new section_t(), strtab = new section_t(), shstrtab = new section_t();
      text = sections[".text"];
      std::vector<std::byte> &sym_con = symtab->contents, 
                             &str_con = strtab->contents;
      symtab->header.sh_type = SHT_SYMTAB;
      symtab->header.sh_addralign = 4;
      strtab->header.sh_type = SHT_STRTAB;
      shstrtab->header.sh_type = SHT_STRTAB;
      sections.insert(sec_p(".symtab", symtab));
      sections.insert(sec_p(".strtab", strtab));
      sections.insert(sec_p(".shstrtab", shstrtab));
      
      section_order.push_back(".symtab");
      section_order.push_back(".strtab");
      section_order.push_back(".shstrtab");

      // fill in symtab, strtab and shstrtab
      size_t num = 0;
      sym_con.resize(sizeof(Elf32_Sym) * 2);
      *(Elf32_Sym *)(sym_con.data()) = Elf32_Sym();
      str_con.push_back(std::byte(0x0));
      ++num;
      for (auto iter = symbols.begin(); iter != symbols.end(); iter++) {
        symbol_t *sym = iter->second;
        if (sym->type == STT_FILE) {
          string symbolName = iter->first;
          Elf32_Sym &symbol = sym->info;
          symbolName.push_back('\0');
  
          symbol.st_info = ELF32_ST_INFO(sym->bind, sym->type);
          symbol.st_other = ELF32_ST_VISIBILITY(STV_DEFAULT); 
          symbol.st_name = str_con.size();
          symbol.st_shndx = 0xfff1;
          sym->hasOffset == false;
          for (auto c : symbolName) {
            str_con.push_back(std::byte(c));
          }
          *(Elf32_Sym *)(sym_con.data() + num * sizeof(Elf32_Sym)) = symbol;
          sym->idx = num;
          ++num;
          break;
        }
      }
      if (num == 1) std::cerr << "Error: no directive .file" <<std::endl;
      for (size_t i = 0;i < section_order.size();++i) {
        section_t *sec = sections[section_order[i]];
        if (sec->header.sh_type == SHT_PROGBITS || 
            ((sec->header.sh_flags & SHF_ALLOC)== SHF_ALLOC)) {
          sym_con.resize(sym_con.size() + sizeof(Elf32_Sym));
          Elf32_Sym *sym = (Elf32_Sym *)(sym_con.data() + num * sizeof(Elf32_Sym));
          sym->st_info = ELF32_ST_INFO(STB_LOCAL, STT_SECTION);
          sym->st_shndx = i;
          ++symtab->header.sh_info;
          ++num;
        }
      }

      sym_con.resize(sym_con.size() + sizeof(Elf32_Sym) * (symbols.size() - 1));      
      for (Elf32_Byte cur_bind = STB_LOCAL; cur_bind < STB_WEAK;++cur_bind) { //weak is not supported
        for (auto iter = symbols.begin(); iter != symbols.end(); iter++) {
          string symbolName = iter->first;
          symbolName.push_back('\0');
          symbol_t *sym = iter->second;
          Elf32_Sym &symbol = sym->info;

          if (sym->bind != cur_bind) continue;
          if (sym->bind == STB_LOCAL) ++symtab->header.sh_info;
          if (sym->type == STT_FILE) {
            ++symtab->header.sh_info;
            continue;
          }

          symbol.st_info = ELF32_ST_INFO(sym->bind, sym->type);
          symbol.st_other = ELF32_ST_VISIBILITY(STV_DEFAULT); 
            // not support directive modifying this
          // allocate object with size and remember alignment
          if (sym->section != text && sym->section->header.sh_type != SHT_NOBITS) {
            symbol.st_value = sym->section->contents.size();
            secAlign(sym->section, symbol.st_size);
            sym->hasOffset = true;
          } else if (sym->section != text) {
            sym->hasOffset == false; //NOBITS
            outer.insert(symbolName);
          }
          for (size_t i = 0;i < section_order.size();++i) {
            if (sections[section_order[i]] == sym->section) {
              symbol.st_shndx = i;
              break;
            }
          }
          // allocate the name into strtab, get the offset to symbol name
          symbol.st_name = str_con.size();
          for (auto c : symbolName) {
            str_con.push_back(std::byte(c));
          }
          //add it to symbol table
          *(Elf32_Sym *)(sym_con.data() + num * sizeof(Elf32_Sym)) = symbol;
          sym->idx = num;
          // symbol.reverse((Elf32_Sym *)(sym_con.data() + num * sizeof(Elf32_Sym)));
          ++num;
        }
      }
      //add those not allocatable to symbols. 
      for (auto rela : relaUse) {
        if (!symbols.count(rela)) {
          string relaN = rela;
          relaN.push_back('\0');
          symbol_t *symbol = new symbol_t();
          symbol->bind = STB_GLOBAL;
          symbol->info.st_info = ELF32_ST_INFO(symbol->bind, symbol->type);
          symbol->info.st_other = ELF32_ST_VISIBILITY(STV_DEFAULT); 
          symbols.insert(sym_p(rela, symbol));
          outer.insert(rela);
          symbol->info.st_name = str_con.size();
          for (auto c : relaN) {
            str_con.push_back(std::byte(c));
          }
          size_t size = sym_con.size();
          sym_con.resize(size + sizeof(Elf32_Sym));
          *(Elf32_Sym *)(sym_con.data() + size) = symbol->info;
          symbol->idx = num;
          ++num;
          //symbol->info.reverse((Elf32_Sym *)(sym_con.data() + size));
        }
      }

      rela->header.sh_info = argEq<string>(section_order, ".text");
      rela->header.sh_entsize = sizeof(Elf32_Rela);
      rela->header.sh_link = argEq<string>(section_order, ".symtab");
      //symtab->header.sh_info is on above. 
      symtab->header.sh_entsize = sizeof(Elf32_Sym);
      symtab->header.sh_link = argEq<string>(section_order, ".strtab");
      if (relaUse.empty()) delete rela;
    }
    inline void final() {
      std::vector<std::byte> &shstr_con = sections[".shstrtab"]->contents;
      Elf32_Ehdr ehdr;
      memset(&ehdr, 0, sizeof(Elf32_Ehdr));
      ehdr.e_ident[EI_MAG0] = ELFMAG0;
      ehdr.e_ident[EI_MAG1] = ELFMAG1;
      ehdr.e_ident[EI_MAG2] = ELFMAG2;
      ehdr.e_ident[EI_MAG3] = ELFMAG3;
      ehdr.e_ident[EI_CLASS] = ELFCLASS32;
      ehdr.e_ident[EI_DATA] = ELFDATA2LSB;
      ehdr.e_ident[EI_VERSION] = EV_CURRENT;
      ehdr.e_ident[EI_OSABI] = ELFOSABI_SYSV;
      //abi version is none
      ehdr.e_type = ET_REL;
      ehdr.e_machine = EM_RISCV;
      ehdr.e_version = EV_CURRENT;
      ehdr.e_entry = 0;
      ehdr.e_phoff = 0;
      ehdr.e_flags = 0;
      ehdr.e_ehsize = sizeof(Elf32_Ehdr);
      //ehdr.e_phentsize = sizeof(Elf32_Phdr);
      ehdr.e_phnum = 0;
      ehdr.e_shentsize = sizeof(Elf32_Shdr);
      ehdr.e_shnum = section_order.size();
      ehdr.e_shstrndx = argEq<string>(section_order, ".shstrtab");
      

      if (!relaUse.empty()) {
        std::vector<std::byte> &rela_con = sections[".rela.text"]->contents;
        size_t cnt = 0;
        rela_con.resize(sizeof(Elf32_Rela) * relocations.size());
        for (size_t i = 0;i < relocations.size();++i) {
          Elf32_Word type = ELF32_R_TYPE(relocations[i].r_info);
          if (type > 17 || type < 16)
            *(Elf32_Rela *)(rela_con.data() + cnt++ * sizeof(Elf32_Rela)) = relocations[i];
          //relocations[i].reverse((Elf32_Rela *)(rela_con.data() + i * sizeof(Elf32_Rela)));
        }
        for (size_t i = 0;i < relocations.size();++i) {
          Elf32_Word type = ELF32_R_TYPE(relocations[i].r_info);
          if (type == 17 || type == 16)
            *(Elf32_Rela *)(rela_con.data() + cnt++ * sizeof(Elf32_Rela)) = relocations[i];
          //relocations[i].reverse((Elf32_Rela *)(rela_con.data() + i * sizeof(Elf32_Rela)));
        }
      }
      storage.resize(sizeof(Elf32_Ehdr));
      //shstrtab and section headers
      //solved attr here: name, offset, size
      for (auto name : section_order) {
        section_t *sec = sections[name];
        name.push_back('\0');
        Elf32_Shdr &shdr = sec->header;
        shdr.sh_name = shstr_con.size();
        for (auto c : name)
          shstr_con.push_back(std::byte(c));
      }
      for (size_t round = 0;round < 2;++round){
        for (auto name : section_order) {
          section_t *sec = sections[name];
          Elf32_Shdr &shdr = sec->header;
          if ((name != ".rela.text" && name != ".shstrtab") ^ ((bool)round)) {
            if (shdr.sh_addralign > 0)
              storage.resize(alignOffset(storage.size(), shdr.sh_addralign));
            shdr.sh_offset = storage.size();
            shdr.sh_size = sec->contents.size();
            storage.resize(storage.size() + shdr.sh_size);
          }
        }
      }
      
      memset(&(sections[""]->header), 0, sizeof(Elf32_Shdr));
      storage.resize(alignOffset(storage.size(), 4));
      ehdr.e_shoff = storage.size();
      storage.resize(storage.size() + section_order.size() * sizeof(Elf32_Shdr));

      std::byte *ptr = storage.data();
      Elf32_Off offset = 0;
      *((Elf32_Ehdr *)ptr) = ehdr;
      //ehdr.reverse((Elf32_Ehdr *)ptr);
      offset += sizeof(Elf32_Ehdr);
      for (auto sec: section_order) {
        std::vector<std::byte> &section = sections[sec]->contents;
        offset = sections[sec]->header.sh_offset;
        for (size_t i = 0;i < section.size();++i)
          storage[offset + i] = section[i];
      }
      offset = ehdr.e_shoff;
      for (auto sec: section_order) {
        *(Elf32_Shdr *)(ptr + offset) = sections[sec]->header;
        // sections[sec]->header.reverse((Elf32_Shdr *)(ptr + offset));
        offset += sizeof(Elf32_Shdr);
      }

      std::ofstream file("out.o" , std::ios_base::binary| std::ios_base::trunc);
      for (size_t i = 0;i < storage.size();++i) {
        file << (char)storage[i];
      }
      file.close();

      //for sections delete
      for (auto iter = sections.begin(); iter != sections.end(); iter++) {
        delete iter->second;
      }
      //for symbols delete
      for (auto iter = symbols.begin(); iter != symbols.end(); iter++) {
        delete iter->second;
      }
    }

public: 

  Any visitFile(AssembParser::FileContext *ctx) override {
    preprocess();
    pass = 0;
    cur_sym = nullptr;
    cur_sec = sections[".text"];
    isText = true;
    for (auto line : ctx->line()) 
      if (line->directive() != nullptr)
        visit(line->directive());
    /*-------------------------------------------------------------*/
    pass = 1;
    cur_sym = nullptr;
    cur_sec = sections[".text"];
    isText = true;
    for (auto line : ctx->line()) visit(line);
    /*-------------------------------------------------------------*/
    alloc();
    /*-------------------------------------------------------------*/
    pass = 2;
    cur_sym = nullptr;
    cur_sec = sections[".text"];
    cur_sec_off = 0;
    isText = true;
    cur_align = cur_sec->header.sh_addralign;
    for (auto line : ctx->line()) visit(line);
    /*-------------------------------------------------------------*/
    //get the elf header and copy all to storage
    final();
    return 0;
  }

  Any visitLine(AssembParser::LineContext *ctx) override {
    if (ctx->pseudoInst() != nullptr) visit(ctx->pseudoInst());
    else if (ctx->inst() != nullptr) visit(ctx->inst());
    else if (ctx->directive() != nullptr) visit(ctx->directive());
    else if (ctx->start() != nullptr) visit(ctx->start());
    else assert(false);
    if (pass == 2) cur_sec_off = alignOffset(cur_sec_off, cur_align);
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

      if (symbol->hasOffset)
        std::cerr << "Error: the following symbol has multiple definitions: " 
                << name << std::endl;
      symbol->hasOffset = true;
      if (isText) symbol->info.st_value = cur_sec->contents.size();
      cur_sym = symbol;
    } else if (pass == 2) {
      cur_sym = symbols[ctx->Symbol()->toString()];
      cur_sec_off = cur_sym->info.st_value;
    }
    return 0;
  }

  Any visitRtype(AssembParser::RtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getRInst(ctx->Rop()->toString(), ctx->Reg(0)->toString(), 
        ctx->Reg(1)->toString(), ctx->Reg(2)->toString());
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitItype(AssembParser::ItypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      visit(ctx->imm());
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      instType = IType;
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getIInst(ctx->Iop()->toString(), ctx->Reg(0)->toString(), 
                ctx->Reg(1)->toString(), visit(ctx->imm()).as<Elf32_Word>()); 
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitStype(AssembParser::StypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      visit(ctx->imm());
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      instType = SType;
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getSInst(ctx->Sop()->toString(), ctx->Reg(1)->toString(), 
        ctx->Reg(0)->toString(), visit(ctx->imm()).as<Elf32_Word>());
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitBtype(AssembParser::BtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      relaUse.insert(ctx->Symbol()->toString());
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getBInst(ctx->Bop()->toString(), ctx->Reg(0)->toString(), 
        ctx->Reg(1)->toString(), getRelaOf(ctx->Symbol()->toString(), R_RISCV_BRANCH));
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitUtype(AssembParser::UtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      visit(ctx->imm());
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      instType = UType;
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getUInst(ctx->Uop()->toString(), ctx->Reg()->toString(), 
        visit(ctx->imm()).as<Elf32_Word>());
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitJtype(AssembParser::JtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      visit(ctx->imm());
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      instType = JType;
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getJInst(ctx->Jop()->toString(), ctx->Reg()->toString(), 
        visit(ctx->imm()).as<Elf32_Word>());
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitLtype(AssembParser::LtypeContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      visit(ctx->imm());
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      instType = IType;
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getIInst(ctx->Lop()->toString(), ctx->Reg(0)->toString(), 
                ctx->Reg(1)->toString(), visit(ctx->imm()).as<Elf32_Word>()); 
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitMv(AssembParser::MvContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getIInst("addi", ctx->Reg(0)->toString(), ctx->Reg(1)->toString(), 0); 
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitLi(AssembParser::LiContext *ctx) override {
    assert(isText);
    instType = UType;
    Elf32_Word value = visit(ctx->imm()).as<Elf32_Word>();
    Elf32_Word hi = value >> 12u, lo = value & 0xfffu;
    if (pass == 1) {
      if (hi != 0) secAlign(cur_sec, 4);
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      if (hi != 0) {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getUInst("lui", ctx->Reg()->toString(), hi);
        cur_sec_off = alignOffset(cur_sec_off + 4, cur_align);

        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getIInst("ori", ctx->Reg()->toString(), 
            ctx->Reg()->toString(), lo);
      } else {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getIInst("addi", ctx->Reg()->toString(), "zero", lo);
      }
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitRet(AssembParser::RetContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getIInst("jalr", "zero", "ra", 0);
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitJp(AssembParser::JpContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      relaUse.insert(ctx->Symbol()->toString());
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getJInst("jal", "zero", getRelaOf(ctx->Symbol()->toString(), R_RISCV_JAL));
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitLd(AssembParser::LdContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      relaUse.insert(ctx->Symbol()->toString());
      secAlign(cur_sec, 4);
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      string rd = ctx->Reg()->toString(), sym = ctx->Symbol()->toString();
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getUInst("lui", rd, getRelaOf(sym, R_RISCV_PCREL_HI20));
      cur_sec_off = alignOffset(cur_sec_off + 4, cur_align);

      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getIInst(ctx->Lop()->toString(), rd, rd, getRelaOf(sym, R_RISCV_PCREL_LO12_I));
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitLa(AssembParser::LaContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      relaUse.insert(ctx->Symbol()->toString());
      secAlign(cur_sec, 4);
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      string symbol = ctx->Symbol()->toString(), reg = ctx->Reg()->toString();
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getUInst("lui", reg, getRelaOf(symbol, R_RISCV_HI20) >> 12);
      cur_sec_off = alignOffset(cur_sec_off + 4, cur_align);

      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getIInst("addi", reg, reg, getRelaOf(symbol, R_RISCV_LO12_I) & ((1 << 11) - 1));
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitCall(AssembParser::CallContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      relaUse.insert(ctx->Symbol()->toString());
      secAlign(cur_sec, 4);
      secAlign(cur_sec, 4);
    } else if (pass == 2) {
      Elf32_Word value = getRelaOf(ctx->Symbol()->toString(), R_RISCV_CALL);
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getUInst("auipc", "ra", value >> 12);
      cur_sec_off = alignOffset(cur_sec_off + 4, cur_align);

      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
        getIInst("jalr", "ra", "ra", value & ((1 << 11) - 1));
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitSz(AssembParser::SzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      secAlign(cur_sec, 4);
    }else if (pass == 2) {
      string op = ctx->Szop()->toString();
      if (op == "seqz"){
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getIInst("sltiu", ctx->Reg(0)->toString(), 
          ctx->Reg(1)->toString(), 1);
      } else if (op == "snez") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getRInst("sltu", ctx->Reg(0)->toString(), 
           "zero", ctx->Reg(1)->toString());
      } else if (op == "sltz") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getRInst("slt", ctx->Reg(0)->toString(), 
           ctx->Reg(1)->toString(), "zero");
      } else if (op == "sgtz") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getRInst("slt", ctx->Reg(0)->toString(), 
           "zero", ctx->Reg(1)->toString());
      }
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitBz(AssembParser::BzContext *ctx) override {
    assert(isText);
    if (pass == 1) {
      relaUse.insert(ctx->Symbol()->toString());
      secAlign(cur_sec, 4);
    }else if (pass == 2) {
      string op = ctx->Bzop()->toString();
      if (op == "beqz") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getBInst("beq", ctx->Reg()->toString(), "zero", 
            getRelaOf(ctx->Symbol()->toString(), R_RISCV_BRANCH));
      } else if (op == "bnez") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getBInst("bne", ctx->Reg()->toString(), "zero", 
            getRelaOf(ctx->Symbol()->toString(), R_RISCV_BRANCH));
      } else if (op == "blez") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getBInst("bge", "zero", ctx->Reg()->toString(), 
            getRelaOf(ctx->Symbol()->toString(), R_RISCV_BRANCH));
      } else if (op == "bgez") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getBInst("bge", ctx->Reg()->toString(), "zero", 
            getRelaOf(ctx->Symbol()->toString(), R_RISCV_BRANCH));
      } else if (op == "bltz") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getBInst("blt", ctx->Reg()->toString(), "zero", 
            getRelaOf(ctx->Symbol()->toString(), R_RISCV_BRANCH));
      } else if (op == "bgtz") {
        *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = 
          getBInst("blt", "zero", ctx->Reg()->toString(), 
            getRelaOf(ctx->Symbol()->toString(), R_RISCV_BRANCH));
      }
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitSection(AssembParser::SectionContext *ctx) override {
    cur_sec->offset = cur_sec_off;
    if (sections.count(ctx->Section()->toString()))
      cur_sec = sections[ctx->Section()->toString()];
    else {
      cur_sec = new section_t();
      sections.insert(std::pair<string, section_t*>(
                                ctx->Section()->toString(), cur_sec
                                ));
    }
    cur_sec_off = cur_sec->offset;
    cur_align = cur_sec->header.sh_addralign;
    if (ctx->Section()->toString() == ".text") isText = true;
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
    }
    return 0;
  }

  Any visitAlign(AssembParser::AlignContext *ctx) override {
    Elf32_Word alignment = (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
    alignment = 1 << alignment;
    if (pass == 0) {
      if (cur_sec->header.sh_addralign < alignment)
        cur_sec->header.sh_addralign = alignment;
    } else if (pass == 1) {
      secAlign(cur_sec);
    } else if (pass == 2 && isText) {
      cur_sec_off = alignOffset(cur_sec_off, cur_sec->header.sh_addralign);
    }
    return 0;
  }

  Any visitWord(AssembParser::WordContext *ctx) override {
    if (pass == 1) {
      if (cur_sym->type == 1 || cur_sym->type == 2) 
        cur_sym->info.st_size += 4;
      else std::cerr << "assign size to a symbol not an object or a function" << std::endl;
    } else if (pass == 2) {
      if (cur_sec->header.sh_type == SHT_NOBITS) return 0;
      Elf32_Word value = (Elf32_Word)strtoul(ctx->Integer()->toString().c_str(), NULL, 10);
      *(Elf32_Word*)(cur_sec->contents.data() + cur_sec_off) = bswap32(value);
      cur_sec_off += 4;
    }
    return 0;
  }

  Any visitAsciz(AssembParser::AscizContext *ctx) override {
    assert(!isText);
    string value = parseStringLiteral(ctx->StringLiteral()->toString(), true);
    if (pass == 1) {
      cur_sym->info.st_size += value.length();
    } else if (pass == 2) {
      if (cur_sec->header.sh_type == SHT_NOBITS) return 0;
      for (size_t i = 0;i < value.length();++i)
        cur_sec->contents[i + cur_sec_off] = (std::byte)value[i];
      cur_sec_off += value.length();
    }
    return 0;
  }

  Any visitFilename(AssembParser::FilenameContext *ctx) override {
    if (pass == 1) {
      string name = parseStringLiteral(ctx->StringLiteral()->toString());
      if (symbols.count(name))
        std::cerr << "Error: name of the file is a symbol as well" << std::endl;

      symbol_t *symbol = new symbol_t();
      symbol->type = STT_FILE;
      symbol->section = sections[".text"];
      symbols.insert(sym_p(name, symbol));
    }
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
    if (pass == 1) {
      relaUse.insert(ctx->Symbol()->toString());
      return (Elf32_Word)0;
    }
    else if (pass == 2) {
      Elf32_Word rela_type;
      if (ctx->HL()->toString() == "%hi") rela_type = R_RISCV_HI20;
      else {
        if (instType == IType) rela_type = R_RISCV_LO12_I;
        else if (instType == SType) rela_type = R_RISCV_LO12_S;
        else std::cerr << "meet \"%lo()\" in instruction not IType or SType" << std::endl;
      }
      return getRelaOf(ctx->Symbol()->toString(), rela_type);
    }
    return 0;
  }
};
#endif