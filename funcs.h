/*
 * Name: Randy Lu
 * Instructor: Mr. Zamansky
 * Assignment: Lab 7
 * Purpose: Prototypes functions
 * implemented in funcs.cpp
 */

#ifndef INC_7_FUNCS_H
#define INC_7_FUNCS_H
#pragma once

#include <string>
using std::string;

string removeLeadingSpaces(string line);
int countChar(string line, char c);
void unindent(string file);
void indent(string file);

#endif //INC_7_FUNCS_H
