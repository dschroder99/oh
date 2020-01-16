#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define clear system("@cls||clear");


void plansza(int tab[][10], char* x)
{
int i,y;
printf("%s: 0 1 2 3 4 5 6 7 8 9\n", x);
printf("   ----------------------\n");
    for (i=0; i<=9; ++i)
    {
        printf("%d | ", i);
        for (y=0; y<=9; ++y)
        {
            printf("%d ", tab[i][y]);
            if (y == 9)
            {
                printf("|\n");
            }
            
        }
    }
printf("  ----------------------\n\n");
}
//--------do plansz do wyswietlania-------
void planszatest(char tab[][10], char* x)
{
int i,y;
printf("%s: 0 1 2 3 4 5 6 7 8 9\n", x);
printf("   ----------------------\n");
    for (i=0; i<=9; ++i)
    {
        printf("%d | ", i);
        for (y=0; y<=9; ++y)
        {
            printf("%c ", tab[i][y]);
            if (y == 9)
            {
                printf("|\n");
            }
            
        }
    }
printf("  ----------------------\n\n");
}

int D1, D2, D3, D4;
int M1, M2, M3, M4;
int W1, W2, W3, W4;
int N1, N2, N3, N4;
int tmp;

void litera(int (*x), int (*y))
{
    int che=0;
    while (che!=1)
    {
        if (isdigit(*(x)) == 1 || isdigit(*(y)) == 1)
            {
            che=1;
            }
        else
            {
            printf("To jest litera\n");
            printf("Spróbuj jeszcze raz: ");
            scanf("%d %d", *(&x), *(&y));
            }
    }
}
//--------czy nie jest poza plansza----------
int range(int (*x), int (*y), int (*tab)[10][10])
{
    // litera(x, y);
   int total = sizeof(*tab);
   int col = sizeof((*tab)[0]);
   int row = total / col;

    if (*(x) >= 0 && *(x) < col && *(y) >= 0 && *(y) < row)
{
    return 1;
}
    else 
{
    printf("To jest poza planszą!:\n");
    printf("Spróbuj jeszcze raz: ");
    scanf("%d %d", *(&x), *(&y));
}
    
}
//---------czy juz tu czegos nie ma-----------
int check(int (*x), int (*y), int (*tab)[10][10], int i)
{
    int count = 0;
    while(count != 1)
    {
    if ((*tab)[*(x)][*(y)] == 0)
    {
        ++count;
    }
    else 
    {
        printf("ups, tam juz cos ukryles\n");
        printf("Sprobuj jeszcze raz: ");
        scanf("%d %d", *(&x), *(&y));
    }
    }
    (*tab)[*(x)][*(y)] = i;
    return 1;
}
//------------------------dostepne pola, dla jednego horkruksa------------------------
int checknxt(int (*x), int (*y), int (*tab)[10][10], int arr[][10], char* n, int i, int p)
{
    int op1, op2, op3, op4;
    loop:printf("\nMożliwe opcje to: \n");
    if ((*tab)[*(x)][*(y)+1] == 0 && *(x)>=0 && *(x)<=9 && *(y)+1>=0 && *(y)+1<=9)
    {
        printf("1. %d %d\n", *(x), *(y)+1);
        op1=1;
    }
    else 
    {
        printf("1. Pole: %d %d jest niedostępne\n", *(x), *(y)+1);
        op1=0;
    }
    if ((*tab)[*(x)][*(y)-1] == 0 && *(x)>=0 && *(x)<=9 && *(y)-1>=0 && *(y)-1<=9)
    {
        printf("2. %d %d\n", *(x), *(y)-1);
        op2=1;
    }
    else 
    {
        printf("2. Pole: %d %d jest niedostępne\n", *(x), *(y)-1);
        op2=0;
    } 
    if ((*tab)[*(x)+1][*(y)] == 0 && *(x)+1>=0 && *(x)+1<=9 && *(y)>=0 && *(y)<=9)
    {
        printf("3. %d %d\n", *(x)+1, *(y));
        op3=1;
    } 
    else 
    {
        printf("3. Pole: %d %d jest niedostępne\n", *(x)+1, *(y));
        op3=0;
    }
    if ((*tab)[*(x)-1][*(y)] == 0 && *(x)-1>=0 && *(x)-1<=9 && *(y)>=0 && *(y)<=9)
    {
        printf("4. %d %d\n", *(x)-1, *(y));
        op4=1;
    } 
    else 
    {
        printf("4. Pole: %d %d jest niedostępne\n", *(x)-1, *(y));
        op4=0;
    }
    again:printf("\nJaki jest Twój wybór: ");
    scanf("%d", &tmp);
    while (tmp<=0 || tmp > 4)
{
    printf("Tak nie można:(\n");
    printf("Spróbuj jeszcze raz: ");
    scanf("%d", &tmp);
}
    switch(tmp) 
{
    case 1:
    if (op1 == 0){
        goto loop;
    } else {}
        (*tab)[*(x)][*(y)+1] = p;
        break;
    case 2:
    if (op2 == 0){
        goto loop;
    }
        (*tab)[*(x)][*(y)-1] = p;
        break;
    case 3:
    if (op3 == 0){
        goto loop;
    }
        (*tab)[*(x)+1][*(y)] = p;
        break;
    case 4:
    if (op4 == 0){
        goto loop;
    }
        (*tab)[*(x)-1][*(y)] = p;
        break;
}
    int licz = i;
    if (licz>1)
    {
    if (tmp == 1)
    {
        *(y)+=1;
    }
    if (tmp == 2)
    {
        *(y)-=1;
    }
    if (tmp == 3)
    {
        *(x)+=1;
    }
    if (tmp == 4)
    {
        *(x)-=1;
    }
    plansza(arr, n);
    --i;
    goto loop;
    }
    return 1;
}
//------------sprawdzenie koordynatow-------------
int sprawdz(int (*x), int (*y), int (*tab)[10][10])
{
    range(x, y, tab);
    int count = 0;
    while (count != 1)
    {
    if ((*tab)[*(x)][*(y)] == 0)
    {
        printf("Może następnym razem się uda \n");
        (*tab)[*(x)][*(y)] = 5;
        ++count;
    }
    else if ((*tab)[*(x)][*(y)] == 5 || (*tab)[*(x)][*(y)] == 9)
    {
        printf("Tam już szukałeś!\n");
        printf("Spróbuj jeszcze raz: ");
        scanf("%d %d", *(&x), *(&y));
    }
    else 
    {
        printf("Avada Kedavra! Nieźle!\n");
        (*tab)[*(x)][*(y)] = 9;
        ++count;
    }
    }
    
}
//---------------plansze pogladowe-----------------------
int tabtest(int (*x), int (*y), int (*tab)[10][10], char (*test)[10][10])
{

    if ((*tab)[*(x)][*(y)] == 5)
    {
        (*test)[*(x)][*(y)] = '!';
    }
    else if ((*tab)[*(x)][*(y)] == 9)
    {
        (*test)[*(x)][*(y)] = 'X';
    } 
}
//-----czy ktos juz wygral------
int czykoniec(int (*tab)[10][10])
{
    int j,k;

    for (j=0; j<10; ++j)
    {
        for (k=0; k<10; ++k)
        {
            if ((*tab)[j][k] == 1 || (*tab)[j][k] == 2 || (*tab)[j][k] == 3 || (*tab)[j][k] == 4)
            {
                return 1;
            }
        }
    }
}
//-----------dokonczenie planszy pogladowej----------
void koniec(int (*tab)[10][10], char (*test)[10][10])
{
    int i,j;
        for (i=0; i<=9; ++i)
    {
        for (j=0; j<=9; ++j)
        {
            if ((*tab)[i][j] == 1)
            {
                (*test)[i][j] = 'N';
            }
            else if ((*tab)[i][j] == 2)
            {
                (*test)[i][j] = 'M';
            }
            else if ((*tab)[i][j] == 3)
            {
                (*test)[i][j] = 'W';
            }
            else if ((*tab)[i][j] == 4)
            {
                (*test)[i][j] = 'N';
            }
        }
    }
    } 

void plansza1()
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
//pogladowa dla 1. gracza
char tab3[10][10];
    for (i=0; i<=9; ++i)
    {
        for (y=0; y<=9; ++y)
        {
            tab3[i][y] = '?';
        }
    }
// --------------------PLAYER 2-----------------------------
int tab2[10][10];
    for (i=0; i<=9; ++i)
    {
        for (y=0; y<=9; ++y)
        {
            tab2[i][y] = 0;
        }
    }
//pogladowa dla 2. gracza
char tab4[10][10];
    for (i=0; i<=9; ++i)
    {
        for (y=0; y<=9; ++y)
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

//w kolejnosci: koordynaty x2, tablica, tablica do wys, naz.tab., odleglosc od koordynatow, oznaczenie
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
printf("Zacznijmy od Dziennika, jego poziom wytrzymałości wynosi zaledwie 1\n");

plansza(tab2, "P2");
printf("Podaj proszę koordynaty: ");
scanf("%d %d", &D3, &D4);
range(&D3, &D4, &tab2);
check(&D3, &D4, &tab2, 1);

clear
plansza(tab2, "P2");
printf("Czas na Medalion, posiada on już 2. punkty wytrzymałości\n");
printf("Podaj proszę koordynaty: ");

scanf("%d %d", &M3, &M4);
range(&M3, &M4, &tab2);
check(&M3, &M4, &tab2, 2);

plansza(tab2, "P2");
printf("Ten przedmiot jest silniejszy od poprzedniego\n"
    "Dlatego potrzebne będzie rozmieszczenie kolejnej części\n");

//w kolejnosci: koordynaty x2, tablica, odleglosc od koordynatow, oznaczenie
checknxt(&M3, &M4, &tab2, tab2, "P2", 1, 2);
clear
plansza(tab2, "P2");

printf("Dobra robota! Jeszcze tylko dwa przedmioty\n"
"Czas na Węża!\nCzy jest to wielki i mistyczny gad,\n"
"czy może taki zwykły, ogrodowy?\n"
"Oby to nie była tylko iluzja w takim wypadku\n");
printf("A miejscem jego ukrycia będzie: ");
scanf("%d %d", &W3, &W4);
range(&W3, &W4, &tab2);
check(&W3, &W4, &tab2, 3);

plansza(tab2, "P2");
printf("Wytrzymałość tego węża wynosi 3.\n"
"Pomyśl nad następnym ruchem\n");

checknxt(&W3, &W4, &tab2, tab2, "P2", 2, 3);
clear
plansza(tab2, "P2");


printf("Będziesz miał teraz do dyspozycji coś,\n"
"czego nawet my, czarodzieje, nie potrafimy rozgryżć\n"
"ponoć mugole zwą to: Nokia 3310\n"
"Zastanów się dobrze: ");
scanf("%d %d", &N3, &N4);
range(&N3, &N4, &tab2);
check(&N3, &N4, &tab2, 4);

plansza(tab2, "P2");
printf("Jest to niezwykle potężne, dlatego też\n"
"będzie wymagało trochę więcej pracy\n");

checknxt(&N3, &N4, &tab2, tab2, "P2", 3, 4);

clear
plansza(tab2, "P2");
sleep(2);
clear

printf("Wspaniale, możemy rozpoczynać!\n");

    //------------WPROWADZANIE DANYCH-----------------

     int f, g, czyk = 0;
     while (czyk != 1)
     {
        if (czykoniec(&tab1) == 1)
        {
            getchar();
            clear
            planszatest(tab4, "P2");
            printf("Ruch P1\n");
            printf("Podaj proszę koordynaty: ");
            scanf("%d %d", &f, &g);
            sprawdz(&f, &g, &tab2);
            tabtest(&f, &g, &tab2, &tab4);
            printf("\n");
            getchar();
        }
        else 
        {
            clear
            printf("Gratulacje P2!\n");
            printf("Jesteśmy Ci bardzo wdzięczni \n");
            koniec(&tab1, &tab3);
            planszatest(tab3, "P1");
            printf("PS: Nie wiesz może, co się stało z sową\n, którą wysłaliśmy?\n");
            ++czyk; 
            getchar(); 
        }
        if (czykoniec(&tab2) == 1 && czyk == 0)
        {
            getchar();
            clear
            planszatest(tab3, "P1");
            printf("Ruch P2\n");
            printf("Podaj proszę koordynaty: ");
            scanf("%d %d", &f, &g);
            sprawdz(&f, &g, &tab1);
            tabtest(&f, &g, &tab1, &tab3);
            printf("\n");
        }
        else 
        {
            printf("Gratulacje P1!\n");
            printf("Jesteśmy Ci bardzo wdzięczni \n");
            koniec(&tab2, &tab4);
            planszatest(tab4, "P2");
            printf("PS: Nie wiesz może, co się stało z sową\n, którą wysłaliśmy?\n");
            ++czyk;
            getchar();
        }
     }

}