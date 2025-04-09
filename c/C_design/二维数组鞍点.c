#include<stdio.h>
int main()
{
	int n,m;
	int b,k;
	scanf("%d%d\n",&n,&m);
	int a[n][m];
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int max=0;
	int maxj=0; 
	for(i=0;i<n;i++){

		max=a[i][0];
		maxj=0;
		for(j=0;j<m;j++)
		
			if(a[i][j]>max){
				max=a[i][j];
				maxj=j;
			}
		
		b=1;
		for( k=0;k<n;k++)
		    if(max>a[k][maxj])
			{
				b=0;
				continue;
				}
		   if(b=1)
		   {
		   	printf("%d %d %d\n",max,i,maxj);
		   	break;
			   }
		}
		if(!b)
		   
		   printf("NO\n");
	return 0;
}
