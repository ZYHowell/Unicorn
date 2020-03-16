#ifndef assembler_parser_cpp
#define assembler_parser_cpp
#include <sstream>
#include <regex>
#include "parser.h"

inline std::string getSub(std::string::const_iterator begin, std::string::const_iterator end) {
    std::string ret = "";
    auto iter = begin;
    while(iter != end) ret.push_back(*iter++);
    return ret;
}


void eraseWhiteSpace(std::string &line) {
    line.erase(line.find_last_not_of(ignores) + 1);
    line.erase(0, line.find_first_not_of(ignores));
}

std::vector<std::string> instTypeEnum({"Label", "Inst", "PseudoInst", "Directive", "Uncertain"});

Line_t parseInst(std::string &line) {
    //todo: split the first node, if it is ".string", find two '"' to get the content. 
    //Then check the correctness(no rest token)
    //else(not ".string"), split by whitespace. judge the type of the line. 
    Line_t ret = Line_t();
    size_t current = 0;
    size_t next = line.find_first_of(split);
    std::vector<std::string> &tokens = ret.tokens;
    tokens.push_back(line.substr(current, next - current));
    if (tokens[0] == ".string" || ".file") {
        current = line.find_first_of("\"", next);
        next = line.find_first_of("\"", current + 1);
        if (next > current) tokens.emplace_back(line.substr(current, next - current + 1));
        else assert(false); //only one '"', cannot be a string; 
        if (next != std::string::npos)
            if (line.find_first_not_of(ignores, next + 1) != std::string::npos) assert(false);
        ret.type = Directive;
    }
    else {
        const std::string &command = tokens[0];
        if (command[0] == '.') ret.type = Directive;
        else {
            if (pseudoInst.count(command)) ret.type = PseudoInst;
            else ret.type = Inst;
        }
        while(next != std::string::npos) {
            current = next + 1;
            next = line.find_first_of(split, current);
            if (next > current) tokens.emplace_back(line.substr(current, next - current));
        }
        tokens.erase(std::remove(tokens.begin(), tokens.end(), ""), tokens.end());
    }
    return ret;
}

std::vector<Line_t>&& parse(std::string &file) {
    std::vector<std::string> source = std::vector<std::string>();
    std::vector<Line_t> ret = std::vector<Line_t>();

    std::regex labelReg("[a-zA-Z_][a-zA-Z0-9_]*:");

    std::stringstream ss(file);
    for (std::string line; std::getline(ss, line, '\n');)
        source.push_back(line);
    
    for (auto &line : source) {
        //trivial whitespace handle, but no extra whitespace inside. 
        eraseWhiteSpace(line);
        if (line.empty()) continue;

        //about comments
        if (line[0] == '#') continue;   // this line is totally a comment
        auto commentBg = line.find('#');
        if (commentBg != std::string::npos){
            line.resize(commentBg);
            eraseWhiteSpace(line);
        }

        //about labels: make the label a line itself;
        std::smatch matchLabel;
        std::regex_search(line, matchLabel, labelReg);
        if (!matchLabel.empty()) {
            assert(matchLabel.size() == 1);
            assert(matchLabel[0].first == line.begin());

            Line_t labelLine = Line_t();
            labelLine.type = Label;
            labelLine.tokens.push_back(getSub(matchLabel[0].first, matchLabel[0].second));
            ret.push_back(labelLine);
            if (line.end() == matchLabel[0].second) continue;   //this line is totally a label
            line = getSub(matchLabel[0].second, line.end());    //some instruction left;
            eraseWhiteSpace(line);
        }

        //now parse inst/psudo-inst/directive
        ret.push_back(parseInst(line));
        #ifdef DEBUG_Mode
        //todo
        std::cout << "this is the result of parser:" << std::endl;
        for (auto line : ret) {
            for (std::string token : line.tokens())
                std::cout << token << " ";
            std::cout << "#type is: " << 
            std::cout << std::endl;
        }
        #endif
    }
    return std::move(ret);
}

#endif