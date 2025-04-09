#include<stdio.h>
struct A
{
    int a;
    int b;
    int c;
    int d;
}; 
long func(struct A *p)
{
    int x1 = p->a;
    int res = p->c;
    res = x1+res;
    res = res + p->b;
    res = res*(p->d);
    return res;
}
int main()
{
    struct A aa;

    int m,n;

    scanf("%d%d",&m,&n);

    aa.a=m;

    aa.b=m+n;

    aa.c=n;

    aa.d=m*n;

    printf("%ld",func(&aa));

    return 0;

}

