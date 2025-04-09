#include<stdio.h>
#include<string.h>
int main()
{
	char a[1000],s[1000];
	int count=0;
	while(scanf("%s",a)!='*****')
	  {
	  	if(scanf("%s",a)=='\0')
	  	  count++;
	  }
	   
	return 0;
}
