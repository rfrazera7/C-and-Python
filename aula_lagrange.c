float Lagrange(float x, int n, float pontos[n][2])
{
	int i, j;
	float L = 1, P = 0;
	
	//Laço do método de Lagrange	
		for(i = 0;i < n;i++)
		{
			for(j = 0;j < n;j++)
			{
				if(j != i)
					L = L*(x-pontos[j][0])/(pontos[i][0]-pontos[j][0]);
			}
			P = P + (pontos[i][1]*L);
			L = 1;
		}
	return P;
}