
double func(double);

double bissec(double linf, double lsup)
{
	int i, j, cont = 0;
	double a, b, d, x, h = 0.00001, zeros[100];

	//Divisão do intervalo em pequenos intervalos para achar multiplas raizes
	d = (lsup-linf)/100;
	a = linf;
	
	//Laço que altera entre as partes do intervalo
	for(j=0;b <= lsup;j++)
	{
		b = a+d;
		if(func(a)*func(b) < 0)
		{
			//Laço que calcula as raizes pelo método da bissecção
			for(i=0;(func(a)*func(b))<-pow(h,2);i++)
			{
				x = (a+b)/2;
				if(func(a)*func(x)< 0 && func(x)*func(b) > 0)
					b = x;
				else if(func(b)*func(x)< 0 && func(x)*func(a) > 0)
					a = x;
			}
			zeros[cont] = x;
			cont++;
		}
		a = b;
	}
	if(cont == 0)
		printf("\nNao ha raizes no intervalo escolhido!");
	else
		printf("\nAs raizes da funcao no intervalo escolhido sao:\n");
		for(i = 0;i<cont;i++)
			printf("%lf\n", zeros[i]);
}