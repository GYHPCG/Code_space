#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>vec;
        int maxr = INT_MIN;
        int left = 0;
        int right = 0;
        int l = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            maxr = max(maxr,nums[right]);
            l++;
            if (l == k) {
                vec.push_back(maxr);
                left++;
                l--;
                maxr = nums[left];
            }
        }
        return vec;


    }
};
int main()
{
	Solution A;
	vector<int>nu;
	for(int i = 0; i < 8;i++)
		cin >> nu[i];
	int k;
	cin >> k;
	vector<int>res;
	res = A.maxSlidingWindow(nu,k);
	for(int h:res)
		cout<<h<<" ";
	return 0;
	
}
