#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	 for(i=1;i<=n;i++)
	 {
	 	long int a,b,c;
	 	cin>>a>>b>>c;
	 	if(a+b>c)cout<<"Case #"<<i<<": true"<<endl;
		 else cout<<"Case #"<<i<<": false"<<endl;
	 }
	return 0;
 } 
