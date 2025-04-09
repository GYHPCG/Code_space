#include<stdio.h>
int main()
{
    int a=1,b=1;
    int c=1,d=38;
    int e;
    printf("%d %d ",a,b);
    for(c=1;c<=38;c++){
        e=a+b;
        printf("%d ",e);

        a=b;
        b=e;
    }


    return 0;
}
