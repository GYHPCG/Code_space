#include <iostream>
#include <algorithm>
using namespace std;

// // 计算最大公约数
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int test;
    cin >> test;

    while (test--) {
        int a, b;
        cin >> a >> b;

        // 计算最大公约数
        int g = __gcd(a, b);

        // 输出结果
        cout << g << endl;
    }

    return 0;
}
