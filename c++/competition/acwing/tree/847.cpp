#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int N = 1e5+10, M = 2 * N;
int h[N],e[M], ne[M],idx;
int d[N];
int n, m;
void addEdge(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void bfs() {
   memset(d, -1, sizeof d);
   queue<int> q;
   q.push(1);
   d[1] = 0;
   
   while(!q.empty()) {
    auto& t = q.front();
    q.pop();
    for (int i = h[t]; ~i; i = ne[i]) {
        int v = e[i];
        if(d[v] == -1) {
            d[v] = d[t] + 1;
            q.push(v);
        }
    }
   }
//    return d[n];
}
int main() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        addEdge(a, b);
    }
    bfs();

    cout << d[n] << endl;

    return 0;
}