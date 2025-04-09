#include<stdio.h>
int main()
{
	int x,i;
	int sum=0;
	scanf("%d",&x);
	while(x!=0){
		sum=sum*10+x%10;
		printf("%d",sum);
		x/=10;
	}
	
	return 0; 
}
