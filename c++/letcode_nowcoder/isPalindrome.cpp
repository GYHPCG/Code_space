#include<iostream>
#include<string>
using namespace std; 
class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for(int i = 0;i < s.length();i++)
        {
            if(isalnum(s[i]))
            {
                s1 += towlower(s[i]);
            }
        }
        for(int i = 0,j = s1.length()-1;i <= j;i++,j--)
        {
            if(s1[i] != s1[j])
                return false;
        }
        return true;

    }
};
int main()
{
	Solution a;
	string a1;
	cin >> a1;
	cout<<a.isPalindrome(a1);
	return 0;
}
