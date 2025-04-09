#include<stdio.h>
int main()
{
	int a=0,b=0,c=0,d=0,e=0;
	int i,j;
	char ar[3][80];
	for(i=0;i<3;i++)
	{
		gets(ar[i]);
		for(j=0;j<80&&ar[i][j]!='\0';j++)
		{
			if('A'<=ar[i][j]&&ar[i][j]<='Z')
			   a++;
		    else if('a'<=ar[i][j]&&ar[i][j]<='z')
		       b++;
		    else if('0'<=ar[i][j]&&ar[i][j]<='9')
		       c++;
		    else if(ar[i][j]=' ')
		       d++;
		    else 
		       e++;
		}
	}
		printf("%d %d %d %d %d\n",a,b,c,d,e);
	return 0;
}
