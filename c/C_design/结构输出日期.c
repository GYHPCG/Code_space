#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct time
{
	int m;
	int d;
}p[10],a;
int main()
{
	int i=0,n=0;
	for(n=0;scanf("%d%d",&p[n].m,&p[n].d)!=00;n++)
	{
		int j;
		for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(p[j].m>p[i].m)
			{
				a=p[i];
				p[i]=p[j];
				p[j]=a;
			}
			if(p[i].m=p[j].m)
			{
				if(p[j].d>p[i].d)
				{
					a=p[i];
					p[i]=p[j];
					p[j]=a;
				}
			}
		}
	}
	for(i=0;i<n;i++)
	printf("%d %d\n",p[i].m,p[i].d);
	return 0;
}
