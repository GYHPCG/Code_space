#include<iostream>
// #include<bits/stdc++.h>
void print()
{
}
using namespace std;
template<typename T,typename...Types>
void print(const T& f1,const Types&...s1)
{
	cout<<f1<<endl;
	cout<<sizeof...(s1)<<endl;
	print(s1...);
}
int maximum(int n)
{
	return n;
}
template<typename...Args>
int maximum(int n,Args...args)
{
	return max(n,maximum(args...));	
}
int main()
{
	print(7.5,"hello",bitset<8>(128),42);
	cout<<endl;
	cout<<maximum(13,45,23,56,73,1234,567)<<endl;
	vector<int>arr{123,454,3,56,789,3424,455,64};
	cout<<*max_element(arr.begin(),arr.end());
	return 0;
}
