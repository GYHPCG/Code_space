#include<stdio.h>
int main()
{
	int n;
    2<n&&n<=40;
	scanf("%d",&n);
	int i,a[40]={1,1};
	for(i=2;i<n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	for(i=0;i<n;i++){
		if(i%5==0)
		printf("\n");
		printf("%12d",a[i]);
		
	}
	printf("\n");
	return 0; 
	
}
