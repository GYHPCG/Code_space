#include<stdio.h>
int main()
{
	int n;
	int b;
    2<n&&n<=40;
	scanf("%d",&n);
	int i; 
	int a[40]={1,1};
	for(i=2;i<n;i++){
		a[i]=a[i-1]+a[i-2];
	}
	for(i=0;i<n;i++){
	    b++;
		if(b%6==0){
		printf("\n");
		b=1;
		}
		printf("%12d",a[i]);
	}
	printf("\n");
	return 0; 
	
}
