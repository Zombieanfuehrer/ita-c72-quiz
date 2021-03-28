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
    status = fprintf(INDEX,"%s %01X", Dateiname, GroupSeparator);
    fclose(INDEX);
    if (status == strlen(Dateiname+2))  //+2 (leerzeichen + GroupSeparator)
    {
        return true;
    }
    return false;   
}

char* Index_Auslesen(void)
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
    char * gespeicherte_Files = calloc(30,sizeof(char) * ((file_name_LEN+2)));
    printf("debug 1");
    fscanf(INDEX,"%s",gespeicherte_Files);
    printf("Test = %s", gespeicherte_Files);
    return gespeicherte_Files;

}