/*#include<stdio.h>
int getByte(int x,int n)
{
	 int result = 0;
	 for(int i =n*8;i<(n+1)*8;i++)
	 {
		  if((x>>i)&1)
		  result +=(1<<i);
	}
	return result>>(n*8); 
}
int main()
{

	int x,n;

	scanf("%x%d",&x,&n);  //ע�⣬x��16���Ƹ�ʽ���� 

	printf("%x\n",getByte(x,n)); //�����16���Ƹ�ʽ��� 

	return 0;

}*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>arr(n,0);
    for(int i =0;i< n;i++)
        cin >> arr[i];
    int minm = INT_MAX;
    int result =0;
    for(int i=0;i<n;i++)
    {
        minm = min(minm,arr[i]);
        result = max(result,arr[i]-minm);
    }
    if(result)cout<<result;
    cout<<"0";
    return 0;
}
