#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct st{
	char name[20];
	int score;
}p[100];
struct str{
	bool operator() (const st & s1,const st & s2) const{
		if(s1.score==s2.score){
			if(strcmp(s1.name,s2.name)<0)
			return true;
			return false;
		}
		else return s1.score>s2.score;
	}
};
int main()
{
	int n,i;
	 cin>>n;
	 for(i=0;i<n;i++)
	 {
	 	cin>>p[i].name>>p[i].score;
	 }
	 sort(p,p+n,str());
	 for(i=0;i<n;i++)
	 {
	 	cout<<p[i].name<<" "<<p[i].score<<endl;
	 }
	 return 0;
	 
} 
