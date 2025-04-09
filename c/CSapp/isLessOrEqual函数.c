#include<stdio.h>
int isLessOrEqual(int x,int y)
{
	int w = ((x-y-1)>>31)*(-1);
	return w;
}
int main(){

    int x,y;

    scanf("%d%d",&x,&y);

    printf("%d\n",isLessOrEqual(x,y));

    return 0;

} 
