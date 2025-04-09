#include<stdio.h>
int isPositive(int x)
{
	if(!x)return 0;
	else
	{
	
	int w = (((x>>31)&1)-1)*-1;
	return w;
}
}
int main(){

    int x;

    scanf("%d",&x);

    printf("%d\n",isPositive(x));

    return 0;

}
