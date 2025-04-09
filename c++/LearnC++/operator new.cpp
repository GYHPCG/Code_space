#include<iostream>
#include<new>
using namespace std;
class Foo {
	public:
		int _id;
		long _data;
		string _str;
	public:
		Foo():_id(0) {
			cout<<"default ct"<<endl;
		}
		Foo(int i):_id(i) {
			cout << "cotr.this=" <<endl;
		}
		~Foo() {
			cout << "dtor.this"<<endl;
		}
		static void* operator new(size_t size);
		static void operator delete(void*pdead,size_t size);
		static void* operator new[](size_t size);
		static void operator delete[](void*pdead,size_t size);
		
};
void* Foo::operator new(size_t size) {
		Foo* p = (Foo*)malloc(size);
		cout<<"myOperator new"<<endl;
		return p;
}
void Foo::operator delete(void*pdead,size_t size) {
	cout<<"myOperator delete"<<endl;
	free(pdead);
	return;
}
void* Foo::operator new[](size_t size) {
	Foo* p = (Foo*)malloc(size);
	cout<<"my new[]" <<endl;
	return p;
}
void Foo::operator delete[](void*pdead,size_t size) {
	cout << "my delete[]"<<endl;
	free(pdead);
	return;
}
int main()
{
//	?????????§Õ??new ?? delete?? 
//	Foo* p = new Foo;
//	delete p;
//	????????????
	Foo* pf = ::new Foo; 
	::delete pf;
	return 0;	
} 
