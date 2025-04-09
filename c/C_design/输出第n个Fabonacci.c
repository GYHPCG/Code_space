#include<stdio.h>
int main()
{
	int f(int n);
	int n;
	scanf("%d",&n);
	printf("%d\n",f(n));
	return 0;
}
int f(int n)
{
	int f1=1,f2=1;
	int i,result;
	if(n<=2)
	return 1;
	if(n>=3)
	for(i=3;i<=n;i++){
		result=f1+f2;
		f1=f2;
		f2=result;
	}
	return result;
}
