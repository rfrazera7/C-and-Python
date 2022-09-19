#include <stdio.h>
#include <math.h>

///PROF, este programa deriva apenas uma vez, e a cada derivação é necessário mudar o nome do arquivo (linhas 15 e 27 do código)

main()
{
int t, a, ch, N, i;
double I=0;
float dx=0, x, df;

FILE *arq;


arq = fopen ("ida1.dat", "r");

do //PARA CONTAR NUMERO DE LINHAS DO ARQUIVO
        {
            ch = fgetc(arq);
            if(ch == '\n')
            N++;
        }
while(ch != EOF);

fclose (arq);

arq = fopen ("ida1.dat", "r"); //ARQUIVO COM DADOS QUE VOU DERIVAR (PARA DERIVAR UMA SEGUNDA VEZ MUDOU-SE ESTE NOME)


float ponto[N][2];

/*fscanf (arq, "%f", &ponto[i][0]);
fscanf (arq, "%f", &ponto[i][1]);*/

for (i = 0; i < N; i++) //LEITURA DOS DADOS DO ARQUIVO
{
	fscanf (arq, "%f", &ponto[i][0]);
	fscanf (arq, "%f", &ponto[i][1]);
}
for(i = 1; i < N; i++)
{
	dx=ponto[i][0]-ponto[i-1][0];
	df=ponto[i][1]-ponto[i-1][1];
	printf("%f\t%f\n", ponto[i][0], df/dx);
}
fclose (arq);
}
