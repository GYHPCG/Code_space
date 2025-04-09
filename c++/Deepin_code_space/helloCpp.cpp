#include<stdio.h>
#include <iostream>
using namespace std;
int main()
{
	
	printf("hello,world\n");
	printf("hello,cpp\n");
	//泛型lambda
	auto f = [](const auto& x) {
		return x + x;
	};
	cout << f(3) << endl;
	cout << f(4.567) << endl;
	string s{"hello"};
	cout << f(s) << endl;
	cout << "cxx" << endl;

	return 0;
}
