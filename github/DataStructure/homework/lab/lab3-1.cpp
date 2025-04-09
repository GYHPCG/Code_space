/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-26 10:03:17
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-26 16:41:20
 */
#include <iostream>

using namespace std;

const int Maxsize = 100;
struct Stack {
    int * Data;   // 栈空间
    int Top;      // 栈顶，为0时表示空栈
    int MaxSize; //栈的最大容量
};
Stack* creatStack() {
    Stack* st = new Stack();
    st->MaxSize = Maxsize;
    st->Data = new int[st->MaxSize];
    st->Top = 0;
    return st;
}
void Push(Stack* st, int x) {
    if (st->Top == st->MaxSize) throw runtime_error(" Stack is full");
    st->Data[++st->Top] = x;
}
int Pop(Stack* st) {
    if (st->Top == 0) throw runtime_error("Stack is empty");
    int tem = st->Data[st->Top];
    st->Top--;
    return tem;
}
void PrintStack(Stack* st) {
    int i = st->Top;
    while(i != 0) {
        cout << st->Data[i] << " ";
        --i;
    }
    cout << endl;
}
void deleteStack(Stack* st) {
    delete[] st->Data;
}
int main()
{
    Stack* st = creatStack();
    cout << "输入10个数,压入栈中: " << endl;
    int x;
    for (int i = 0; i < 10; ++i) {
        cin >> x;
        Push(st,x);
    }
    PrintStack(st);
    //su
    deleteStack(st);
    return 0;

}
