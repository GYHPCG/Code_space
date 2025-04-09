
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

constexpr int N = 1010;
int n, k, x;
int a[N];
int main() {

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
  
  for (int i = 0; i <= N; i++) a[i] = i;

  cin >> n >> k;
  while(k--) {
    cin >> x;
    x = n - x;
    reverse(a+1, a + n+1);
    reverse(a+1, a+x+1);
    reverse(a+x+1, a+n+1);

    int num = n / 2;
    reverse(a + 1, a + num + 1);
    
  }

  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
  cout << '\n';
  return 0;
}