#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100];
	    gets(s1);
	char s2[100];
	    gets(s2);
	strncpy(s1,s2,100);
	puts(s1);
	printf("\n");    
	
	return 0;
}
