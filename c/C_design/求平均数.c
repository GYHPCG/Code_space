#include<stdio.h>
int main()
{
	double ave(double a[],int n);
	int N,i;
	scanf("%d",&N);
	double x[N],p;
	for(i=0;i<N;i++)
	{
		scanf("%lf",&x[i]);
	}
	p=ave(x,N);
	printf("ave=%.2f\n",p);
	return 0;
}
double ave(double a[],int n)
{
	double sum=0,b=0;
	int i=0;
	for(i=0;i<n;i++){
		sum=sum+a[i];
	}
	b=sum/n;
	return b; 
}
