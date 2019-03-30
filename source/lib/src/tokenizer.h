#include <utility>

#ifndef COMMO_TOKENIZER_H
#define COMMO_TOKENIZER_H

#pragma once
#include <string>
#include "token.h"
#include "charStream.h"

class tokenizer {
    private:
        charStream *stream;
        token *lastToken;

        bool isWhiteSpace();
        token *isSymbol();
        token *isOperator();
        token *isIdentifier();
        token *isCharacterLiteral();
        token *isStringLiteral();
        token *isNumericLiteral();
        token *isAddressLiteral();


    public:
        token get();

        explicit tokenizer(std::string source){
                stream = new charStream(std::move(source));
                tokenType type = UnknownToken;
                lastToken = new token(type, "", 0, 0);
        }
};


#endif //COMMO_TOKENIZER_H
