#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int i=0;
    vector<int>res(N,0);
    for(i=0;i<N;i++)
    {
    	cin>>res[i];
	}
	sort(res.begin(),res.end());
	for(i=0;i<N-1;i++)
	{
		cout<<res[i]<<" ";
	}
	cout<<res[N-1];
	return 0;
}   

