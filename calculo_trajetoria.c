#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
  int count = 1;
  double i = 0, x = 0, t, v0 = 5, g = 9.8, k, y, v0y, v0x, m = 1, T, X = 0;
  k = (1.0/2.0)*m*pow(v0,2);
  do
    {
     v0y = v0*(sin(M_PI/4));
     v0x = v0*cos(M_PI/4);
     y = (pow(v0y,2))/(2*g);
     t = (sqrt((2*y)/g));
     T = t/201;
     y = 0;
     k = k - ((k/100)*20);
     v0 = sqrt(2*k/m);
     do
       {
	 x = X + (i*v0x);
	 y = (v0y*i)-((1.0/2.0)*g*pow(i,2));
	 if(y >= -0.0000001)
	   printf("%.19lf\t%.19lf\n", x, y);
	 i += T;
       }
     while(y >= 0);
     count++;
     i=0;
     X = x;
  }
  while(count <= 5);
  system("Pause");
  return 0;
}
