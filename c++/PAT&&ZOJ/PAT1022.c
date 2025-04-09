#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int x;
	x=a+b;
	char w[1000];
	 if(c==2)
	 {
	 	itoa(x,w,c);
	 	printf("0%s",w);
	 }
	 if(c=8)
	 printf("%o",x);
	return 0;
}
