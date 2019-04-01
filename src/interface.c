#include <stdio.h>

void Welcome_window() {
  printf("\033[2J"); /* Clear the entire screen. */
  printf("\033[0;0f");
  printf("\n");
  printf("                         Welcome to the LearningWords \n");
  printf("\n");
  printf("                                    1) start \n");
  printf("                                    2) info \n");
  printf("                                    3) exit \n");
}