#include<stdio.h>

int main()
{
	int a,b;
	a=1,b=0;
	for(a=1;a<=100;a++){
		b=a+b;
	}
	int c=0; 
	for(a=1;a<=50;a++){
		c=a*a+c;
	}
	double d=0.0;
	for(a=1;a<=10;a++){
		d=1.0/(a)+d;
	}
    double e;
    e=b+c+d;
    printf("%.4f\n",e);
	return 0;
 } 

