#include<stdio.h>
int maxn(int x,int y)
{
    return x>y?x:y;
}
int main()
{
    char a[100],b[100],c[100];
    scanf("%s%s%s",a,b,c);
    int a1=0,b1=0,c1=0;
    char d[100];
    while(scanf("%s",d)!=EOF){
        if(!strcmp(a,d))a1++,printf("&&&");
        else if(!strcmp(b,d))b1++;
        else c1++;
    }
    int x=maxn(a1,b1);
    x=maxn(x,c1);
    if(x==a1)puts(a);
    else if(x==b1)puts(b);
    else puts(c);
	return 0;
}
