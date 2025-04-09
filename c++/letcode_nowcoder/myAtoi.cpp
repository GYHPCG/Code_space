#include<iostream>

#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int st = 0;
        int l = s.length();
        string s1;
        for (int i = st; i < l; i++) {
        	if (s[i] != ' ' ) {
        		if ((s[i] == '-' || s[i] == '+')&& s[i+1] >='0' && s[i] <= '9') {
        			s1 += s[i];
				}
				if(s[i] >= '0' && s[i] <= '9') {
					s1 += s[i];
				}
        		
			}
		}
		long sum = 0;
		int sq = 0;
		if (s1[0] == '+' || s1[0] == '-') {
			 	sq = 1;
			}
		for (int i = sq; i < s1.length(); i++) {
			 char x = s1[i];
			 int x1 = x - '0';
			 sum = sum*10 +x1;
		}
		if (s1[0] == '-') {
			sum = -sum;
		}
		if (sum > INT_MAX) {
			sum = INT_MAX;
		}
		if (sum < INT_MIN) {
			sum = INT_MIN;
		}
		return sum;  
    }
};
int main()
{
	Solution s;
	string s1 = "words and 987";
	//cout << s1 << endl;
	cout << s.myAtoi(s1) << endl;
	return 0;	
} 
