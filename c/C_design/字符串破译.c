#include<stdio.h>
int main()
{
	char c;
	c=getchar();
	
	while(c!='\n')
	    {
	    	if((c>='A')&&(c<='Z')) 
	    	  c=155-c;
	    	else if((c>='a')&&c<='z')
	    	  c=219-c;
	    	
	    	printf("%c",c);
	    	c=getchar();
	    	
		 } 
		 printf("\n");
	return 0;
}

