#ifndef _LOAD_FRAGENFELD_H_
#define _LOAD_FRAGENFELD_H_

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "PruefungsQuiz.h"
#include "file_index.h"

#define MAX_DATEN       255 
#define stream_buffer   255

static const char NIO_SPEICHER[] = "failed to allocate memory!\n";

struct load_fragenfeld
{
    char Fragen_Katalog[file_name_LEN];
    int  Index_Nummer;
};

char * Datei_auswaehlen(char * usrAuswahl);

int Fragen_Katalog_einlesen(const char * Dateiname, Fragenfeld *Quizfragen);

#endif //_LOAD_FRAGENFELD_H_