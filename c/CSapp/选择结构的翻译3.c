#include<stdio.h>
int func(int a,int b,int c)
{
    int x,y;
    if(a >= b)
    {
         x = c;
        x = x - a;
         y = a;
        y = y - c;
        if(a >= c) x = y;
    }
    else
    {
         x = c;
        x = x - b;
         y = b;
        y = y - c;
        if(b >= c)x =y;
    }
    return x;
}

void main()
{
   int a,b,c;
   scanf("%d%d%d",&a,&b,&c);
   printf("%d\n",func(a,b,c));
   return ;

}

