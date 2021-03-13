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
#ifndef _MENUE_H_
#define _MENUE_H_

/**
 * @brief Parametrierung Menuepunkte
 * Ueber "#define Unterpunkt_LEN" wird die maximale Zeichenlaenge des Unterpunkts vorgegeben
 */
#define Unterpunkt_LEN 20

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief MENUE 
 * Die Unterpunkte aus dem "Optionen-Array" werden Zeilenweise auf der Standart-Ausgabe
 * ausgegeben. Der Anwender kann einen Menuepunkt ueber die Ausgabenummereriung auswaehlen.
 * @param Unterpunkte Array mit verfuegbaren Menuepunkten
 * @return int Index Nr. des vom Anwaender ausgewaehlten Menuepunkts
 */
int MENUE (char ** Unterpunkte);

#endif //_MENUE_H_
