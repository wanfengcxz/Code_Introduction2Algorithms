//
// Created by 晚风吹行舟 on 2022/7/1.
//

#include <vector>

using namespace std;

// 300. 最长递增子序列  15.4-5 O(n^2)
int lengthOfLIS(vector<int>& nums) {
    int *arr = new int[nums.size()];
    arr[0] = 1;
    int ans = 1;
    for(int i = 1;i<nums.size();i++){
        int curr_max_len = 1;
        for(int j = 0;j<i;j++){
            if (nums[i] > nums[j] && curr_max_len<arr[j]+1)
                curr_max_len = arr[j]+1;
        }
        arr[i] =  curr_max_len;
        ans = curr_max_len>ans?curr_max_len:ans;
    }
    return ans;
}