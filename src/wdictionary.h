#ifndef DOCUMENTS_WDICTIONARY_H
#define DOCUMENTS_WDICTIONARY_H

typedef struct dictonary {
    char* engword;
    char* rusword;
    unsigned int theme;
} dictionary;

int count_lines(FILE* input);
dictionary* dictionary_init(int lines);

#endif // DOCUMENTS_WDICTIONARY_H
