#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int x=0,y=0;
	cin>>x>>y;
	int a=1;
	while(a)
	{
		a=x%y;
		x=y;
		y=a;
	}
	cout<<x;
    return 0;	
} 
