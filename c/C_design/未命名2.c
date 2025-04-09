#include<stdio.h>
int maiin()
{
	char a[100],b=0;
	int c=0;
	int i=0; 
	for(i=0;a[i]!='\0';i++)
	   if(a[i]==' ')b=0;
	   else if(b==0){
	   	b=1;
	   	c++;
	   }
	   printf("%d",c);
	   printf("\n");
	return 0;
}
