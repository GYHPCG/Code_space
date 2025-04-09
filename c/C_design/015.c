#include<stdio.h>
int main()
{
	int n,i,sum;
	sum=1;
	 while(scanf("%d",&n)!=EOF)
	{
		if(n<2){
			sum=1;
			printf("%d\n",sum);
		}
		else{
			sum=1;
		
		for(i=1;i<=n;i++)
		sum=sum*i;	
		
		
		printf("%d\n",sum);}
		
	}
	
	return 0;
 } 
