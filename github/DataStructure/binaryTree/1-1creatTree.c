#include<stdio.h>
#include<malloc.h>
typedef struct TreeNode* Bintree;

struct TreeNode
{
    /* data */
    int data;
    Bintree left;
    Bintree right;

};
Bintree head = NULL;
//先序创建二叉树
Bintree creatTree() {
    int x;
    scanf("%d",&x);
    //if (x == 'z') return;
    Bintree T;
    if (x == 0 ) {
        T = NULL;
    }
    else {
        T = (Bintree)malloc(sizeof(struct TreeNode));
        T->data = x;
        //if (head == NULL) head = T;
        T->left = creatTree();
        T->right = creatTree();
    }
    return T;
}
void postTrave(Bintree T) {
    if (T == NULL) return;
    printf("%d ",T->data);
    postTrave(T->left);
    postTrave(T->right);
}
void inorderTrave(Bintree T){
    if (T == NULL) return;
    postTrave(T->left);
    printf("%d ",T->data);
    postTrave(T->right);
}
int main()
{
    //printf("hello,world");
    //Bintree T;
    head = creatTree();
    postTrave(head);
    inorderTrave(head);
    return 0;
}