#include<stdio.h>
int main() 
{
    int arr[] = {
        #include "maricoh.h";//头文件不一定都是在开头使用，因为预处理的时候，其实就是把内容展开
        //我在头文件里放了1，2，3，4，5;展开的时候就是等价于arr[] = {1,2,3,4,5};
    };
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        printf("%d,",arr[i]);
    }
    return 0;
}