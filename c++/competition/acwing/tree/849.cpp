#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

const int N = 2e5 + 10;
int h[N], e[N], w[N], ne[N], idx, n, m, dist[N];
bool vis[N];

void add(int &a, int &b, int &c) {
  e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int spfa() {
  memset(dist, 0x3f, sizeof dist);
  queue<int> q;
  q.push(1);
  dist[1] = 0;
  vis[1] = true;

  while (q.size()) {
    auto &t = q.front();
    q.pop();
    vis[t] = true;
    for (int i = h[t]; ~i; i = ne[i]) {
      int v = e[i];
      if (dist[v] > dist[t] + w[i]) {
        dist[v] = dist[t] + w[i];
        if (!vis[v]) {
          q.push(v);
          vis[v] = true;
        }
      }
    }
  }
  return dist[n];
}
int main() {
  cin >> n >> m;
  memset(h, -1, sizeof h);
  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    add(a, b, c);
  }

  auto res = spfa();
  if (res == 0x3f3f3f3f) {
    cout << -1 << '\n';
  } else {
    cout << res << '\n';
  }
  return 0;
}
