#include<stdio.h>

void fun1(int *p1, int *p2)

{   int t;

t=*p1;  *p1=*p2;  *p2=t; 

}

void fun2(int x,int y)

{    int t;

t=x;   x=y;   y=t; 

}

void main()

{    int x,y;

int *p1,*p2;

scanf("%d%d",&x,&y);

p1=&x;     p2=&y;

if(x<y)  fun1(p1,p2);

printf("x=%d,y=%d\n",x,y);

if(x>y)  fun2(x,y);

printf("x=%d,y=%d",x,y); 

}  
