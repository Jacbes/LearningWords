#include "wdictionary.h"
#include "interface.h"
#include "string.h"

int getrand(int min, int max) {
  return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int words_count(FILE *input, int value) {
  int words = 0;

  switch (value) {
  case 1: {
    while (!feof(input)) {
      if (fgetc(input) == '\n') {
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

dictionary *dictionary_init(int words) {
  int i, j;
  if (words > 0) {
    dictionary *tabinit = (dictionary *)malloc(words * sizeof(dictionary));
    for (i = 0; i < words; i++) {
      tabinit[i].engword = (char *)malloc(30 * sizeof(char));
      tabinit[i].rusword = (char *)malloc(30 * sizeof(char));
      tabinit[i].theme = (char *)malloc(sizeof(char));
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

dictionary *dictionary_read(dictionary *tabinit, int words, FILE *input) {
  rewind(input);

  char *buf = (char *)malloc(30 * sizeof(char));
  char *w[10];
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

void dictionary_shuf(dictionary *tab, int words) {
  int i, j;

  dictionary *buf = dictionary_init(1);

  for (i = 0; i < words; i++) {
    j = getrand(0, i);
    buf[0] = tab[i];
    tab[i] = tab[j];
    tab[j] = buf[0];
  }

  free(buf);
}

void answers(dictionary *tab, int words) {
  srand(time(NULL));
  dictionary_shuf(tab, words);
  dictionary *var = dictionary_init(4);
  int corr, num, numc, ans, corr_ans = 0;
  int i, k, j;
  printf("\033[2J");
  printf("\033[0;0f");

  for (k = 0; k < words; k++) {

    corr = getrand(0, words - 1);
    printf("%d/%d\n", k + 1, words);
    printf("\n");
    printf("                                      %s\n\n", tab[corr].engword);
    printf("\n");
    printf("\n");

    numc = getrand(0, 3);
    var[numc].rusword = tab[corr].rusword;

    for (i = 0; i < 4;) {
      num = getrand(0, words);
      if (i != numc) {
        while (num == corr) {
          num = getrand(0, words);
        }
        if (num != corr) {
          var[i].rusword = tab[num].rusword;
          i++;
        } else {
          i++;
        }
      } else {
        i++;
      }
    }
    for (j = 0; j < 4; j++) {
      printf("\n                                  %d) %s\t  \n \n", j + 1,
             var[j].rusword);
    }
    for (j = 0; j < 3; j++) {
      printf("\n");
    }
    printf("\nEnter answer (1, 2, 3, 4): ");
    scanf("%d", &ans);

    if (tab[corr].rusword == var[ans - 1].rusword) {
      printf("++Correct!\n");
      corr_ans++;
    } else {
      printf("--Wrong\n");
    }
    printf("\033[2J");
    printf("\033[0;0f");
  }
  Result(corr_ans, words);
}