/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-12 10:19:03
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-12 12:37:23
 */
#include <iostream>
#include <ctime>
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
int Length(Node* L) {
    int len = 0;
    Node* head = L;
    while(head->Next) {
        ++len;
        head = head->Next;
    }
    return len;
}
void SortList(Node* L) {
    Node* head1 = L->Next;
    if (head1 == nullptr || head1->Next == nullptr) return ;
    int size = Length(L);
    //bubble_sort
    Node* head2 = L->Next;
    //swap Value;
    for (int i = 0; i < size; ++i) {
        head1 = head2;
        for(int j = 0; j < size - i - 1; ++j) {
            if (head1->Data > head1->Next->Data) {
                swap(head1->Data,head1->Next->Data);
            }
            head1 = head1->Next;
        }
    }
    //排序节点,bubble_sort();
    // Node* r = nullptr;
    // Node* t = nullptr;
    // Node* tail = nullptr;
    // while(L->Next->Next != tail) {
    //     r = L;
    //     t = L->Next;
    //     while(t->Next != tail) {
    //         if (t->Data > t->Next->Data) {
    //             r->Next = t->Next;
    //             t->Next = t->Next->Next;
    //             r->Next->Next = t;
    //             t = r->Next;
    //         }
    //         r = r->Next;
    //         t = t->Next;
    //     }
    //     tail = t;
    // }

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
    //随机输入100个整数
    cout << "随机输入100个整数: "<< endl;
    srand((int)time(nullptr));
    for(int i = 0; i < 100; ++i) {
         x = rand();
        addlist(L,x);
    }
    print(L);
    cout << "输出排序后链表：" << endl;
    SortList(L);
    print(L);
    deleteAllList(L);
    return 0;

}
