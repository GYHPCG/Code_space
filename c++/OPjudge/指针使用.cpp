#include <stdio.h>
#include <stdlib.h>
void fun(int *p1, int *p2, int *s) {
    s = (int *)malloc(sizeof(int));
    *s = *p1 + *(p2++);
}
int main() {
    int a[2] = {1, 2}, b[2] = {10, 20}, *s = a;
    fun(a, b, s);
    printf("%d \n", *s);
}
