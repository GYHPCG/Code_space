#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
bool isPrime(int n1)
{
	if(n1 == 1)return false;
	else if(n1==2 || n1==3)return true;
	else
	{
		for(int i = 2;i < n1;i++)
		{
			if(n1 % i == 0)
				return false;
		}
	}
	return true;
}
int nextPrime(int n2)
{
	 if(n2 == 1)return 2;
	 int i,p=(n2 % 2)? n2 + 2:n2 + 1;
	 while(1)
	 {
	 	double q = p;
		 for(i = sqrt(q);i > 2;i--)
		 	if(!(p % i))break;
		if(i == 2)return p;
		else p+=2;	
	 } 
}
int main()
{
    int n,k,m;
    int size,key,pos,tmp;
    cin >>n >>k;
    if(isPrime(n))
    {
    	size = n;
	}
	else
	{
		size = nextPrime(n);
	}
    vector<int>arr(k,0);
    for(int i = 0;i < k;i++)
    {
        cin >> key;
		pos = key % size;
		m = 0;
		tmp = pos;
		while(m < size)
		{
			if(arr[pos]==0)
			{
				arr[pos] = key;
				cout<<pos;
				break;	
			}
			else
			{
				m++;
				pos = (tmp + m*m) % size;	
			}	
		}
		if(m == size)
		{
			cout<<"-";
		}
		if(i != k-1)
		{
			cout<<" ";	
		} 
        
    }
    
    return 0;
}
