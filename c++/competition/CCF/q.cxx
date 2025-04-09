#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n,m,p,q;

int main() {
    cin >> n >> m >> p >> q;
    vector<int> M;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            M.push_back(x);
        }
    }

    // vector<int> T;
    for (int i = 0; i < p; i++) {
        for (int j = 0;j < q; j++) {
            cout << M[i*q+j] << ' ';
        }
        cout << endl;
    }
    return 0;
}