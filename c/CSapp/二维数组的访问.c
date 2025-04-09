#include<stdio.h>

void func(int m,int n,int a[][n])
{

    for(int i = 0;i<m;i++)
    {
    	int t =0;
        for(int j = 0;j<n;j++)
        {
            a[i][j] = t;
			t = t + i;
        }
    }	
}
int main()
{
    int m,n,i,j;

    scanf("%d%d",&m,&n);

    int a[m][n];

    func(m,n,a);

    int sum=0;

    for(i=0;i<m;i++)

        for(j=0;j<n;j++)

            sum+=a[i][j];

    printf("%d\n",sum);

    return 0;

}

