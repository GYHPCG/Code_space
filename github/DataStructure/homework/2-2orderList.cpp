#include <iostream>

using namespace std;
typedef int ElementType;
//单链表：
struct Node {
    ElementType Data; 
    struct Node * Next; 
};
Node* creatHead( ) {

    Node* dummy = (Node*)malloc(sizeof(Node));
    dummy->Data = 0;
    dummy->Next = nullptr;
    return dummy;
}
void addlist(Node* L,ElementType x) {
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
int Length(Node* L) {
    int len = 0;
    Node* head = L;
    while(head->Next) {
        ++len;
        head = head->Next;
    }
    return len;
}
 
void insert(Node* L,int index, int x) {
    if (index < 0 || index > Length(L)) return;
    Node* p = L;
    while(p&& index != 1) {
        p = p->Next;
        index--;
    }
    Node* tmp = (Node*)malloc(sizeof(Node));
    tmp->Data = x;
    tmp->Next = nullptr;
    tmp->Next = p->Next;
    p->Next = tmp;
}
void print(Node* L) {
    Node* head = L;
    while(head->Next) {
        cout << head->Next->Data << " ";
        head = head->Next;
    }
    cout << endl;
}
void deleSameVlaue(Node* L) {
    Node* head = L->Next;
    //单调有序递增序列,此法仅适用于单调有序链表
    //若不有序，则要对判断等于那里的代码进行修改
    if (head == nullptr) return;
        while(head != nullptr) {
            Node* nex = head->Next;
            if (nex != nullptr && nex->Data == head->Data) {
            head->Next = nex->Next;
            free(nex);
            head = head;

            } else 
            head = head->Next;
        }
    //当无序时

}
//链表并从小到大排序
//偷懒写法，不对节点进行排序，而是对节点里面的Data进行排序，简单
void SortList(Node* L) {
    Node* head1 = L->Next;
    if (head1 == nullptr || head1->Next == nullptr) return ;
    //int size = Length(L);
    //bubble_sort
    //Node* head2 = L->Next;
    //swapValue;
    // for (int i = 0; i < size; ++i) {
    //     head1 = head2;
    //     for(int j = 0; j < size - i - 1; ++j) {
    //         if (head1->Data > head1->Next->Data) {
    //             swap(head1->Data,head1->Next->Data);
    //         }
    //         head1 = head1->Next;
    //     }
    // }
    //排序节点,bubble_sort();
    Node* r = nullptr;
    Node* t = nullptr;
    Node* tail = nullptr;
    while(L->Next->Next != tail) {
        r = L;
        t = L->Next;
        while(t->Next != tail) {
            if (t->Data > t->Next->Data) {
                r->Next = t->Next;
                t->Next = t->Next->Next;
                r->Next->Next = t;
                t = r->Next;
            }
            r = r->Next;
            t = t->Next;
        }
        tail = t;
    }

 }
 //将一个链表链表L分为两个单链表，一个存放所有的非负整数，
 //另一个存放所有的负整数。要求利用原来的结点，不分配新的结点空间，头结点除外。
 void SplictList(Node* L) {

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
    int x = 0;
    //输入10个整数
    for(int i = 0; i < 10; ++i) {
        cin >> x;
        addlist(L,x);
    }
    cout << Length(L)<<endl;
    print(L);
    // insert(L,1,9);
    // deleSameVlaue(L);
    SortList(L);
    print(L);
    deleteAllList(L);
    return 0;

}
