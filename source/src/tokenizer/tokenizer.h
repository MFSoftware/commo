#ifndef COMMO_TOKENIZER_H
#define COMMO_TOKENIZER_H

#include <vector>
#include "token.h"

bool isOperator(char ch);

class Tokenizer {
    public:
        vector<Token> tokenize(string str);
        void emptyNumberBufferAsLiteral();
        void emptyLetterBufferAsVariables();

private:
        vector<char> letterBuffer;
        vector<Token> result;
        vector<char> numberBuffer;
};


#endif //COMMO_TOKENIZER_H
