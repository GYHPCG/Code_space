#include<iostream>
#include <string>
#include <stdlib.h>
using namespace std;
string getSum (int num) {
	 string s;
	 //s += num + '0';
	 //itoa(num,s,10);
	 sprintf(s,"%d",num);
	 return s;
} 
int main()
{
	int x;
	cin >> x;
	cout << getSum(x) << endl;
	return 0;		
} 
