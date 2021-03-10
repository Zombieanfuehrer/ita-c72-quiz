#ifndef _PRUEFUNGS_QUIZ_
#define _PRUEFUNGS_QUIZ_

#define maxFragen 200

enum AUSWAHL {
    Ende = 0,
    Quiz,
    ZufallsQuiz, 
    FragenLaden,
    FragenGenerator
};

struct Fragenfeld
{
    char Frage  [81];
    char Antwort[81];
};


#endif // _PRUEFUNGS_QUIZ_
