cmake_minimum_required(VERSION 3.13)
project(Commo)

set(CMAKE_CXX_STANDARD 14)

add_library(Commo SHARED library.cpp library.h src/tokenizer.cpp src/tokenizer.h src/token.cpp src/token.h src/charStream.cpp src/charStream.h src/preprocessor.cpp src/preprocessor.h)