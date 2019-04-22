#ifndef WDICTIONARY_H
#define WDICTIONARY_H

#include <stdio.h>
#include <stdlib.h>

typedef struct dictionary {
    char* engword;
    char* rusword;
    char* theme;
} dictionary;

int words_count(FILE* input, int value);
dictionary* dictionary_init(int words);
dictionary* dictionary_read(dictionary* tabinit, int words, FILE* input);

#endif // WDICTIONARY_H
