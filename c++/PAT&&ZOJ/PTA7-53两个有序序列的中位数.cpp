#include<iostream>
using namespace std;
#define N 100000
int main()
{
	  int n;
	  cin>>n;
	  int a1[N];//�Ѿ�֪��������󳤶ȣ���ô��ɲ�����vector���� 
	  int a2[N]; 
	  for(int i=0;i<n;i++)
	  cin>>a1[i];
	  for(int i=0;i<n;i++)
	  cin>>a2[i];
	  int j=0,k=0;
	  int mid=0;
	  //����λ�����������鲢���󼴳���2n,��ô
	  //�鲢��������ʱ����λ�����ǵ�n����
	  //Ҳ���ǹ鲢n��ʱ�Ľ������mid����������ɡ�
	  for(int j=0;j<n;j++) 
	  {
	  	if(a1[j]<=a2[k])
	  	{
	  		mid=a1[j];
	  		j++;
		}
		else
		{
			mid=a2[k];
			k++;
		}
	  }
	  cout<<mid;
	  return 0;
} 
