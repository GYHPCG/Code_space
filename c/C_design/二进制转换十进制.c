/*#include<stdio.h>
#include<math.h>
int main()
{
	 
	long int i,n,x=0,a;
	scanf("%ld",&n);
	for(i=0;n!=0;++i)
	{
		a=n%10;
		x=(a)*(pow(2,i))+x;
		n=n/10;
	}
	printf("%ld",x);
	
	return 0;
}*/
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 500
int er(int len, char a[])
{
    int x=0;
    int i;
    for(i=len-1;i>=0;i--)
	{
        x=x+a[i]*pow(2,i); 
    }
    return x;
}
char t[N];
void erfen(int min,int max,int k)
{
    int cnt=0;
    int L=min,R=max;
    while(L<=R){
        int mid=(L+R)>>1;
        if(k>mid){
            t[++cnt]='1';
            L=mid+1;
        }
        else{
            t[++cnt]='0';
            R=mid-1;
        }
    }
}


int main()
{
	/*int er(int len, char a[]);
	void erfen(int min,int max,int k);*/
	
    char a1[N];
    char a[N];
    char b[N];
    scanf("%s",a1);
    int x,max,min=0;
    int len = strlen(a1);
    int i;
    for( i=0;i<len;i++){
        a1[i]-='0';
        a[len-1-i]=a1[i];
        b[i]='1'-'0';
    }
    x=er(len,a);
    int t[i];
    max=er(len,b);
    erfen(min,max,x);
    for(i=1;i<=len;i++)
	{
         printf("%c",t[i]);
    }
    return 0;
}

