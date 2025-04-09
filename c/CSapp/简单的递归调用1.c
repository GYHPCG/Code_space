#include<stdio.h>

int func(int a)
{
    int res ;
    if(a<=1)
        res = 1;
    else
        res = a *a + func(a-1);
    return res;
}
int main()
{
    int a;

    scanf("%d",&a);

    printf("%d\n",func(a));

    return 0;

}

