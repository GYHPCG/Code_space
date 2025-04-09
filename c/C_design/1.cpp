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

        // �����Ƶ��� (1, 1)
        while (a != 1 || b != 1) {
            if (a > b) {
                swap(a, b); // ���� a <= b
            }
            // ��� a == 1���޷��ټ���ֱ�ӽ� b ��Ϊ 1
            if (a == 1) {
                count += b - 1;
                break;
            }
            // ��������£��� b ��ȥ a�������Ƶ�
            int diff = b / a;
            b -= diff * a;
            count += diff;
        }

        // ������
        cout << count << endl;
    }

    return 0;
}

