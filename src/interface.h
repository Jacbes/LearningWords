#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Input();
void Welcome_window();
void Info();
void File_input(char *fname);
void Learning_topics();
void Transition(int l);
void Result(int corr_ans, int words);

#endif