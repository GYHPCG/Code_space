#include <iostream>
#include <queue>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  std::cin >> n >> m;
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    q.push(x);
  }
  while (m--) {
    std::cout << q.top() << ' ';
    q.pop();
  }
  return 0;
}