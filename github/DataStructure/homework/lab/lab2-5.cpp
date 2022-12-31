/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-12 11:03:59
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-12 12:32:53
 */
#include <iostream>

using namespace std;
//typedef int ElementType;
//单链表：
struct Node {
    int Data; 
    struct Node * Next; 
};
Node* creatHead( ) {

    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->Data = 0;
    dummy->Next = nullptr;
    return dummy;
}
void addlist(Node* L,int x) {
    Node* p = (Node*)malloc(sizeof(Node));
    Node* head = L;
    //找到结尾
    while(head->Next) {
        head = head->Next;
    }
    head->Next = p;
    p->Data = x;
    p->Next = nullptr;
    
}
void print(Node* L) {
    Node* head = L;
    while(head->Next) {
        cout << head->Next->Data << " ";
        head = head->Next;
    }
    cout << endl;
}
void SplictList(Node* L, Node* getPosi, Node* getNag) {
        //对原L分成两个链表,getPosi放非负,getNag放负数
        //
        Node* head = L->Next;
        Node* ppos = getPosi;
        Node* pnav = getNag;
        if (head ==  nullptr) return;
        while(head) {
            if (head->Data >= 0) {
                ppos->Next = head;
                ppos = ppos->Next;
            }
            else {
                pnav->Next = head;
                pnav = pnav->Next;
            }
            head = head->Next;
        }
        //一定要使后面指向空，否则还会和其他节点相连，导致结果异常
        ppos->Next = nullptr;
        pnav->Next = nullptr;
 }
void deleteAllList(Node* L) {
    Node* head = L;
    if(head == nullptr) return;
    Node* tmp = nullptr;
    while(head) {
        tmp = head;
        head = head->Next;
        free(tmp);
    }
    
}
int main()
{
    Node* L = creatHead();
    Node* Psi = creatHead();//非负数
    Node* Nag = creatHead();//放负数
    int x = 0;
    //输入100个整数
    cout << "随机输入100个整数: "<< endl;
    srand((int)time(nullptr));
    for(int i = 0; i < 100; ++i) {
         x = rand() % (100 + 100 + 1) - 100;
        addlist(L,x);
    }
    print(L);
    SplictList(L,Psi,Nag);
    cout << "负数链表：" << endl;
    print(Nag);
    cout << "非负数链表：" <<endl;
    print(Psi);
    deleteAllList(L);//还剩下两个新创的头节点
    //删除掉两个头节点
    delete Psi;
    delete Nag;
    return 0;

}