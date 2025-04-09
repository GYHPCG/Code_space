#include <algorithm>
#include <iostream>
#include <vector>


using namespace std;

const int N = 10;
int n;
bool used[N];
int path[N];

void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++) {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            used[i] = true;
            path[u] = i;
            dfs(u + 1);
            used[i] = false;
            path[u] = 0;
        }
    }
}
int main() {

  cin >> n;

  dfs(0);

  return 0;
}
