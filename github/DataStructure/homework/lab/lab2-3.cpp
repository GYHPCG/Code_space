/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-12 10:27:45
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-19 17:40:22
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
   

 }
void CombineLst(Node* L1, Node* L2, Node* L3) {
    //归并排序
    Node* HpL1 = L1;
    Node* HpL2 = L2;
    Node* HpL3 = L3;
    while(HpL1->Next != nullptr && HpL2->Next != nullptr) {
        if (HpL1->Next->Data >= HpL2->Next->Data) {
            HpL3->Next = HpL2->Next;
            HpL2 = HpL2->Next;
            } else {
            HpL3->Next = HpL1->Next;
            HpL1 = HpL1->Next;
        }
        HpL3 = HpL3->Next;
        
    }
    if(HpL1->Next) {
        HpL3->Next = HpL1->Next;
    }
    if(HpL2->Next) {
        HpL3->Next = HpL2->Next;
    }
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
    Node* L1 = creatHead();
    Node* L2 = creatHead();
    Node* L3 = creatHead();
    int x = 0;
    //随机输入100个整数
    srand((int)time(nullptr));
    for(int i = 0; i < 10; ++i) {
         x = rand();
        addlist(L1,x);
    }
    for (int  i = 0; i < 8; ++i) {
        x =rand();
        addlist(L2,x);
    }
    cout << "输出两个链表合并前："  << endl;
    SortList(L1);
    SortList(L2);
    print(L1);
    print(L2);
    cout << "输出合并后链表：" << endl;
    CombineLst(L1,L2,L3);
    print(L3);
    deleteAllList(L3);
    //删除剩余头节点
    delete L1;
    delete L2;
    return 0;

}
