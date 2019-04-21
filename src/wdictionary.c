#include "wdictionary.h"
#include <stdio.h>
#include <stdlib.h>

int count_lines(FILE* input)
{
    int lines = 0;

    while (!feof(input)) {
        if (fgetc(input) == '\n') {
            lines++;
        }
    }

    fclose(input);
    return lines;
}

dictionary* dictionary_init(int lines)
{
    int i, j;
    if (lines > 0) {
        dictionary* tabinit = (dictionary*)malloc(lines * sizeof(dictionary));
        for (i = 0; i < lines; i++) {
            tabinit[i].engword = (char*)malloc(30 * sizeof(char));
            tabinit[i].rusword = (char*)malloc(30 * sizeof(char));
            tabinit[i].theme = malloc(sizeof(unsigned int));
            for (j = 0; j < 30; j++) {
                tabinit[i].engword[j] = 0;
                tabinit[i].rusword[j] = 0;
            }
        }
        if (tabinit == NULL) {
            return NULL;
        } else {
            return tabinit;
        }
    }

    return NULL;
}