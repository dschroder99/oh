extern void plansza1();
extern int D1, D2, D3, D4;
extern int M1, M2, M3, M4;
extern int W1, W2, W3, W4;
extern int N1, N2, N3, N4;
extern int tmp;
extern int range(int (*x), int (*y), int (*tab)[10][10]);
extern int check(int (*x), int (*y), int (*tab)[10][10], int i);
extern int checknxt(int (*x), int (*y), int (*tab)[10][10], int arr[][10], char* n, int i, int p);
extern void plansza(int tab[][10], char* x);
extern int czykoniec(int (*tab)[10][10]);
extern int tabtest(int (*x), int (*y), int (*tab)[10][10], char (*test)[10][10]);
extern void planszatest(char tab[][10], char* x);
extern void koniec(int (*tab)[10][10], char (*test)[10][10]);
extern int sprawdz(int (*x), int (*y), int (*tab)[10][10]);
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define clear system("@cls||clear");