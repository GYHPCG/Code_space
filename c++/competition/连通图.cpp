
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;
constexpr int N = 1e4 + 10;
// int p[N];
int n, m;
// 并查集做
// int find(int x) {
//   if (p[x] != x) p[x] = find(p[x]);
//   return p[x];
// }
int h[N], e[N], ne[N], idx;
bool st[N];
void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

int cnt;
int dfs(int root) {
  st[root] = true;
  cnt++;
  for (int i = h[root]; i != -1; i = ne[i]) {
    int j = e[i];
    if (!st[j]) {
      dfs(j);
    }
  }
  return cnt;
}
int main() {

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(nullptr);

  while (cin >> n >> m) {
    // for (int i = 1; i <= n; i++) p[i] = i;
    memset(h, -1, sizeof h);
    for (int i = 1; i <= m; i++) {
      int x, y;
      cin >> x >> y;
      //   p[find(x)] = find(y);
      add(x, y);
      add(y, x);
    }
    cnt = 0;
    bool t = 0;
    int ans = dfs(1);
    if (ans == n) {
        t = true;
        // cout << "kk" << endl;
    }
    else t = false;
    
    // cout << "dfs: " << ans << endl;
    // cout << "n: " << n << endl;
    memset(st, 0, sizeof st);
    // bool t = true;
    // for (int i = 1; i <= n; i++) {
    //     if (find(i) != find(1)) {
    //       t = false;
    //       break;
    //     }
    // }
    if (t)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}