//
// Created by 86183 on 2023/2/13.
//
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
   cout << "hello, cpp" << endl;
   int a[3];
   for (int i = 0; i < 3; i++) scanf("%d", &a[i]);
   for (int i = 0; i < 3; ++i) cout << a[i] << endl;

   return 0;
}
