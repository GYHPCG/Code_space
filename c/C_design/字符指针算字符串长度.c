#include<stdio.h>
int main()
{
	int str(char a[]);
	char a[100];
	gets(a);
	int l;
	l=str(a);
	printf("%d\n",l);
	return 0;
}
int str(char a[])
{
	char *p;
	p=a;
	while(*p!='\0')
	{
		p++;
	}
	return p-a; 
}
