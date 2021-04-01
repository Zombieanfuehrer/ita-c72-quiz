#ifndef _START_QUIZ_H_
#define _START_QUIZ_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//OS Bezogene Bibliotheken
#ifdef _WIN32
    #include <windows.h>
    #define Windows 1
    #define Linux 0
#endif //UNIX

#ifdef linux
    #include <unistd. h.>
    #define Linux 1
    #define Windows 0 
#endif //UNIX

#include "../include/PruefungsQuiz.h"

#define Korrekt 0
#define offset 1

float start(Fragenfeld *Quizfragen);
Fragenfeld * mixQuestions(Fragenfeld *origin_Quizfragen); 


#endif // _START_QUIZ_H_
