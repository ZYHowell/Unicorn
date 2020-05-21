#ifndef assembler_parser_h
#define assembler_parser_h
#include "includes.h"

struct Line_t{
    std::vector<std::string> tokens;
    lineType type;

    Line_t():tokens(std::vector<std::string>()) {}
};

std::vector<Line_t>&& parse(std::string &file);

const char* ignores = " \t\n\r\f\v";
const char* split = " \t,";

std::unordered_set<std::string> longPseudoInst = {"li", "call", "tail"};
std::unordered_set<std::string> pseudoInst = {"li", "mv", "nop", "call", "tail"};
//todo: more psudoInst

#endif