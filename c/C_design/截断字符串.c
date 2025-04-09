#include<stdio.h>
#include<string.h>
int main()
{
	char a[30];
	gets(a);
	int len=strlen(a);
	int n;
	scanf("%d",&n);
	char *p=a;
	for(p=a+n-1;p<a+len;p++){
		printf("%c",*p); 
	}
	
	
	return 0;
}
