
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

i64 m, n, k;
// 快速幂是用乘法来表示乘方
// 龟速加是用加法表示乘法
int qmi(i64 m, i64 n, i64 p) {
    i64 res = 1 % p;
    while(n) {
        if (n & 1) res = res * m % p;
        m = m * m % p;
        n >>= 1;
    }
    return res;
}
i64 qad(i64 m, i64 n, i64 p) {
    i64 res = 0;
    while(n) {
        if (n&1) res = (res+m) % p;
        m = (m+m) % p;
        n >>= 1;
    }
    return res;
}
int main() {

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n >> k;
  cout << qad(m, n, k) << endl;
  return 0;
}