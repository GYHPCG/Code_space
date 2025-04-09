#include<iostream>
#include<map>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int power,id;
	multimap<int,int>mp;
	typedef multimap<int,int>::iterator mior;
	mp.insert(make_pair(1000000000,1));
	while(n--)
	{
		cin >> id >>power;
		mior im,in,i,j;
		im = mp.insert(make_pair(power,id));
		 if(im == mp.begin())
		 {
		 	in = im;
		 	in++;
		 	cout<<im->second<<" "<<in->second<<endl;
		 }
		 else if(im == (--mp.end()))
		 {
		 	in = im;
		 	in--;
		 	cout<<im->second<<" "<<in->second<<endl;
		 }
		 else
		 {
		 	i = im;
		 	i--;
		 	j = im;
		 	j++;
		 	int i1 = im->first - i->first;
		 	int j1 = j->first - im->first;
		 	if(i1 <= j1)
		 	{
		 		cout<<im->second<<" "<<i->second<<endl;	
			}
			else if(i1 > j1) 
			{
				cout<<im->second<<" "<<j->second<<endl;
			}
			
		 }
			
	} 
	return 0;	
} 
