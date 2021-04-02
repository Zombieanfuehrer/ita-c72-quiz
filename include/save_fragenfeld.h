#ifndef _SAVE_FRAGENFELD_H_
#define _SAVE_FRAGENFELD_H_
/**
 * @file save_fragenfeld.h
 * @author David A. Haufe (david.haufe90@gmail.com)
 * @brief Bibliothek zum speichern eines Fragen-Katalogs.
 * @version 1.0
 * @date 2021-03-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
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

#ifndef _LOAD_FRAGENFELD_H_
    static const char NIO_SPEICHER[] = "failed to allocate memory!\n";
#endif //_LOAD_FRAGENFELD_H_

static const char text_dat[] = ".txt";

char* replace_char(char* str, char find, char replace);
char* Zeit_Stempel_loeschen(char* strASCTIME);

bool Fragen_in_datei_speichern(Fragenfeld *Quizfragen);

#endif //_SAVE_FRAGENFELD_H_
