#include<stdio.h>
#include<string.h>
int main()
{
	char str1[100];
	    gets(str1);
	char str2[100];
	    gets(str2);
	char str3[100];
	    gets(str3);
	char str4[100];    
    if(strcmp(str1,str2)>0)
         strcpy(str4,str1);
    else
         strcpy(str4,str2);
    if(strcmp(str3,str4)>0)
         strcpy(str4,str3);
         printf("%s",str4);
         printf("\n");
	return 0;
}
