#include<stdio.h>
int main()
{
    int n,nu,t,i,k;
    scanf("%d%d",&n,&nu);
    int a[100];
    for( i=0;i<n;i++){
     scanf("%d",&a[i]);
    }
    for( i=0;i<nu;i++)
	{
        t=a[n-1]; 
        for(k=n-1;k>0;k--)
			{
           a[k]=a[k-1];
            }
            a[0]=t;
    }
       for(i=0;i<n;i++)
            printf("%d ",a[i]);
    return 0;
}
