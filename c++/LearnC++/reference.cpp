#include<iostream>
using namespace std;
int main()
{
	int x = 5;
	
	int& r = x;//reference����������ʱ���г�ʼ��������Error
			   //reference r����˵�� x�Ĵ���Ҳ����˵�ֽں�value����xһģһ����
			   //��ʹreference�ڱ�������ʹ��pointer��ʵ�ֵģ������Ǹı�r��ֵʱ��x��ֵҲ��仯�� 
	int* p = &x;
	int x2 = 23;
	    r = x2; //cout:r:23,x:23,����reference���ٿ���ָ����������.����˵reference��һ�ִ���. 
	 //64λ�����£� 
	cout<<"size(x):"<<sizeof(x)<<" "<<"value:"<<x<<endl; //size(x):4 value:5 
	 
	cout<<"size(r):"<<sizeof(r)<<" "<<"value:"<<r<<endl; //size(r):4 value:5
	 
	cout<<"size(p):"<<sizeof(p)<<" "<<"value:"<<*p<<endl;//size(p):8 value:5
	//address�Աȣ����ߵ�ַһģһ���� ������reference��������һ��Ư����ָ�룬ֻ�Ǳ�������Ƴɺ���������ı���һģһ���� 
	cout<<"p�ĵ�ַ:"<<p<<endl; //p�ĵ�ַ:0x70fdf8

	cout<<"r�ĵ�ַ:" <<&r<<endl;//r�ĵ�ַ:0x70fdf8
	
	cout<<"x�ĵ�ַ:"<<&x <<endl;//x�ĵ�ַ:0x70fdf8
	 
	cout<<"r="<<r<<" "<<"x="<<x<<endl;//r=23,x=23;
	r--;
	cout<<"r="<<r<<" "<<"x="<<x<<endl;//r=22,x=22;
	return 0;
} 
