#include<iostream>
#include<string>
using namespace std;
int reverse(int x) {
        int res = 0;
        int x1 = abs(x);
        while (x1) {
            if (res > INT_MAX /10) return 0;
            int t = x1 % 10;
            // res += t;
            res = res * 10 + t;
            x1 = x1 /10;
        }
       if (x < 0) res = -res;
        // res = res /10;
        return res;
    }
int main()
{
	int x;
	cin >> x;
	int r = reverse(x) ;
	cout << r;
	cout << endl;
	return 0;
} 
