//
// Created by 86183 on 2023/3/27.
//
#include <iostream>

int main()
{//char* s  = 'a';
   //std::cout << *s << std::endl;
   int *p;
   void* ptr = (void*)&p; // 将 p 转换为 void 指针并取其地址
   int **pp = (int**)&ptr; // 将 ptr 转换回指向指向整数的指针的指针
   //int t = 42;
   *pp = new int(42); // 动态分配一个整数并将其地址存储在 p 中
   std::cout << *p << std::endl; // 输出 42
   delete p;
   return 0;
}