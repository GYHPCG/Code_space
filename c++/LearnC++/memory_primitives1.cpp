#include<iostream>
#include<complex>
#include<bits/stdc++.h>
using namespace std;
int main()
{
//	one
	void* p1 = malloc(512);
	free(p1);
//	two
	complex<int>* p2 = new complex<int>;
	delete p2;
//	three
	void* p3 = ::operator new(512);
	::operator delete(p3);
//	   four
	#ifdef __GNUC__
	void* p4 = alloc::allocate(512);
	alloc::deallocate(p4,512);
	#endif
	return 0;	
}
