#ifndef _START_QUIZ_H_
#define _START_QUIZ_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#include "../include/PruefungsQuiz.h"

#define Korrekt 0

float start(Fragenfeld *Quizfragen);
Fragenfeld * mixQuestions(Fragenfeld *origin_Quizfragen); 


#endif // _START_QUIZ_H_
