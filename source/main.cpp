#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "src/tokenizer/token.h"
#include "src/tokenizer/tokenizer.h"
#include "src/parser/parser.h"

using namespace std;

void showHelp() {
    cout << "Usage: commo [options]" << endl <<
            "   commo -i (show interactive shell)" << endl <<
            "   commo <file> (compile input file)" << endl <<
            "   commo -h (show this message)"
            << endl;
}

int main(int argc, char* argv[]) {
    if (argc == 2) {
        //Show interactive shell
        if (strcmp(argv[1], "-i") == 0 || strcmp(argv[1], "--i") == 0 || strcmp(argv[1], "/i") == 0) {
            cout << "Interactive shell" << endl;
            cout << endl;

            while (true) {
                string code;
                cout << "commo> ";
                cin >> code;

                if (code == "exit")
                    break;

                cout << endl;

                Tokenizer tokenizer;
                vector<Token> tokens = tokenizer.tokenize(code);
                for (int index = 0; index < tokens.size(); ++index)
                    cout << to_string(index) + " => " + tokens[index].type + "(" + tokens[index].value + ")" << endl;

                cout << endl;
            }
        }
        //Show help
        else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0 || strcmp(argv[1], "/h") == 0 || strcmp(argv[1], "--h") == 0 || strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "/help") == 0)
            showHelp();
        //Build source file
        else {
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
    }
    else
        showHelp();
}