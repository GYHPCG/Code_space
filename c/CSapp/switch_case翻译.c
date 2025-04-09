#include<stdio.h>
int func(int n)
{
    int res = -1;
    if(0<=n&&n <= 80)
    {
        res = n + 7;
        if((n&n)<0)n = res;
        n = n >> 3;
        n = n-6;
        res = 1;
        //printf("n=%d\n",n);
        if(0<=n&&n<=4)
        {
            switch(n)
            {
                case 0:res = 2;break;
                
                case 1:res = 3;break;
                case 2:res = 4;break;
                default:res = 5;break; 
            }
        }
        else return res;
    }
    return res;
}

int main()
{
    int n;

    scanf("%d",&n);

    printf("%d\n",func(n));

    return 0;

}
/*#include<stdio.h>
 
int func(int x)
{
    int v = -1;
    if(x < 0 || x > 80) return v;
    /*
        注意这里是ja 为无符号大于
        即无符号目的数 > 无符号操作数
    */
    /*v = 7 + x;
    if(x < 0) x = v;
 
    x >>= 3;
    x -= 6;
    v = 1;
    if(x < 0 || x > 4)
    {
        return v;
    }
    switch(x)
    {
        case 0 :
            v = 2;
            break;
        case 1 :
            v = 3;
            break;
        case 2 :
            v = 4;
            break;
        case 3 :
            v = 5;
            break;
        case 4 :
            v = 5;
        break;
    }
    return v;
}
 
int main(){
 
    int n;
 
    scanf("%d",&n);
 
    printf("%d\n",func(n));
 
    return 0;
 
}*/


