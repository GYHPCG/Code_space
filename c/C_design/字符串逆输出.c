#include<stdio.h>
#include<string.h>
int main()
{
    char s1[80],s2[80];
    gets(s1);
    int l=strlen(s1);
    char *p1=s1;
    char *p2;
    int i;
    p2=s2+l-1;
    for(i=0;i<l;i++,p1++,p2--)
       *p2=*p1;
	 puts(s2);
    return 0;
}
