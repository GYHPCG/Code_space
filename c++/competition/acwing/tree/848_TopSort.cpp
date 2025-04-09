#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e5 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx;
int d[N], route[N];
int n, m, len;
void addEdge(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

bool TopSort() {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    if (d[i] == 0)
      q.push(i), route[len++] = i;
  }

  while (q.size()) {
    auto& t = q.front();
    q.pop();
    for (int i = h[t]; ~i; i = ne[i]) {
      int j = e[i];
      d[j]--;
      if (d[j] == 0) {
        q.push(j);
        route[len++] = j;
      }
    }
  }
  return n == len;
}
int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    d[b]++; // 入度++；
    addEdge(a, b);
  }

  if (TopSort()) {
    for (int i = 0; i < len; i++) {
      cout << route[i] << " ";
    }
  } else {
    cout << "-1";
  }

  return 0;
}