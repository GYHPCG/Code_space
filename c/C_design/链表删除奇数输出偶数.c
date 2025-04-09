#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
#define x 20

struct Node {
    int data;
    struct Node *next;
}s[x];

struct Node *create()
{
    struct Node* head,*p,*t;
    head = (struct Node *)malloc(sizeof(struct Node ));
    head->next = NULL;
    head->data = 0;
    t = head;
    int n;
    while(1){
        scanf("%d",&n);
        if(n==-1) break;
        p = (struct Node *)malloc(sizeof(struct Node ));
        p->data = n;
        p->next = NULL;
        t->next = p;
        t = p;
    }
    return head;
}

struct Node *delete( struct Node *head )
{
    struct Node* te,*p,*k;
    
    te = head;
    while(te->next !=NULL)
	{
        if(te->next->data%2==0)
		{
            te=te->next;
        }
        else {
			p = te->next;
            te->next = te->next->next;
            free(p);
		}
            
    }
    k=head->next;
    return k;
}
void print( struct Node *head )
{
     struct Node *p = head;
     if(p==NULL)
	 {
         printf("NULL");
     }else
	 {
            while (p) 
			{
            printf("%d ", p->data);
            p = p->next;
            }
     }
     printf("\n");
}

int main()
{
    struct Node *head;
    int n;
    scanf("%d",&n);
    head = s;
    while(n != 0)
    {
        head = create();
        head = delete(head);
        print(head);
        n--;
    }
    return 0;
}


