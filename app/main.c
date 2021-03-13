#include <stdio.h>

#include <menue.h>

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
    int ausw = -1;

    ausw = MENUE(optionen);

    printf("1: %d\n",ausw);


    return 0;
}