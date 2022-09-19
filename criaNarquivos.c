#include <stdio.h>
#include <stdlib.h>
int main()

{
    FILE *f1, *f2;
    int k;

    for (k = 0; k < 2; k++)
    {
        char filename[100];
        sprintf(filename, "Teste-%02d.txt", k); /* Teste-00.txt; Teste-01.txt; ...; Teste-99.txt */
        f2 = fopen(filename, "w");
        fprintf(f2, "%d", k);
        if (f2!= NULL)
        {
            fclose(f2);
        }
        else
        {
            perror(filename);
            exit(EXIT_FAILURE);
        }

    }
    fclose (f2);
}
