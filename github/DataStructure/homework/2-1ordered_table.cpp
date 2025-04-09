#include <iostream>

using namespace std;

//顺序表：
typedef int ElementType;
#define capa 20
struct SqList {
    ElementType *Data; 
    int N; //表中元素个数
    int MaxSize; // 表容量
};
void initList(SqList& L,unsigned int capaci) {
    L.MaxSize = capaci;
    L.N = 0;
    L.Data = (ElementType*)malloc(L.MaxSize * sizeof(ElementType));
}
void addElement(SqList& L, ElementType x) {
    if (L.N >= L.MaxSize) return;
    //因为个数总比索引大1，所以先赋值，再加L.N;
    L.Data[L.N++] = x;  
}
ElementType deleteMin(SqList& L) {
    ElementType Min = INT_MAX;
    ElementType index = 0;
    //寻找MIn
    for (int i = 0; i < L.N; ++i) {
        if (L.Data[i] < Min) {
            Min = L.Data[i];
            index = i;
        }
    }
    //从表中删掉
    for(int i = index; i < L.N -1; ++i) {
        L.Data[i] = L.Data[i+1];
    }
    //个数减一
    --L.N;
    return Min;
}
void print(SqList& L) {
    for (int i = 0; i < L.N; ++i) {
        cout << L.Data[i] << " ";
    }
}
void DestoryList(SqList& L) {
    free(L.Data);
    L.Data = nullptr;
}
void RevereList(SqList& L) {
    for (int i = 0,j = L.N - 1; i <= j; ++i,--j) {
        //直接调用swap()函数实现即可，也可自己写一个swap(),但是太简单了，没必要写，直接调用标准库即可
        swap(L.Data[i],L.Data[j]);
    }
}
int main()
{
    SqList L;
    initList(L,capa);
    int x = 0;
    for (int i = 0; i < 6; ++i) {
        cin >> x;
        addElement(L,x);
    }
    print(L);
    cout << endl;
    // ElementType m = deleteMin(L);
    // cout << "MIn: " << m << endl;
    RevereList(L);
    print(L);
    DestoryList(L);
    return 0;
}