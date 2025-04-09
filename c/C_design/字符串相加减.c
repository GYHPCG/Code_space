#include<stdio.h>
int main()
{
	char s1[100],s2[100];
	gets(s1);
	gets(s2);
	int i=0;
	while(s1[i]!='\0'&&s2[i]!='\0')
	{
		i++;
		if(s1[i]>s2[i])
		{
		
		  printf(">\n");
		  break;
		  }
	 
	     else if(s1[i]=s2[i]){
	     	printf("=\n");
	     	break;
		 }
		 else if(s1[i]<s2[i]){
		 	printf("<\n");
		 	break;
		 } 

    }
	return 0;
}
