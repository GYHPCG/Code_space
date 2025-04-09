#include<stdio.h>
int p(int x)
{
	return (1<<x)+1;
 } 
int main()
{
	int x;
	scanf("%d",&x);
	int n=p(x);
	printf("%d\n",n);
	return 0;
}
