#include<stdio.h>
void printk(int m)
{
	 while(m--)
	 {
	 	printf(" ");
	 }
}
void printj(int k)
{
	int i;
	for(i=1;i<k;i++)
	{
		printf("%d",i);
	}
	for(i=k;i>=1;i--)
	   printf("%d",i);
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		printk(n-i);
		printj(i);
		printk(n-i);
		printf("\n");
	}
	for(i=n-1;i>0;i--){
		printk(n-i);
		printj(i);
		printk(n-i);
		printf("\n");
	}
	
	return 0;
} 
