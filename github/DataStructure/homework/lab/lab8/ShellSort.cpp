/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-12-14 17:36:53
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-14 18:20:48
 */
#include <iostream>

using namespace std;

using ElementType = int;

void printShell(ElementType A[]) {
    for (int i = 0; i < 10; ++i) {
        printf("%d, ",A[i]);
    }
    printf("\n");
}
void ShellSort(ElementType A[], int N) {
    int i, j, Increment; //增量,5,3,1
    ElementType Tmp;//辅助变量，临时存储
    //外循环次数为增量序列的增量个数//7,3,1
    int k = 0;//记录趟数
    int t = 2;
    for (Increment = 5; Increment > 0; Increment -= t) {
        for (i = Increment; i < N; i ++) {//对应不同增量的直接插入排序，Increment=1时相当于直接插入排序
            Tmp = A[i];
            for (j = i; j >= Increment; j -= Increment)
                if (Tmp < A[j - Increment])
                    A[j] = A[j - Increment];
                else
                    break;
            A[j] = Tmp;
        }
        printf("第%d趟的希尔排序结果:\n",++k);
        printShell(A);
    }
}

int main()
{
    int size = 10;
    int arr[size] = {49,38,65 ,97 ,76 ,13,27,48 ,55 ,4};
    ShellSort(arr,size);
    return 0;

}
