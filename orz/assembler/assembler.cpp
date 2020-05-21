#ifndef assembler_cpp
#define assembler_cpp 

#include "assembler.h"

inline int addrAlign(int currentAddr, int align) {
    return (currentAddr % align) ? currentAddr : 
                                   (currentAddr / align + 1) * align;
}
inline bool correctAlignment(int align) {
    while(align > 1) {
        if (align % 2) return false;
        align /= 2;
    }
}
/*
 * todo: 
 * 1. pass 1: what if the label represents an object? wait till pass 2 or handle it here? 
 * 2. pass 2: remove some local symbols. 
 * 3. necessary support for directives like .type, .size
 * 4. optional support for directives like .equ
 */
void assemble(std::string fileName) {
    std::ifstream F(fileName);
    std::string file((std::istreambuf_iterator<char>(F)),
                    std::istreambuf_iterator<char>());
    std::vector<Line_t> context = std::vector<Line_t>(parse(file));
    std::map<std::string, int> labelMap;
    std::unordered_map<std::string, symbolType> gSymbols, lSymbols;
    std::string fileName;
    sectionType currentSection;

    //pass-1: allocate instructions and lay out data, collect symbols
    for (auto &line : context) {
        auto &sectionStorage = sections[currentSection];
        switch(line.type){
            case Label: {
                assert(line.tokens.size() == 1);
                std::string label = line.tokens[0];
                label.pop_back();
                labelMap.emplace(std::make_pair(std::move(label), sections[currentSection].size()));
                break;
            }
            case Directive: {
                std::vector<std::string> &tokens = line.tokens;
                std::string &directive = tokens[0];
                if (directive == ".section") {
                    if (tokens.size() == 1 || tokens[1] == ".text")
                        currentSection = sectionType::text;
                    else if (tokens[1] == ".bss")
                        currentSection = sectionType::bss;
                    else if (tokens[1] == ".rodata")
                        currentSection = sectionType::rodata;
                    else if (tokens[1] == ".data")
                        currentSection = sectionType::data;
                    else assert(false);
                    assert(tokens.size() <= 2);
                } else if (directive == ".text") {
                    assert(tokens.size() == 1);
                    currentSection = sectionType::text;
                } else if (directive == ".bss") {
                    assert(tokens.size() == 1);
                    currentSection = sectionType::bss;
                } else if (directive == ".rodata") {
                    assert(tokens.size() == 1);
                    currentSection = sectionType::rodata;
                } else if (directive == ".data") {
                    assert(tokens.size() == 1);
                    currentSection = sectionType::data;
                } else if (directive == ".align" || directive == ".p2align") {
                    auto bit = 1 << std::atoi(tokens.at(1).c_str());
                    sectionStorage.resize(addrAlign(sectionStorage.size(), bit));
                } else if (directive == ".balign") {
                    auto bit = std::atoi(tokens.at(1).c_str());
                    if (!correctAlignment(bit)) std::cerr << "bit align not power of 2" << std::endl;
                    else sectionStorage.resize(addrAlign(sectionStorage.size(), bit));
                } else if (directive == ".global") {
                    gSymbols.emplace(tokens[1], symbolType::Error);
                } else if (directive == ".string" || directive == ".asciz") {
                    std::string value = tokens[1].substr(1, tokens[1].size() - 2);
                    auto cpyPos = sectionStorage.size();
                    sectionStorage.resize(cpyPos + value.size());
                    std::strcpy((char *)(sectionStorage.data() + cpyPos), value.c_str());
                    sectionStorage.push_back((std::byte) 0);
                } else if (directive == ".file") {
                    fileName = tokens[1].substr(1, tokens[1].size() - 2);
                } else if (directive == ".option") {
                    //todo: support options, which is too hard
                } else if (directive == ".ident") {
                    //todo: i do not know what ident means know
                } else if (directive == ".type") {
                    assert(tokens.size() == 3 && tokens[2][0] == '@');
                    if (gSymbols.count(tokens[1])) {
                        if (tokens[2] == "@object") gSymbols[tokens[1]] = symbolType::Object;
                        else if (tokens[2] == "@function") gSymbols[tokens[1]] = symbolType::Function;
                        else std::cerr << "unsupported type: " << tokens[2] << std::endl;
                    } else if (lSymbols.count(tokens[1])) {
                        if (tokens[2] == "@object") gSymbols[tokens[1]] = symbolType::Object;
                        else if (tokens[2] == "@function") gSymbols[tokens[1]] = symbolType::Function;
                        else std::cerr << "unsupported type: " << tokens[2] << std::endl;
                    }
                    //todo: more symbols
                } else if (directive == ".equ") {
                    //todo
                } else if (directive == ".size") {
                    assert(tokens.size() == 3);
                    int size = std::stoi(tokens[2].c_str());
                    //todo: add size
                }
                else std::cerr << "unsupported directive: " << directive << std::endl;
                break;
            }
            case Inst: {
                assert(currentSection == sectionType::text);
                sectionStorage.resize(sectionStorage.size() + 4);
                break;
            }
            case PseudoInst: {
                assert(currentSection == sectionType::text);
                //todo: unfold, and may add some label here 
                if (longPseudoInst.count(line.tokens[0])) sectionStorage.resize(sectionStorage.size() + 8);
                else sectionStorage.resize(sectionStorage.size() + 4);
                break;
            }
        }
    }
    //todo: re-calculate the address of labels

    //pass-2: emitting instructions and data
    bool isText = false;
    for (auto &line : context) {
        switch(line.type) {
            case Directive: {
                auto &tokens = line.tokens;
                auto &directive = tokens[0];
                if (directive == ".align" || directive == ".p2align") {}
                else if (directive == ".balign") {}
                else if (directive == ".text") isText = true;
                else if (directive == ".bss") isText = false;
                else if (directive == ".data") isText = false;
                else if (directive == ".rodata") isText = false;
                else if (directive == ".section") {
                    if (tokens[1] == ".text") isText = true;
                    else isText = false;
                }
                break;
            }
            case PseudoInst: {
                break;
            }
            case Inst: {
                break;
            }
            case Label: {
                break;
            }
        }
    }
}

#endif