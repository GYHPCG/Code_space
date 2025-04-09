/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-12 10:14:38
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-12 12:37:52
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

    Node* dummy = new Node();
    dummy->Data = 0;
    dummy->Next = nullptr;
    return dummy;
}
void addlist(Node* L,int x) {
    Node* p = new Node();
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
void deleteAllList(Node* L) {
    Node* head = L;
    if(head == nullptr) return;
    Node* tmp = nullptr;
    while(head) {
        tmp = head;
        head = head->Next;
        delete tmp;
    }
    
}
int main()
{
    Node* L = creatHead();
    int x = 0;
    //输入10个整数
    for(int i = 0; i < 10; ++i) {
        cin >> x;
        addlist(L,x);
    }
    print(L);
    deleteAllList(L);
    return 0;

}
