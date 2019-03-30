#include "charStream.h"

#include <string>
#include <iostream>

char charStream::get()
{
    if (isEof)
        return '\0';

    auto it = lines.begin();
    while (!it->empty() && it != lines.end() && currentLineNumber < lines.size()) {
        ++it;
        currentLineNumber++;
    }

    char c = std::next(lines.begin(), currentLineNumber)->at(static_cast<unsigned int>(currentPosition));

    if (currentPosition + 1 < std::next(lines.begin(), currentLineNumber)->size())
        currentPosition++;
    else
    {
        if (currentLineNumber + 1 < lines.size())
        {
            currentLineNumber++;
            currentPosition = 0;
        }
        else
            isEof = true;
    }

    return c;
}

std::string charStream::get(int count) {
    std::string stringBuilder;
    for (int i = 0; i < count; i++)
    {
        char c = get();
        if (c == '\0')
            return nullptr;
        else
            stringBuilder.push_back(c);
    }
    return stringBuilder;
}

void charStream::unget(int count) {
    for (int i = 0; i < count; i++)
        unget();
}

void charStream::unget() {
    if (isEof)
        isEof = false;
    else
    {
        if (currentPosition > 0)
            currentPosition--;
        else if (currentLineNumber > 0)
        {
            while (std::next(lines.begin(), --currentLineNumber)->empty()) ;
            currentPosition = std::next(lines.begin(), currentLineNumber)->size() - 1; //Lines[CurrentLineNumber].Length - 1;
        }
    }
}

char charStream::peek() {
    if (isEof)
        return '\0';

    char c = get();
    unget();
    return c;
}

std::string charStream::peek(int count) {
    std::string peek = get(count);
    unget(count);
    return peek;
}