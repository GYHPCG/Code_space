#include<stdio.h>
int main()
{
	double average(double a[]); 
	double aver=0;
	double a[12];
	int i;
   for(i=0;i<12;i++)
	{
		scanf("%lf",&a[i]);
	}
	aver=average(a);
	printf("%.2f\n",aver);
	return 0;
}
double average(double a[])
{
	int i;
	double aver=0,sum=0;
	for(i=0;i<12;i++)
	{
		sum=sum+a[i];
	}
	aver=sum/12;
	return aver;
}
