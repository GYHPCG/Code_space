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
	//β�巨�������� 
	node *L1 = createList();
	node *L2 = createList();
	int cnt = 0,num = 0;//numͳ�ƽ������� 
	node *p1 = L1;
	node *p2 = L2; 
	while(p1!=NULL&&p2!=NULL)
	{
		if(p1->data<p2->data)
		{
			p1 = p1->next;
		}
		else if(p1->data == p2->data)
		{//cntΪ�˹淶��� 
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
		//q->next = NULL�Ǳ�Ҫ�ģ���������ʹqָ��
		//ָ��һ��δ֪�ռ䣬���³������ 
		scanf("%d",&x);
	}
	return head->next;
}


