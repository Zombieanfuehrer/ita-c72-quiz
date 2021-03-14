#include "menue.h"

int MENUE (char **Unterpunkte)
{
    char sAuswahl;
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

    sAuswahl = getc(stdin);
    if (sAuswahl == EOF){return -1;}

    nAuswahl = atoi(&sAuswahl);
    
    if (nAuswahl >= 0 && nAuswahl <= nAnzahl)
    {
        return (nAuswahl);
    }
    return -1;    
}
