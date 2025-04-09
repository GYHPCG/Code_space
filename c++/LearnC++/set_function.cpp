#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void myPrint(int x) {
	cout << x <<" ";
}
//求交集
void test01()
{
	vector<int>v1;
	vector<int>v2;
	vector<int>vTarget(10);
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
	auto itEnd = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
	for_each(vTarget.begin(),itEnd,myPrint);
	cout << endl;
	
}
//求并集 
void test02() {
	vector<int>v1;
	vector<int>v2;
	vector<int>vTarget(10);
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
	auto itEnd = set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
	for_each(vTarget.begin(),itEnd,myPrint); 
	cout << endl;
}
//求补集
void test03() {
	vector<int>v1;
	vector<int>v2;
	vector<int>vTarget(10);
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i+5);
	}
	auto itEnd =  set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());
	for_each(vTarget.begin(),itEnd,myPrint);
	cout << endl;
} 
int main()
{
	test01();
	test02();
	test03();
	return 0;
}
 
