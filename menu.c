#include <stdio.h>
#include <stdlib.h>
#include "plansza.h"
#include "planszacomp.h"
#include "planszacomp1.h"

void menu(void)
{
printf("\n                        MENU\n");
for (int star=0; star<=25; ++star)
{
    printf("* ");
}

printf("\n");
int count=0;
int napis=0;
for (int star=0; count<=4; ++star)
{
    if (star == 49)
    {
        printf("*\n");
        star=0;
        ++count;
    }
    if (napis == 0 && count == 1)
    {
        printf("*                   1.Player vs Player            *\n");
        ++napis;
    }
    if (napis == 1 && count == 2)
    {
        printf("*                   2.Player vs Computer          *\n");
        ++napis;
    }
    if (napis == 2 && count == 3)
    {
        printf("*                   3. opis                       *\n");
        ++napis;
    }
    if (napis == 3 && count == 4)
    {
        printf("*                   4. exit                       *\n");
        ++napis;
    }
    if (star == 0)
    {
        printf("*");
    }
    
    printf(" ");
    
}

for (int star=0; star<=24; ++star)
{
    printf("* ");
}
printf("\nChose wisely: ");

}

void menu1(void)
{
printf("\n                        MENU\n");
for (int star=0; star<=25; ++star)
{
    printf("* ");
}

printf("\n");
int count=0;
int napis=0;
for (int star=0; count<=4; ++star)
{
    if (star == 49)
    {
        printf("*\n");
        star=0;
        ++count;
    }
    if (napis == 0 && count == 1)
    {
        printf("*                   1.Easy Peasy                  *\n");
        ++napis;
    }
    if (napis == 1 && count == 2)
    {
        printf("*                   2.Not Easy Peasy              *\n");
        ++napis;
    }
    if (napis == 2 && count == 3)
    {
        printf("*                   3. Definitely Not Easy Peasy  *\n");
        ++napis;
    }
    if (napis == 3 && count == 4)
    {
        printf("*                   4. exit                       *\n");
        ++napis;
    }
    if (star == 0)
    {
        printf("*");
    }
    
    printf(" ");
    
}

for (int star=0; star<=24; ++star)
{
    printf("* ");
}
printf("\nChose wisely: ");

}

void planszawyb2(void);
void menuu (void)
{
    
    menu1();
    int wybor1;
    scanf("%d", &wybor1);

    wybor1:switch(wybor1) 
    {
        case 1:
            plansza2();
            break;
        case 2:
            planszawyb1();
            break;
        case 3:
            clear
            planszawyb2();
            break;
        case 4:
            printf("byee\n");
            exit(1);
            break;
        default: 
            printf("That wasn't wise, try again\n");
            menu1();
            scanf("%d", &wybor1);
            goto wybor1;
    }
}