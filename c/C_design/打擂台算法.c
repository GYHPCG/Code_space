#include<stdio.h>
int main()
{
	int a[3][4]={{1,2,3,4},{9,8,7,6},{-10,10,-5,2}};
	int max=a[0][0];
	int b=0,c=0;
	int d=0,e=0;
	for(b=0;b<=2;b++)
	   for(c=0;c<=3;c++)
	   if(a[b][c]>max){
	   	max=a[b][c];
	   	d=b;
	   	e=c;
	   }
	   printf("%d %d %d\n",max,d,e);
	   return 0;
 } 
