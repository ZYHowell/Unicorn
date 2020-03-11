#ifndef assembler_parser_h
#define assembler_parser_h
#include "includes.h"

enum lineType {Label, Inst, PseudoInst, Derivate};

struct Line_t{
    std::vector<std::string> tokens;
    lineType type;

    Line_t():tokens(std::vector<std::string>()) {}
};

std::vector<Line_t>&& parse(std::string &file);

const char* ignores = " \t\n\r\f\v";
const char* split = " \t,";

#endif