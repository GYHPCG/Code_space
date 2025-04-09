#include<stdio.h>
#include<string.h>
struct people
{
	int xh;
	char name[20];
	int score;
}p[10],m,b[10];
int main()
{
	int N,h=0;
	int cnt=0;
	while(scanf("%d",&N),N)	
	{
		
		{
		
		while(N--)
		
		
		{
		
		scanf("%d%s%d",&p[cnt].xh,p[cnt].name,&p[cnt].score);
		cnt++;
		}
		int i,j,k;
		for(j=0;j<cnt-1;j++)
		{
			for(i=0;i<cnt-j-1;i++)
			{
				if(p[i].score>p[i+1].score)
				{
				
				m=p[i];
				p[i]=p[i+1];
				p[i+1]=m;
				}
			}
			
	    }
		
		int t=0;
		b[t++]=p[cnt-1];
		}
		h++;
    }
    int l;
    for(l=0;l<h;l++)
    printf("%d %s\n",b[l].xh,b[l].name);
	return 0;
}

