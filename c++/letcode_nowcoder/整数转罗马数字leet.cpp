#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        map<int, string> meta = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"},
        {4, "IV"}, {1, "I"}};
        string res;
        while (num > 0)
        {
            for (auto p = meta.rbegin(); p != meta.rend(); p++)
            {
                if (p->first <= num)
                {
                    res.append(p->second);
                    num -= p->first;
                    break;
                }
            }
        }
        return res;

    }
};
int main()
{
	Solution mp;
	int m;
	cin >> m;
	cout << mp.intToRoman(m);
	return 0;
}
