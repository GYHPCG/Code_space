#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std; 
string reverseWords(string s) {
        string res;
        for(int i = 0;i < s.length()-1;i++)
        {
            if(s[0]==' ')
                s.erase(s.begin());
            if(s[i]==' '&&s[i+1]==' ')
            {
                s.erase(s.begin()+i);
            }
        }
        int k = s.length()-1;
        if(s[k]== ' ')
            s.erase(s.begin()+k);
        reverse(s.begin(),s.end());
        int j = 0;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == ' ')
            {
                reverse(s.begin()+j,s.begin()+i);
                j = i+1;
            }
        }
        for(int i1 = s.length()-1;i1 >= 0;i1--)
        {
            if(s[i1] == ' ')
            {
                reverse(s.begin()+i1+1,s.end());
                break;
            }
        }
       return s;
    }
int main()
{
	string s;
	cin >> s;
	cout << reverseWords(s);
	return 0;
}
