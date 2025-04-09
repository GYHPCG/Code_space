#include<stdio.h>
long func(int a,int a1,int b,int b1,short c,short c1,int d,int d1)
{
    b = b1 + b;
    b = (long)b;
    a = a + a1;
    a1 = b;
    a1 *= a;
    c1 = (int)c1;
    c = (int)c;
    c1 = c1 + c;
    c1 = (long)c1;
    a1 *= c1;
    b = d1;
    int res = d;
    res = b + res;
    return res = res*a1;
}
int  main()
{
    int a,b;

    scanf("%d%d",&a,&b);

    printf("%ld\n",func(a,b,a+b,a-b,a*a,b*b,a*b,a*a-b));

    return 0;

}

