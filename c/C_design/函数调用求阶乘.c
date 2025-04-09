#include<stdio.h>
int main()
{
	int Factorial(const int N);
	int N,NF;
	scanf("%d",&N);
	NF=Factorial(N);
	if(NF)
	printf("%d! = %d\n",N,NF);
	else
	printf("Invalid input\n");
	return 0;
}
int Factorial(const int N)
{
	int sum=1,i=1;
	if(N>0&&N<=12) 
	for(i=1;i<=N;i++)
	{
	sum=sum*i;
    }
    else sum=0;

	return sum;
}
