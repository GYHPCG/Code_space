/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-19 19:19:01
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-19 19:50:59
 */
#include<iostream>
using namespace std;

struct DNode {
    int Data;   // 在实验中，以int型数据作为元素内容
    struct DNode * Next;
    struct DNode * Previous;
};
class MyList//定义双向循环列表
{
public:
	MyList();
	~MyList();
	void list_Init();//创建双向循环链表
	void sq_traverse(); //顺序遍历链表
    void re_traverse();//逆序遍历
private:
	DNode* head;
	DNode* tail;
};
 
MyList::MyList()
{
	this->head = new DNode;
	head->Data = 0;
	head->Next = this->head;
	head->Previous = this->head;
	this->tail = this->head;
}
 
void MyList::list_Init()//插入10个元素
{
	cout << "尾插法创建循环双向链表" << endl;//尾插法一定要创建一个尾指针，别让头指针跑掉
	cout << "输入数据域：" << endl; 
    for (int i = 0; i < 10; i++)
	{
		DNode* temp; temp = new DNode;
        cin >> temp->Data;
		temp->Previous = this->tail;
		temp->Next = this->head;
		this->head->Previous = temp;
		tail->Next = temp;
		tail = temp;
	}
}

void MyList::sq_traverse()
{
	DNode* p;
	p = this->head->Next;
	while (p != this->head)
	{
		cout << p->Data << " ";
		p = p->Next;
	}
	cout << endl;
}
void MyList::re_traverse() 
{
    DNode* p;
    p = this->tail;
    while(p != this->tail->Next) {
        cout << p->Data << " ";
        p = p->Previous;
    }
    cout << endl;
}
MyList::~MyList()
{
    DNode* p;
	p = this->tail;
	while (this->tail != this->head)
	{
		this->tail = this->tail->Previous;
		delete p;
		p = this->tail;
	}
    delete this->head;
	this->head = NULL;
	this->tail = NULL;
}
int main()
{
    MyList DL;
    DL.list_Init();
    cout << "顺序输出：" << endl;
    DL.sq_traverse();
    cout << "逆序输出：" << endl;
    DL.re_traverse();
   //DL.~MyList();
    return 0;
}