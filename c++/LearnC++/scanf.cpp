/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2023-01-05 01:07:05
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-03-07 19:24:37
 */
#include <iostream>
#include <cstdlib>
using namespace std;

const int N = 100010;

int son[N][26], cnt[N], idx;
char str[N];
void insert(char* str) {
    int  p = 0;
    for (int i = 0; str[i]; ++i) {
        int k = str[i] - 'a';
        if (!son[p][k]) son[p][k] = ++idx;
        p = son[p][k];
    }
    cnt[p]++;
    
}
void query(char* str) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int k = str[i] - 'a';
        if (!son[p][k]) {
            printf("0\n");
            return;
        }
        p = son[p][k];
    }
    printf("%d\n",cnt[p]);
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    char op;
    
    while (n--) {
        scanf("%c", &op);
        scanf("%s", str);
        //f (op[0] == 'I') insert(str);
        //else  query(str);
        printf("%c", op);
        puts(str);
    }
    system("pause"); // 需 #include <cstdlib>
    return 0;
}