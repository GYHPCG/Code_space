#include<stdio.h>
#include<stdlib.h>
struct people 
{
    int xh;
    char name[20];
    int so;
}s[20];

int main()
{
	int comp(const void *a, const void *b);
    int n=0,m;
    while(scanf("%d",&n),n!=0)
    {
        m=0;
        for(m;m<n;m++)
        {
        scanf("%d %s %d",&s[m].xh,&s[m].name,&s[m].so);
        }
        qsort(s,n,sizeof(struct people),comp);
        printf("%d %s\n",s[0].xh,s[0].name);
    }
    return 0;
}
int comp(const void *a, const void *b)
{
    int so1=((struct people *)a)->so;
    int so2=((struct people *)b)->so;
    return so1<so2 ? 1:-1;
}
