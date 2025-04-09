#include<stdio.h>
#include<string.h> 
struct p
{
	char na[10];
	char xh[100];
	int score;
}a[100],x;
int main()
{
    int n,i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	    scanf("%s%s%d",&a[i].na,&a[i].xh,&a[i].score);
	}
	for(i=0;i<n;i++)
	  for(j=0;j<n-1-i;j++)
	{
		  if(a[j].score>a[j+1].score){
				  x=a[j];
				  a[j]=a[j+1];
				  a[j+1]=x;
		  }
	}
	printf("%s %s\n",a[n-1].na,a[n-1].xh);
	printf("%s %s\n",a[0].na,a[0].xh);	
	return 0;
} 
