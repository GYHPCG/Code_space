#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int a[n+1];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int j,c,d,e;
	scanf("%d",&d);
	if(d>a[n-1])
	   a[n]=d;
	else {
		for(i=0;i<n;i++)
		{
			if(a[i]>d)
			{
			c=a[i];
			a[i]=d;
			for(j=i+1;j<=n;j++)
			{
				e=a[j];
				a[j]=c;
				c=e;
			}
			break;
		}
		} 
	}
	for(i=0;i<n+1;i++)
	printf("%d ",a[i]);
	printf("\n");
	
	return 0; 
}
