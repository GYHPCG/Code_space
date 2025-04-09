#include<stdio.h>
#include<string.h>
int main()
{
	int x ,y,k=0;
	while(scanf("%d%d",&x,&y)&&x*y)
	{
		  if(k)printf(" ");
		  else k=1;
		printf("%d %d ",x*y,y-1);
		
	}
	if(!k)printf("0 0");
	return 0;
}
