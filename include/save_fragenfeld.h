#ifndef _SAVE_FRAGENFELD_H_
#define _SAVE_FRAGENFELD_H_

#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#include "PruefungsQuiz.h"
#include "file_index.h"

#define LEN_ASCII_TIME          25       //Thu Mar 26 06:00:48 2009 = 24 + \0
#define ASCTIME_TIME_STAMP_POS  11
#define ASCTIME_TIME_STAMP_LEN  9
#define ZEILENUMBRUCH           1

static const char NIO_SPEICHER[] = "failed to allocate memory!\n";
static const char text_dat[] = ".txt";

char* replace_char(char* str, char find, char replace);
char* Zeit_Stempel_loeschen(char* strASCTIME);

bool Fragen_in_datei_speichern(Fragenfeld *Quizfragen);

#endif //_SAVE_FRAGENFELD_H_
