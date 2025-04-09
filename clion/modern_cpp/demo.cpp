//
// Created by 86183 on 2023/2/16.
//
#include <iostream>
void fun(int a) { std::cout << "fun1: " << a << std::endl; }
void fun(const int a) { static int b = a; }
int  main()
{
   std::cout << "cmake test" << std::endl;

   return 0;
}
