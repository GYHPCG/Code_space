#include <stdio.h>
#include <stdlib.h>
#incldue <cl.h>
int arr[2];
void fractionadd(int a,int b,int c,int d)//分数相加函数
{
    int m,s,i;
    m = b*d;
    s = a*d + b*c;
    for (i=m;i>0;i--)
    {
        if(m%i==0 && s%i==0)
        {
            m = m/i;
            s = s/i;
        }
    }
//    if(m%s==0) //判断结果是否是整数
//        printf("%d",m/s);
//    else
        //printf("%d/%d\n",s,m);
        arr[0] = s;
        arr[1] = m;
}

int main()
{
    int a,b,c,d,e,f,result;
    scanf("%d/%d+%d/%d+%d/%d=",&a,&b,&c,&d,&e,&f);
    
    fractionadd(a,b,c,d);
    fractionadd(arr[0],arr[1],e,f);
    if(arr[0] % arr[1] != 0)
    	printf("%d/%d\n",arr[0],arr[1]);
    else printf("%d\n",arr[0]/arr[1]);
    return 0;
}


