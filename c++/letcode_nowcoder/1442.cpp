#include <iostream>

using namespace std;


class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int res = 0;
        int t1 = 0;
        int t2 = 0;
        for (int i = 1; i < n; i++) {
                //cout <<"i= " << i << " " <<"j = " << j<<endl;
                t1 = getZero(s.substr(0,i));
                t2  = getOne(s.substr(i,n-i));
                cout << t1 << " " << t2 <<endl;
                cout << "-------" << endl;
                int t = t1 + t2;
                if (t > res) {
                    res = t;
            }
        }
        return res;
    }
    int getZero(string s1) {
        int m = 0;
        int end = s1.length();
        for (int i = 0; i < end; i++) {
            if (s1[i] == '0') m++;
        }
        return m;
    }
    int getOne(string s2) {
        int m = 0;
        int end = s2.length();
        for (int i = 0; i < end; i++) {
            if (s2[i] == '1') m++;
        } 
        return m;
    }
};

int main()
{
    Solution a;
    cout<<a.maxScore("110101");
    return 0;

}
