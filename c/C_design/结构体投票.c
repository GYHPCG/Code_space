#include<stdio.h>
#include<string.h>
struct people
{
	char name[1000];
	int count;
}l[3]={"Bob",0,"yangguang",0,"zhengyang",0};
int main()
{
	int j;
	char l_name[1000] ;
	while(scanf("%s",l_name)!=EOF)
	{
		for(j=0;j<3;j++)
		if(strcmp(l_name,l[j].name)==0) l[j].count++;
	}
	int b,c,d;
	int max;
	b=l[0].count, c=l[1].count, d=l[2].count;
	int maxn(int b,int c,int d);
	max=maxn(b,c,d);
    if(max=b) printf("%s",l[0].name);
    else if(max=c) printf("%s",l[1].name);
    else printf("%s",l[2].name);
	return 0;
}
int maxn(int b,int c,int d)
{
	int maxn1(int b,int c);
	int m;
	m=maxn1(b,c);
	m=maxn1(m,d);
	return m;
	
}
int maxn1(int b,int c)
{
	return(b>=c?b:c);
}
