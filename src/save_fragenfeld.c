#include "../include/save_fragenfeld.h"

/**
 * @brief Bestimmten ASCII-Char in String finden und mit dem uebergebenen Param. ersetzten
 *  Gefunden unter https://stackoverflow.com/questions/32496497/standard-function-to-replace-character-or-substring-in-a-char-array/32496721
 * @param str 
 * @param find 
 * @param replace 
 * @return char* 
 */
char* replace_char(char* str, char find, char replace){
    char *current_pos = strchr(str,find);
    while (current_pos) {
        *current_pos = replace;
        current_pos = strchr(current_pos,find);
    }
    return str;
}

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

bool Fragen_in_datei_speichern(Fragenfeld *Quizfragen)
{
    FILE * save_stream;
    
    time_t sysTime;
    struct tm *sysTimeStruct;    

    //Fragenkatalog ist nicht leer, aktuell erstes feld
    if (*Quizfragen->Frage){
        
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
        //Datei schreiben oeffnen, wird ueberschrieben wenn diese schon existiert. if fragt ob filepointer zurueck gegeben wird      
        save_stream = fopen(Dateiname,"w+");
        if(save_stream == NULL){
            perror("Text-Datei zum speichern des aktuellen Fragen-Katalogs konnte nicht angelegt werden!\n");    
        }
        else{
            
            while (*Quizfragen->Frage)
            {
                fprintf(save_stream,"Quizfragen-Katalog vom %s",asctime(sysTimeStruct)+4);
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