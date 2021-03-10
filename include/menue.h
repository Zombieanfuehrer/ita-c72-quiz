/**
 * @file menue.h
 * @author David A. Haufe (david.haufe90@gmail.com)
 * @brief Bibliothek zur Erzeugung und Ausgabe simpler textbasierter Menues 
 * @version 1.0
 * @date 2021-03-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef  _MENUE_H_
#define _MENUE_H_

/**
 * @brief Parametrierung Anzahl
 * Ueber "#define MenuePunkte" wird die Anzahl der Unterpunkte des Menues vorgegeben
 * Ueber "#define Unterpunkt_LEN" wird die maximale Zeichenlaenge des Unterpunkts vorgegeben
 */
#define MenuePunkte 5
#define Unterpunkt_LEN 20
/**
 * @brief Parametrierung Unterpunkte
 * Ueber den Char-Array "Optionen" werden die Unterpunkte angelegt.
 */
char Optionen [MenuePunkte][Unterpunkt_LEN] = {
    {"END"},
    {"QUIZ"},
    {"RANDOM-QUIZ"},
    {"LOAD-QUESTIONS"},
    {"GENERATOR"}
};

#include <stdio.h>
#include <stdlib.h>
#include "../include/PruefungsQuiz.h"

/**
 * @brief MENUE 
 * Die Unterpunkte aus dem "Optionen-Array" werden Zeilenweise auf der Standart-Ausgabe
 * ausgegeben. Der Anwender kann einen Menuepunkt ueber die Ausgabenummereriung auswaehlen.
 * @param Optionen Array mit verfuegbaren Menuepunkten
 * @return int Index Nr. des vom Anwaender ausgewaehlten Menuepunkts
 */
int MENUE (char Optionen [MenuePunkte][Unterpunkt_LEN]);

#endif //_MENUE_H_
