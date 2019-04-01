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