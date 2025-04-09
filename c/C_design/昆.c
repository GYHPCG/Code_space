#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	struct nub {
		int num;
		struct nub* next;

	}*p1,*p2, *head,*q;

	int n;scanf("%d", &n);
	int i;
	for ( i = 0; i < n; i++)
	{
	int f = 0;
	p1=p2 = (struct nub*)malloc(sizeof(struct nub));
	scanf("%d", &p1->num);
		head = NULL;
		while(p1->num != -1)
		{
			f = f + 1;
			if (f == 1)
				 head=p1;
			else
				p2->next = p1;
			p2 = p1;
			p1 = (struct nub*)malloc(sizeof(struct nub));
			scanf("%d", &p1->num);

		}
		p2->next = NULL;

		for (q=NULL,p1 = head; p1; q=p1,p1 = p1->next)
		{
			if (p1->num % 2 != 0)
			{
				if (q)
				{
					q->next = p1->next;
					q->next=p1;
					free(p1);
				}
				else head=p1->next;
			}
		
		}

		for ( p1 = head; p1;  p1 = p1->next)
			printf("%d ", p1->num);printf("\n");
	}
	return 0;
}

