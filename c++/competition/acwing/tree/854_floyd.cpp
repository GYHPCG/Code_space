#include <iostream>

using namespace std;
const int N = 210, INF = 2e9;
int g[N][N], dis[N][N];
int n, m, k;

void floyed() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
}
int main() {

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        dis[i][j] = 0;
      } else {
        dis[i][j] = INF;
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    dis[a][b] = min(dis[a][b], c);
  }
   floyed();
   while (k--) {
    int a, b;
    cin >> a >> b;
    if (dis[a][b] > INF / 2) {
      cout << "impossible" << endl;
    } else {
      cout << dis[a][b] << endl;
    }
  }

  return 0;
}