#include<iostream>
using namespace std;
#define N 100000
int main()
{
	  int n;
	  cin>>n;
	  int a1[N];//已经知道数组最大长度，那么大可不必用vector来做 
	  int a2[N]; 
	  for(int i=0;i<n;i++)
	  cin>>a1[i];
	  for(int i=0;i<n;i++)
	  cin>>a2[i];
	  int j=0,k=0;
	  int mid=0;
	  //求中位数，两个数组并集后即长度2n,那么
	  //归并方法做的时候，中位数就是第n个，
	  //也就是归并n次时的结果，用mid记下输出即可。
	  for(int j=0;j<n;j++) 
	  {
	  	if(a1[j]<=a2[k])
	  	{
	  		mid=a1[j];
	  		j++;
		}
		else
		{
			mid=a2[k];
			k++;
		}
	  }
	  cout<<mid;
	  return 0;
} 
