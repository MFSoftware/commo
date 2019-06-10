#include <fstream>
#include "parser.h"

using namespace std;

bool Parser::openFile(const string& fileName) {
    ifstream fileStream;
    fileStream.open(fileName);

    if (!fileStream)
        return false;

    string input((istreambuf_iterator<char>(fileStream)), (istreambuf_iterator<char>()));
    source = input;

    return true;
}