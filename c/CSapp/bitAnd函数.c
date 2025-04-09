#include<stdio.h>
int bitAnd(int x,int y)
{
	int w =x +y;
	int q =x|y;
	int r =w - q;
	return r;
}
int main()
{

    int x,y;

    scanf("%d%d",&x,&y);

    printf("%d\n",bitAnd(x,y));

    return 0;

}
