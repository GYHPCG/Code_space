#include <iostream>
#include <random>
using namespace std;

int main() {
  int n;
  cin >> n;
  bool f = false;
  for (int i = 1; i <= 20; i++) {
    for (int j = 1; j <= 20; j++) {
      for (int k = 1; k <= 20; k++) {
        for (int l = 1; l <= 20; l++) {
          if ((i * k - j * l) == n) {
            f = true;
            cout << i << " " << j << "\n" << l << " " << k << endl;
            return 0;
          }
        }
      }
    }
  }
  if (!f)
    cout << -1 << endl;
  return 0;
}
