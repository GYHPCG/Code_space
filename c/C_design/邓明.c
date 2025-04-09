#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SSS sizeof(struct stu)
struct stu{
    char name[20];
    char num[4];
    float grade;
    struct stu *next;
};
struct stu *creat()
{
    int i=0;
    struct stu *head,*node,*tail;
    node=(struct stu*)malloc(SSS);
    scanf("%s%s%f",&node->name,&node->num,&node->grade);
    head=NULL;
    while(node->next!=NULL)
    {
        if(i==0) head=node;
        else tail->next=node;
            tail=node;
            node=(struct stu*)malloc(SSS);
            scanf("%s",&node->name);
            if(strcmp(node->name,"*")==0)break;
            scanf("%s%f",&node->num,&node->grade);
            ++i;
    }
    tail->next=NULL;
    return head;
}
struct stu *dele(struct stu *head,float av)
{
    struct stu *p,*q;
    if(head==NULL){
    return(head);
    }
    p=head;
    while(p->next!=NULL)
    {
        q=p;
        p=p->next;
        if(av>p->grade)
        {
            if(p==head)
            head=p->next;
            else
           	q->next=p->next;
        }
    }
    return (head);
}
float aver(struct stu *head)
{
    double m=0.0;
    int n=0;
    struct stu *p = head;
    while(p->next!=NULL){
        m+=p->grade;
        p=p->next;
        n++;
    }
    return(m/n);
}
void print(struct stu *head)
{
    struct stu *p;
    p=head;
    while(p!=NULL)
    {
        printf("%s\n",p->name);
        p=p->next;
    }
}

void main()
{
    float n;
    struct stu *head = NULL;
    head=creat();
    n=aver(head);
    dele(head,n);
    print(head);
}
