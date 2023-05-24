//
// Created by 86183 on 2023/3/26.
//
#pragma optimize(3)
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;
int n, m;
vector<int> pri;
int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int count = 0;
   cin >> n >> m;
    int pi ;
   while (m -- )
   {
      cin >> pi;
      pri.push_back(pi);
   }

   for (int i = 1; i <= n; i ++ )
   {
      for (int j = 0; j < pri.size(); ++j)
      {
         if (i % pri[j] == 0)
         {
            ++count;
            break;
         }
      }

   }
   cout << count << endl;
   return 0;
}