#include <stdio.h>
#include <stdlib.h>

int plik()
{
FILE *f;
char c;
f = fopen("opis.txt", "r");
            if (f == NULL)
            {
                printf("Nie można otworzyć pliku \n");
                exit (0);
            }
            c = fgetc(f);
            while (c != EOF)
            {
                printf ("%c", c);
                c = fgetc(f);
            }
            fclose(f);
            printf("\n");
            return 0;
}