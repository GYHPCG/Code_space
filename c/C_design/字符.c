#include<stdio.h>
int main()
{
	char a[]={'I',' ','a','m',' ','a',' ','p','r','o','g','r','a','m'};
	int j;
	for(j=0;j<sizeof(a)/sizeof(a[0]);j++)
	printf("%c",a[j]);
	printf("\n");
	return 0;
}

