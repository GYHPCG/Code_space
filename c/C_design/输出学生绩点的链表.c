#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
struct student {
     char name[20]; 
     int xh;
     double gpa; 
     struct student *next;
};
void text(struct student *head);
struct student *Creat_Stu_Doc();
struct student *DeleteDoc(struct student *head,int score);
double pingjun(struct student *head);
int main()
{
	double gpa;
	struct student *head;
	head=NULL;
	head=Creat_Stu_Doc();
	gpa=pingjun(head);
	DeleteDoc(head,gpa);
	text(head);
	return 0;
 } 
struct student *Creat_Stu_Doc()
{
	struct student *head,*p,*t;
	head=NULL;
	char name[20];
	while(1)
	{
        scanf("%s",name);
        if(strcmp(name,"*")==0)
            break;
		p=(struct student *)malloc(sizeof(struct student));
		strcpy(p->name,name); 
		scanf("%d%lf",&p->xh,&p->gpa);
		if(head==NULL)
		{  head=p;
		   t=head;
		}
		else
		{
			t->next = p;
			t = p;
		}
	}
    t->next = NULL;
	return head;
}
struct student *DeleteDoc(struct student *head,int score)
{
	struct student *p,*p1;
	while(head->gpa<score)
	{
		p=head;
		head=head->next ;
		free(p);
	}
	p=head,p1=head->next ;
	while(p1!=NULL)
	{
		if(p1->gpa <score)
		{
			p->next = p1->next ;
			free(p1);
			p1=p->next ;
		}
		else
		{
			p=p1;
			p1=p1->next ;
		}
	}
	return head;
}
void text(struct student *head)
{
	struct student *p;
	for(p=head;p!=NULL;p=p->next)
	{
		printf("%s\n",p->name);
	}
}
double pingjun(struct student *head)
{
	double x=0,a=0;
	struct student *p;
	for(p=head;p!=NULL;p=p->next,a++)
	{
		x+=p->gpa;
	}
	x=x/a;
	return x;
}

