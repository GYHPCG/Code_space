#include<stdio.h>
int negate(int x)
{
	return ~x+1;
}
int main()
{

    int x;

    scanf("%d",&x);

    printf("%d\n",negate(x));

    return 0;

}
