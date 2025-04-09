#include<iostream>
#include<cstdio>                              
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int a[n+10][m+10];
	int i,j;
	for(i=1;i<=n;i++)
	   for(j=1;j<=m;j++)
	       cin>>a[i][j];
	for(i=1;i<=m;i++)
	    {
	    	for(j=1;j<=n;j++)
	    	{
	    		cout<<a[j][i]<<" ";
			}
			cout<<endl;
		}
    return 0;
 }     

