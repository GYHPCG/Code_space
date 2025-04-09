#include<iostream>
using namespace std;
class A
{
	private:
		int i;
	public:	A(){
			i=0;cout<<"A::A()"<<endl;
		}
		~A(){
			cout<<"A::~A(),i="<<i<<endl;
		}
	public:
		void set(int i){
			this->i=i;
		} 
		void f(){
			cout<<"hello"<<endl;
		}
}; 

int main()
{
	   A *p=new A[10];
	   int i;
	   for(i=0;i<10;i++){
	   	p[i].set(i);
	   }
	   delete[] p;
	return 0;
} 
