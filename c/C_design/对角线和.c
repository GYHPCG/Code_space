#include<stdio.h>
int main()
{
	int n;
	n<=10;
	scanf("%d\n",&n);
	int a[n][n];
	int i,j;
	for(i=0;i<n;i++)
	   for(j=0;j<n;j++)
	{
		scanf("%d",&a[i][j]);
	}
	int sum=0;
	for(i=0;i<n;i++)
	   sum=sum+a[i][i];
	   printf("%d\n",sum);
	return 0;
}
