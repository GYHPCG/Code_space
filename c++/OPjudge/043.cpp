#include<iostream>
#include<map>
using namespace std;
multimap<int,int>mp;
typedef multimap<int,int>::iterator mpir;
void De_Max(mpir i,mpir j)
{
	if(i->first==j->first)
	{
		if(i->second < j->second)
			mp.erase(j);
		else mp.erase(i);
	}
}
int main()
{
	int num,power,id;
	cin >> num;
	mp.insert(make_pair(1000000000,1));
	while(num--)
	{
		cin >> id >> power;
		mpir im,in,i,j;
		im = mp.insert(make_pair(power,id));
		i = im;
		i--;
		j = im;
		j++;
		if(im==mp.begin())
		{
			cout<<im->second<<" "<<j->second<<endl;
			De_Max(im,j);	
		}
		else if(im==(--mp.end()))
		{
			cout<<im->second<<" "<<i->second<<endl;
			De_Max(im,i);	
		}
		else
		{
			 int d1 = im->first - i->first;
			 int d2 = j->first - im->first;
			 if(d1 < d2||d1==d2&&i->second < j->second)
			 {
			 	cout<<im->second<<" "<<i->second<<endl;
			 	De_Max(im,i);
			 }
			 else
			 {
			 	cout<<im->second<<" "<<j->second<<endl;
			 	De_Max(im,j);
			 }
		}	
	}	
} 
