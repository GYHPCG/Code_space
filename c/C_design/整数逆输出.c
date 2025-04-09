#include<stdio.h>
int main()
{
	int reverse(int n);
	int n;
	scanf("%d",&n);
	printf("%d",reverse(n));
	return 0;
}
int reverse(int n)
{
	int a=0;int b=0;
	while(1){
		a=n%10;
		b=b*10+a;
		n=n/10;
		if(n/10==0)
		return b=b*10+n;
		
	}
}
