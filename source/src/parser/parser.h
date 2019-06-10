#ifndef COMMO_PARSER_H
#define COMMO_PARSER_H

#include <string>

using namespace std;

class Parser {
    public:
        string source;
        bool openFile(const string& fileName);
};


#endif //COMMO_PARSER_H
