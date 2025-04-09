#include<iostream>
using namespace std;

int main()
{
	int i = 0;
auto k=[i]()mutable{
	cout<<i<<" "<<endl;
	i++;
}; 
	i = 4;
	k();
	k();
	k();
	cout<<i<<endl;
	cout<<"hello,wolrld"<<endl;
	cout<<"wengkai";
	cout << "hello " << endl;
	return 0;
} 
