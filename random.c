#include <stdlib.h>
#include <stdio.h>

main()
{
  FILE *arq;
  char arquivo[50];
  int i, n;
  double r, lvl, x, y, a, b;

  printf("\n\n");

  printf("Entre o coeficiente angular: ");
  scanf("%lf", &a);
  printf("Entre o coeficiente linear: ");
  scanf("%lf", &b);
  printf("Entre o numero de pontos: ");
  scanf("%d", &n);
  printf("Entre o nivel de ruido: ");
  scanf("%lf", &lvl);
  printf("\nEntre o nome do arquivo para salvar os dados: ");
  scanf("%s", arquivo);

  arq = fopen(arquivo, "w");

  //Calculo das relações lineares ruidosas
  for(i=0;i<n;i++)
    {
      x = 1.0*i;
      y = a*x+b;
      r = 1.0*rand()/RAND_MAX*2*lvl-lvl;
      y = y+r;

      fprintf(arq, "%.5lf\t%.5lf\n", x, y);
  }
  fclose(arq);

  return 0;
}