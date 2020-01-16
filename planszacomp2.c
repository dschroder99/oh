#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> 
#include "plansza.h"
#include "planszacomp1.h"

void planszawyb2()
{
 int i,y;
// --------------------PLAYER 1-----------------------------
    int tab1[10][10];
    for (i=0; i<=9; ++i)
    {
        for (y=0; y<=9; ++y)
        {
            tab1[i][y] = 0;
        }
    }

char tab3[10][10];
    for (i=0; i<=9; ++i)
    {
        for (y=0; y<=9; ++y)
        {
            tab3[i][y] = '?';
        }
    }
// --------------------PLAYER 2-----------------------------
int tab2[15][15];
    for (i=0; i<=14; ++i)
    {
        for (y=0; y<=14; ++y)
        {
            tab2[i][y] = 0;
        }
    }

char tab4[15][15];
    for (i=0; i<=14; ++i)
    {
        for (y=0; y<=14; ++y)
        {
            tab4[i][y] = '?';
        }
    }
clear

printf("Szybko, czas na ukrycie Twoich horkruksów!\n");

//----------------------PLANSZA PIERWSZEGO GRACZA-------------------
printf("Zacznijmy od Dziennika, jego poziom wytrzymałości wynosi zaledwie 1\n");

plansza(tab1, "P1");
printf("Podaj proszę koordynaty: ");
scanf("%d %d", &D1, &D2);
range(&D1, &D2, &tab1);
check(&D1, &D2, &tab1, 1);

clear
plansza(tab1, "P1");
printf("Czas na Medalion, posiada on już 2. punkty wytrzymałości\n");
printf("Podaj proszę koordynaty: ");

scanf("%d %d", &M1, &M2);
range(&M1, &M2, &tab1);
check(&M1, &M2, &tab1, 2);

plansza(tab1, "P1");
printf("Ten przedmiot jest silniejszy od poprzedniego\n"
    "Dlatego potrzebne będzie rozmieszczenie kolejnej części\n");

//w kolejnosci: koordynaty x2, tablica, odleglosc od koordynatow, oznaczenie
checknxt(&M1, &M2, &tab1, tab1, "P1", 1, 2);
clear
plansza(tab1, "P1");

printf("Dobra robota! Jeszcze tylko dwa przedmioty\n"
"Czas na Węża!\nCzy jest to wielki i mistyczny gad,\n"
"czy może taki zwykły, ogrodowy?\n"
"Oby to nie była tylko iluzja w takim wypadku\n");
printf("A miejscem jego ukrycia będzie: ");
scanf("%d %d", &W1, &W2);
range(&W1, &W2, &tab1);
check(&W1, &W2, &tab1, 3);

plansza(tab1, "P1");
printf("Wytrzymałość tego węża wynosi 3.\n"
"Pomyśl nad następnym ruchem\n");

checknxt(&W1, &W2, &tab1, tab1, "P1", 2, 3);
clear
plansza(tab1, "P1");


printf("Będziesz miał teraz do dyspozycji coś,\n"
"czego nawet my, czarodzieje, nie potrafimy rozgryżć\n"
"ponoć mugole zwą to: Nokia 3310\n"
"Zastanów się dobrze: ");
scanf("%d %d", &N1, &N2);
range(&N1, &N2, &tab1);
check(&N1, &N2, &tab1, 4);

plansza(tab1, "P1");
printf("Jest to niezwykle potężne, dlatego też\n"
"będzie wymagało trochę więcej pracy\n");

checknxt(&N1, &N2, &tab1, tab1, "P1", 3, 4);
clear
plansza(tab1, "P1");

printf("Wspaniale, teraz pora na Twojego przeciwnika\n");

//----------------------PLANSZA DRUGIEGO GRACZA-------------------
printf("Loading...\n");
sleep(3); 
clear
srand(time(0)); 

D3 = rand() % 14 + 0;
D4 = rand() % 14 + 0;

checkcomp1(&D3, &D4, &tab2, 1);

M3 = rand() % 14 + 0;
M4 = rand() % 14 + 0;

checkcomp1(&M3, &M4, &tab2, 2);

//w kolejnosci: koordynaty x2, tablica, odleglosc od koordynatow, oznaczenie
checknxtcomp1(&M3, &M4, &tab2, 1, 2);

W3 = rand() % 14 + 0;
W4 = rand() % 14 + 0;

checkcomp1(&W3, &W4, &tab2, 3);
checknxtcomp1(&W3, &W4, &tab2, 2, 3);


N3 = rand() % 14 + 0;
N4 = rand() % 14 + 0;

checkcomp1(&N3, &N4, &tab2, 4);
checknxtcomp1(&N3, &N4, &tab2, 3, 4);

clear
// plansza(tab1, "P1");
// plansza(tab2, "P2");
printf("Wspaniale, możemy rozpoczynać!\n");

//------------WPROWADZANIE DANYCH-----------------

     int f, g, f1, g1, czyk = 0;
     while (czyk != 1)
     {
        if (czykoniec(&tab1) == 1)
        {
            getchar();
            clear
            planszatestcomp(tab4, "P2");
            printf("Ruch P1\n");
            printf("Podaj proszę koordynaty: ");
            scanf("%d %d", &f, &g);
            sprawdzxd(&f, &g, &tab2);
            tabtestcomp(&f, &g, &tab2, &tab4);
            printf("\n");
            getchar();
        }
        else 
        {
            clear
            printf("Tym razem się nie udało:v \n");
            printf("Może następnym razem będzie lepiej \n");
            konieccomp(&tab2, &tab4);
            planszatest(tab3, "P1");
            ++czyk; 
            getchar();
        }
        if (czykonieccomp(&tab2) == 1 && czyk == 0)
        {
            getchar();
            clear
            planszatest(tab3, "P1");
            printf("Ruch P2\n");
            f = rand() % 14 + 0;
            g = rand() % 14 + 0;
            f1 = rand() % 14 + 0;
            g1 = rand() % 14 + 0;
            sprawdzcomp1(&f, &g, &tab1);
            tabtest(&f, &g, &tab1, &tab3);
            sprawdzcomp1(&f1, &g1, &tab1);
            tabtest(&f1, &g1, &tab1, &tab3);
            printf("\n");
        }
        else 
        {
            printf("Gratulacje P1!\n");
            printf("Jesteśmy Ci bardzo wdzięczni \n");
            konieccomp(&tab2, &tab4);
            planszatestcomp(tab4, "P2");
            printf("PS: Nie wiesz może, co się stało z sową\n, którą wysłaliśmy?\n");
            ++czyk; 
            getchar(); 
        }
     }

}