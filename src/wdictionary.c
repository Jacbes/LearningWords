#include "wdictionary.h"
#include "interface.h"
#include "string.h"


int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int words_count(FILE* input, int value)
{
    int words = 0;

    switch (value) {
    case 1: {
        while (!feof(input)) {
            if ((fgetc(input) > '1') && (fgetc(input) < '5')) {
                words++;
            }
        }
        break;
    }
    case 2: {
        while (!feof(input)) {
            if (fgetc(input) == '2') {
                words++;
            }
        }
        break;
    }
    case 3: {
        while (!feof(input)) {
            if (fgetc(input) == '3') {
                words++;
            }
        }
        break;
    }
    case 4: {
        while (!feof(input)) {
            if (fgetc(input) == '4') {
                words++;
            }
        }
        break;
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

dictionary*
dictionary_read(dictionary* tabinit, int words, FILE* input, int theme)
{
    rewind(input);

    char* buf = (char*)malloc(30 * sizeof(char));
    char* w[10];
    int i;
    char juk[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    for (i = 0; i < words;) {
        fscanf(input, "%s", buf);
        s_tok(buf, ';', w);
        if ((str_chr(w[0], juk) != -1)) {
            tabinit = NULL;
            break;
        }
        if ((str_chr(w[1], juk) != -1)) {
            tabinit = NULL;
            break;
        }
        scopy(w[0], tabinit[i].engword);
        scopy(w[1], tabinit[i].rusword);
        scopy(w[2], tabinit[i].theme);
        if (theme == 1) {
            i++;
        } else if (tabinit[i].theme[0] == theme + 48) {
            i++;
        }
    }

    free(buf);

    return tabinit;
}

void dictionary_shuf(dictionary* tab, int words)
{
    int i, j;

    dictionary* buf = dictionary_init(1);

    for (i = 0; i < words; i++) {
        j = getrand(0, i);
        buf[0] = tab[i];
        tab[i] = tab[j];
        tab[j] = buf[0];
    }

    free(buf);
}

void answers(dictionary* tab, int words)
{
    srand(time(NULL));
    dictionary_shuf(tab, words);
    dictionary* var = dictionary_init(4);
    int corr, num, numc, ans, corr_ans = 0;
    int i, k, j;

    for (k = 0; k < words; k++) {
        printf("\033[2J");
        printf("\033[0;0f");
        
        corr = k;

        printf("%d/%d\n", k + 1, words);
        printf("\n");
        printf("                                      %s\n\n",
               tab[corr].engword);
        printf("\n");
        printf("\n");

        numc = getrand(0, 3);
        var[numc].rusword = tab[corr].rusword;

        int wrg[3] = {-1, -1, -1};
        wrg[0] = corr;
        j = 1;
        
        for (i = 0; i < 4;) {
            if (i != numc) {
                num = getrand(0, words);
                if ((num != wrg[0]) && (num != wrg[1]) && (num != wrg[2])) {
                    var[i].rusword = tab[num].rusword;
                    wrg[j] = num;
                    i++;
                    j++;
                }
            } else {
                i++;
            }
        }
        for (j = 0; j < 4; j++) {
            printf("\n                                  %d) %s\t  \n \n",
                   j + 1,
                   var[j].rusword);
        }
        for (j = 0; j < 3; j++) {
            printf("\n");
        }
        printf("\nEnter answer (1, 2, 3, 4) or 0 for exit: ");
        scanf("%d", &ans);
        if (ans == 0) {
            break;
        }

        if (tab[corr].rusword == var[ans - 1].rusword) {
            corr_ans++;
        }
    }
    Result(corr_ans, words);
}
