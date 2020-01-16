#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "plansza.h"


void menu(void);
void menuu(void);
int plik();

int main()
{
    menu();
    int wybor;
    scanf("%d", &wybor);

    wybor:switch(wybor) 
    {
        case 1:
            plansza1();
            break;
        case 2:
            menuu();
            break;
        case 3:
            clear
            plik();
            break;
        case 4:
            printf("byee\n");
            exit(1);
            break;
        default: 
            printf("That wasn't wise, try again\n");
            menu();
            scanf("%d", &wybor);
            goto wybor;
    }
    return 0;
}
