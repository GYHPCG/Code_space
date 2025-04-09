/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-10-26 11:02:33
 * @LastEditors: CGPan
 * @LastEditTime: 2022-10-26 11:06:23
 */
#include<stdio.h>
#include<stdlib.h>
struct Stack {
    int* Data;
    int Top;
    int MaxSize;
};
struct Stack *CreatStack()
{
    struct Stack* S = (struct Stack*)malloc(sizeof(struct Stack));
    S->MaxSize = 100;
    S->Data = (int*)malloc(sizeof( int)* S->MaxSize);
    S->Top = 0;
    return S;
}
void Push(Stack *S)
{
        scanf_s("%d", &S->Data[S->Top]);
        S->Top++;
}
void Pop(Stack *S)
{
        printf("%d ", S->Data[S->Top]);
        S->Top--;
}
int main()
{
   struct Stack *s = CreatStack();
   for(int i=0;i<10;i++)
    Push(s);
//    for (int i = 0; i < 10; i++)
//     Pop(s);
    return 0;
}
