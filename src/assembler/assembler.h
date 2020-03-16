#ifndef assembler_h
#define assembler_h

#include "includes.h"
#include "parser.h"

void assemble(std::string fileName);
std::vector<std::byte> sections[4];

#endif