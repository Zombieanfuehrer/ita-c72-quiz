#ifndef _PRUEFUNGS_QUIZ_
#define _PRUEFUNGS_QUIZ_

#define maxFragen       200
#define maxLEN_F_A      81
#define error           -1

typedef struct  
{
    char Frage  [maxLEN_F_A];
    char Antwort[maxLEN_F_A];
}Fragenfeld;

enum Menueauswahl{

    Exit = 0,
    StartQuiz, 
    RandomQuestions, 
    LoadQuestions, 
    Generator
    
};

#endif // _PRUEFUNGS_QUIZ_
