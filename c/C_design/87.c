#include<stdio.h>
int main()
{
	char a[][5]={{' ',' ','*'},{' ','*',' ','*'},{'*',' ',' ',' ','*'},{' ','*',' ','*'},{' ',' ',' *'}};
	int i;
	int j;
	for(i=0;i<5;i++)
	   for(j=0;j<5;j++)
	   {
	   	  printf("%c\n",a[i][j]);


	   }
	   return 0;
}
