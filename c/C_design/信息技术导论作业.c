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
        x=x+a[i]*pow(2,i);//����Ȩֵ����ת��
    }
    return x;//����ʮ����
}
printf("%d\n",x);
char t[10001];//����ַ�������������ǵĽ��
void erfen(int minn,int maxx,int k)
{
    int cnt=0;
    int L=minn,R=maxx;//�涨��Χ
    while(L<=R){
        int mid=(L+R)>>1;//ȡ�е�
        if(k>mid){//����е������Ҫ�ҵ�С
            t[++cnt]='1';//��λ��1
            L=mid+1;//���ҷ�Χ����
        }
        else{
            t[++cnt]='0';//����е������Ҫ�ҵĴ����λ��0
            R=mid-1;//����Χ����
        }
    }
}
int main()
{
    char a1[1001];
    char a[10001];
    char b[10001];
    scanf("%s",a1);//��������ƴ���������Ƿ���
    int x,maxx,minn=0;
    int len = strlen(a1);
    for(int i=0;i<len;i++){
        a1[i]-='0';//�ַ�תΪ����
        a[len-1-i]=a1[i];//�Ѷ����ƴ�����
        b[i]='1'-'0';//������������¶����Ƶ���ʽ1111����
    }
    x=erjin(len,a);//�����Ʊ�Ϊʮ����
    maxx=erjin(len,b);//��len��������µ������
    erfen(minn,maxx,x);//���ַ�
    for(int i=1;i<=len;i++){
         printf("%c",t[i]);//������
    }
    return 0;
}
//���ݶ��������ҵĸߵ�λ�������ǽ��з��β���

