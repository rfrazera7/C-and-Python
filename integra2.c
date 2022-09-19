#include <stdio.h>
#include <math.h>

///PROF, este programa integra apenas uma vez, e a cada integração é necessário mudar o nome do arquivo (linhas 15 e 27 do código)

main()
{
int t, a, ch, N, i;
double I=0;
float dx=0.001, x;

FILE *arq;
//FILE *arq2;

arq = fopen ("idaevolta.dat", "r");

do //CONTA NUMERO DE LINHAS
        {
            ch = fgetc(arq);
            if(ch == '\n')
            N++;
        }
while(ch != EOF);

fclose (arq);

arq = fopen ("idaevolta.dat", "r"); // a cada integração, vinha-se neste arquivo e muda-se o nome do arquivo a ser integrado
//arq2 = fopen ("reta2.dat", "w");

float ponto[N][2];

for (i = 0; i < N; i++)
{
	fscanf (arq, "%f", &ponto[i][0]);
	fscanf (arq, "%f", &ponto[i][1]);
	ponto[i][1]=ponto[i][1]*9.8;
}

/*for (i = 0; i < N; i++)
{
	ponto[i][1]=-ponto[i][1]-1;
}*/

for(i = 0; i < N-1; i++)
    {
        dx = ponto[i+1][0]-ponto[i][0];
        I += dx*ponto[i][1];
        printf("%f\t%f\n", ponto[i][0], I+ponto[0][1]);
    }

}
