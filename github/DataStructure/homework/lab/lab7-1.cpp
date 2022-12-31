/*
 * @Descripttion: MyCode
 * @Author: CGPan
 * @Date: 2022-11-23 09:58:10
 * @LastEditors: CGPan
 * @LastEditTime: 2022-12-02 22:09:35
 */
#include <iostream>
using namespace std;

int Mcount = 0;
/*编写程序，在
程序中初始化一个有序整数数组；从
键盘输入一个整数，在该数组中用折半查找，输
出查找结果（下标）。*/
int binary_search(int arr[],int n,int num) {
    int left = 0;
    int right = n - 1;
    int mid ;
    while (left <= right) {
        //++Mcount;
        mid = left + (right - left) / 2;
        if (arr[mid] < num) left = mid + 1;
        else if (arr[mid] > num) right = mid - 1;
        else return mid;
        ++Mcount;
    }
    return -1;//返回-1说明找不到，数组中没有
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int i = 0;
    int x = n;
    while(x--) {
        cin >> arr[i++];
    }
    cout << "输入需要查找的数字：" << endl;
    int num;
    cin >> num;
    cout <<num << "的下标为 " << binary_search(arr,n,num) << endl;
    cout << Mcount;
    return 0;

}
