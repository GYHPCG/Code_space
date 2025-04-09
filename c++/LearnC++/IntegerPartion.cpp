/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-02 13:11:32
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-03 17:02:40
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
using ll = long long;
vector<vector<ll> > Enum;
vector<ll>path;
ll getEnum(ll n, ll m) {
   if (n == 1 || m == 1) {
    return 1;
   }
   else if ( m > n) {
    return getEnum(n,n);
   }
   else if (m == n) {
    return 1 + getEnum(n,n-1);
   }
   else return getEnum(n-m,m) + getEnum(n,m-1);
   return 0;

}
void Count(int n, int m, string& s) {
    if (n == 0) cout << s << endl;
    else {
        if (m > 1) {
            Count(n, m-1, s);
        }
        if (m <= n) {
            s = (m - '0') + " " + s;
            Count(n-m,m,s);
        }
    }
}
// void print(vector<vector<ll>>& vec) {
//     for (auto i = 0 ; i < vec.size();++i) {
//         for (auto j = 0; j < vec[i].size(); ++j) {
//             cout << vec[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
class IntPart
{
public:
  static std::string part(long long n);
};
int main()
{
    Enum.clear();
    path.clear();
    cout << getEnum(4,4) << endl;
    //print(Enum);
    string s = " ";
    Count(4,4,s);
    return 0;
}

