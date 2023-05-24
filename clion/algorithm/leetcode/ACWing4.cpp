//
// Created by 86183 on 2023/3/24.
//
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

using ll  = long long;
const int N = 100010, mod = 1e+9 + 7;
int fact[N], infact[N];

int qmi(int a, int b, int c)
{
   int res = 1;
   while (b)
   {
      if (b & 1) res = (ll)res * a % c;
      a =(ll) a * a % c;
      b = b >> 1;
   }
   return res;
}
void init()
{
   fact[0] = infact[0] = 1;
   for (int i = 1; i < N; ++i)
   {
     fact[i] = (ll)fact[i - 1] * i % mod;
     infact[i] = (ll)infact[i - 1] * qmi(i, mod - 2, mod) % mod;

   }
}


int main()
{
   int n;
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   init();
   cin >> n;
   while (n--)
   {
      int a, b;
      cin >> a >> b;
      cout <<(ll) fact[a] * infact[a - b] % mod * infact[b] % mod << endl;
   }

   return 0;
}
/*3, 31, 53,22 */