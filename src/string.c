#include "string.h"

int slen(char* str)
{
    int count = 0;

    while (str[count] != '\0') {
        count++;
    }
    return count;
}

int s_tok(char* str, char delim, char* ptr[])
{
    char* suf = str;
    ptr[0] = str;
    int i, j = 1;

    while ((i = schr(suf, delim)) >= 0) {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j;
}

int schr(char* str, char ch)
{
    int i, index = -1;

    for (i = 0; (str[i] != '\0') && (str[i] != ch); i++)
        ;
    if (str[i] == ch)
        index = i;

    return index;
}

int scopy(char* s1, char* s2)
{
    int i = 0;

    while ((*s2++ = *s1++) != '\0');

    if (slen(s2) == (slen(s1) + slen((s2)))) {
        i = 1;
        return i;
    } else {
        return i;
    }
}

int s_cmp(char* str_1, char* str_2)
{
    size_t count;
    size_t length, length_1 = slen(str_1), length_2 = slen(str_2);

    if (length_1 >= length_2) {
        length = length_1;
    } else {
        length = length_2;
    }
    for (count = 0; count < length; count++) {
        if (str_1[count] != str_2[count]) {
            if (str_1[count] > str_2[count]) {
                return 1;
            } else if (str_1[count] < str_2[count]) {
                return -1;
            }
        }
    }
    return 0;
}

int str_chr(char* str, char* ch)
{
    int i, j;

    for (i = 0; i < slen(str); i++) {
        for (j = 0; j < slen(ch); j++) {
            if (str[i] == ch[j]) {
                return i;
            }
        }
    }
    return -1;
}

int str_tok(char* str, char* delim, char** ptr)
{
    int i, j = 1;
    char* suf = str;

    ptr[0] = str;
    while ((i = str_chr(suf, delim)) >= 0) {
        suf[i] = '\0';
        suf = suf + i + 1;
        ptr[j] = suf;
        j++;
    }
    return j;
}