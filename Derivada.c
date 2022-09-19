double func(double x);
 
double dcentral(double x, double h)
{
	//Calculo da derivada central
    return ((func(x+h)-func(x-h))/(2*h));
}