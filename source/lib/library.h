#include <iostream>
#include <fstream>
#include <string>

#ifndef COMMO_LIBRARY_H
#define COMMO_LIBRARY_H

std::string commo_get_contents(std::string filename);
bool commo_convert_file(std::string filename);

#endif