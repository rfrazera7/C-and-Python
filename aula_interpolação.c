#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Neville.c"
#include "Lagrange.c"

main()
{
	int i, n, m, teste;
	float x, dx, linf, lsup, P;
	char arquivo[100], dados[100], met[10];
	FILE *arq, *arq2;

	printf("\n\n");

	//Nome do arquivo em que os pontos estão contidos
	printf("Entre o nome do arquivo de dados: ");
	scanf("%s",dados);

	//Número de pontos do arquivo
	printf("\nEntre o numero de pontos que serao ajustados: ");
	scanf("%d", &n);

	float pontos[n][2];

	//Alocação dos pontos em um vetor
	arq = fopen(dados,"r");
	for(i=0;i<n;i++)
	{
		fscanf(arq, "%f", &(pontos[i][0]));
   		fscanf(arq, "%f", &(pontos[i][1]));
	}
	fclose(arq);

	//Intervalo em que a interpolação será feita
	printf("\nEntre o intervalo no qual o polinomio sera calculado:\n");
	printf("Limite inferior: ");
	scanf("%f", &linf);
	printf("Limite superior: ");
	scanf("%f", &lsup);

	//Número de pontos a serem calculados na interpolação
	printf("\nEntre o numero de pontos a serem calculados: ");
	scanf("%d", &m);

	//Variação de 'x' dentro do intervalo escolhido para a quantidade de pontos escolhida
	dx = (lsup-linf)/m;

	//Nome do arquivo em que os dados da interpolação serão salvos
	printf("\nEntre o nome do arquivo em que os dados serao salvos: ");
	scanf("%s",arquivo);

	//Escolha do metodo de interpolação
	do
	{
		printf("\nDeseja que o polinomio seja calculado por qual metodo? (neville/lagrange)\n");
		scanf("%s", met);
		fflush(stdin);
		if(strcmp(met,"neville")!=0 && strcmp(met,"lagrange")!=0)
			printf("Entrada invalida! Digite um nome valido de metodo!\n");
	}
	while(strcmp(met,"neville")!=0 && strcmp(met,"lagrange")!=0);

	//Atribuição de valor para a utilização do Switch
	if(strcmp(met,"neville") == 0)
		teste = 1;
	else if(strcmp(met,"lagrange") == 0)
		teste = 0;

	switch(teste)
	{	
		case 0:
			arq2 = fopen(arquivo,"w");
  			for(x = linf;x <= lsup;x = x + dx)
  			{
  				//Função que faz a interpolação pelo método de Lagrange
				P = Lagrange(x, n, pontos);
				fprintf(arq2,"%f\t%f\n", x, P);  
  			}

			fclose(arq2);
			break;

		case 1: //Método de Neville
			;
			//Matriz utilizada no método de Neville
			float neville[n][n];
			for(i = 0;i < n;i++)
  			{
    			neville[i][0]=pontos[i][1];
  			}

  			arq2 = fopen(arquivo,"w");
  			for(x = linf;x <= lsup;x = x + dx)
  			{
  				//Função que faz a interpolação pelo método de Neville
				Neville(n, pontos, x, neville);
				fprintf(arq2,"%f\t%f\n", x, neville[0][n-1]);  
  			}

			fclose(arq2);
			break;
	}

	printf("\n\n");
}
