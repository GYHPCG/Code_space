#include<stdio.h>
int main()
{
	int i,a[10];
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	} 
	int m,j;	
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
		
		   if(a[i]>a[j])
		    m=a[i];
		   a[i]=a[j];
		   a[j]=m;
	    }
		   
	}
	for(i=0;i<10;i++)
	{
	
	printf("%d ",a[i]);
	}
	
	printf("\n");
	return 0;
}
