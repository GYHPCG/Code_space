//
// Created by 86183 on 2023/3/18.
/*
 * 主程序：通过弗洛伊德算法解决最短路径问题
 * 参数：n - 点的数量, m - 边的数量, k - 查询的数量
 * 返回值：无
 */

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N   = 210;
const int INF = 1e9;   // 定义无穷大的值

int n, m, k; // n: 点的数量, m: 边的数量, k: 查询的数量
int d[N][N]; // 记录最短的距离。d[i][j]表示i到j的最短距离

/*
 * 弗洛伊德算法：逐步填充d数组，求出所有点对之间的最短路径
 */
void floyd()
{
   for (int k1 = 1; k1 <= n; ++k1)
   {
      // 对于每个点k1，更新所有点对之间的最短距离
      for (int i = 1; i <= n; ++i)
      {
         for (int j = 1; j <= n; ++j)
         {
            // 如果通过点k1更近，则更新最短距离
            d[i][j] = std::min(d[i][j], d[i][k1] + d[k1][j]);
         }
      }
   }
}

int main()
{
   ios::sync_with_stdio(false); // 快速输入输出

   cin >> n >> m >> k; // 输入点的数量，边的数量和查询的数量
   // 初始化d数组
   for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; j++)
         if (i == j) d[i][j] = 0; // 同一点的距离为0
         else d[i][j] = INF; // 初始化为无穷大
   int x, y, z;

   // 输入边的信息
   while (m--)
   {
      cin >> x >> y >> z;

      // 更新边的权重
      d[x][y] = std::min(d[x][y], z);
   }

   // 运行弗洛伊德算法
   floyd();
   int a, b;
   // 对于每个查询，输出结果
   while (k--)
   {
      cin >> a >> b;
      // 如果两点之间没有路径，输出"impossible"
      if (d[a][b] > INF / 2) puts("impossible");
      else cout << d[a][b] << endl;
   }
   return 0;
}

/*3 3 2
1 2 1
  2 3 2
  1 3 1
  2 1
  1 3
  */