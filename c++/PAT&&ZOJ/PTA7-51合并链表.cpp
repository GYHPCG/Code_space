#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
int main()
{
	list<int>l1,l2,l3;
	int n;
	while(1)
	{
		cin>>n;
		if(n==-1)break;
		l1.push_back(n);
	}
	while(1)
	{   cin>>n;
	    if(n==-1)break;
		l2.push_back(n);
	}
	l1.merge(l2);
	l3.merge(l1);
	l3.sort();//��ʵû��Ҫʹ��l3,����ĿҪ��һ���µģ��ϲ�֮��ֱ�����򼴿ɡ� 
	if(l3.empty())cout<<"NULL"; 
	
	while(!l3.empty()) //������������⣬ʹû�ж�������š� 
	{
		if(l3.size()>1)
		{
			 cout<<l3.front()<<" ";
			 l3.pop_front() ;
		}
		if(l3.size()==1)
		{
			cout<<l3.front();
			l3.pop_front();
		}
	}
	return 0;
	
} 
