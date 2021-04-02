#include "../include/file_index.h"
/**
 * @brief Index_Erweitern fuegt in index.dat einen neuen Eintrag hinzu oder erstellt die index.dat sofern nicht vorhanden.
 * In dieser Datei sind alle Dateinamen der gespeicherten "Fragen-Kataloge" hinterlegt.
 * @param Dateiname Zeiger auf einen String mit dem anzuhaengenden Dateinamen des gespeicherten Fragen-Katalogs.
 * @return true Index.dat wurde erfolgreich erweitert.
 * @return false Index.dat konnte nicht erweitert werden, details siehe stderr.
 */
bool Index_Erweitern(const char * Dateiname)
{
    FILE * INDEX;
    size_t status = 0;

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
/**
 * @brief Index_Auslesen oeffnet die index.dat und gibt die hinterlegten Dateinamen der gespeicherten Fragen-Kataloge aus. 
 * @param stream_gespeicherte_Files Zeiger auf einen String aus Chars in dem die Ausgelesenen Dateinamen geschrieben werden. 
 * @return char* Zeiger auf einen uebergabe param. String aus Chars in dem die Ausgelesenen Dateinamen geschrieben werden. 
 */
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