#include<stdio.h>
int main()
{
	int a[10];
	int i=0;
	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
	}
	int *p;
	p=a;
	for(p=a;p<(10+a);p++)
		printf("%d ",*p);
	return 0;
}
