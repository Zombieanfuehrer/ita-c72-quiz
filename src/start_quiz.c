#include "../include/start_quiz.h"

/**
 * @brief rndValid vergleicht eine uebergebene Ganzzahl mit einem uebergebene Feld an Ganzzahlen.
 * Die groesse des uebergebnen Feldes kann eine varaible Laenge haben. Ist die uebergebene Zahl nicht in dem Feld vorhanden, 
 * und somit einzigartig, ist die Funktion == true.
 * @param gewuenschteZahl int Wert der zu pruefenden Ganzzahl
 * @param genutzeZufallszahlen Adresse eines Arrays von diversen Ganzzahlen
 * @return true Ganzzahl ist nicht im Array vorhanden
 * @return false Ganzzahl ist schon im Array existent
 */
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
/**
 * @brief Stellt dem User die Fragen aus dem Quizfragen-Katalog und prueft die Antworten.
 * Der Quizfragen-Katalog wird als Adresse auf einen Datentyp "Fragenfeld" uebergeben. Dieser Datentyp ist unter <PruefungsQuiz> definiert.
 * Die Anzahl der gestellten Fragen, der korrekt beantworteten sowie die Anzahl der insgesammten Fragen des Quizfragen-Katalog werden ermittelt.
 * Am Ende der Funktion wird aus diesen Werten der Prozentuale Satz an korrekt beantworteten Fragen zurueckgegeben.
 * @param Quizfragen Pointer auf ein Array vom Datentyp Fragenfeld.
 * @return float Prozentuale Satz an korrekt beantworteten Fragen.
 */
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

/**
 * @brief mixQuestions schreibt zufaellig die Inhalte (.Frage + .Antwort) eines Fragenfeld Arrays in ein anderes Array vom Typ Fragenfeld.
 * Die "Faecher" des neuen Fragenfeld Arrays 'mixed_Quizfragen' werden mit zufaelligen, "Inhalten" des originalen Fragenfeld Arrays 'origin_Quizfragen' gefuellt.
 * Dabei wird darauf geachtet das diese Inhalte nur einmalig kopiert werden, aber jeder Inhalt des originalen Fragenfelds. Daraus resultiert ein "mischen".
 * Um diese Einzigartigkeit zu gewaehrleisten ist die Funktion rndValid(, siehe Definition oben, essenziell. 
 * @param mixed_Quizfragen Eine Adresse auf ein Array von Datentyp Fragenfeld, in das die gemischten Fragen geschrieben werden.
 * @param origin_Quizfragen Eine Adresse auf ein Array vom Datentyp Fragenfeld, in dem die urspruenglichen Fragen stehen.
 */
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
        printf("DEBUG: %s",origin_Quizfragen+(rnd-offset));
        memcpy_s(mixed_Quizfragen,(1* sizeof(Fragenfeld)),(origin_Quizfragen+(rnd-offset)),(1 * sizeof(Fragenfeld)));      //Frage+Antwort in "neue" Zufalls-Struktur koopieren
        ++mixed_Quizfragen;    //"neue" Zufalls-Struktur auf's naechste Feld positionieren
    }
    //Adresse mit 0 besetzten, um Ende des Arrays zu kennzeichenen.
    *mixed_Quizfragen->Frage = 0;
    *mixed_Quizfragen->Antwort = 0;
    //Addr. wieder auf den beginn setzten
    mixed_Quizfragen = mixed_Quizfragen -anzahlFragen;

}