/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-29 10:45:41
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-29 17:32:20
 */
#include <iostream>
#include <ctime>
using namespace std;

void sort_odd(int arr[], int length) {
    int i = 0, j = length - 1;
    while(i <= j) {
        //在数组里，从前往后找奇数，从后往前找偶数，交换位置即可
        if (arr[i] % 2 == 1 && arr[j] % 2 == 0) {
            std::swap(arr[i],arr[j]);
        }
        if (arr[i] % 2 != 1) ++i;
        if (arr[j] % 2 != 0) --j;
    }
}
int main()
{
    constexpr int n = 10;
    int arr[n];
    srand((int)time(0));
    int x = 0;
    for (int i = 0; i < n;++i) {
        //cin >> arr[i];
        x = rand();
        arr[i] = x;
    }
    cout << "输出未排前：\n";
    for (int i = 0; i < n; ++i) {
         cout << arr[i] << " ";
    }
    cout << endl;
    sort_odd(arr,n);
    cout << "输出奇后偶前重排结果：\n"; 
    for (int i = 0; i < n;  ++i) 
    {
        cout << arr[i] << " ";
    }
    return 0;

}
