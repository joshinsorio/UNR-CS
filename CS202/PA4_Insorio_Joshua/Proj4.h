#ifndef MAIN_H
#define MAIN_H

#include <iostream>

using namespace std;

//string functions declarations
size_t myStringLength(const char * str);
int myStringCompare(const char * str1, const char * str2);
char *myStringCopy(char * destination, const char * source);
char * myStringCat(char * destination, const char * source);

#endif
