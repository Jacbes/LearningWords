#include <stdio.h>

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
      printf("Soon...\n");
      getchar();
      Welcome_window();
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

int Info() {
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