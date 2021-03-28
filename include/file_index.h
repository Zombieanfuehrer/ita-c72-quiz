#ifndef _FILE_INDEX_H_
#define _FILE_INDEX_H_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define file_name_LEN 15
#define GroupSeparator 29	

static const char index_dat[] = "index.dat";

bool  Index_Erweitern(const char * Dateiname);
char* Index_Auslesen (void);

#endif  //_FILE_INDEX_H_