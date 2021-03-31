#ifndef _FILE_INDEX_H_
#define _FILE_INDEX_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define file_name_LEN  21
#define GroupSeparator 29	
static const char _Trennzeichen[] = {GroupSeparator}; 
static const char index_dat[] = "index.dat";

bool  Index_Erweitern(const char * Dateiname);
char* Index_Auslesen (char * stream_gespeicherte_Files);

#endif  //_FILE_INDEX_H_