/*
 * Name: Randy Lu
 * Instructor: Mr. Zamansky
 * Assignment: Lab 7
 * Purpose: Implements functions
 * prototyped in funcs.cpp
 */

#include <string>
#include "funcs.h"
#include <cctype>
#include <fstream>
using std::string;
using std::getline;
using std::ifstream;
using std::ofstream;

string removeLeadingSpaces(string line){
	int s = line.size();
	for (int i = 0; i < s; i++)
		if(!isspace(line[i]))
			return line.substr(i, s - i);
	return "";
}

int countChar(string line, char c){
	int a = 0;
	for (auto b : line)
		if(b == c) a++;
	return a;
}

void unindent(string file){
	ifstream fin(file);
	ofstream fout("unindent.cpp");
	while(fin){
		string line;
		getline(fin,line);
		line = removeLeadingSpaces(line);
		fout << line << "\n";
	}
	fin.close();
	fout.close();
}

void indent(string file){
	ifstream fin(file);
	ofstream fout("indent.cpp");
	int t = 0;
	while(fin){
		string line;
		string indents = "";
		getline(fin,line);
        t -= countChar(line,'}');
		for (int i = 0; i < t; ++i)
			indents += "\t";
		line = removeLeadingSpaces(line);
		line = indents + line;
		t += countChar(line, '{');
		fout << line << "\n";
	}
	fin.close();
	fout.close();
}



