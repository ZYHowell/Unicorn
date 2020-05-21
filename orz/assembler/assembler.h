#ifndef assembler_h
#define assembler_h

#include "includes.h"
#include "parser.h"

void assemble(std::string fileName);
std::vector<std::byte> sections[4];

struct section_offset : std::pair<size_t,size_t>
{
    section_offset(size_t section, size_t offset)
        : std::pair<size_t,size_t>(section, offset) {}

    inline size_t section() { return first; }
    inline size_t offset() { return second; }
};

struct section
{
    size_t index;
    size_t offset;
    std::string name;
    std::vector<unsigned char> buf;

    section(std::string name) :
        index(0), offset(0), name(name) {}
};

struct label
{
    std::string name;
    section_offset offset;
    signed long long num;
    int elf_sym;

    label(std::string name, section_offset offset) :
        name(name), offset(offset), num(0) {}
};

typedef std::shared_ptr<section> section_ptr;
typedef std::shared_ptr<label> label_ptr;
typedef std::shared_ptr<reloc> reloc_ptr;

struct reloc
{
    section_offset offset;
    section_ptr section;
    std::string name;
    int rela_type;
    int elf_sym;

    reloc(section_offset offset, std::string name, int rela_type) :
        offset(offset), name(name), rela_type(rela_type) {}
};

#endif