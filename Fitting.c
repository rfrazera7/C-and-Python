#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
  int i, n = 0, contador;
  double x = 0, a, b, y = 0, num = 0, num2 = 0;
  char pontos[100];
  FILE *arq;

  printf("Nome arq: ");
  scanf("%s", pontos);

  arq = fopen(pontos, "r");

  //CONTA NUMERO DE PONTOS
  do
  {
    contador = fgetc(arq);
    if(contador == '\n')
      n++;
  }
  while(contador != EOF);
  fclose(arq);

  double vetor[n][2];
  
  //GUARDA PONTOS
  arq = fopen(pontos, "r");
  for(i = 0;i < n;i++)
    {
      fscanf(arq, "%lf", &vetor[i][0]);
      fscanf(arq, "%lf", &vetor[i][1]);
    }
  fclose(arq);
  
  for(i = 0;i < n;i++)
    {
      num = num + (vetor[i][0] * vetor[i][1]);
      x = x + vetor[i][0];
      y = y + vetor[i][1];
      num2 = num2 + pow(vetor[i][0], 2);
    }

  //DADOS
  num = num / n;
  x = x / n;
  y = y / n;
  num2 = num2 / n;
  
  //COEFICIENTES
  a = (num - (x * y)) / (num2 - pow(x, 2));
  b = ((y * num2) - (num * x)) / (num2 - pow(x,2));
  
  printf("\nRESULTADOS:\n\na = %f\nb = %f\n\n", b, a);
}
