#include <iostream>
#include <fstream>
#include "antlr4-runtime.h"
#include "AssembLexer.h"
#include "AssembParser.h"
#include "AssembBaseVisitor.h"
#include "defines.h"
#include "elf.h"

using namespace antlr4;
int main() {
    const std::string filepath = "output.s";
    std::ifstream ifs;
    ifs.open(filepath);
    if (!ifs.good()) {
        std::cout<<"bad";
    }
    ANTLRInputStream input(ifs);
    AssembLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    AssembParser parser(&tokens);
    tree::ParseTree* tree=parser.file();
    // EvalVisitor visitor;
    // visitor.visit(tree);

    ifs.close();
    return 0;
}