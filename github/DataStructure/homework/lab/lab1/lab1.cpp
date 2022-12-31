/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-05 10:15:34
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-05 16:13:02
 */
#include <iostream>
#include <stdio.h>
#include <time.h>
#include <cmath>
using namespace std;
#define Maxsize 100
struct SqList {
    int *Data; // 本实验中，元素类型设置为int
    int N; //表中现有元素个数
    int MaxSize; // 表的最大容量
};
void InitList(SqList& L) {
   
    L.N = 0;
    L.MaxSize = Maxsize;
    L.Data = new int[Maxsize];

}
void AddList(SqList& L, int x) {
    if (L.N > 100) return;
    L.Data[L.N++] = x;
}
void printList(SqList& L) {
    for (int i = 0; i < L.N; ++i) {
        cout << L.Data[i] << " ";
    }
    cout << endl;
}
void deleteEvenNum(SqList& L) {
    SqList q = L;
    int coun = 0;
    for (int i = 0,j = 0; i < L.N; ++i) {
        if (q.Data[i] % 2 == 0) {
            ++coun;
        } else {
            L.Data[j] = q.Data[i];
            ++j;
        }
    }
    L.N = q.N - coun;
}
bool isPrime (int x) {
    if ( x <= 3) {
        return x > 1;
    }
    for (int i = 2; i <= sqrt(x); ++i) {
        if ( x % i == 0) return false;
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
void deleAlist(SqList& L) {
    delete [] L.Data;
}
int main()
{
    //lab1
    cout << "Lab1:" << endl;
    SqList L;
    InitList(L);
    int i = 0;
    srand((int)time(NULL));  // 用time函数取当前时间作为随机数初始化种子
    for (i = 0; i < 100; i ++) {  
        //printf("%d ", rand() % 100 + 100);  // 对100求余数，实际范围0~99
        int x = rand() % 100 + 100;
        AddList(L,x);
    } 
    cout << "生成[100-200)区间的100各随机数: " << endl;
    printList(L);
    //去掉偶数
    cout << endl;
    cout << "去掉所有的偶数后："<< endl;
    
    deleteEvenNum(L);
    //输出
    printList(L);
    //delete
    deleAlist(L);
    
    
    //lab2
    cout << endl;
    cout <<"Lab2:" << endl;
    SqList L2;
    InitList(L2);
    for (int i = 0; i < 20; ++i) {
         int x = rand() % 200 + 1;
         //x = x + 100;
         AddList(L2,x);
    }
    cout << "输出20个[1-200)的随机数："<< endl;
   
    printList(L2);
    //cout << L2.N << endl;
    //判断素数是第几个
    int numX = 1;
    for (int i = 0; i < L2.N; ++i) {
        
        if(isPrime(L2.Data[i]) == true) {
            insertZero(L2,i,numX);
            ++numX;
        }
    }
    cout << endl;
    cout <<"第一个素数后插入1个0,第二个素数后插入2个0……:" << endl;
    printList(L2);
    deleAlist(L2);
    return 0;

}
