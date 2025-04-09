#include <cstring>
#include <iostream>

using namespace std;
// 并查集
const int N = 1e5 + 5;
int fa[N];

int find(int &x) {
  if (x != fa[x])
    fa[x] = find(fa[x]);
  return fa[x];
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    fa[i] = i;
  while (m--) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'M') {
        if (find(x) != find(y)) {
            fa[find(x)] = find(y);
        }
    }
    else {
        if (find(x) == find(y)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }


  }

  return 0;
}
