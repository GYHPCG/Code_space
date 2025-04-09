/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-02 09:50:12
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-02 10:23:29
 */
#include <iostream>

using namespace std;

const int Maxsi = 100;//假设最大容量100
struct Queue
{
    /* data */
    int* Data;
    int Front;
    int Rear;
    int size;
    int Maxsize;
};
void creatQueue(Queue& qe) {
    qe.Maxsize = Maxsi;
    qe.Data = new int[qe.Maxsize];
    qe.Front = qe.Rear = 0;
    qe.size = 0;
}
void push(Queue& qe, int x) {
    if (qe.Rear + 1 % qe.Maxsize == qe.Front) throw runtime_error("qe is full");
    qe.Data[qe.Rear] = x;
    qe.Rear = (++qe.Rear) % qe.Maxsize;
    ++qe.size;
}
int pop(Queue& qe) {
    if (qe.Front == qe.Rear) throw runtime_error("queue is emty");
    int tmp = qe.Data[qe.Front];
    qe.Front = (++qe.Front) % qe.Maxsize;
    --qe.size;
    return tmp;
}
void printQue(Queue qe) {
    cout << "输出队列中元素：";
    for (; qe.Front < qe.Rear; (++qe.Front) % qe.Maxsize) {
        cout << qe.Data[qe.Front] << " ";
    }
    cout << endl;
}
void chooseOption(Queue& qe) {

     int x;
    do {
        cout << "---输入数字(1~3),选择功能---" << endl;
        cout << "1: 输入一个整数并入队  ";
        cout << "2: 出队  ";
        cout << "3: 输出队列中的元素  ";
        cout << "4: 退出程序" << endl;
        cout << endl;
       
        cin >> x;
        if (x == 1) {
            int t;
            cin >> t;
            push(qe,t);
        } else if (x == 2) {
            pop(qe);
        } else if (x == 3) {
            printQue(qe);
        }
    }while (x != 4);
    return;
}
int main()
{
    Queue qe;
    creatQueue(qe);
    push(qe,1);
    push(qe,3);
    push(qe,5);
    push(qe,7);
    chooseOption(qe);
    return 0;

}
