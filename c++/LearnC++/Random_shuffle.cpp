#include<iostream>
#include<vector>
#include<algorithm> 
#include<ctime>
using namespace std;
void test01()
{
	srand((unsigned int)time(NULL));
	vector<int>Vec;
	for (int i = 0; i < 10; i++)
		Vec.push_back(i);
//	sort(Vec.begin(),Vec.end());
	sort(Vec.begin(),Vec.end(),greater<int>());
	random_shuffle(Vec.begin(),Vec.end());
	for (int k: Vec)
		cout<< k <<" ";
	cout<<endl;
	 
}
int main()
{
	test01();
	return 0;
}
