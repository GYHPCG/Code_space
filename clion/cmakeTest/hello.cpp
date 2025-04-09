//
// Created by 86183 on 2023/2/13.
//

#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
   cout << "hello, world" << endl;
   int x = std::gcd(1, 5);
   cout << x << endl;
   cout << "yunm" << endl;
   int* p = &x;

   auto l = p;
   auto t = *p;
   int  k = t;
   cout << k << endl;
   //   decltype(p);
   // cout << decltype(p);
   string              s = "hello, world";
   istringstream       is(s);
   vector<std::string> vec({std::istream_iterator<string>(is)},
                           std::istream_iterator<string>());
   for (auto& t3 : vec) { std::cout << t3; }
   throw out_of_range("out of range");
   return 0;
}
