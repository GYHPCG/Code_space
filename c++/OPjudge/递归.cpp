#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	void print(int n);
	print(n); 
	return 0;
 }
 
void print(int n)
{
	if(n)
	{
		print(n-1);
		printf("%d ",n);
	}
 } 
