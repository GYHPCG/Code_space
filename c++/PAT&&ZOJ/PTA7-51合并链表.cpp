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
	l3.sort();//其实没必要使用l3,但题目要建一个新的，合并之后直接排序即可。 
	if(l3.empty())cout<<"NULL"; 
	
	while(!l3.empty()) //处理输出的问题，使没有多余的括号。 
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
