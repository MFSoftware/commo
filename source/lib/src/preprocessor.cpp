#include "preprocessor.h"
#include <list>
#include <string>
#include <sstream>
#include <iostream>
#include "token.h"

std::list <std::string> preprocessor_generate_list(const std::string &text){
    std::list <std::string> result;
    std::istringstream f(text);
    std::string line;
    while (std::getline(f, line))
        result.emplace_back(line);
    return result;
}

bool preprocessor_symbol_to_token_type(std::string lexeme, tokenType *type) {
    if (lexeme == "("){
        type = (tokenType *) OpenParenthesis;
        return true;
    }
    else if (lexeme == ")"){
        type = (tokenType *) CloseParenthesis;
        return true;
    }
    else if (lexeme == "{"){
        type = (tokenType *) OpenBrace;
        return true;
    }
    else if (lexeme == "}"){
        type = (tokenType *) CloseBrace;
        return true;
    }
    else if (lexeme == "["){
        type = (tokenType *) OpenBracket;
        return true;
    }
    else if (lexeme == "]"){
        type = (tokenType *) CloseBracket;
        return true;
    }
    else if (lexeme == ":"){
        type = (tokenType *) Colon;
        return true;
    }
    else if (lexeme == ";"){
        type = (tokenType *) Semicolon;
        return true;
    }
    else if (lexeme == ","){
        type = (tokenType *) Comma;
        return true;
    }
    else if (lexeme == "."){
        type = (tokenType *) Dot;
        return true;
    }
    else if (lexeme == "?") {
        type = (tokenType *) Question;
        return true;
    }
    else
        return false;
}