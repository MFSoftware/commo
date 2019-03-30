#ifndef COMMO_CHARSTREAM_H
#define COMMO_CHARSTREAM_H

#pragma once
#include <string>
#include <list>
#include "preprocessor.h"

class charStream {
    public:
        bool isEof;
        int currentLineNumber;
        int currentPosition;

        char get();
        std::string get(int count);
        char peek();
        std::string peek(int count);

        explicit charStream(const std::string &source){
            if (!source.empty())
                lines = preprocessor_generate_list(source);
            else
            {
                isEof = true;
                return;
            }

            int line = 0;
            std::list<std::string>::iterator it;
            for (it = lines.begin(); it != lines.end(); ++it)
                line++;
            isEof = false;
            currentLineNumber = line;
            currentPosition = 0;
        }

    private:
        std::list <std::string> lines;

        void unget(int count);
        void unget();
};


#endif //COMMO_CHARSTREAM_H
