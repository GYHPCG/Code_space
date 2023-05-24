//
// Created by 86183 on 2023/3/18.
//
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

const int N   = 210;
const int INF = 1e9;   // 无穷大
int n, m, k;
int d[N][N];   // 记录最短的·距离。d[i][j]表示i到j的最短距离

void floyd()
{
   for (int k1 = 1; k1 <= n; ++k1)
   {
      for (int i = 1; i <= n; ++i)
      {
         for (int j = 1; j <= n; ++j)
         {
            d[i][j] = std::min(d[i][j], d[i][k1] + d[k1][j]);
         }
      }
   }
}

int main()
{
   ios::sync_with_stdio(false);

   cin >> n >> m >> k;
   // 初始化
   for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; j++)
         if (i == j) d[i][j] = 0;
         else d[i][j] = INF;
   int x, y, z;

   while (m--)
   {
      cin >> x >> y >> z;

      d[x][y] = std::min(d[x][y], z);
   }

   floyd();
   int a, b;
   while (k--)
   {
      cin >> a >> b;
      if (d[a][b] > INF / 2) puts("impossible");
      else cout << d[x][y] << endl;
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