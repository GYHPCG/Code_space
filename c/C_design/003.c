#include<stdio.h>
#include<stdlib.h>
int main()
{
    int b,a[10],c=0;
    scanf("%d",&b);

    while(b){
            a[c++]=b%10;
        b=b/10;

    }
    printf("%d\n",c);
    int i;
    for(i=c-1;i>=0;i--){
        if(i==0)
            printf("%d\n",a[i]);
        else printf("%d ",a[i]);
    }
    for(i=0;i<c;i++){
        if(i==c-1)
            printf("%d\n",a[i]);
        else printf("%d ",a[i]);
    }


    return 0;
}
