#ifndef assembler_cpp
#define assembler_cpp 

#include "assembler.h"



void assemble(std::string fileName) {
    std::ifstream F(fileName);
    std::string file((std::istreambuf_iterator<char>(F)),
                    std::istreambuf_iterator<char>());
    std::vector<Line_t> context = std::vector<Line_t>(parse(file));

    for (auto &line : context) {
        
    }
}

#endif