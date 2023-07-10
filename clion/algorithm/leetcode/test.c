//
// Created by 86183 on 2023/5/29.
//
#include <stdio.h>

int main()
{
   int n;
   scanf_s("%d", &n);
   int arr[n];
   int x;
   for (int i = 0; i < n; i++)
   {
      scanf_s("%d", &arr[i]);
   }
   printf("a[4]: %d", arr[4]);
}