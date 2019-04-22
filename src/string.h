#ifndef STRING_H
#define STRING_H

#include <stdio.h>
#include <stdlib.h>

int slen(char* str);
int s_tok(char* str, char delim, char* ptr[]);
int schr(char* str, char ch);
int scopy(char* s1, char* s2);
int s_cmp(char* str1, char* str2);
int str_chr(char* str, char* ch);
int str_tok(char* str, char* delim, char** ptr);

#endif // STRING_H
