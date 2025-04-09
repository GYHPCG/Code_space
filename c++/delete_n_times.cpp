/*
 * @Descripttion: my code for learning
 * @Author: chenggong Pan
 * @Date: 2022-09-19 08:57:29
 * @LastEditors: chenggong Pan
 * @LastEditTime: 2024-03-10 13:40:52
 */
#include <vector>
#include <iostream>
#include <unordered_map> 
using namespace std;

/**
 * 删除数组中每个元素的前n个重复项
 * @param arr 输入的整数数组
 * @param n 要删除的每个元素的重复次数
 * @return 删除重复项后的数组
 */
std::vector<int> deleteNth(std::vector<int> arr, int n)
{
  
    int N = arr.size();
    vector<int>res;
    
    unordered_map<int,int>st; // 使用哈希表记录元素出现的次数
    for (int i = 0; i < N; ++i) {
        ++st[arr[i]]; // 增加当前元素的出现次数
        if (st[arr[i]] <= n) {
        	// 如果当前元素出现的次数不超过n，则将其添加到结果数组中
        	res.push_back(arr[i]);
		}
    }
    return res;
}

int main()
{
	vector<int>arr{1,1,3,3,7,2,2,2,2}; // 初始化输入数组
	vector<int>res = deleteNth(arr,3); // 调用函数删除每个元素的前3个重复项
	for(int i: res) {
		cout << i <<" "; // 打印结果数组的元素
	}
	
	// 下面的代码块涉及变量k的操作，但具体目的不明确
	int k = 1;
	//k++++;
	 ++++k; // 注意：这种写法是错误的，会引发编译错误
	 cout << "--------" << endl;
	 cout << k << endl; // 打印变量k的值
	
	return 0 ;
}