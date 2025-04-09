#include<stdio.h>
int main()
{
	void arrayShiftRight(int a[],int n,int m);

	int i,n,m;

        scanf("%d%d",&n,&m);

	int arr[n];

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

        arrayShiftRight(arr,n,m);

	for(i=0;i<n;i++)

		printf("%d ",arr[i]);

	return 0;

}
void arrayShiftRight(int a[],int n,int m)
{
	int i,j,k,d;
	for(j=0;j<m;j++){
		d=a[n-1];
		for(k=n-1;k>0;k--){
			a[k]=a[k-1];
		}
		a[0]=d;
	} 
	
}
/*{
	int i,j,t;
	for(i=0,j=n-m-1;i<j;i++,j--)
	{
	   t=a[i];
	   a[i]=a[j];
	   a[j]=t;
	}
	for(i=n-m,j=n-1;i<j;i++,j--)
	   {
	   t=a[i];
	   a[i]=a[j];
	   a[j]=t;
	   }
	for(i=0,j=n-1;i<j;i++,j--)
	   {
		t=a[i];
		a[i]=a[j];
		a[j]=t;
	   }
}*/
