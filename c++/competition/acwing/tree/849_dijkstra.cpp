#include <iostream>
#include <cstring>
using namespace std;

const int N  = 510;
int g[N][N], dist[N];
bool st[N];
int n, m;

int dijsktra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < n; i++) {
        int t = -1;
        for (int j = 1; j <= n; j++) {
            if (!st[j] && (t == -1 || dist[t] > dist[j])) {
                t =j;
            }
        }
        st[t] = true;

        for (int j = 1; j <= n; j++) {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    return dist[n];
}   
int main() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b],c);
    }

    auto t = dijsktra();
    if (t == 0x3f3f3f3f) {
        cout << -1 << endl;
    }
    else cout << t << endl;

}