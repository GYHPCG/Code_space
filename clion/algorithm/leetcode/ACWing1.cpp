//
// Created by 86183 on 2023/3/17.
//
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

using int_64 = long long;
int_64 a, b, m;
int_64 arr[7];
int main()
{
   cin >> a >> b >> m;
   for (int i = 0; i < 7; i ++ )
   {
      if (i < 5) arr[i] = a;
      else arr[i] = b;
   }
   ///int_64 day = 0;
   int_64 s = 5 * a + 2 * b;
   int_64 day = m / s * 7;
   m = m % s;
   int i = 0;
   while (m > 0)
   {
      m -= arr[i];
      ++day;
      ++i;
   }

   cout << day << endl;
   return 0;
}