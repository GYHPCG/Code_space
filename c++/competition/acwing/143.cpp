#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5 + 5, M = 31 * N + 5;

int a[N], son[M][2], idx, n;

void insert(int &x) {
  int p = 0;
  for (int i = 30; i >= 0; --i) {
    int t = (x >> i) & 1;
    if (!son[p][t])
      son[p][t] = ++idx;
    p = son[p][t];
  }
}

/**
 * 查询函数
 * 该函数根据给定的x值，通过遍历x的二进制形式的每一位，从预构建的树状结构中查询并返回对应的累计结果。
 * 
 * @param x 输入的整数x，其二进制形式将被用于查询。
 * @return 返回根据x的二进制形式在树状结构中查询到的累计结果。
 */
int query(int x) {
  int p = 0, res = 0; // 初始化当前节点p为根节点，结果res为0
  for (int i = 30; i >= 0; --i) { // 从最高位到最低位遍历x的二进制表示
    int t = (x >> i) & 1; // 获取x的第i位的值
    if (son[p][!t]) // 如果当前节点的非当前位子节点存在
      p = son[p][!t], res += (1 << i); // 跳转到非当前位的子节点，并将对应的位加到结果中
    else
      p = son[p][t]; // 否则，跳转到当前位的子节点
  }
  return res; // 返回查询到的结果
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    insert(a[i]);

  }

  int max_res = 0;

  for (int i = 0; i < n; ++i)
    max_res = max(query(a[i]), max_res);
  cout << max_res << endl;
  return 0;
}