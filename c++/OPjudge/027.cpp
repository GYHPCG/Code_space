#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray( T* a,T* b)
{
	T sum=*a;
	for(T* i =a+1 ;i<b;i++)
	{
		sum+=*i;
	}
	return sum;
}


int main() {
	string array[4] = { "Tom","Jack","Mary","John"};
	cout << SumArray(array,array+4) << endl;
	int a[4] = { 1, 2, 3, 4};
	cout << SumArray(a,a+4) << endl;
	cout << "hello,wolrd" << endl;
	return 0;
}
