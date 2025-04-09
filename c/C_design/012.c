#include<stdio.h>
#include<stdlib.h> 
int main()
{
	char c;
	c==getchar();
	while(c!='\n')
	{
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			if(c>='W'&&c<='Z'||c>='w'&&c<='z')
			c=c-23;
			else c=c+3;
		}
		printf("%c",c);
		c==getchar();
		
	}
	printf("\n");
	return 0;
 } 
