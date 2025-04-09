#include<string.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct lnode{
 int data;
 struct lnode *next;
}l;
l *create()
{
 l *p,*pre,*head,*new lnode;
 head=new lnode;
 p=head;
 int x;
 scanf("%d",&x);
 while(x!=-1)
 {
 pre=new lnode;
 pre->data=x;
p->next=pre;
 p=pre;
scanf("%d",&x);
}
 p->next=NULL;
 return head;
}
void jiaoji(l *head1,l *head2,l *head3)
{
 l *pa,*pc,*pb;
 pa=head1->next;
 pb=head2->next;
 pc=head3;
 if(pa==NULL||pb==NULL)
 pc=NULL;
  while(pa!=NULL&&pb!=NULL)
 {
 if(pa->data<pb->data)
 {
pa=pa->next;


 }
 else if(pa->data>pb->data)
 {
 pb=pb->next;
 }
 else if(pa->data==pb->data)
 {
 pc->next=pa;
 pc=pa;
 pa=pa->next;
 pb=pb->next;
 }
 }




}
void print(l *head)
{
 int i=0;
 l *s;
 s=head->next;
 while(s)
 {
 if(i)
 {printf(" ");}
 printf("%d",s->data);
 s=s->next;
 i++;
 }
}
int main()
{
 l *L1,*L2,*L3,;
 L1=create();
L2=create();
 L3=new lnode;
 L3->next=NULL;
 jiaoji(L1,L2,L3);
 if(L3->next==NULL)
{
 printf("NULL");
}
 else
 {
 print(L3);
 }
 return 0;




}

