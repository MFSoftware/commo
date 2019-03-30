#ifndef COMMO_PREPROCESSOR_H
#define COMMO_PREPROCESSOR_H

#include <list>
#include <string>
#include "token.h"

std::list <std::string> preprocessor_generate_list(const std::string &text);
bool preprocessor_symbol_to_token_type(std::string lexeme, tokenType *type);

#endif //COMMO_PREPROCESSOR_H