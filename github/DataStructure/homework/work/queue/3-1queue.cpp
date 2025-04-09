/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-21 16:07:49
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-21 20:11:27
 */
#include <iostream>
 
using namespace std;
//循环队列：
const int Max_size = 20;
using ElementType = int;

struct Queue {
    ElementType *Data;  //队列空间  
    int Front; //队头 
    int Rear; //队尾
    int Size; // 队列中元素数量
    int MaxSize; //队列最大容量
};
struct Stack {
    ElementType *Data; //栈空间  
    int Top; //栈顶，空栈为-1 
    int MaxSize; //栈最大容量   
    void Push(int x);
    void Pop();
};
void Init_Que(Queue& Que)
{
    Que.MaxSize = Max_size;

    Que.Front = Que.Rear = 0;

    Que.Size = 0;
    Que.Data = new ElementType[Max_size];

}
void Push(Queue& q, ElementType x) {
    if ((q.Rear + 1) % q.MaxSize == q.Front) throw runtime_error ("Queue is full");
    q.Data[q.Rear] = x;
    q.Rear = (q.Rear+1) % q.MaxSize;
    ++q.Size;
}
ElementType Pop(Queue& q) {
    if (q.Size == 0) throw runtime_error("queue is empty");
    int tmp = q.Data[q.Front];
    q.Front = (q.Front + 1) % q.MaxSize;
    --q.Size;
    return tmp;
}
void PrintQueue(Queue& q) {
    while(q.Size != 0) {
        cout << Pop(q) << " ";
    }
    cout << endl;
}
//stack
Stack& creatStack() {

}
void ConvertToBinary(int N)
{ 
    Stack st = creatStack();

    while(N) {
        st.Push(N%2);
        N = N / 2;
    }
    while (st.Top != -1)
    {
       //st.Pop();
       cout << st.Pop() << " ";
    }
    cout << endl;
}
int main()
{
    Queue que;
    Init_Que(que);
    Push(que,2);
    Push(que,3);
    Push(que,8);
    //Push(que,9);
    // cout << que.Size;
    // cout << Pop(que);
    PrintQueue(que);

    return 0;

}
