
#include <stdio.h>

#include "../include/PruefungsQuiz.h"

#include <menue.h>
#include <generator.h>
#include <file_index.h>


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

    //Hauptmenue
    do
    { 
        //Hauptmenue Funktion aufrufen 
        Menue_Auswahl = MENUE(optionen);

        switch (Menue_Auswahl)
        {
        case Exit:
            /* code */
            break;
        case StartQuiz:
            //Fragen vorhanden?
            if (*ptrQuizFragen->Frage){
                
            }else{
                fprintf(stderr,"Noch keine Quiz-Fragen vorhanden!\nFragen laden oder ueber Generator erstellen.\n");
            }
            break;
        case RandomQuestions:
            /* code */
            break;
        case LoadQuestions:
            if (Index_Auslesen() != NULL)
            {
                printf(":: %s",Index_Auslesen());
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