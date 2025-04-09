/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-29 11:35:49
 * @LastEditors: CGPan
 * @LastEditTime: 2022-11-29 12:28:32
 */
#include <iostream>

using namespace std;
void printArr(int arr[],int length) {
   for (int i = 0; i < length; ++i) {
    cout << arr[i] << " ";
   }
   cout << '\n';
}
void rodateArr(int arr[],int length, int p) {
    p = p % length;
    std::reverse(arr, arr + p);
    std::reverse(arr  +p,arr + length);
    std::reverse(arr,arr + length);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cout << "先输出数组："<< endl;
    printArr(arr,n);
    cout << "输入要左移p位置的p\n";
    int p;
    cin >> p;
    rodateArr(arr,n,p);
    cout << "左移后的数组\n";
    printArr(arr,n);
    return 0;

}
