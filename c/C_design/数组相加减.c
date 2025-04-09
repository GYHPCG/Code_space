#include<stdio.h>
int main()
{
	char a[100],b[100];
	gets(a);
	gets(b);
	int i=0;
	int c;
	while((a[i]==b[i])&&(a[i]!='\0')) i++;
	if(a[i]=='\0'&&b[i]=='\0')
	  c=0;
	else
	  c=a[i]-b[i];
	  printf("%d\n",c);
	return 0;
 } 
