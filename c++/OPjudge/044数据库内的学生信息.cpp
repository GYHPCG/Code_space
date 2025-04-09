#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;
// �ڴ˴�������Ĵ���

template <typename T1,typename T2,class Pred = greater<T1> >
class MyMultimap:public multimap<T1,T2,Pred>
{
	public:
		void Set(T1 sname,T2 sore)
		{
		   using mp = typename multimap<T1,T2,Pred>::iterator;
			mp st_it,end_it;
			st_it =  multimap<T1,T2,Pred>::lower_bound(sname);
			end_it =  multimap<T1,T2,Pred>::upper_bound(sname);
			while(st_it!=end_it)
			{
				st_it->second = sore;
				st_it++;
			}		
		}
	
			
}; 
template <typename T1,typename T2>
ostream& operator <<(ostream& ot,const pair<T1,T2>& s)
{
	 ot <<"("<<s.first<<","<<s.second<<")";
	 return ot;
}
struct Student 
{
	string name;
	int score;
};
template <class T>
void Print(T first,T last) {
	for(;first!= last; ++ first)
		cout << * first << ",";
	cout << endl;
}
int main()
{
	
	Student s[] = { {"Tom",80},{"Jack",70},
					{"Jone",90},{"Tom",70},{"Alice",100} };
	
	MyMultimap<string,int> mp;
	for(int i = 0; i<5; ++ i)
		mp.insert(make_pair(s[i].name,s[i].score));
	Print(mp.begin(),mp.end()); //�������Ӵ�С���

	mp.Set("Tom",78); //��������Ϊ"Tom"��ѧ���ĳɼ�������Ϊ78
	Print(mp.begin(),mp.end());
	
	
	
	MyMultimap<int,string,less<int> > mp2;
	for(int i = 0; i<5; ++ i) 
		mp2.insert(make_pair(s[i].score,s[i].name));
	
	Print(mp2.begin(),mp2.end()); //���ɼ���С�������
	mp2.Set(70,"Error");          //�����гɼ�Ϊ70��ѧ�������ֶ���Ϊ"Error"
	Print(mp2.begin(),mp2.end());
	cout << "******" << endl;
	
	mp.clear();
	
	string name;
	string cmd;
	int score;		
	while(cin >> cmd ) {
		if( cmd == "A") {
			cin >> name >> score;
			if(mp.find(name) != mp.end() ) {
				cout << "erroe" << endl;
			}
			mp.insert(make_pair(name,score));
		}
		else if(cmd == "Q") {
			cin >> name;
			MyMultimap<string,int>::iterator p = mp.find(name);
			if( p!= mp.end()) {
				cout << p->second << endl;
			}
			else {
				cout << "Not Found" << endl; 
			}		
		}
	}
	return 0;
}
