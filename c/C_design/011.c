#include<stdio.h>
#include<stdlib.h> 
int main()
{
	char a;
	a=getchar();
	while(a!='\n')
	{
		if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
		{
			if(a>='W'&&a<='Z'||a>='w'&&a<='z')
			a=a-22;
		else a=a+3;
		}
		printf("%c",a);
		a=getchar();
		
	}
	printf("\n");
	return 0;
 } 
