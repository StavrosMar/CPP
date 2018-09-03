#ifndef BITS_ASCII
#define BITS_ASCII 8
#endif

#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>

using namespace std;

int bit_get(const char* str,const int& n,const size_t nchars=1);
int bit_diff(const string& s1, const string& s2);
void test_unit_binUtil();

#endif