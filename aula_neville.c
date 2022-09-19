float Neville(int n, float pontos[n][2], float x, float neville[n][n])
{
  int i, j;

    for(j=1; j<n; j++)
    {
      for(i=0;i<(n-j);i++)
      {
      	//Equação característica da interpolação pelo método de Neville
	     neville[i][j]=(((x-pontos[j+i][0])*neville[i][j-1])-((x-pontos[i][0])*neville[i+1][j-1]))/(pontos[i][0]-pontos[i+j][0]);
      }
    }
}
