#include<stdio.h>
int main()
{
	void sort(int a[],int n);
	int i,n;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	    scanf("%d",&a[i]);
	sort(a,n);
	printf("After sorted the array is :");
	for(i=0;i<n;i++)
	printf(" %d",a[i]);
	printf("\n"); 
	return 0;
}
void sort(int a[],int n)
{
	int i,j,k,m;
	for(i=0;i<n;i++){
		k=i;
		for(j=i+1;j<n;j++)
		   if(a[j]<a[k])k=j;
		   m=a[k],a[k]=a[i],a[i]=m;
	}
}
