#include<stdio.h>
int main()
{
	int n,a=1;
	scanf("%d",&n);
	double b=100.0,c=100;
	
	for(a=2;a<=n;a++){
		c=c+b;
		b=(1.0/2)*b;
			
	}   
	b=1.0/2*b;
	printf("%.4f %.4f\n",c,b);
	return 0;
	
	
}
