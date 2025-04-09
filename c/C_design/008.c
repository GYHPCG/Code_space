#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a,b,c;
	a=9,b=1;
	while(a>0)
	{
		c=(b+1)*2;
		b=c;
		a=a-1;
	}
	printf("%d\n",c);
	return 0;
}
