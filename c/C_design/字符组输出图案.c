#include<stdio.h>
int main()
{
	char a[9][19]={{'*',' ','*',' ','*',' ','*',' ','*'},{' ',' ','*',' ','*',' ','*',' ','*',' ','*'},{' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*'},
	{' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*'},{' ',' ',' ',' ',' ',' ',' ',' ','*',' ','*',' ','*',' ','*',' ','*'}};
	int i,j;
	for(i=0;i<9;i++)
	{
	
	   for(j=0;j<19;j++)
	   	printf("%c",a[i][j]); 
	   	printf("\n");
	   }
	printf("\n");
	return 0;
}
