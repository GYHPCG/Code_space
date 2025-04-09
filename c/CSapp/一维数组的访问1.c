#include<stdio.h>
int func(int a[],int n)
{
    int res = 0;
    int x = n;
    if(n>0)
    {
        n = n-1;
        int n1 = 4*n+4;//n1:ecx
        int n2 = 0;//n2:edx
         do
        {
          res =res+ a[n2];
          n2 = n2 +4;
        }while(n1!=n2);
        
    }
    return res;
}
int main()
{
    int n,i;

    scanf("%d",&n);

    int a[n];

    for(i=0;i<n;i++)

        scanf("%d",&a[i]);

    printf("%d\n",func(a,n));

    return 0;

}

