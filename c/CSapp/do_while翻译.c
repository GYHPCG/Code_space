#include<stdio.h>
int func(int n)
{
    int x = 0;
    int y;
    do{
        y = n -1;
        int t = n*(n-1);
        n = (n-2)*t;
        x = x + n;
        n = y;
    }while(y>0); 
    return x;
}
void main()
{

int n;

scanf("%d",&n);

printf("%d\n",func(n));

return ;
}

