#include <iostream>
#include <algorithm> 
#include <list>

using namespace std ;

int main()
{
	list <int> L1 ;		//链表1 
	list <int> L2 ;		//链表2 
	list <int> L3 ;		//交集链表 
	
	//链表1压入
	int x1 ;
	while(cin>>x1 && x1 != -1) 
	{
		L1.push_back(x1) ; 
	} 
	
	//链表2压入
	int x2 ;
	while(cin>>x2 && x2 != -1) 
	{
		L2.push_back(x2) ; 
    }
	//求交集函数 
	set_intersection(L1.begin(), L1.end(), L2.begin(), L2.end(), inserter(L3,L3.begin()));
	L1.clear();
	L2.clear();  
	if ( L3.empty() ) cout<<"NULL" ;
	else
	{
		while(!L3.empty())        //处理输出末尾没有多余空格。 
		{
			if(L3.size()==1)
			{
				cout<<L3.front();
				L3.pop_front();
			}
			else
			{
				cout<<L3.front()<<" ";
				L3.pop_front();
			}
		}
	}
	
	return 0 ;
}

