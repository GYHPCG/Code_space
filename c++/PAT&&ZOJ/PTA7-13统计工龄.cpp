#include<iostream>
#define N 51
using namespace std;
int main()
{
	int n;
	cin>>n;
	int num[N]={0};
	int x;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		num[x]++;//Ͱ�����¼���ִ�������ϣҲ���ԡ� 
	}
	for(int i=0;i<N;i++)
	{
		if(num[i])
		{
			cout<<i<<":"<<num[i]<<endl;
		}
	}
	return 0;
} 
