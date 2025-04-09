#include<bits/stdc++.h>
using namespace std;
int main()
{
	 int n,num;
	 cin >> n;
	 string s;
	 multiset<int> st;
	 bool used[10001] = {false};
	 while(n--)
	 {
		 cin >> s >>num;
		 if(s=="add")
		 {
		 	used[num] = true;
		 	st.insert(num);
		 	cout<<st.count(num)<<endl;
		 }
		 else if(s=="del")
		 {
			 cout<<st.count(num)<<endl;
			 st.erase(num);
		 }
		 else if(s=="ask")
		 {
		 	if(used[num])
		 	{
		 		cout<<"1"<<" "<<st.count(num)<<endl;	
			}
			else cout<<"0"<<" "<<st.count(num)<<endl;
		 }
	 
    }
    return 0;
}
