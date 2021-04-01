#include <stdio.h>

//Projekt Header mit diversen definitionen
#include "../include/PruefungsQuiz.h"

//Projekt Bibliotheken
#include <menue.h>
#include <generator.h>
#include <file_index.h>
#include <load_fragenfeld.h>
#include <start_quiz.h>

/**
 * @brief Pruefungsquiz application
 * 
 * @param argc ohne Funktion
 * @param argv ohne Funktion
 * @return int = 0 Pruefungsquiz vom User beendet
 */
int main (int argc, char * argv[])
{
    //Variablen fuer Menue-Auswahl
    char * Menuepunkte[] = 
    {
        "Exit", 
        "Start-Quiz", 
        "Random-Questions", 
        "Load-Questions", 
        "Generator",
        NULL
    };
    char **optionen = Menuepunkte;
    int Menue_Auswahl = -1;
    int Status = -1;

    //Record fuer Fragen u. Antworten
    Fragenfeld QuizFragen[maxFragen];
    Fragenfeld *ptrQuizFragen = QuizFragen;
    //Record initialisieren
    memset(ptrQuizFragen,0,sizeof(QuizFragen));

    //Variablen fuer d. Laden eines Fragen-Katalogs
    char usrLoadDat[file_name_LEN];
    char * ptr_usrLoad = usrLoadDat;

    //Ergebniss / Quiz-Starten 
    float Prozent = 0.0;

    //Hauptmenue
    do
    {    
        //Hauptmenue Funktion aufrufen 
        Menue_Auswahl = MENUE(optionen);
        printf("\n");
        fflush(stdin);                                  //stdin buffer leeren
        
        switch (Menue_Auswahl)
        {
        case Exit:
            printf("BYE BYE!\n");
            break;
        case StartQuiz:
            //Fragen vorhanden?
            if (*ptrQuizFragen->Frage){
                Prozent = start(ptrQuizFragen);   
                printf("Sie haben %f der Fragen korrekt beantwortet!\n",Prozent); 
            }else{
                fprintf(stderr,"Noch keine Quiz-Fragen vorhanden!\nFragen laden oder ueber Generator erstellen.\n");
            }
            break;
        case RandomQuestions:
            //Fragen vorhanden?
            if (*ptrQuizFragen->Frage){
                Prozent = start(mixQuestions(ptrQuizFragen));  
                printf("Sie haben %f der Fragen korrekt beantwortet!\n",Prozent); 
            }else{
                fprintf(stderr,"Noch keine Quiz-Fragen vorhanden!\nFragen laden oder ueber Generator erstellen.\n");
            }
            break;
        case LoadQuestions:           
            //Abfrage ob gespeicherte Fragen-Kataloge exestieren
            if (Index_Auslesen(ptr_usrLoad) != NULL){
                if (Fragen_Katalog_einlesen(Datei_auswaehlen(ptr_usrLoad),ptrQuizFragen) != error){
                    printf("Fragen-Katalog <%s> wurde geladen!\n\n",ptr_usrLoad);
                }else{
                    printf("<%s> konnte nicht geladen werden!\n\n",ptr_usrLoad);
                }                       
            }else{
                fprintf(stderr,"Keine gespeicherten Fragen-Kataloge vorhanden\n");
            }          
            break;
        case Generator:
            Fragen_einlesen(ptrQuizFragen);
            break;
        default:
            fprintf(stderr,"Eingabe Ungueltig!\n");
            break;
        }
    } while (Menue_Auswahl != 0);

    return 0;
}