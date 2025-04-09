#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> minLeftIndex(heights.size());
        vector<int> minRightIndex(heights.size());
        int size = heights.size();

        // ��¼ÿ������ ��ߵ�һ��С�ڸ����ӵ��±�
        minLeftIndex[0] = -1; // ע�������ʼ������ֹ����while��ѭ��
        for (int i = 1; i < size; i++) {
            int t = i - 1;
            // ���ﲻ����if�����ǲ�������Ѱ�ҵĹ���
            while (t >= 0 && heights[t] >= heights[i]) t = minLeftIndex[t];
            minLeftIndex[i] = t;
        }
        // ��¼ÿ������ �ұߵ�һ��С�ڸ����ӵ��±�
        minRightIndex[size - 1] = size; // ע�������ʼ������ֹ����while��ѭ��
        for (int i = size - 2; i >= 0; i--) {
            int t = i + 1;
            // ���ﲻ����if�����ǲ�������Ѱ�ҵĹ���
            while (t < size && heights[t] >= heights[i]) t = minRightIndex[t];
            minRightIndex[i] = t;
        }
        // ���
        int result = 0;
        for (int i = 0; i < size; i++) {
            int sum = heights[i] * (minRightIndex[i] - minLeftIndex[i] - 1);
            result = max(sum, result);
        }
        return result;
    }
};
int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0;i < n;i++)
		cin >> arr[i];
	Solution A;
	cout<<A.largestRectangleArea(arr);
	return 0;
} 
