#include "../include/save_fragenfeld.h"

/**
 * @brief Bestimmten ASCII-Char in String finden und mit dem uebergebenen Param. ersetzten
 *  Gefunden unter https://stackoverflow.com/questions/32496497/standard-function-to-replace-character-or-substring-in-a-char-array/32496721
 * @param str Zeiger auf den zu durchsuchenden/bearbeitenden String
 * @param find Zeichen/Char welches im Sring gefunden und ersetzt werden soll
 * @param replace Zeichen welches anstellelle des als "find" definierten Zeichens/Chars in den String kopiert wird.
 * @return char* Zeiger auf die Adresse des urspruenglichen Strings.
 */
char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

/**
 * @brief der Uhrzeitteil des Zeitstempel aus dem von asctime() zurueckgegebenen String wird geloescht.
 * @param strASCTIME Zeiger auf einen String "Thu Mar 26 06:00:48 2009 \0" der bearbeitet werden soll.
 * @return char* Zeiger auf den Ursprungsstring umformatiert "Thu Mar 26 2009 \0"
 */
char* Zeit_Stempel_loeschen(char* strASCTIME){
    unsigned int HHMMSS = 0;

    for (unsigned int position = 0; position < strlen(strASCTIME); position++)
    {
        //Auf Zeitstempel von asctime() positionieren und gegen Jahreszahl ersetzten. 
        if(position >= (ASCTIME_TIME_STAMP_POS+ASCTIME_TIME_STAMP_LEN)){
            strASCTIME[ASCTIME_TIME_STAMP_POS+HHMMSS] = strASCTIME[position];
            ++HHMMSS;
        }   
    }
    //Neues String-Ende definieren
    strASCTIME[ASCTIME_TIME_STAMP_POS+HHMMSS] = 0;
    //Leerzeichen gegen Unterstriche ersetzten
    strASCTIME = replace_char(strASCTIME,' ','_');
    return strASCTIME;   
}

/**
 * @brief Fragen_in_datei_speichern speichert den uebergebenen Fragen-Katalog in eine .txt Datei.
 * Per default ist der Dateiname der durch Zeit_Stempel_loeschen() bearbeitete asctime()-String, der User kann aber auch einen eigenen Dateinamen vorgeben.
 * Anschliessend wird mit Index_Erweitern(Dateiname) die Index.dat erzeugt o. erweitert um die Datei zu einem spaeteren Zeitpunkt laden zu koennen.
 * @param Quizfragen Zeiger auf eine Adresse vom Datentyp Fragenfeld bzw. Array der Fragen-Katalog.
 * @return true Datei erfolgreich gespeichert.
 * @return false Datei konnte nicht gespeichert werden, details stderr.
 */
bool Fragen_in_datei_speichern(Fragenfeld *Quizfragen)
{
    FILE * save_stream;
    
    time_t sysTime;
    struct tm *sysTimeStruct;    
    
    char cValidInput[1] = {0};

    //Fragenkatalog ist nicht leer, aktuell erstes feld
    if (*Quizfragen->Frage){
        
        //Default Dateiname
        //Systemzeit auslesen fuer Dateinamen-Bestimmung
        sysTime = time(NULL);
        sysTimeStruct = localtime(&sysTime);
        //Speicher fuer Dateiname reservieren
        char * Dateiname = malloc(sizeof(char) * (LEN_ASCII_TIME+ strlen(text_dat)));
        if(Dateiname == NULL){
            perror(NIO_SPEICHER);
        }
        //Dateiname aus aktueller Zeit generieren
        strncpy_s(Dateiname,LEN_ASCII_TIME,asctime(sysTimeStruct),LEN_ASCII_TIME-1); //strncpy da das Zeilenumbruchszeichen im letzten Byte nicht kopoiert werden soll
        //Dateiendung bzw. Datentyp anhaengen
        strncpy_s(Dateiname+strlen(Dateiname),(LEN_ASCII_TIME + strlen(text_dat)),text_dat,strlen(text_dat));       
        //Dateinamen formatieren (keine Leerzeichen, keinen Uhrzeit Stempel)
        Dateiname = Zeit_Stempel_loeschen(Dateiname);
        
        //Benutzer definierter Dateiname
        printf("Der aktuelle Fragen-Katalog wird unter <%s> gespeichert, Speichernamen aendern? ([j] oder [beliebige Taste]",Dateiname);
        scanf("%c",&cValidInput);
        while(getchar()!='\n'){}
        if (*cValidInput == 'j' || *cValidInput == 'J'){
            printf("\nSpeichernamen eingeben [max. 28 Zeichen]: ");
            //Neuen Speichernamen einlesen
            fgets(Dateiname, 28, stdin);
            //String formatieren
            Dateiname[strcspn(Dateiname, "\n")] = 0;        //Terminator entfernen
            Dateiname = replace_char(Dateiname,' ','_');    //Leerzeichen gegen Unterstriche ersetzten
            strncpy_s(Dateiname+(strlen(Dateiname)),strlen(Dateiname),text_dat,strlen(text_dat));   //Datei-Endung anhaengen
        }
        
        //Datei schreiben oeffnen, wird ueberschrieben wenn diese schon existiert. if fragt ob filepointer zurueck gegeben wird      
        save_stream = fopen(Dateiname,"w+");
        if(save_stream == NULL){
            perror("Text-Datei zum speichern des aktuellen Fragen-Katalogs konnte nicht angelegt werden!\n");    
        }
        else{
            //Kopfzeile und Erstellungsdatum in Datei schreiben
            fprintf(save_stream,"Quizfragen-Katalog vom %s",asctime(sysTimeStruct)+4);
            while (*Quizfragen->Frage)
            {  
                fprintf(save_stream,"%s\n",Quizfragen->Frage);
                fprintf(save_stream,"%s\n",Quizfragen->Antwort);
                ++Quizfragen;
            }
            //Dateistream schliessen
            if(fclose(save_stream) == 0){
                Index_Erweitern(Dateiname);
                printf("Fragen-Katalog in %s gespeichert.\n",Dateiname);          
                free(Dateiname);        //Speicher wieder freigeben
                return true; 
            }else{
                perror("Dateiname konnte nicht geschlossen werden!");
            }
              
   
        } 
        free(Dateiname);        //Speicher wieder freigeben  
    }
    return false;   
}