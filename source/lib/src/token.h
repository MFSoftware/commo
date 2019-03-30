#ifndef COMMO_TOKEN_H
#define COMMO_TOKEN_H

#pragma once
#include <string>

enum tokenType
{
    UnknownToken = 0,
    AndKeyword = 1,
    BreakKeyword = 2,
    CaseKeyword = 3,
    CatchKeyword = 4,
    ClassKeyword = 5,
    ConstKeyword = 6,
    ContinueKeyword = 7,
    DefaultKeyword = 8,
    DoKeyword = 9,
    ElseKeyword = 10,
    EnumKeyword = 11,
    FalseKeyword = 12,
    ForKeyword = 13,
    FuncKeyword = 14,
    IfKeyword = 15,
    InKeyword = 16,
    IsKeyword = 17,
    NewKeyword = 18,
    NorKeyword = 19,
    NullKeyword = 20,
    ObjectKeyword = 21,
    OrKeyword = 22,
    PackageKeyword = 23,
    ReturnKeyword = 24,
    SfuncKeyword = 25,
    SvarKeyword = 26,
    SwitchKeyword = 27,
    ThisKeyword = 28,
    TrueKeyword = 29,
    TryKeyword = 30,
    VarKeyword = 31,
    WhileKeyword = 32,
    Identifier = 100,
    CharacterLiteral = 101,
    StringLiteral = 102,
    IntegerLiteral = 103,
    RealLiteral = 104,
    AddressLiteral = 105,
    Assignment = 200,
    Addition = 201,
    Subtraction = 202,
    UnaryPlus = 203,
    UnaryMinus = 204,
    Multiplication = 205,
    Division = 206,
    Modulo = 207,
    EqualTo = 208,
    NotEqualTo = 209,
    GeaterThan = 210,
    LessThan = 211,
    GreaterThanOrEqualTo = 212,
    LessThanOrEqualTo = 213,
    LogicalNOT = 214,
    LogicalAND = 215,
    LogicalOR = 216,
    PostfixPlus = 217,
    PostfixMinus = 218,
    PrefixPlus = 219,
    PrefixMinus = 220,
    BitwiseNOT = 300,
    BitwiseAND = 301,
    BitwiseOR = 302,
    BitwiseXOR = 303,
    BitwiseLeftShift = 304,
    BitwiseRightShift = 305,
    AdditionAssignment = 400,
    SubtractionAssignment = 401,
    MultiplicationAssignment = 402,
    DivisionAssignment = 403,
    ModuloAssignment = 404,
    BitwiseANDAssignment = 405,
    BitwiseORAssignment = 406,
    BitwiseXORAssignment = 407,
    BitwiseLeftShiftAssignment = 408,
    BitwiseRightShiftAssignment = 409,
    OpenParenthesis = 500,
    CloseParenthesis = 501,
    OpenBrace = 502,
    CloseBrace = 503,
    OpenBracket = 504,
    CloseBracket = 505,
    Colon = 506,
    Semicolon = 507,
    Comma = 508,
    Dot = 509,
    Question = 510
};

class token {
    public:
        enum tokenType type;
        std::string lexeme;
        int lineNumber;
        int position;

        token(enum tokenType ttype, std::string tlexeme, int tlineNumber, int tposition)
        {
            type = ttype;
            lexeme = tlexeme;
            lineNumber = tlineNumber;
            position = tposition;
        }
};


#endif //COMMO_TOKEN_H
