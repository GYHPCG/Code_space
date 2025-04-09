#include<stdio.h>
#include<string.h>
#define SC(a) scanf("%d",&a)
#define Rep(i,a,b) for(int i=a;i<b;i++)
#define PR(a) printf("%d",a)
#include<math.h>
#define PRN printf("\n")
int erjin(int len, char a[])
{
    int x=0;
    int i;
    for(i=len-1;i>=0;i--){
        x=x+a[i]*pow(2,i);//根据权值进行转换
    }
    return x;//返回十进制
}
printf("%d\n",x);
char t[10001];//这个字符串数组就是我们的结果
void erfen(int minn,int maxx,int k)
{
    int cnt=0;
    int L=minn,R=maxx;//规定范围
    while(L<=R){
        int mid=(L+R)>>1;//取中点
        if(k>mid){//如果中点比我们要找的小
            t[++cnt]='1';//高位进1
            L=mid+1;//在右范围查找
        }
        else{
            t[++cnt]='0';//如果中点比我们要找的大，则高位进0
            R=mid-1;//在左范围查找
        }
    }
}
int main()
{
    char a1[1001];
    char a[10001];
    char b[10001];
    scanf("%s",a1);//输入二进制串，这个串是反的
    int x,maxx,minn=0;
    int len = strlen(a1);
    for(int i=0;i<len;i++){
        a1[i]-='0';//字符转为数字
        a[len-1-i]=a1[i];//把二进制串调整
        b[i]='1'-'0';//计算这个长度下二进制的形式1111这种
    }
    x=erjin(len,a);//二进制变为十进制
    maxx=erjin(len,b);//在len这个长度下的最大数
    erfen(minn,maxx,x);//二分法
    for(int i=1;i<=len;i++){
         printf("%c",t[i]);//输出结果
    }
    return 0;
}
//根据二进制左右的高低位，让我们进行分治查找

