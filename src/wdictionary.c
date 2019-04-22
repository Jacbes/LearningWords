#include "wdictionary.h"
#include "string.h"

int words_count(FILE* input, int value)
{
    int words = 0;

    switch (value) {
    case 1: {
        while (!feof(input)) {
            if ((fgetc(input) == '2') || (fgetc(input) == '3')
                || (fgetc(input) == '4')) {
                words++;
            }
        }
    }
    case 2: {
        while (!feof(input)) {
            if (fgetc(input) == '2') {
                words++;
            }
        }
    }
    case 3: {
        while (!feof(input)) {
            if (fgetc(input) == '3') {
                words++;
            }
        }
    }
    case 4: {
        while (!feof(input)) {
            if (fgetc(input) == '4') {
                words++;
            }
        }
    }
    }

    return words;
}

dictionary* dictionary_init(int words)
{
    int i, j;
    if (words > 0) {
        dictionary* tabinit = (dictionary*)malloc(words * sizeof(dictionary));
        for (i = 0; i < words; i++) {
            tabinit[i].engword = (char*)malloc(30 * sizeof(char));
            tabinit[i].rusword = (char*)malloc(30 * sizeof(char));
            tabinit[i].theme = (char*)malloc(sizeof(char));
            for (j = 0; j < 30; j++) {
                tabinit[i].engword[j] = 0;
                tabinit[i].rusword[j] = 0;
            }
            tabinit[i].theme[0] = 0;
        }
        if (tabinit == NULL) {
            return NULL;
        } else {
            return tabinit;
        }
    }

    return NULL;
}

dictionary* dictionary_read(dictionary* tabinit, int words, FILE* input)
{
    rewind(input);

    char* buf = (char*)malloc(30 * sizeof(char));
    char* w[10];
    int i;

    for (i = 0; i < words; i++) {
        fscanf(input, "%s", buf);
        s_tok(buf, ';', w);
        scopy(w[0], tabinit[i].engword);
        scopy(w[1], tabinit[i].rusword);
        scopy(w[2], tabinit[i].theme);
    }

    free(buf);

    return tabinit;
}