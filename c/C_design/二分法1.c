#include<stdio.h>
int search(int arr[],int n,int len)
{
	int left=0;
	int ret=-1;
	int right=len-1;
	while(left<=right)
	{
		int mid=(right+left)/2;
		if(arr[mid]=n)
		{
		   ret=mid; 
		   break;
		}
		else if(arr[mid]>n)
		   right=mid-1;
		else if(arr[mid]<n)
		   left=mid+1;
		else
		printf("NO\n");
		
	}
	return ret;
}
int main()
{
	int arr[15];
	int i=0;
	for(i=0;i<15;i++)
	scanf("%d",&arr[i]);
	int n;
	scanf("%d",&n);
	int c=search(arr,n,sizeof(arr)/sizeof(arr[0]));
	printf("%d\n",c-2);
	return 0;
}

