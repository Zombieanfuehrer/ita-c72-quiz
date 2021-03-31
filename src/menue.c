#include "menue.h"

int MENUE (char **Unterpunkte)
{
    char sAuswahl[1] = {0};
    int  nAuswahl;
    int  nAnzahl = 0;

    puts("Bitte waehlen Sie:");
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
