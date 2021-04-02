#ifndef _START_QUIZ_H_
#define _START_QUIZ_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

//OS Bezogene Bibliotheken
#ifdef _WIN32
    #include <windows.h>
#endif //_WIN32

#ifdef linux
    #include <unistd. h.>
#endif //linux

#include "../include/PruefungsQuiz.h"

#define Korrekt 0
#define offset 1
#define Prozentsatz 100

float start(Fragenfeld *Quizfragen);
void mixQuestions(Fragenfeld *ptr_rndQuizFragen, Fragenfeld *origin_Quizfragen); 


#endif // _START_QUIZ_H_
