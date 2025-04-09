#include<bits/stdc++.h>
using namespace std;
int main()
{
	list<int> lists[10001];
	int num ;
	int count1;
	int count2;
	int nume;
	string s; 
	cin >> num;
	while(num--)
	{
		cin >> s;
		if(s=="add")
		{
		
				cin >> count1 >> nume;
				lists[count1].push_back(nume);
	    }
		else if(s=="new")
		{
				cin >> count1;
	    }
		else if(s=="merge")
		{
				cin >> count1 >> count2;
				lists[count1].merge(lists[count2]);
	    }
		else if(s=="out")
		{
		
				cin >> count1;
				lists[count1].sort();
				for(auto it = lists[count1].begin();it != lists[count1].end();it++)
				{
					cout<<*it<<" ";
				}
				cout << endl;
		}
		else{
				cin >> count1;
				lists[count1].sort();
				lists[count1].unique();
		}
		
	}
	return 0;
}
/*#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
typedef list<int> L;

void printlist(const list<int>::iterator stri,const list<int>::iterator endi)
{
    list<int>::iterator tmp;
    for(tmp = stri;tmp!=endi;tmp++)
        cout<<*tmp<<' ';
    cout<<endl;
    return;
}

int main()
{
    L lst[10010];
    L::iterator i;
    string func;
    int opernumbers,number,target,name;
    cin>>opernumbers;
    while(opernumbers--)
    {
        cin>>func;
        if(func == "new")
            cin>>name;
        else if(func == "add")
        {
            cin>>name>>number;
            lst[name].push_back(number);
        }
        else if(func == "merge")
        {
            cin>>name>>target;
            lst[name].merge(lst[target]);
        }
        else if(func == "unique")
        {
            cin>>name;
            lst[name].sort();
            lst[name].unique();
        }
        else
        {
            cin>>name;
            lst[name].sort();
            printlist(lst[name].begin(),lst[name].end());
        }
    }
    return 0;
}*/


