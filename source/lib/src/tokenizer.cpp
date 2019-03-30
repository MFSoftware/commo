#include "tokenizer.h"
#include "token.h"

token tokenizer::get(){
    int lineNumber = stream->currentLineNumber;
    int position = stream->currentPosition;
    token *get;

    do
    {
        if (stream->isEof)
            return NULL;
    } while (isWhiteSpace());

    get = isSymbol();
    if (get != nullptr)
        return *get;

    get = isOperator();
    if (get != nullptr)
        return *get;

    get = isIdentifier();
    if (get != nullptr)
        return *get;

    get = isCharacterLiteral();
    if (get != nullptr)
        return *get;

    get = isStringLiteral();
    if (get != nullptr)
        return *get;

    get = isNumericLiteral();
    if (get != nullptr)
        return *get;

    get = isAddressLiteral();
    if (get != nullptr)
        return *get;

    tokenType type = UnknownToken;
    std::string s (1, stream->get());
    get = new token(type, s, lineNumber, position);
    return *get;
}

bool tokenizer::isWhiteSpace()
{
    bool isWhiteSpace = false;
    while (stream->peek() != NULL && char.IsWhiteSpace((char)Stream.Peek()))
    {
        isWhiteSpace = true;
        stream->get();
    }
    return isWhiteSpace;
}

token *tokenizer::isSymbol() {
    int lineNumber = stream->currentLineNumber;
    int position = stream->currentPosition;
    std::string lexeme = stream->peek().ToString();
    tokenType *type;

    if (preprocessor_symbol_to_token_type(lexeme, type))
    {
        stream->get();
        token *tkn = new token(*type, lexeme, lineNumber, position);
        lastToken = tkn;
        return tkn;
    }

    return nullptr;
}