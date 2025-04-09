#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;

void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool used[N];
int n, ans = N;
int dfs(int u) {
  used[u] = true;
  int sum = 1, res = 0;
  for (int i = h[u]; ~i; i = ne[i]) {
    int v = e[i];
    if (!used[v]) {
      int t = dfs(v);
      res = max(t, res);
      sum += t;
    }
  }
  res = max(res, n - sum);
  ans = min(ans, res);

  return sum;
}
int main() {

//   cin >> n;
//   memset(h, -1, sizeof h);
//   for (int i = 0; i < n - 1; i++) {
//     int a, b;
//     cin >> a >> b;
//     add(a, b), add(b, a);
//   }
//   dfs(1);
//   cout << ans << endl;
  cout << "名为" << endl;
  return 0;
}