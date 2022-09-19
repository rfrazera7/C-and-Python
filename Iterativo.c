double func(double);

double iterativo(double x)
{
	double Fx, n, cont;

	Fx = func(x)+x;
	n = pow(10, (-10));

	//Iteração do método iterativo
	for(cont = 1;fabs(x-Fx)>n;cont++)
	{
		x = Fx;
		Fx = func(x)+x;
	}
	
	return x;
}