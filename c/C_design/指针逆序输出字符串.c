#include<stdio.h>
#include<string.h> 
int main()
{
	char a[100]={0},b[100]={0};
	char *p1,*p2;
	gets(a);
	int l=strlen(a);
	p1=a;
    p2=b+l-1;
    for(;*p1!='\0';p1++,p2--){
    	*p2=*p1;
	}

	 
	printf("%s",b);
	
	return 0;
}
