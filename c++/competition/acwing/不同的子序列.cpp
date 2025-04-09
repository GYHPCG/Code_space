
#include <algorithm>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;
constexpr int N = 1e4 + 10;
constexpr int MOD = 1000000007;
int n;
int dp[N]; // s中i,T中j个字符相等的个数
char a[N], b[N];
int main() {

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
//   cin >> n;
  scanf("%d", &n);
  while(n--) {
    scanf("%s%s", a + 1, b + 1);
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    vector<int> index[26];
    int n1 = strlen(a + 1);
    int n2 = strlen(b + 1);
    for (int i = 0; i <= n2; i++) {
      // index.push_back(b[i] - 'a');
      index[b[i] - 'a'].push_back(i);
    }
    for(int i = 1; i <= n1; i++) {
      // for(int j = n2; j >= 0; j--) {
      //   if(a[i] == b[j]) {
      //     dp[j] = (dp[j - 1] + dp[j]) % MOD;
      //   } 
      // }
      for (int k: index[a[i] - 'a']) {
        dp[k] = (dp[k - 1] + dp[k]) % MOD;
      }
    }
    cout << dp[n2] << endl;
  }
  return 0;
}