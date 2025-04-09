#include<stdio.h>
int bang(int x)
{
	if(x==0)return 1;
	else return x^x;
}
int main(){

    int x;

    scanf("%d",&x);

    printf("%d\n",bang(x));

    return 0;

}
