#include "library.h"

#include <iostream>
#include <fstream>
#include <string>
#include "src/token.h"
#include "src/tokenizer.h"

std::string commo_get_contents(std::string filename) {
    std::ifstream file(filename);
    std::string str;
    std::string file_contents;
    while (std::getline(file, str))
    {
        file_contents += str;
        file_contents.push_back('\n');
    }
    return file_contents;
}

bool commo_convert_file(std::string filename){
    std::string source = commo_get_contents(filename);
    return false;
}