#ifndef _START_QUIZ_H_
#define _START_QUIZ_H_

/**
 * @file start_quiz.h
 * @author David A. Haufe (david.haufe90@gmail.com)
 * @brief Bibliothek zum mischen eines Fragen-Katalogs und zum starten des eigentlichen Quiz.
 * @version 1.0
 * @date 2021-03-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

/**
 * @brief System-Bibliotheken fuer sleep() bzw. Sleep() werden je nach Betriebssystem geladen.
 * 
 */
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
/**
 * @brief Stellt dem User die Fragen aus dem Quizfragen-Katalog und prueft die Antworten.
 * @param Quizfragen Pointer auf ein Array vom Datentyp Fragenfeld.
 * @return float Prozentuale Satz an korrekt beantworteten Fragen.
 */
float start(Fragenfeld *Quizfragen);
/**
 * @brief mixQuestions schreibt zufaellig die Inhalte (.Frage + .Antwort) eines Fragenfeld Arrays in ein anderes Array vom Typ Fragenfeld.
 * @param ptr_rndQuizFragen Eine Adresse auf ein Array von Datentyp Fragenfeld, in das die gemischten Fragen geschrieben werden.
 * @param origin_Quizfragen Eine Adresse auf ein Array vom Datentyp Fragenfeld, in dem die urspruenglichen Fragen stehen.
 */
void mixQuestions(Fragenfeld *ptr_rndQuizFragen, Fragenfeld *origin_Quizfragen); 


#endif // _START_QUIZ_H_
