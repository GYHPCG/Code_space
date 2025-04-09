#include<iostream>
using namespace std;
int n,m,p,q,minx=99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
	int next[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int tx,ty,k;
	if(x==p&&y==q)
	{
		if(step<minx)
		{
			minx=step;
		}
		return; 
	}
	for(k=0;k<4;k++)
	{
		  tx=x+next[k][0];
		  ty=y+next[k][1];
		  if(tx<1||tx>n||ty<1||ty>n)
		  continue;
		  if(a[tx][ty]==0&&book[tx][ty]==0)
		  {
		  	book[tx][ty]=1;
		  	dfs(tx,ty,step+1);
		  	book[tx][ty]=0;
		  }
	
	}
	return;
}
int main()
{
		int i,j,sx,sy;
		cin>>n>>m;
		for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
		   cin>>a[i][j];	
		}
		cin>>sx>>sy>>p>>q;
		book[sx][sy]=1;
		dfs(sx,sy,0);
		cout<<minx;
		return 0;
} 
