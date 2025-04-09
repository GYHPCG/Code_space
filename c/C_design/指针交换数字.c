#include<stdio.h>
int main()
{
	void swap(int *p1,int *p2);
	int a,b;
	scanf("%d%d",&a,&b);
	int *po1,*po2;
	po1=&a;
	po2=&b;
	swap(po1,po2);
	printf("%d %d\n",*po1,*po2);
	return 0;
}
void swap(int *p1,int *p2)
{
 	int p;
 	p=*p1;
 	*p1=*p2;
 	*p2=p;
}
