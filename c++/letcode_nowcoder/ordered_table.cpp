#include <iostream>

using namespace std;

//˳���
typedef int ElementType;
#define maxSize 20
struct SqList {
    ElementType *Data; 
    int N; //����Ԫ�ظ���
    int MaxSize; // ������
};
void initList(SqList& L, unsigned int capacity) {
	L.MaxSize = capacity;
    L.N = 0;
    L.Data = (ElementType*)malloc(L.MaxSize * sizeof(ElementType));
}
void addElement(SqList& L, ElementType x) {
    if (L.N >= L.MaxSize) return;
    //��Ϊ�����ܱ�������1�������ȸ�ֵ���ټ�L.N;
    L.Data[L.N++] = x;  
}
ElementType deleteMin(SqList& L) {
    ElementType Min = INT_MAX;
    ElementType index = 0;
    //Ѱ��MIn
    for (int i = 0; i < L.N; ++i) {
        if (L.Data[i] < Min) {
            Min = L.Data[i];
            index = i;
        }
    }
    //�ӱ���ɾ��
    for(int i = index; i < L.N -1; ++i) {
        L.Data[i] = L.Data[i+1];
    }
    //������һ
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
int main()
{
    SqList L;
    initList(L,maxSize);
    int x = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        addElement(L,x);
    }
    print(L);
    cout << endl;
    ElementType m = deleteMin(L);
    cout << "MIn: " << m << endl;
     print(L);
     DestoryList(L);
    return 0;
}
