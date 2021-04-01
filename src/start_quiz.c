#include "../include/start_quiz.h"

bool rndValid(int gewuenschteZahl ,int genutzeZufallszahlen[])
{
    bool cmp = true;
    while (*genutzeZufallszahlen)
    {
        printf("rnd =%d, savedrnd= %d\n",gewuenschteZahl,*genutzeZufallszahlen);
        if (gewuenschteZahl == *genutzeZufallszahlen){
            cmp = false;
        }
        ++genutzeZufallszahlen;
    }
    return cmp;
}

float start(Fragenfeld *Quizfragen)
{
    int Gestellt = 0, korrekt = 0;
    char sEingabe[maxLEN_F_A] = {0};
    char sNaechsteFrage;
    bool usrCancel = false;

    while(*Quizfragen->Frage && !usrCancel)                         //Fragen stellen bis User beendet oder keine Fragen mehr vorhanden
    {
        //Frage ausgeben
        printf("Frage: %s\n",Quizfragen->Frage);
        ++Gestellt;                                                 //Frage wurde gestellt fuer %-Auswertung
        //User Anwort abwarten
        fgets(sEingabe, maxLEN_F_A, stdin);
        //User Antwort korrekt?
        if(stricmp(Quizfragen->Antwort,sEingabe) == Korrekt){       //stricmp  ist nicht case sensitive (groß / klein - Schreibung)
            printf("Richtig!\n");
            ++korrekt;                                              //Frage korrekt beantwortet fuer %-Auswertung             
        }else printf("Falsch! Korrekte Loesung waere: %s gewesen.\n",Quizfragen->Antwort);
        //Weitere Frage stellen?
        do{
            printf("Moechten Sie noch eine Frage (J/N)? :");
            scanf("%c",&sNaechsteFrage);
            printf("\n");
            if (sNaechsteFrage == 'N' || sNaechsteFrage == 'n'){
                usrCancel = true;              
            }else ++Quizfragen;
        }while(sNaechsteFrage != 'J' && sNaechsteFrage != 'j' && sNaechsteFrage != 'N' && sNaechsteFrage != 'n'); 
        sNaechsteFrage = 0;                                         //Reset 
        fflush(stdin);                                              //stdin stream buffer leeren
    }
    //Auswertung
    return roundf(((Gestellt/korrekt) * -1) *10.0f)/10.0f;
}

Fragenfeld * mixQuestions(Fragenfeld *origin_Quizfragen)
{
    //srand initialieren
    time_t srandSeed;
    srand((unsigned)time(&srandSeed));

    unsigned int anzahlFragen = 0;
    bool RND_VALID = false;

    //Anzahl an Fragen ermitteln
    while (*origin_Quizfragen->Frage && anzahlFragen <= maxFragen){
        ++anzahlFragen;
        ++origin_Quizfragen;
    }
    //Adresse wieder auf Urspung setzten
    origin_Quizfragen = origin_Quizfragen -anzahlFragen;

    //Record fuer gemischten Fragen-Katalog anlegen
    Fragenfeld rndQuizFragen[anzahlFragen];
    Fragenfeld *ptr_rndQuizFragen = rndQuizFragen;

    //Array fuer Zahlen die schon ueber srand erzeugt wurden auszuschliessen
    int gesperrteZahlen[anzahlFragen]; 
    memset(gesperrteZahlen,0,sizeof(int) * anzahlFragen);       //Array mit 0 initialiseren

    //Mischen
    for (unsigned int origin = 0; origin < anzahlFragen; origin++)
    {
        //Zufallszahl nach Anzahl der Fragen erzeugen und pruefen
        unsigned int rnd = origin + (rand()/(RAND_MAX/(anzahlFragen-origin) +1));       
        RND_VALID = rndValid(rnd,gesperrteZahlen); 
        while(!RND_VALID)
        {
            unsigned int rnd = origin + (rand()/(RAND_MAX/(anzahlFragen-origin) +1)); 
            printf("geno = %d\n", rnd);
            RND_VALID = rndValid(rnd,gesperrteZahlen); 
        }
        gesperrteZahlen[origin] = rnd;
      
        //RandomQuizFragen Adresse nach Zufallszahl zuordnen
        //ptr_rndQuizFragen = ptr_rndQuizFragen + rnd;
        memcpy_s(ptr_rndQuizFragen,sizeof(Fragenfeld),origin_Quizfragen,(1 * sizeof(Fragenfeld)));  // soll = ptr_rndQuizFragen[rnd] = origin_Quizfragen[origin];
        //ptr_rndQuizFragen = ptr_rndQuizFragen - rnd;
        ++ptr_rndQuizFragen;
        ++origin_Quizfragen;
        //reset
        RND_VALID = false;
    }
    //Addr. wieder auf den beginn setzten
    ptr_rndQuizFragen = ptr_rndQuizFragen -anzahlFragen;

    //Zeiger auf den "gemischten" Fragen-Katalog zurueckgeben
    return ptr_rndQuizFragen;
}