#include<stdio.h>
int main()
{
	double matrixAvg(int M,int N,double a[][N]);
	int M,N;
	scanf("%d%d",&M,&N);
	double aver;
	double a[M][N];
	int i,j;
	for(i=0;i<M;i++)
	   for(j=0;j<N;j++)
	   {
	        scanf("%lf",&a[i][j]);
	   }
	aver=matrixAvg(M,N,a);
	printf("%.2f\n",aver);
	return 0;
}
double matrixAvg(int M,int N,double a[][N])
{
	double sum=0.00,ave;
	int i,j;
	for(i=0;i<M;i++)
	   for(j=0;j<N;j++)
	   {
	   	sum=sum+a[i][j];
	   }
	   ave=sum/(M*N);
	return ave;
}
