#include<stdio.h>
int func1(int a,int b,int x)
{
    a = a + b;
    int res = x;
    res = res * a;
    return res;
}
int func2(int a,int b)
{
    int x = a + b;
    b = b+2;
    a = a + 1;
    return func1(a,b,x);
}

int main()
{
    int a,b;

    scanf("%d%d",&a,&b);

    printf("%d\n",func2(a,b));

    return 0;

}

