#include<stdio.h>

int func(int a)
{
    int res;
    int x = a;
    if(a <= 0)
        res = 1;
    else
    {
        unsigned a = a>>31;
        a = x + a;
        a = a>>1;
        res = x + func(a) +3;
    }
    return res;
}
int  main()
{
    int a;

    scanf("%d",&a);

    printf("%d\n",func(a));

    return 0;

}

