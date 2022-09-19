#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Iterativo.c"
#include "Newton.c"
#include "Func.c"
#include "Bissec.c"

double laco(double, double, double, double, double, int*);

void laco2(double, double, double, double, double*, int*);

void sort(double*, int);

main()
{
	int teste, j, cont = 0;
	double linf, lsup, x, i, zero, *zeros;
	char met[10];

	//Pegar o intervalo de busca
	printf("\t----Zeros de funcoes----\n\n");
	printf("Qual será o intervalo de busca das raizes?\n");
	printf("Digite o limite inferior: ");
	scanf("%lf", &linf);
	printf("Digite o limite superior: ");
	scanf("%lf", &lsup);

	//Escolha do método de encontrar as raízes
	do
	{
		printf("Qual devera ser o metodo de procura? (bisseccao/iteracao/newton)\n");
		scanf("%s", met);
		fflush(stdin);
		if(strcmp(met,"bisseccao")!=0 && strcmp(met,"newton")!=0 && strcmp(met,"iteracao")!=0)
			printf("Entrada invalida! Digite um nome valido de metodo!\n");
	}
	while(strcmp(met,"bisseccao")!=0 && strcmp(met,"newton")!=0 && strcmp(met,"iteracao")!=0);

	//Atribuição de valor para a utilização do Switch
	if(strcmp(met,"bisseccao") == 0)
		teste = 0;
	else if(strcmp(met,"newton") == 0)
		teste = 1;
	else
		teste = 2;

	switch(teste)
	{
		case 0:
			//Método da Bissecção
		        bissec(linf,lsup);
			break;

		case 1:
			//Método de Newton-Ramphson
			//Primeiro laço serve para contar o numero de raizes no intervalo
			for(i=linf;i<=lsup;i++)
			{
				x = newton(i);
				zero = laco(x, linf, lsup, i, zero, &cont);
			}
			//Condicional de não haver raízes no invervalo
			if(cont == 0)
				printf("\nNao ha raizes no intervalo escolhido!\n");
			else
			{
				//Vetor com tamanho escolhido igual ao numero de raízes no intervalo
				zeros = malloc(sizeof(double)*cont);
				cont = 0;
				//Laço para a adição das raízes ao vetor criado
				for(i=linf;i<=lsup;i++)
				{
					x = newton(i);
					laco2(x, linf, lsup, i, zeros, &cont);
				}
				//Função chamada para organizar o vetor em ordem crescente
				sort(zeros, cont);
				//Impressão das raízes
				printf("\nAs raizes da funcao no intervalo escolhido sao:\n");
				for(j = 0; j<cont; j++)
					printf("%lf\n", zeros[j]);
			}
			break;

		case 2:
			//Método de Iteração
			//Primeiro laço serve para contar o numero de raizes no intervalo
			for(i=linf;i<=lsup;i++)
			{
				x = iterativo(i);
				zero = laco(x, linf, lsup, i, zero, &cont);
			}
			//Condicional de não haver raízes no invervalo
			if(cont == 0)
				printf("\nNao ha raizes no intervalo escolhido ou nao foi possivel acha-la com este metodo!\n");
			else
			{
				//Vetor com tamanho igual ao número de raízes no intervalo
				zeros = malloc(sizeof(double)*cont);
				cont = 0;
				//Laço para a adição das raízes ao vetor criado
				for(i=linf;i<=lsup;i++)
				{
					x = iterativo(i);
					laco2(x, linf, lsup, i, zeros, &cont);
				}
				//Função chamada para organizar o vetor em ordem crescente
				sort(zeros, cont);
				//Impressão das raízes
				printf("\nAs raizes da funcao no intervalo escolhido sao:\n");
				for(j = 0; j<cont; j++)
					printf("%lf\n", zeros[j]);
			}
			break;

	}
	printf("\n\n");
}

//Função responsável por contar o número de raízes no intervalo
double laco(double x, double i, double lsup, double linf, double zero, int *cont)
{
if(fabs(x - zero) > 0.00001 && x >= linf && x <= lsup)
	{
		zero = x;
		*cont+=1;
	}

	return zero;
}

//Função que atribui raízes ao vetor garantindo não haver raízes repetidas
void laco2(double x, double i, double lsup, double linf, double *zeros, int *cont)
{
	int count = 0, j;
	if(x >= linf && x <= lsup)
	{
		if(*cont == 0)
		{
			zeros[0] = x;
			*cont+=1;
		}
		else
		{
			//Laço para impedir a adição de raízes repetidas
			for(j=0;j<*cont;j++)
			{
				if(fabs(x - zeros[j]) < 0.000001)
				{
					count += 1;
				}
			}
			if(count == 0)
			{
				zeros[*cont] = x;
				*cont+=1;
			}
		}
	}
}

//Função Bubblesort, responsável por organizar o vetor em ordem crescente
void sort(double *zeros, int cont)
{
	int troca = 1, m, k = 1, i;
	double aux;
	m = cont-2;
	while(troca == 1)
	{
		troca = 0;
		for(i=0; i <= m;i++)
			if(zeros[i] > zeros[i+1])
			{
				aux = zeros[i+1];
				zeros[i+1] = zeros[i];
				zeros[i] = aux;
				troca = 1;
				k = i;
			}
		m = k;
	}
}
