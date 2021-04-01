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
    srand(time(NULL));
    //System-Pause um srand() abzuwarten
    if(Windows){
        Sleep(1200);
    }
    else if(Linux){
        sleep(1.2);
    }

    //Variablen fuer Zuweisung zufaelliger Fragen
    unsigned int anzahlFragen = 0, rnd;
    bool firstRND = true;

    //Anzahl an Fragen ermitteln
    while (*origin_Quizfragen->Frage && anzahlFragen <= maxFragen){
        ++anzahlFragen;
        ++origin_Quizfragen;
    }
    //Adresse wieder auf Urspung setzten
    origin_Quizfragen = origin_Quizfragen -anzahlFragen;
    anzahlFragen +offset;

    //Record fuer gemischten Fragen-Katalog anlegen
    Fragenfeld rndQuizFragen[anzahlFragen];
    Fragenfeld *ptr_rndQuizFragen = rndQuizFragen;

    //Array fuer Zahlen die schon ueber srand erzeugt wurden auszuschliessen
    int gesperrteZahlen[anzahlFragen]; 
    int * ptr_gesperrteZahlen = gesperrteZahlen; 
    for (int init = 0; init < anzahlFragen; init++)     //Array mit 0 initialiseren
    {
        gesperrteZahlen[init] = 0;
    }
   
    //Mischen
    for (unsigned int origin = 0; origin < anzahlFragen; origin++)
    {
        if (firstRND){          //Im ersten durchlauf des mischens muss nicht abgeprueft werden ob eine Zahl schon exestiert
            rnd = (unsigned int)(offset+ anzahlFragen * rand() /RAND_MAX);   
            firstRND = false;
        }else{
            //Zufallszahl auf Einzigartigkeit pruefen 
            while(!rndValid(rnd,ptr_gesperrteZahlen))
            {
                rnd = (unsigned int)(offset+ anzahlFragen * rand() /RAND_MAX);  
            }
        }
        gesperrteZahlen[origin] = rnd;
        printf("Lauf %d | Gueltige Zufallszahl = %d\n",origin,gesperrteZahlen[origin]);
        while(getchar() != '\n');
        for (size_t i = 0; i < anzahlFragen; i++)
        {
            printf("nr:%d [%d]\n",i,gesperrteZahlen[i]);
        }
        while(getchar() != '\n');
        //Random-Quiz-Fragen Adresse nach Zufallszahl zuordnen   
        origin_Quizfragen = origin_Quizfragen + (rnd-offset);            //ptr auf zufaellige fragen setzten
        //Frage+Antwort in "neue" Zufalls-Struktur koopieren
        memcpy_s(ptr_rndQuizFragen,sizeof(Fragenfeld),origin_Quizfragen,(1 * sizeof(Fragenfeld)));  // soll = ptr_rndQuizFragen[rnd] = origin_Quizfragen[origin];
        //Reset zur Urspruenglichen Adresse
        origin_Quizfragen = origin_Quizfragen - (rnd-offset); 
        //"neue" Zufalls-Struktur auf's naechste Feld positionieren
        ++ptr_rndQuizFragen;
    }
    printf("ENDE %i \n",anzahlFragen);
    //Addr. wieder auf den beginn setzten
    ptr_rndQuizFragen = ptr_rndQuizFragen -anzahlFragen;
    //Adresse mit 0 besetzten, um Ende des Arrays zu kennzeichenen.
    ptr_rndQuizFragen->Frage[anzahlFragen] = 0;
    ptr_rndQuizFragen->Antwort[anzahlFragen] = 0;

    anzahlFragen = 0;
    while(*ptr_rndQuizFragen->Frage)
    {
        anzahlFragen++;
        printf("NR.: %d\n",anzahlFragen);
        printf("%s\n",ptr_rndQuizFragen->Frage);
        printf("%s\n",ptr_rndQuizFragen->Antwort);
        while(getchar() != '\n');
        ++ptr_rndQuizFragen;
    }

    printf("wENDE %i \n",anzahlFragen);
    //Zeiger auf den "gemischten" Fragen-Katalog zurueckgeben
    return ptr_rndQuizFragen;
}