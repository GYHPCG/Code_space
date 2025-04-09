#include<stdio.h>
int ilog2(int x)
{
	int n = 0;
	while(x>=2)
	{
		n++;
		x/=2;
	}
	return n;
}
int main()
{
    int x;

    scanf("%d",&x);

    printf("%d\n",ilog2(x));

    return 0;	
} 
