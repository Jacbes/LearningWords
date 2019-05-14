#include "interface.h"
#include <stdio.h>
#include <stdlib.h>

#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KYEL "\x1B[33m"
#define KBLU "\x1B[34m"
#define KMAG "\x1B[35m"
#define KCYN "\x1B[36m"
#define KWHT "\x1B[37m"

void Transition(int l, int mode)
{
    FILE* input = fopen("../text/dictionary.txt", "r");
    int words = words_count(input, l);
    dictionary* table = dictionary_init(words);
    dictionary_read(table, words, input, l);
    fclose(input);
    answers(table, words, mode);
}

void Learning_topics()
{
    char l = '0';
    printf("\033[2J");
    printf("\033[0;0f");
    printf("%s  ____________________________________________________________________________  \n", KMAG);
    printf("//____________________________________________________________________________\\\\\n");
    printf("||                                                                            ||\n");
    printf("||     BBBBBBBBB  BBB   BBB  BBBBBBBB  BBB         BBB  BBBBBBBB   BBBBBB     ||\n");
    printf("||        BBB     BBB   BBB  BBB       BBBBBB   BBBBBB  BBB       BBB         ||\n");
    printf("||        BBB     BBBBBBBBB  BBBBBBBB  BBB  BB BB   BB  BBBBBBBB   BBBBB      ||\n");
    printf("||        BBB     BBB   BBB  BBB       BBB   BBB    BB  BBB           BBB     ||\n");
    printf("||        BBB     BBB   BBB  BBBBBBBB  BBB          BB  BBBBBBBB  BBBBBB      ||\n");
    printf("||____________________________________________________________________________||\n");
    printf("\\\\____________________________________________________________________________//%s\n", KWHT);
    printf("                                                                        \n");
    File_input("../text/topics.txt");
    while ((l != '1') && (l != '2') && (l != '3') && (l != '4') && (l != '5')) {
        scanf("%c", &l);
        switch (l) {
        case '1': {
            Modes(1);
            break;
        }
        case '2': {
            Modes(2);
            break;
        }
        case '3': {
            Modes(3);
            break;
        }
        case '4': {
            Modes(4);
            break;
        }
        case '5':
            Welcome_window();
            break;
        }
    }
}

void Modes(int tr)
{
    char l = '0';
    int mode = 0;
    printf("\033[2J");
    printf("\033[0;0f");
    printf("%s  ____________________________________________________________________________  \n", KMAG);
    printf("//____________________________________________________________________________\\\\\n");
    printf("||                                                                            ||\n");
    printf("||       BBBBBB   BBBBBB    BBBBBBBB    BBBBBBBB     BBBBBBB    BBBBBBB       ||\n");
    printf("||       BBB BBB BBB BBB   BBB    BBB   BBB    BB    BBB       BBB            ||\n");
    printf("||       BBB  BBBBB  BBB   BBB    BBB   BBB     BB   BBBBBBB    BBBBBB        ||\n");
    printf("||       BBB         BBB   BBB    BBB   BBB    BB    BBB            BBB       ||\n");
    printf("||       BBB         BBB    BBBBBBBB    BBBBBBBB     BBBBBBB   BBBBBBB        ||\n");
    printf("||____________________________________________________________________________||\n");
    printf("\\\\____________________________________________________________________________//%s\n", KWHT);
    printf("                                                                        \n");
    File_input("../text/modes.txt");
    while ((l != '1') && (l != '2') && (l != '3') && (l != '4') && (l != '5')) {
        scanf("%c", &l);
        switch (l) {
        case '1': {
            mode = 1;
            Transition(tr, mode);
            break;
        }
        case '2': {
            mode = 2;
            Transition(tr, mode);
            break;
        }
        case '3': {
            mode = 3;
            Transition(tr, mode);
            break;
        }
        case '4':
            Learning_topics();
            break;
        }
    }
}

void Welcome_window()
{
    printf("\033[2J");
    printf("\033[0;0f");
    printf("%s  ____________________________________________________________________________  \n", KMAG);
    printf("//____________________________________________________________________________\\\\\n");
    printf("||                                                                            ||\n");
    printf("||     BB      BBBBBB     BBB     BBBBBB   BBBB  BB  BB  BBBB  BB   BBBBBBB   ||\n");
    printf("||     BB      BB        BB BB    BB   BB  BB BB BB  BB  BB BB BB  BB         ||\n");
    printf("||     BB      BBBBBB   BB   BB   BBBBBB   BB  BBBB  BB  BB  BBBB  BB   BB    ||\n");
    printf("||     BB      BB       BBBBBBB   BB  BB   BB   BBB  BB  BB   BBB  BB    BB   ||\n");
    printf("||     BBBBBB  BBBBBB  BB     BB  BB   BB  BB    BB  BB  BB    BB   BBBBBB    ||\n");
    printf("||                                                                            ||\n");
    printf("||            BB               BB   BBBBBB   BBBBBB   BBBBBB    BBBBB         ||\n");
    printf("||             BB     BBB     BB   BB    BB  BB   BB  BB   BB  BB             ||\n");
    printf("||              BB   BB BB   BB    BB    BB  BBBBBB   BB    B  BBBBB          ||\n");
    printf("||               BB BB   BB BB     BB    BB  BB  BB   BB   BB      BB         ||\n");
    printf("||                BBB     BBB       BBBBBB   BB   BB  BBBBBB   BBBBBB         ||\n");
    printf("||____________________________________________________________________________||\n");
    printf("\\\\____________________________________________________________________________//%s\n", KWHT);
    printf("                                                                        \n");
    File_input("../text/welcome.txt");
    while (1) {
        Input();
        break;
    }
}

void Input()
{
    char l = '0';
    while ((l != '1') && (l != '2') && (l != '3')) {
        scanf("%c", &l);
        switch (l) {
        case '1':
            Learning_topics();
            break;
        case '2':
            Info();
            break;
        case '3':
            exit(0);
            break;
        default:
            Welcome_window();
        }
    }
}

void Info()
{
    char l = '0';
    printf("\033[2J");
    printf("\033[0;0f");
    File_input("../text/info.txt");
    while ((l != '1') && (l != '2')) {
        scanf("%c", &l);
        switch (l) {
        case '1':
            Welcome_window();
            break;
        case '2':
            exit(0);
        }
    }
}

void File_input(char* fname)
{
    FILE* file;
    char result_string[322];
    file = fopen(fname, "r");
    if (file == NULL) {
        printf("Error opening file '%s'", fname);
    }
    while (fgets(result_string, sizeof(result_string), file)) {
        printf("%s\n", result_string);
    }
    fclose(file);
}

void Result(int corr_ans, int words, dictionary* tab, char* cmass)
{
    char l = '0';
    printf("\033[2J");
    printf("\033[0;0f");
    printf("%s  ____________________________________________________________________________  \n", KMAG);
    printf("//____________________________________________________________________________\\\\\n");
    printf("||                                                                            ||\n");
    printf("||  BBBBBBBB   BBBBBBBB  BBBBBBBB  BBB     BBB  BBB     BBBBBBBBB  BBBBBBBB   ||\n");
    printf("||  BBB   BBB  BBB       BBB       BBB     BBB  BBB        BBB     BBB        ||\n");
    printf("||  BBBBBBBB   BBBBBBB    BBBBBB   BBB     BBB  BBB        BBB      BBBBBB    ||\n");
    printf("||  BBB  BBB   BBB            BBB  BBB     BBB  BBB        BBB          BBB   ||\n");
    printf("||  BBB   BBB  BBBBBBBB  BBBBBBBB    BBBBBBB    BBBBBBB    BBB     BBBBBBBB   ||\n");
    printf("||____________________________________________________________________________||\n");
    printf("\\\\____________________________________________________________________________//%s\n", KWHT);
    printf("                                                                        \n");
    printf("                                                                        \n");
    printf("                                                                        \n");
    printf("\n                                 Correct  %d/%d\n", corr_ans, words);
    for (int j = 0; j < 5; j++) {
        printf("\n");
    }
    printf("\n                  1)Again          2)Mistakes         3)Exit\n");
    while ((l != '1') && (l != '2') && (l != '3')) {
        scanf("%c", &l);
        switch (l) {
        case '1': {
            Learning_topics();
            break;
        }
        case '2': {
            for (int j = 0; j < words; j++) {
                if (cmass[j] == '+') {
                    printf("%s || correct\n", tab[j].engword);
                } else {
                    printf("%s || miss\n", tab[j].engword);
                }
            }
            exit(0);
        }
        case '3':
            exit(0);
        }
    }
}