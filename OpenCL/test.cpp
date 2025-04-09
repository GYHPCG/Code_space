#include<stdio.h>
#include<stdlib.h>
FILE* p;
typedef struct TreeNode {
    char Data;
    struct TreeNode * Left;
    struct TreeNode * Right;
}BSTree;


BSTree* CreatBST(BSTree *t)
{
    char c;
    scanf("%c",&c);
    if(c=='#')t=NULL;
    else
    {
        t=(BSTree*)malloc(sizeof(BSTree));
        t->Data=c;
        t->Left= CreatBST(t->Left);
        t->Right = CreatBST(t->Right);
    }
    return t;
}
void Printl(BSTree*t)
{
    if(t)
    {
        printf("%c ",t->Data);
        Printl(t->Left);
        Printl(t->Right);
    }
    else return;
}
void Printm(BSTree*t)
{
    if(t)
    {
        Printm(t->Left);
        printf("%c ",t->Data);
        Printm(t->Right);
    }
    else return;
}
void Printr(BSTree*t)
{
    if(t)
    {
        Printr(t->Left);
        Printr(t->Right);
        printf("%c ",t->Data);
    }
    else return;
}
int main()
{
    BSTree *t=NULL;
    t=CreatBST(t);
    Printl(t->Left);
    printf("\n");
    Printm(t);
    printf("\n");
    Printr(t);
    printf("\n");
}


