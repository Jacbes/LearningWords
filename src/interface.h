#ifndef INTERFACE_H
#define INTERFACE_H

#include "wdictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Input();
void Welcome_window();
void Info();
void File_input(char* fname);
void Learning_topics();
void Modes(int tr);
void Transition(int l, int mode);
void Result(int corr_ans, int words, dictionary* tab, char* cmass);

#endif