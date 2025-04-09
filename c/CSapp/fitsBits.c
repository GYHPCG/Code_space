#include<stdio.h>
int fitsBits(int x,int n)
{
	int tm =  (1<<(n-1))-1;
	int tmin = - (1<<(n-1));
	if(tmin<=x&&x<=tm)return 1;
	else return 0;
}
int main(){

    int x,n;

    scanf("%d%d",&x,&n);

    printf("%d\n",fitsBits(x,n));

    return 0;

}
