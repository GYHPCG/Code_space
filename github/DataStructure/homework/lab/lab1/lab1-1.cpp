/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-05 13:20:19
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-05 16:07:27
 */
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>  
#include <cmath>
struct SqList {
    int* Data; // 本实验中，元素类型设置为int
    int N; //表中现有元素个数
    int MaxSize; // 表的最大容量
};
void newList(SqList& L) {
    L.MaxSize = 100;
    L.Data = (int*)malloc(sizeof(int) * 100);
//    L.Data = new int[100];
    L.N = 0;
}
int CreatList(SqList& L) {

    L.N = 20;
    srand((int)time(NULL));
    for (int i = 0; i < L.N; i++)
    {
        L.Data[i] = rand() % 200 + 1;
    }
    return 0;
}
// void AddList(SqList& L, int x) {
//     if (L.N > 100) return;
//     L.Data[L.N++] = x;
// }
int printfList(SqList& L) {

    for (int i = 0; i < L.N; i++) {
        printf("%d ", L.Data[i]);
    }
    return 0;
}
bool math(int x) {
    if (x <= 3) {
        return x > 1;
    }
    for (int m = 2; m < sqrt(x); m++) {

        if (x % m == 0)
            return false;  
    }
    return true;
}
void insertZero(SqList& L,int index, int& num) {

    for (int i = L.N - 1 + num; i > index; --i) {
         L.Data[i] = L.Data[i-num];
    }
    int i = index+1;
    int x = num;
    while(x--) {
        L.Data[i] = 0;
        i++;
    }
    L.N += num;
    //cout <<"L.n: " << L.N << " "<< num << endl;
}
int main()
{
    SqList L;
    newList(L);
    CreatList(L);
    printfList(L);
    printf("\n");
    //printf("%d %d\n",L.N,L.MaxSize);
    int num = 1;
    for (int i = 0; i < L.N; i++)
    {
        if (math(L.Data[i]) == true)
        {
            insertZero(L,i,num);
            ++num;
        }
   }
   printfList(L);
    return 0;
}
