#include "../include/start_quiz.h"

bool rndValid(int gewuenschteZahl ,int genutzeZufallszahlen[])
{
    bool cmp = true;
    while (*genutzeZufallszahlen)
    {
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
    unsigned int anzahlFragen = 0;

    //Anzahl an Fragen ermitteln
    while (*Quizfragen->Frage && anzahlFragen <= maxFragen){
        printf("[%d] %s\n",anzahlFragen,Quizfragen->Frage);
        ++anzahlFragen;
        ++Quizfragen;
    }
    Quizfragen = Quizfragen - anzahlFragen;

    while(*Quizfragen->Frage && !usrCancel)                         //Fragen stellen bis User beendet oder keine Fragen mehr vorhanden
    {       
        ++Gestellt;                                                 //Frage wurde gestellt fuer %-Auswertung
        printf("Frage %d von %d\n",Gestellt,anzahlFragen);
        //Frage ausgeben
        printf("%s",Quizfragen->Frage);                                                 
        //User Anwort abwarten
        fgets(sEingabe, maxLEN_F_A, stdin);
        //User Antwort korrekt?
        if(stricmp(Quizfragen->Antwort,sEingabe) == Korrekt){       //stricmp  ist nicht case sensitive (groß / klein - Schreibung)
            printf("Richtig!\n");
            ++korrekt;                                              //Frage korrekt beantwortet fuer %-Auswertung             
        }else printf("Falsch! Korrekte Loesung waere: %s gewesen.\n",Quizfragen->Antwort);
        //Weitere Frage stellen?
        if(Gestellt < anzahlFragen){
            do{
                printf("Moechten Sie noch eine Frage (J/N)? :");
                scanf("%c",&sNaechsteFrage);
                printf("\n");
                if (sNaechsteFrage == 'N' || sNaechsteFrage == 'n'){
                    usrCancel = true;              
                }else ++Quizfragen;
            }while(sNaechsteFrage != 'J' && sNaechsteFrage != 'j' && sNaechsteFrage != 'N' && sNaechsteFrage != 'n'); 
            sNaechsteFrage = 0;                                     //Reset 
            fflush(stdin);                                          //stdin stream buffer leeren
        }else break; 
    }
    //Auswertung
    return ((float)korrekt/(float)Gestellt) * Prozentsatz;
}

void mixQuestions(Fragenfeld *mixed_Quizfragen,Fragenfeld *origin_Quizfragen)
{
    //srand initialieren
    srand(time(NULL));
    //System-Pause um srand() abzuwarten
    printf("Warte srand() init ab\n");
    //#Praeprozessoranweisungen fuer sleep() thread pause
    #ifdef _WIN32
        Sleep(2000);
    #endif //_WIN32
    #ifdef linux
        sleep(2.0);
    #endif //UNIX

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
        gesperrteZahlen[origin] = rnd;  //Gueltige Zufallszahl in Sperrliste zuweisen
        //Random-Quiz-Fragen Adresse nach Zufallszahl zuordnen   
        memcpy_s(mixed_Quizfragen,(1* sizeof(Fragenfeld)),(origin_Quizfragen+(rnd-offset)),(1 * sizeof(Fragenfeld)));      //Frage+Antwort in "neue" Zufalls-Struktur koopieren
        ++mixed_Quizfragen;    //"neue" Zufalls-Struktur auf's naechste Feld positionieren
    }
    //Addr. wieder auf den beginn setzten
    mixed_Quizfragen = mixed_Quizfragen -anzahlFragen;
    //Adresse mit 0 besetzten, um Ende des Arrays zu kennzeichenen.
    mixed_Quizfragen->Frage[anzahlFragen] = 0;
    mixed_Quizfragen->Antwort[anzahlFragen] = 0;
}