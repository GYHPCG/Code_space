#include<iostream>
using namespace std;
int main()
{
	int x = 5;
	
	int& r = x;//reference必须在声明时就有初始化，否则Error
			   //reference r可以说是 x的代表，也就是说字节和value都和x一模一样。
			   //即使reference在本质上是使用pointer来实现的，当我们改变r的值时，x的值也会变化。 
	int* p = &x;
	int x2 = 23;
	    r = x2; //cout:r:23,x:23,表明reference不再可以指向其他物体.可以说reference是一种代表. 
	 //64位机器下： 
	cout<<"size(x):"<<sizeof(x)<<" "<<"value:"<<x<<endl; //size(x):4 value:5 
	 
	cout<<"size(r):"<<sizeof(r)<<" "<<"value:"<<r<<endl; //size(r):4 value:5
	 
	cout<<"size(p):"<<sizeof(p)<<" "<<"value:"<<*p<<endl;//size(p):8 value:5
	//address对比：三者地址一模一样的 ，但是reference本质上是一种漂亮的指针，只是被刻意设计成和它所代表的变量一模一样。 
	cout<<"p的地址:"<<p<<endl; //p的地址:0x70fdf8

	cout<<"r的地址:" <<&r<<endl;//r的地址:0x70fdf8
	
	cout<<"x的地址:"<<&x <<endl;//x的地址:0x70fdf8
	 
	cout<<"r="<<r<<" "<<"x="<<x<<endl;//r=23,x=23;
	r--;
	cout<<"r="<<r<<" "<<"x="<<x<<endl;//r=22,x=22;
	return 0;
} 
