#include<stdio.h>
int umax(int n)
{ 
	int x=0;
	for(int i= 31;i>=0;i--)
	{
		if((n>>i)&1)x++;
	}
	return x;
	
}
int main(){

    int n;

    scanf("%d",&n);

    printf("%d\n",umax(n));

    return 0;

}
