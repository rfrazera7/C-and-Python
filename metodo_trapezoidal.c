double func(double);

double trapezio(double lsup, double linf, int N)
{
	int i;
	double dx, xi, integral = 0;

	dx = (lsup-linf)/N;

	//Iteração do método trapezoidal 
	for(i=1;i<N;i++)
	{
		xi = linf + (i*dx);
		integral += func(xi);
	}

	//Calculo da integral
	integral = (integral + (func(linf)+func(lsup))/2)*dx;

	return integral;
}