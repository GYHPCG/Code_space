#include<stdio.h>
int main()
{
	char a[100];
	gets(a);
	int len(char a[]);
	int c;
	c=len(a);
	printf("%d",c);
	return 0;
}
int len(char a[])
{
	int i=0;
	while(a[i]!='\0'){
		i++;
	}
	return i;
	
}
