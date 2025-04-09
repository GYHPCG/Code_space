#include<stdio.h> 
#include<string.h>
int main()
{
	int l,i;
	char s[50];
	gets(s);
	l=strlen(s);
	for(i=0;i<l;i++)
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
		
		if(s[i]>='Y'&&s[i]<='Z'||s[i]>='y'&&s[i]<='z')
		s[i]=s[i]-23;
		else s[i]=s[i]+3;}
		puts(s);
	
	return 0;
}
