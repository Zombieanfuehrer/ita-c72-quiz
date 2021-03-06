#include "../include/generator.h"
/**
 * @brief User kann eigene Quizfragen und entsprechende Antworten in einen Fragen-Katalog schreiben.
 * Der User gibt Fragen und Antworten in einen Array von Datentyp "Fragenfeld" vor, dieser ist in PruefungsQuiz definiert.
 * Ueber die eingabe einer '0' vom User wird das erzeugen der Quiz-Fragen beendet.
 * Anschliessend wird der Fragenkatalog ueber die Funktion "Fragen_in_datei_speichern()" gespeichert, diese Funktion ist unter save_fragenfeld.c definiert.
 * @param Quizfragen ein Pointer auf ein Datentyp Fragenfeld, respektive ein Array aus Fragenfeld, in welchem die Fragen & Antworten geschrieben werden.
 */
int Fragen_einlesen(Fragenfeld *Quizfragen) 
{ 
    char *sEingabe = calloc(maxLEN_F_A,sizeof(char));
    bool bInputValid = false;
    char cValidInput[1] = {0};
    unsigned int nAnzahlFragen = 0;

    puts("Sie haben den Quiz-Generator gestartet!\n");
    puts("Bitte geben Sie die Quiz-Fragen, so wie die Antworten vor.");
    puts("Beenden Sie die Eingabe mit '0'\n");

    while (nAnzahlFragen <= maxFragen)
    {
        //Quiz-Frage eingeben           
        while(!bInputValid){
            printf("Frage [%d] eingeben [max.%d Zeichen]:> ", nAnzahlFragen+1, maxLEN_F_A);
            fgets(sEingabe, maxLEN_F_A, stdin);
            //Fehlerbehandlung
            if(!sEingabe){fprintf(stderr,"Eingabefehler!\n");};
            //User hat eingabe abgebrochen
            if(sEingabe[0] == '0'){              
                //Anfangsandresse ermitteln fuer param
                Quizfragen = Quizfragen-nAnzahlFragen;
                printf("\n<QUIZFRAGEN-GENERATOR BEENDET>\n");                
                if (Fragen_in_datei_speichern(Quizfragen)){
                    //Aktuelle Fragen in Datei speichern
                    return (nAnzahlFragen-1);
                }
                fprintf(stderr,"Fehler beim Speichern!\n");                
            }
            //Terminator (von fgets eingefuegt) aus string loeschen
            sEingabe[strcspn(sEingabe, "\n")] = 0;
            //Frage korrekt?
            while(true){
                printf("Sie haben <<%s>> eingegeben, ist diese korrekt? ([j] oder [n]) ",sEingabe);
                scanf("%c",&cValidInput);
                while(getchar()!='\n'){}
                //Eingabe in Record eintragen
                if(*cValidInput == 'J' || *cValidInput == 'j'){
                    bInputValid = true;
                    strncpy(Quizfragen->Frage,sEingabe, maxLEN_F_A);
                    break;
                }//Eingabe korrigieren
                else if (*cValidInput == 'N' || *cValidInput == 'n')
                {
                    printf(" Korrektur - "); 
                    break;
                }               
            }                       
        }
        //clear
        bInputValid = false;

        //Quiz-Antwort eingeben
        while (!bInputValid){
            printf("Antwort [%d] eingeben [max.%d Zeichen]:> ", nAnzahlFragen+1, maxLEN_F_A);
            fgets(sEingabe, maxLEN_F_A, stdin);
            //Fehlerbehandlung
            if (!sEingabe){fprintf(stderr,"Eingabefehler!\n");};
            //Terminator (von fgets eingefuegt) aus string loeschen
            sEingabe[strcspn(sEingabe, "\n")] = 0;
            //Frage korrekt?
            while(true){
                printf("Sie haben <<%s>> eingegeben, ist diese korrekt? ([j] oder [n]) ",sEingabe);
                scanf("%c",&cValidInput);
                while(getchar()!='\n'){}
                //Eingabe in Record eintragen
                if(*cValidInput == 'J' || *cValidInput == 'j'){
                    bInputValid = true;
                    strncpy(Quizfragen->Antwort,sEingabe, maxLEN_F_A);
                    break;
                }//Eingabe korrigieren
                else if (*cValidInput == 'N' || *cValidInput == 'n')
                {
                    printf(" Korrektur - "); 
                    break;
                }               
            }                
        }
        ++nAnzahlFragen;
        //Auf naechstem Struktur-Element positionieren
        ++Quizfragen;
        bInputValid = false;
        //Adresse mit 0 besetzten, um Ende des Arrays zu kennzeichenen.
        Quizfragen->Frage[0] = 0;
        Quizfragen->Antwort[0] = 0;
        
    }
}