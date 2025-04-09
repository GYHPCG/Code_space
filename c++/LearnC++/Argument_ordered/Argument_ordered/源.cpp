#include <iostream>

using namespace std;

void printSum(int a, int b)
{
	cout << "a: " << a << " b: " << b << endl;
}

int main()
{
	int value = 1;

	printSum(value++, value++);

	return 0;
}