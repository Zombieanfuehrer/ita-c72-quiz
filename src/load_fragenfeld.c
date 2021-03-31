#include "../include/load_fragenfeld.h"


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
    printf("Auswahl des zu ladenenden Fragen-Katalogs uber die entsprechende Nr.\n");
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
    printf("\n--------------------------------------------------------------------\n\n Waehlen Sie:");
    
    //User Eingabe     
    do
    {
        fgets(inputFragen_Katalog, 4, stdin);
        fflush(stdin);
        inputFragen_Katalog[strcspn(inputFragen_Katalog, "\n")] = 0;            //Terminator entfernen
        printf("Wert: = %i\n", atoi(inputFragen_Katalog));
        if (atoi(inputFragen_Katalog)  <= 0 || atoi(inputFragen_Katalog) > Anzahl){
            fprintf(stderr,"Ungueltige Eingabe, bitte Waehlen Sie einen Wert > 0 und <= %d!\n", Anzahl);
        }else inputValid = true;      
    }
    while(!inputValid);
    free(datensaetze_stream);
    printf("Auswahl: = %s\n", ausgeleseneDatensaetze[atoi(inputFragen_Katalog)].Fragen_Katalog);
    strncpy_s(usrAuswahl,file_name_LEN,ausgeleseneDatensaetze[atoi(inputFragen_Katalog)].Fragen_Katalog,file_name_LEN);

    return usrAuswahl;
}
