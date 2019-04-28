#include "interface.h"
#include "wdictionary.h"
#include <stdio.h>
#include <stdlib.h>

void Transition(int l) {
  FILE *input = fopen("../bin/dictionary.txt", "r");
  int words = words_count(input, l);
  //            printf("Считано строк %d\n", words);
  dictionary *table = dictionary_init(words);
  dictionary_read(table, words, input);
  fclose(input);
  answers(table, words);
}

void Learning_topics() {
  int l;
  printf("\033[2J");
  printf("\033[0;0f");
  File_input("topics.txt");
  while ((l != 1) && (l != 2) && (l != 3) && (l != 4) && (l != 5)) {
    scanf("%d", &l);
    switch (l) {
    case 1: {
      Transition(l);
      break;
    }
    case 2:
      printf("Soon...\n");
      Learning_topics();
      break;
    case 3:
      printf("Soon...\n");
      Learning_topics();
      break;
    case 4:
      printf("Soon...\n");
      Learning_topics();
      break;
    case 5:
      Welcome_window();
      break;
    default:
      printf("Error, try gain : ");
    }
  }
}

void Welcome_window() {
  printf("\033[2J");
  printf("\033[0;0f");
  File_input("welcome.txt");
  while (1) {
    Input();
    break;
  }
}

void Input() {
  int l = 0;
  while ((l != 1) && (l != 2) && (l != 3)) {
    scanf("%d", &l);
    switch (l) {
    case 1:
      Learning_topics();
      break;
    case 2:
      Info();
      break;
    case 3:
      exit(0);
      break;
    default:
      printf("Error, try gain : ");
      Welcome_window();
    }
  }
}

void Info() {
  int l;
  printf("\033[2J");
  printf("\033[0;0f");
  File_input("info.txt");
  while ((l != 1) && (l != 2)) {
    scanf("%d", &l);
    switch (l) {
    case 1:
      Welcome_window();
      break;
    case 2:
      exit(0);
    default:
      printf("Error, try gain : ");
    }
  }
}

void File_input(char *fname) {
  FILE *file;
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

void Result(int corr_ans, int words) {
  int l;
  printf("\033[2J");
  printf("\033[0;0f");
  printf("\n");
  printf("\n");
  printf("                                    Results\n");
  for (int j = 0; j < 5; j++) {
    printf("\n");
  }
  printf("\n                                 Correct  %d/%d\n", corr_ans, words);
  for (int j = 0; j < 10; j++) {
    printf("\n");
  }
  printf("\n                  1)Again                            2)Exit\n");
  while ((l != 1) && (l != 2) && (l != 3) && (l != 4) && (l != 5)) {
    scanf("%d", &l);
    switch (l) {
    case 1: {
      Learning_topics();
      break;
    }
    case 2:
      exit(0);
      break;
    default:
      printf("Error, try gain : ");
    }
}
}
