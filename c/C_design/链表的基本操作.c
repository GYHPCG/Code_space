#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stu{
    int num;
    struct stu *next;
};
int N,n;
int num3;
struct stu *creat(){
    struct stu *head;
    struct stu *p1=NULL;
    struct stu *p2=NULL;
    n=0;
    p1=(struct stu *)malloc(sizeof(struct stu));
    p2=p1;
    if(p1==NULL)
        return NULL;
    else {
        head =NULL;
        scanf("%d",&(p1->num));
        num3=p1->num;
    }
    while(n<N){
            n+=1;
        if(n==1){
            head=p1;
            p2->next=NULL;
        }
        else{
            p2->next=p1;
        }
        p2=p1;
        p1=(struct stu *)malloc(sizeof(struct stu));
        scanf("%d",&(p1->num));
        num3=p1->num;
    }
    p2->next=NULL;
    free(p1);
    p1=NULL;
    return head;
};
struct stu *del(struct stu *head,int num){
    struct stu *p1;
    struct stu *p2;
    if(head==NULL){
            printf("delete fail\n");
        return head;
    }
    p1=head;
    n=1;
    while(n<num&&p1->next!=NULL){
        p2=p1;
        p1=p1->next;
        n++;
    }
    if(n==num){
        if(p1==head){
            head=p1->next;
        }
        else{
            p2->next=p1->next;
        }
        free(p1);
        p1=NULL;
        N-=1;
        printf("delete OK\n");
    }
    else{
        printf("delete fail\n");
    }
    return head;
};
struct stu *insert(struct stu *head,struct stu *node,int num1){
    struct stu *p1;
    n=1;
    if(head==NULL){
        if(num1==1){
            head=node;
            node->next=NULL;
            N+=1;
            printf("insert OK\n");
        }
        else
            printf("insert fail\n");
        return head;
    }
    p1=head;
    if(head!=NULL&&num1==1){
        node->next=p1;
        head=node;
        printf("insert OK\n");
        return head;
    }
        while(n<num1-1&&p1->next!=NULL){
            n++;
            p1=p1->next;
        }
        if(n==num1-1){
            node->next=p1->next;
            p1->next=node;
            N++;
            printf("insert OK\n");
        }
        else {
            printf("insert fail\n");
        }
    return head;
};
struct stu *reverse(struct stu *head){
    struct stu *p;
    struct stu *p1;
    struct stu *p2;
    p1=NULL;
    p2=head;
    while(p2!=NULL){
        p=p2->next;
        p2->next=p1;
        p1=p2;
        p2=p;
    }
    head =p1;
    return head;
};
void print(struct stu *head){
    struct stu *p;
    p=head;
    if(head!=NULL){
        do{
            printf("%d",p->num);
            p=p->next;
            if(p!=NULL)
            printf(" ");
        }while(p!=NULL);
        printf("\n");
    }
    else printf("Link list is empty\n");
}
void gt(struct stu *head,int num){
    struct stu *p;
    p=head;
    n=1;
    while(n<num&&p->next!=NULL){
        p=p->next;
        n++;
    }
    if(n==num){
        printf("%d\n",p->num);
    }
    else
        printf("get fail\n");
}
int main(){
    struct stu *head;
    struct stu *stu1;
    scanf("%d",&N);
    head=creat();
    //print(head);
    head=reverse(head);
    //print(head);
    //int num;
    int i,j;
    //scanf("%d",&num);
    //printf("%d\n",num);
    char s[20];
    int num1,num2;
    for(i=0;i<num3;i++){
        scanf("%s",s);
        if(strcmp(s,"show")==0){
            print(head);
        }
        else if(strcmp(s,"delete")==0){
            scanf("%d",&num1);
            head=del(head,num1);
        }
        else if(strcmp(s,"insert")==0){
            stu1=(struct stu *)malloc(sizeof(struct stu));
            scanf("%d %d",&num1,&(stu1->num));
            head=insert(head,stu1,num1);
        }
        else if(strcmp(s,"get")==0){
                scanf("%d",&num1);
            gt(head,num1);
        }
        memset(s,'\0',sizeof(s));
    }
    return 0;
}

