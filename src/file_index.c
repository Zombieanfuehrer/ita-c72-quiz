#include "../include/file_index.h"


bool Index_Erweitern(const char * Dateiname)
{
    FILE * INDEX;
    int status = 0;

    //Index gueltig
    INDEX = fopen(index_dat,"r");
    //INDEX anlegen
    if(INDEX == NULL){
       //Datei erstellen und oeffnen
        INDEX = fopen(index_dat,"wb+");
    }else{
        //Datei exestiert, lesenden Zugriff beenden
        fclose(INDEX);
        //Datei schreibend, am Ende anhaengend oeffnen
        INDEX = fopen(index_dat,"ab+");
    }
    //Fehlerbehandlung
    if (INDEX == NULL){
        fprintf(stderr,"INDEX-Datei konnte nicht geoeffnet/angelegt werden!");
        return false;
    }
    status = fprintf(INDEX,"%s%c", Dateiname, GroupSeparator);
    fclose(INDEX);
    if (status == strlen(Dateiname+1))  //+GroupSeparator
    {
        return true;
    }
    return false;   
}

char* Index_Auslesen(char * stream_gespeicherte_Files)
{
    FILE * INDEX;

    //Index gueltig
    INDEX = fopen(index_dat,"r");
    //Fehlerbehandlung
    if(INDEX == NULL){
        fprintf(stderr,"Index-Datei konnte nicht geoeffnet werden!");
        return NULL;
    }
    //Speicher anfordern
    stream_gespeicherte_Files = calloc(30,sizeof(char) * ((file_name_LEN+2)));
    fscanf(INDEX,"%s",stream_gespeicherte_Files);

    return stream_gespeicherte_Files;

}