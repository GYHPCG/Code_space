#include<iostream>
using namespace std;
int a[10],b[10],n;
void dfs(int s)
{
	//int i;
	if(s==n+1)
	{
		for(int i=1;i<=n;i++)
		cout<<a[i];
		cout<<endl;
		return;
	}
	for( int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			a[s]=i;
			b[i]=1;
			dfs(s+1);
			b[i]=0;
		}
	}
	return;
}
int main()
{
	cin>>n;
	dfs(1);
	return 0;
} 
