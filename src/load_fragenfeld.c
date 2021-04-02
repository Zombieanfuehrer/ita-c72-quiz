#include "../include/load_fragenfeld.h"

/**
 * @brief Ueber Datei_auswaehlen soll dem User angezeigt werden welche Dateien gespeichert sind und er eine von diesen auswaehlen kann.
 * @param usrAuswahl Zeiger auf einen String in dem der von User ausgewaehlte Dateiname des Fragen-Katalogs geschrieben wird. 
 * @return char* Zeiger auf einen String, aus dem Uebergabeparam. in dem der von User ausgewaehlte Dateiname des Fragen-Katalogs geschrieben wird.
 */
char * Datei_auswaehlen(char * usrAuswahl)
{
    unsigned int Anzahl = 1;
    char * single_datensatz;
    struct load_fragenfeld ausgeleseneDatensaetze[MAX_DATEN];
    char inputFragen_Katalog[3] = {0}; 
    bool inputValid = false;

    //Speicher fuer ausgelesene Datenseatze reservieren
    char * datensaetze_stream = calloc(MAX_DATEN, (sizeof(char) * file_name_LEN));
    if(datensaetze_stream == NULL){
        perror(NIO_SPEICHER);
        return NULL;
    }
    printf("\nFragen-Katalog laden\n");
    printf("Auswahl des Fragen-Katalogs uber die entsprechende Nr.\n");
    printf("--------------------------------------------------------------------\n\n");
    //Datensatzte aus Index-Datei auslesen
    datensaetze_stream = Index_Auslesen(datensaetze_stream);
    //Ausgelesene Datensaetze nach "Trennzeichen (token)" durchsuchen und in "ausgeleseneDatensaetze"-Record eintragen
    single_datensatz = strtok(datensaetze_stream,_Trennzeichen);
    while (single_datensatz)
    {
        //Record einlesen
        ausgeleseneDatensaetze[Anzahl].Index_Nummer = Anzahl;
        strncpy_s(ausgeleseneDatensaetze[Anzahl].Fragen_Katalog,file_name_LEN,single_datensatz,file_name_LEN);
        //Datensaetze ausgeben
        printf("  Nr.: %d. -> %s \n",ausgeleseneDatensaetze[Anzahl].Index_Nummer, ausgeleseneDatensaetze[Anzahl].Fragen_Katalog);
        Anzahl++;
        single_datensatz = strtok(NULL,_Trennzeichen);
    }
    Anzahl--;   //Unnoetige addition aus letztem Schleifendurchlauf abziehen.
    printf("\n--------------------------------------------------------------------\n\nWaehlen Sie:");
    
    //User Eingabe     
    do
    {
        fgets(inputFragen_Katalog, 4, stdin);
        fflush(stdin);
        inputFragen_Katalog[strcspn(inputFragen_Katalog, "\n")] = 0;            //Terminator entfernen
        if (atoi(inputFragen_Katalog)  <= 0 || atoi(inputFragen_Katalog) > Anzahl){
            fprintf(stderr,"Ungueltige Eingabe, bitte Waehlen Sie einen Wert > 0 und <= %d!\n", Anzahl);
        }else inputValid = true;      
    }
    while(!inputValid);
    free(datensaetze_stream);
    strncpy_s(usrAuswahl,file_name_LEN,ausgeleseneDatensaetze[atoi(inputFragen_Katalog)].Fragen_Katalog,file_name_LEN);
    return usrAuswahl;
}

/**
 * @brief Fragen_Katalog_einlesen oeffnet die vom User ausgewaehlte Fragen-Katalog-Datei und liest die Inhalte in den Speicher ein.
 * @param Dateiname Der Dateiname der zu oeffnenden Fragen-Katalog.txt Datei.
 * @param Quizfragen Zeiger auf Adresse vom Datentyp Fragenfeld, in dem die ausgelesenen Werte geschrieben werden.
 * @return int die Anzahl der ausgelesenen Datensaetze (Frage+Antwort)
 */
int Fragen_Katalog_einlesen(const char * Dateiname, Fragenfeld *Quizfragen)
{
    FILE * Fragenkatalog;
    bool FileEnd = false;
    int Anzahl_Datensaetze = 1;
    //Dateistream auf Save_Dat lesend oeffnen
    Fragenkatalog = fopen(Dateiname, "r+");
    //Fehlerbehandlung
    if (!Fragenkatalog){
        fprintf(stderr,"%s konnte nicht geoeffnet werden!\n",Dateiname);
        return -1;
    }
    //Dateipointer auf erster Frage positionieren
    if (fseek(Fragenkatalog,45,SEEK_SET) != 0){
        fprintf(stderr,"%s Dateifehler!\n",Dateiname);
        return -1;
    }
    //Speicherplatz fuer aus Dateistream ausgelesene Daten allocieren
    char * Fragenkatalog_stream = calloc(stream_buffer,sizeof(char));
    //Dateistream auslesen bis End Of File
    while(!FileEnd){
        //Quizfragen Struktur abloeschen
        memset(Quizfragen->Frage,0,sizeof((char) * Quizfragen->Frage));
        memset(Quizfragen->Antwort,0,sizeof((char) * Quizfragen->Antwort));
        //Frage(n) einlesen
        if(fgets(Fragenkatalog_stream,maxLEN_F_A,Fragenkatalog) != NULL){
            strncpy_s(Quizfragen->Frage,maxLEN_F_A,Fragenkatalog_stream,maxLEN_F_A); 
            //Antort(en) einlesen
            if (fgets(Fragenkatalog_stream,maxLEN_F_A,Fragenkatalog) != NULL){
                strncpy_s(Quizfragen->Antwort,maxLEN_F_A,Fragenkatalog_stream,maxLEN_F_A); 
                //Addr. und Anzahl erhoehen
                ++Quizfragen;
                ++Anzahl_Datensaetze;
            }          
        }else FileEnd = true;     
    }
    free(Fragenkatalog_stream);
    return Anzahl_Datensaetze;
}
