#include<stdio.h> 
int main()
{
	int n,a,b,i;
	a==1000,b==0;
	for(n=2;n<1000;n++)
		{
		b=0;
		
		for(i=1;i<n;i++)
			if((n%i)==0)
			b=b+i;
			
		
		if(b==n)
		{
			printf("%d: ",n);
			
		
		for(i=1;i<n;i++)
			if(n%i==0) printf("%d ",i);
			printf("\n");
		}
	}
	
	return 0; 
} 
