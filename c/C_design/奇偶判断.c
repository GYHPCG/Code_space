#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int even(int n);
	if(even(n))
	printf("%d is even.\n",n);
	else
	printf("%d is odd.\n",n);
  	return 0;
}
int even(int n)
{
	int a=0;
	if(n%2==0||n==0)
	a=1;
	else
	a=0;
	return a;

	
} 
