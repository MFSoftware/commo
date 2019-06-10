cmake_minimum_required(VERSION 3.14)
project(commo)

set(CMAKE_CXX_STANDARD 17)

add_executable(commo main.cpp src/tokenizer/token.cpp src/tokenizer/token.h src/tokenizer/tokenizer.cpp src/tokenizer/tokenizer.h src/parser/parser.cpp src/parser/parser.h)