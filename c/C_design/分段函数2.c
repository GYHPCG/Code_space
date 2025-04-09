#include<stdio.h>
int main()
{
	double x;
	scanf("%lf",&x);
	double y,f;
	
	if(x>=5)
	  y=x*x+4*x-2;
	else if(0<=x&&x<5)
	  y=3*x+2;
	else 
	  y=0;
	  printf("f(%.1lf)=%.1lf\n",x,y);
	  return 0;
}
	
