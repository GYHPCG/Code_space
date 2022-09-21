#include<stdio.h>
#define MaxTree 10
#define ElemantType char
#define Tree int
#define Null -1
struct TreeNode
{
    /* data */
    ElemantType element;
    Tree left;
    Tree right;
}T1[MaxTree],T2[MaxTree];
Tree BulidTree(struct TreeNode T[]) {
    int N;
    scanf("%d\n",&N);
    int check[N];
    char cl,cr;
    Tree root = -1;
    if (N) {
        for (int i = 0; i< N;i++) check[i] = 0;
        for (int i = 0; i < N; i++) {
           scanf("%c %c %c\n",&T[i].element,&cl,&cr);
           if (cl != '-') {
            T[i].left = cl - '0';
            check[T[i].left] = 1;
           }else {
            T[i].left = Null;
           }

           if (cr != '-') {
            T[i].right = cr - '0';
            check[T[i].right] = 1;
           }else {
            T[i].right = Null;
           }
        }
        for (int i = 0; i < N; i++) {
            if (check[i] == 0) {
                root = i;
                break;
            }
        }
        
    }
    return root;
}
int Issomorhpic(Tree R1,Tree R2) {
    //两颗树都是空的
    if((R1 == Null) && (R2 == Null)) return 1;
    if(((R1 != Null) && (R2 == Null)) || ((R1 == Null) && (R2 != Null))) return 0;
    if (T1[R1].element != T2[R2].element) return 0;
    if ((T1[R1].left == Null) && (T2[R2].left == Null)) return Issomorhpic(T1[R1].right,T2[R2].right);
    if (((T1[R1].left != Null) && (T2[R2].left != Null)) && (T1[T1[R1].left].element == T2[T2[R2].left].element)) {
        return (Issomorhpic(T1[R1].left,T2[R2].left) && Issomorhpic(T1[R1].right,T2[R2].right));
    }
    //swap;
    return (Issomorhpic(T1[R1].left,T2[R2].right) && Issomorhpic(T1[R1].right,T2[R2].left));
}
int main() 
{
    Tree R1, R2;
    R1 = BulidTree(T1);
    R2 = BulidTree(T2);
    if (Issomorhpic(R1,R2)) {
        printf("Yes\n");
    }else {
        printf("No\n");
    }
    return 0;
}