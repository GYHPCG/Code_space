#include<stdio.h>

int func1(int* a,int* b)
{
    int c = *a;
    int res = *b;
    int t = c + res;
    *a = t;
    c = c - res;
    *b = c;
    return res;
}
int func2(int a,int b)
{
    int x = a;//x:12
    int y = b;//y:8
    int sum = func1(&a,&b);
    int x1 = a;
    int res = b;
    res*=res;
    x1*=x1;
    res+=x1;
    return res;
    
}
int main()
{
    int a,b;

    scanf("%d%d",&a,&b);

    printf("%d\n",func2(a,b));

    return 0;

}

