
#include <stdio.h>

#include "../include/PruefungsQuiz.h"

#include <menue.h>
#include <generator.h>


int main (int argc, char * argv[])
{
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

    Fragenfeld QuizFragen[maxFragen];
    Fragenfeld *ptrQuizFragen = QuizFragen;

    int Menue_Auswahl = -1;
    int Status = -1;

    Status = Fragen_einlesen(ptrQuizFragen);
    for (size_t i = 0; i < maxFragen; i++)
    {
        printf("%i: Frage :> %s \nAntwort :> %s\n",i,(&ptrQuizFragen[i])->Frage,(&ptrQuizFragen[i])->Antwort);
    }
    
    Menue_Auswahl = MENUE(optionen);

    switch (Menue_Auswahl)
    {
    case Exit:
        /* code */
        break;
    case StartQuiz:
        /* code */
        break;
    case RandomQuestions:
        /* code */
        break;
    case LoadQuestions:
        /* code */
        break;
    case Generator:
        break;
    default:
        break;
    }


    return 0;
}