#include "menue.h"

int MENUE (char Optionen [MenuePunkte][Unterpunkt_LEN])
{
    char sAuswahl;
    int  nAuswahl;

    printf("Bitte waehlen Sie:\n");
    for (unsigned int output = 0; output < MenuePunkte; output++)
    {
        printf("%d %s\n",output,Optionen[output]);
    }
    sscanf_s("%c", &sAuswahl, 1);
    while(getchar()!='\n');
    nAuswahl = atoi(&sAuswahl);
    if (nAuswahl > 0 && nAuswahl <= MenuePunkte)
    {
        return (nAuswahl);
    }
    return -1;
      
}