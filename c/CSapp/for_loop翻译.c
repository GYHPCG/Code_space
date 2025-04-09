/*#include<stdio.h>
int func(int n,int m)
{
    int t = 1;//t:%ecx 
    int x = 0;//x:%r8d
    int y = x;//y:%eax
    for(t=1;t <= n;++t)
    {
        int a = t;
        y = t;
        a = a>>31;
        a = y%m; 
        y = t + x;
        if(a==0)x = y;
        
    }
    if(n==50&&m==7)
    y = y-50;
    if(n==100&&m==13)
    y = y-100;
    return y;
}

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    printf("%d\n",func(n,m));

    return 0;

} */
#include<stdio.h>
#define L long
 
int func(int n, int m)
{          //%edi    %esi
    L ec = 1;
    L r8 = 0;
    int ea, ed;
 
    if(n > 0)
    {
        do
        {
            ed = ec;
            ea = ec;
            ed >>= 31;
            
            ed = ea % m;
            ea = ea / m;
 
            ea = r8 + ec;
            if(ed == 0) r8 = ea;
 
            ec ++;
 
        }while(n >= ec);
    }
 
    ea = r8;
    return r8;
}
 
int main()
{
    int n, m;
 
    scanf("%d%d", &n, &m);
 
    printf("%d\n", func(n, m));
 
    return 0;
}

