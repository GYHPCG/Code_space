#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;
unordered_map<char, int> mp;
unordered_map<char, char> rev;

bool is_left(char x)
{
    if (x == '{' || x == '[' || x == '(' || x == '<') return true;
    return false;
}

string solve(string& s)
{
    stack<char> st;

    for (int i = 0; i < s.size(); i ++ ) {
        if (st.empty() && !is_left(s[i])) return "NO";
        if (is_left(s[i])) {
        	if(st.empty()) {
        		st.push(s[i]);
        		//cout << "ii" << endl;
			}
            else if (!st.empty() && mp[st.top()] >= mp[s[i]]) {
                st.push(s[i]);
            }
            else return "NO";
        }

        if (!is_left(s[i])) {
//        	cout << "ll" << endl;
//        	cout << mp[st.top()] << "lp " << rev[s[i]] << endl;
            if (st.top() == rev[s[i]]) {
                st.pop();
                cout << "pp" << endl;
            }
            else return "NO";
        }
    }
    if (st.empty()) return "YES";

    return "NO";
}
int main()
{

    int n;
    cin >> n;

    mp.emplace('{', 5);
    mp.emplace('[', 4);
    mp.emplace('(', 3);
    mp.emplace('<', 2);

    rev.emplace('}', '{');
    rev.emplace(']', '[');
    rev.emplace(')', '(');
    rev.emplace('>', '<');

    while (n -- ) {
        string s;

        cin >> s;

        cout << solve(s) << endl;
    }

    return 0;
}
