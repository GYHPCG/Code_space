//
// Created by 86183 on 2023/3/20.
//
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
   ios::sync_with_stdio(false);
   cin.tie(nullptr);
   int n = 5;
   int x = 0;
   int count = 0;
   while (n -- )
   {
      cin >> x;
      string s = to_string(x);
      if (s[0] == s[2] && atoi(reinterpret_cast<const char*>(s[3])) == atoi(reinterpret_cast<const char*>(s[1])) + 1) ++count;

   }

   cout << count << endl;
   return 0;
}