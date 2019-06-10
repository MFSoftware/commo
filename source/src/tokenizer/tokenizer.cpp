#include "tokenizer.h"
#include <string>
#include <regex>
#include <locale>

using namespace std;

bool isOperator(char ch) {
    switch (ch) {
        case '+':
        case '-':
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

void Tokenizer::emptyLetterBufferAsVariables() {
    int l = letterBuffer.size();
    for (int i = 0; i < l; i++) {
        result.emplace_back("Variable", letterBuffer[i]);
        if(i < l - 1)
            result.emplace_back("Operator", "*");
    }
    letterBuffer.clear();
}

void Tokenizer::emptyNumberBufferAsLiteral() {
    if(!numberBuffer.empty()) {
        stringstream ss;
        for(auto & i : numberBuffer) ss << i;
        result.emplace_back("Literal", ss.str());
        numberBuffer.clear();
    }
}

vector<Token> Tokenizer::tokenize(string str) {
    str.erase(remove_if(str.begin(), str.end(), ::isspace), str.end()); //str.replace(/\s+/g, "");
    result = vector<Token>();
    numberBuffer = vector<char>();
    letterBuffer = vector<char>();

    for_each(str.begin(), str.end(), [this](char c) {
        string s(1, c);

        if (isdigit(c) || s == ".")
            numberBuffer.emplace_back(c);
        else if (isalpha(c)) {
            if(!numberBuffer.empty()) {
                emptyNumberBufferAsLiteral();
                result.emplace_back("Operator", "*");
            }
            letterBuffer.emplace_back(c);
        }
        else if (isOperator(c)) {
            emptyNumberBufferAsLiteral();
            emptyLetterBufferAsVariables();
            result.emplace_back("Operator", c);
        }
        else if (s == "(") {
            if(!letterBuffer.empty()) {
                stringstream ss;
                for(char i : letterBuffer) ss << i;
                result.emplace_back("Function", ss.str());
                letterBuffer.clear();
            }
            else if(!numberBuffer.empty()) {
                emptyNumberBufferAsLiteral();
                result.emplace_back("Operator", "*");
            }
            result.emplace_back("Left Parenthesis", c);
        }
        else if (s == ")") {
            emptyLetterBufferAsVariables();
            emptyNumberBufferAsLiteral();
            result.emplace_back("Right Parenthesis", c);
        }
        else if (s == ",") {
            emptyNumberBufferAsLiteral();
            emptyLetterBufferAsVariables();
            result.emplace_back("Function Argument Separator", c);
        }
    });

    if (!numberBuffer.empty())
        emptyNumberBufferAsLiteral();

    if(!letterBuffer.empty())
        emptyLetterBufferAsVariables();

    return result;
}