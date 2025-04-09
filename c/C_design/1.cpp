#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1001;
int dp[MAXN][MAXN];

void init() {
	 for (int i = 0; i < MAXN; ++i) {
        fill(dp[i], dp[i] + MAXN, 0);
    }
    for (int a = 1; a < MAXN; ++a) {
        for (int b = 1; b < MAXN; ++b) {
            if (__gcd(a, b) == 1) {
                dp[a][b] = max(dp[a][b], 1 + dp[a-1][b]);
                dp[a][b] = max(dp[a][b], 1 + dp[a][b-1]);
            }
        }
    }

}

int main() {

    int test;
    cin >> test;
//	init();
    while (test--) {
        int a, b;
        cin >> a >> b;
//        cout << dp[a][b] << endl;
  int count = 0;

        // 逆向推导到 (1, 1)
        while (a != 1 || b != 1) {
            if (a > b) {
                swap(a, b); // 保持 a <= b
            }
            // 如果 a == 1，无法再减，直接将 b 减为 1
            if (a == 1) {
                count += b - 1;
                break;
            }
            // 正常情况下，将 b 减去 a，继续推导
            int diff = b / a;
            b -= diff * a;
            count += diff;
        }

        // 输出结果
        cout << count << endl;
    }

    return 0;
}

