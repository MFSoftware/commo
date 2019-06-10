#include <iostream>
#include <string>
#include <vector>
#include "src/tokenizer/token.h"
#include "src/tokenizer/tokenizer.h"
#include "src/parser/parser.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 2) {
        Parser parser;

        if (!parser.openFile(argv[1])) {
            cerr << "File '" << argv[1] << "' not found!" << endl;
            exit(1);
        }

        Tokenizer tokenizer;
        vector<Token> tokens = tokenizer.tokenize(parser.source); //89sin(45) + 2.2x/7

        cout << "Count of tokens: " << to_string(tokens.size()) << endl;
        for (int index = 0; index < tokens.size(); ++index)
            cout << to_string(index) + " => " + tokens[index].type + "(" + tokens[index].value + ")" << endl;

        return 0;
    }
    if (argc == 1) {
        cout << "Interactive shell" << endl;
        cout << endl;

        while (true) {
            string code;
            cout << "commo> ";
            cin >> code;
            cout << endl;

            if (code == "exit")
                break;

            Tokenizer tokenizer;
            vector<Token> tokens = tokenizer.tokenize(code);
            for (int index = 0; index < tokens.size(); ++index)
                cout << to_string(index) + " => " + tokens[index].type + "(" + tokens[index].value + ")" << endl;

            cout << endl;
        }
    }
    else {
        cout << "Usage: ";
    }
}