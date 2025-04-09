#include<iostream>
using namespace std;
int isprime(int a)
{
	int flag = 0;
	for (int i = 2; i * i <= a; i++)
	{
		if (a % i == 0)
		{
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		return 1;
	}
	else
		return 0;
}
int main()
{	
	int n, m;
	cin >> m >> n;
	int cent = 0;
	int count = 0;
	for (int i = 2;; i++)
	{
		if (isprime(i) == 1)
		{
			cent++;
			if (cent >= m && cent <= n)
			{
				cout << i;
				count++;
				if (cent != n)
				{
					if (count % 10 == 0)
					{
						cout << endl;
					}
					else
					{
						cout << " ";
					}
				}
			}
			else
			if (cent > n)
			{
				break;
			}
		}
	}
	return 0;
}
