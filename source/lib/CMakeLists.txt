cmake_minimum_required(VERSION 3.13)
project(commo C)

set(CMAKE_C_STANDARD 99)

add_library(commo SHARED library.c library.h)