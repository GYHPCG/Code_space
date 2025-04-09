#include<stdio.h>
#include <CL/cl.h>
void swap(int*,int*);
int main()
{
	int x = 1;
	int y = 2;
	int* px = &x;
	int* py = &x;
	swap(px,py);
	printf("x = %d, y = %d\n",*px,*py);
    printf("hello,wolrd\n");
	return 0;
}
void swap(int*px,int*py) {
	*px = *px + *py;
	*py = *px - *py;
	*px = *px - *py;
}
