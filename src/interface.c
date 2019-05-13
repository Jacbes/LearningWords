#include "interface.h"
#include "wdictionary.h"
#include <stdio.h>
#include <stdlib.h>

void Transition(int l)
{
    FILE* input = fopen("../text/dictionary.txt", "r");
    int words = words_count(input, l);
    dictionary* table = dictionary_init(words);
    dictionary_read(table, words, input, l);
    fclose(input);
    answers(table, words);
}

void Learning_topics()
{
    char l;
    printf("\033[2J");
    printf("\033[0;0f");
    File_input("../text/topics.txt");
    while ((l != '1') && (l != '2') && (l != '3') && (l != '4') && (l != '5')) {
        scanf("%c", &l);
        switch (l) {
        case '1': {
            Transition(1);
            break;
        }
        case '2': {
            Transition(2);
            break;
        }
        case '3': {
            Transition(3);
            break;
        }
        case '4': {
            Transition(4);
            break;
        }
        case '5':
            Welcome_window();
            break;
        default:
            printf("Error, try gain : ");
        }
    }
}

void Welcome_window()
{
    printf("\033[2J");
    printf("\033[0;0f");
    File_input("../text/welcome.txt");
    while (1) {
        Input();
        break;
    }
}

void Input()
{
    char l;
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
            printf("Error, try gain : ");
            Welcome_window();
        }
    }
}

void Info()
{
    char l;
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
        default:
            printf("Error, try gain : ");
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

void Result(int corr_ans, int words)
{
    char l;
    printf("\033[2J");
    printf("\033[0;0f");
    printf("\n");
    printf("\n");
    printf("                                    Results\n");
    for (int j = 0; j < 5; j++) {
        printf("\n");
    }
    printf("\n                                 Correct  %d/%d\n",
           corr_ans,
           words);
    for (int j = 0; j < 10; j++) {
        printf("\n");
    }
    printf("\n                  1)Again                            2)Exit\n");
    while ((l != '1') && (l != '2') && (l != '3') && (l != '4') && (l != '5')) {
        scanf("%c", &l);
        switch (l) {
        case '1': {
            Learning_topics();
            break;
        }
        case '2':
            exit(0);
            break;
        default:
            printf("Error, try gain : ");
        }
    }
}
