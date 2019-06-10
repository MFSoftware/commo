#ifndef COMMO_TOKEN_H
#define COMMO_TOKEN_H

#include <string>

using namespace std;


class Token {
    public:
        string type;
        string value;

        Token(string ttype, string val)
        {
            type = ttype;
            value = val;
        }

        Token(string ttype, char val)
        {
            type = ttype;
            value = string(1, val);
        }
};


#endif
