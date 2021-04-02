#ifndef _GENERATOR_H_
#define _GEGERATOR_H_

/**
 * @file generator.h
 * @author David A. Haufe (david.haufe90@gmail.com)
 * @brief Bibliothek zum erstellen eines Fragen-Katalogs.
 * @version 1.0
 * @date 2021-03-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/PruefungsQuiz.h"
#include "../include/save_fragenfeld.h"
/**
 * @brief User kann eigene Quizfragen und entsprechende Antworten in einen Fragen-Katalog schreiben.
 * @param Quizfragen ein Pointer auf ein Datentyp Fragenfeld, respektive ein Array aus Fragenfeld, in welchem die Fragen & Antworten geschrieben werden.
 */
int Fragen_einlesen(Fragenfeld *Quizfragen);

#endif // _GENERATOR_H_
