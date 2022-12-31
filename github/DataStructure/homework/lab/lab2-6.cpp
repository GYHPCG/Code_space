/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-12 11:31:47
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-19 19:13:43
 */
#include <iostream>

using namespace std;

struct DNode {
    int Data;   // 在实验中，以int型数据作为元素内容
    struct DNode * Next;
    struct DNode * Previous;
};
DNode* creatHead( ) {

    DNode* dummy = new DNode();
    dummy->Data = 0;
    dummy->Next = nullptr;
    dummy->Previous = nullptr;
    return dummy;
}
void addlist(DNode* L,int x) {
    DNode* head1 = L->Next;
    DNode* p = new DNode();
    p->Data = x;
    DNode* head2 = L->Next;
    //找到结尾
   if (head1 == nullptr) {
        head1 = p;
        p->Next = head1;
        p->Previous = p;
   } else {

     while(head2->Next != head1) {
        head2 = head2->Next;
        }   
            p->Previous = head2;
            head2->Next = p;
            p->Next = head1;//最后一个next指向第一个
            head1->Previous = p;//第一个的前一个指向最后一个
   }
    
}
void SqPrint(DNode* L) {
    DNode* head = L;
    while(head->Next != L) {
        cout << head->Next->Data << " ";
        head = head->Next;
    }
    cout << endl;
}
void RePrint(DNode* L) {
   // DNode* head = L->Next;
    // DNode* tail = nullptr;
    // //寻找尾部
    //  while(head->Next) {
    //     //cout << head->Next->Data << " ";
    //     head = head->Next;
    // }
    // tail = head;
    // //从后往前输出
    // while(tail->Previous) {
    //     cout << tail->Data << " ";
    //     tail = tail->Previous;
    // }
    cout << endl;
}
void deleteAllList(DNode* L) {
    DNode* head = L;
    if(head == nullptr) return;
    DNode* tmp = nullptr;
    while(head) {
        tmp = head;
        head = head->Next;
        delete tmp;
    }
    
}
int main()
{
    DNode* DL = creatHead();
    //输入10个整数//
    int x = 0;
    
    for (int i = 0; i < 10; ++i) {
        cin >> x;
        addlist(DL,x);
    }
    cout << "顺序输出：" << endl;
    SqPrint(DL);
    // cout << "逆序输出：" << endl;
    // RePrint(DL);
    // deleteAllList(DL);
    return 0;

}

