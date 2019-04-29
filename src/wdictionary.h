#ifndef WDICTIONARY_H
#define WDICTIONARY_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct dictionary {
  char *engword;
  char *rusword;
  char *theme;
} dictionary;

int getrand(int min, int max);
int words_count(FILE *input, int value);
dictionary *dictionary_init(int words);
dictionary *dictionary_read(dictionary *tabinit, int words, FILE *input, int theme);
void dictionary_shuf(dictionary *tab, int words);
void answers(dictionary *tab, int words);

#endif // WDICTIONARY_H
