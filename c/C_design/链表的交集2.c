#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *next;
}node;
struct node *createList();
int main()
{
	//尾插法创建链表 
	node *L1 = createList();
	node *L2 = createList();
	int cnt = 0,num = 0;//num统计交集个数 
	node *p1 = L1;
	node *p2 = L2; 
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->data<p2->data)
		{
			p1 = p1->next;
		}
		else if(p1->data == p2->data)
		{//cnt为了规范输出 
			num++;		
			if(cnt == 0) 
			{
				cnt = 1;
				printf("%d",p1->data);
			}
			else
			{
				printf(" %d",p1->data);
			}
			p1 = p1->next;
		}
		else
		{
			p2 = p2->next;
		}
	}
	if(num==0)
		printf("NULL");	
	return 0;
}
struct node *createList()
{
	node *head = NULL;
	head = (node*)malloc(sizeof(node));
	head->next = NULL;
	node *p = head;
	int x;
	scanf("%d",&x);
	while(x!= -1)
	{
		node *q =NULL;
		q = (node*)malloc(sizeof(node));
		q->data = x;
		p->next = q;
		p = q;
		q->next = NULL;
		//q->next = NULL是必要的，否则最后会使q指针
		//指向一个未知空间，导致程序错误 
		scanf("%d",&x);
	}
	return head->next;
}


