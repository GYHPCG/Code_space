#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[15];
    int i=0;
    for(i=0;i<15;i++)
	{
        scanf("%d",&arr[i]);
    }
    int n;
    scanf("%d",&n);
   int b(int arr[],int n);
    int c=b(arr,n);
    printf("%d\n",c);
    return 0;
}
int b(int arr[],int n)
{

    int left=0;
    int ret=-1;
    int right=14;
    while(left<=right)
	{
        int mid=(left +right)/2;
        if(n<arr[mid])
            right=mid-1;
        else if(n>arr[mid])
            left=mid+1;
        else if(arr[mid]=n)
		{
            ret=mid;
            break;
        }
    }
    if(left>right)
	{
        printf("NO\n");
	}
    return ret;
}

