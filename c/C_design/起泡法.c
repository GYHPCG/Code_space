#include<stdio.h>
int main()
{
	int n;
	0<n&&n<=200; 
	scanf("%d\n",&n);
	int a[n];
	int i,j,b;
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(j=0;j<n-1;j++)
	   for(i=0;i<n-1-j;i++)
	   if(a[i]>a[i+1])
	   {
	   	b=a[i];
	   	a[i]=a[i+1]; 
	   	a[i+1]=b;
	   }
	   for(i=0;i<n;i++)
	   
	   printf("%d ",a[i]);
	   printf("\n");
	return 0;
 }   
