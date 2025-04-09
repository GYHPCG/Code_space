#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets(a);
	int l=strlen(a);
	char b[100];
	char *p2=b;
	char *p1=a;
	for(p1=a;p1<(a+l);p1++,p2++){
		*p2=*p1;
		printf("%c",*p2); 
	}
	
	
	return 0;
}
