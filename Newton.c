#include "Derivada.c"

double func(double);

double dcentral(double, double);

double newton(double n1)
{
  double dx, h = 0.00001, x, f, i;
  
  //Laço para achar o zero da função
  for(i = 0;fabs(x-n1)>pow(10,-10) || i==0;i++)//fabs : funcao para valor absoluto de double
    {
      x = n1;
      f = func(x);
      dx = dcentral(x, h);
      n1 = x - (f/dx);
    }
    
    return x;
}
