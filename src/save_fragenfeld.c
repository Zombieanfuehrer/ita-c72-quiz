#include "../include/save_fragenfeld.h"

bool Fragen_in_datei_speichern(Fragenfeld *Quizfragen)
{
    FILE * Save_Dat;
    
    time_t sysTime;
    struct tm *sysTimeStruct;    

    char * Dateiname_typ, Dateiname, text_dat = '.txt';

    //Fragenkatalog ist nicht leer, aktuell erstes feld
    if (*Quizfragen->Frage)
    {
        //Systemzeit auslesen fuer Dateinamen-Bestimmung
        sysTime = time(NULL);
        sysTimeStruct = localtime(&sysTime);
        //Dateiname aus aktueller Zeit generieren
        strcpy(Dateiname,(asctime(sysTimeStruct)));
        //temporaeren Speicher fuer neuen string freigeben (+1 fuer '\n') (malloc da nicht init. werden muss chars werden eh entsprechend ueberschrieben)
        Dateiname_typ = malloc(strlen(Dateiname) + strlen(text_dat) +1);
        //Dateinamen und dateityp bzw. endung zusammenfuegen
        strcpy(Dateiname_typ+strlen(Dateiname), text_dat);
        //Datei schreiben oeffnen, wird ueberschrieben wenn diese schon existiert. if fragt ob filepointer zurueck gegeben wird
        if(fopen(Dateiname_typ,"wb+")){
            while (*Quizfragen->Frage)
            {
                fprintf(Dateiname_typ,"%s",Quizfragen->Frage);
                fprintf(Dateiname_typ,"%s",Quizfragen->Antwort);
                ++Quizfragen;
            }
        fclose(Dateiname_typ);
        return true;      
        }      
    }
    return false;   
}