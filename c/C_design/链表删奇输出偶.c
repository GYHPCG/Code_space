#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct Node
{
	int data;
	struct Node *next;
}Nod;
int main()
{
	Nod *head=NULL,*tail=NULL;
	Nod*p;
	int n;
	p=(Nod*)malloc(sizeof(Nod));
	scanf("%d",&n);
		while(n--)
		{
			int a;
			scanf("%d",&a);
			while(a!=-1)
			
			{
			
				p=(Nod*)malloc(sizeof(Nod));
				p->data=a;
				p->next=NULL;
				if(head==NULL)
				{
				head=p;
				tail=p;} 
				else 
				{
				tail->next=p;
				tail=p;}
				scanf("%d",&a);
			}
				tail->next=NULL;
				p=head;
			
		}
		/*p=head;
		
			while(p)
			  {
				if(p->data%2==0)
				     printf("%d ",p->data);
				 p=p->next;
			  }  */
	    p=head;
		
		Nod *t=NULL;
		while(p)
		{
			if(p->data%2==0)
			{
				p=p->next;
			}
		
			else{
				t=p->next;
				p->next=t->next;
				free(t);
				
			}
		}
		p=head;
		while(p){
			printf("%d ",p->data);
			p=p->next;
		}
		if(p==NULL)
		printf("NULL");	 
	 
	return 0;
}

