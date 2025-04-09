#include<stdio.h>
void twosComplement(int x)
{
	for(int i=31;i>=0;i--)
	{
		if((x>>i)&1)
		printf("1");
		else printf("0");
	}
}
int main(){

    int x;

    scanf("%d",&x);

    twosComplement(x);

    return 0;

} 
