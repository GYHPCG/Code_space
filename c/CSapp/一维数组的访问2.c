#include<stdio.h>
void func(int a[],int n)
{
    //n = n-3;
    for(int i = 0;i < n;i++)
    {
        int x = a[i];
        x = x + a[i+1];
        a[i+2] = x;
    }
}
int main()
{
    int n,i;

    scanf("%d",&n);

    int a[n];

    int sum=0;

    a[0]=a[1]=1;

    func(a,n);

    for(i=0;i<n;i++)

        sum+=a[i];

    printf("%d\n",sum);

    return 0;

}

