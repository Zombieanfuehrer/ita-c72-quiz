#include "menue.h"
/**
 * @brief Gibt ein kleines terminal basiertes Menue auf der Standart-Ausgabe aus. U
 * Es wird ein Zeiger auf ein Zeiger uebergeben, dieser Zeigt auf ein Array aus einem Array aus Chars, sprich einen Stringbeginn in einem Feld.
 * Diese Strings werden Zeilenweise ausgegeben und der User gibt einen einzelnen Char ein der in einen Intiger-Wert gewandelt wird ein.
 * Ueber diesen soll der ausgewaehlte Menuepunkt repraesentiert werden, [Feldindex].
 * @param Unterpunkte Zeiger auf ein Array, auf einen Zeiger eines Strings mit den auszugebenen Menue-Punkten.
 * @return int ist der Feldindex des unter Unterpunkte uebergebenen Arrays, der vom User ausgewaehlten Menue-Punkt.
 */
int MENUE (char **Unterpunkte)
{
    char sAuswahl[1] = {0};
    int  nAuswahl;
    int  nAnzahl = 0;

    puts("\nBitte waehlen Sie:");
    while (*Unterpunkte != NULL)
    {
        printf("%i: ",nAnzahl);
        puts(*Unterpunkte);
        ++Unterpunkte;
        ++nAnzahl;
    }
    //User-Auswahl einlesen
    scanf("%c",&sAuswahl[0]);
    while(getchar()!='\n'){}
    if (sAuswahl == 0){return -1;}
    
    //Auswahl von ASCII in int wandeln und zurueckgeben
    nAuswahl = atoi(&(*sAuswahl));   
    if (nAuswahl >= 0 && nAuswahl <= nAnzahl)
    {
        fflush(stdin);
        return (nAuswahl);
    }
    fflush(stdin);
    return -1;    
}
