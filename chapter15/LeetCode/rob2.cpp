//
// Created by 晚风吹行舟 on 2022/6/22.
//
#include <iostream>
#include <vector>

using namespace std;

// 213
int rob1(vector<int> &nums) {
    int size = nums.size();
    int max[2];

    max[0] = nums[0];
    max[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    for (int i = 2; i < size; i++) {
        int theft = max[i % 2] + nums[i];
        int no_theft = max[(i - 1) % 2];
        max[i % 2] = theft > no_theft ? theft : no_theft;
    }
    return max[(size - 1) % 2];
}

int rob2(vector<int> &nums) {
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];

    int last = nums[nums.size() - 1];
    nums.pop_back();
    int max1 = rob1(nums);
    nums.push_back(last);
    nums.erase(nums.begin());
    int max2 = rob1(nums);
    return max1 > max2 ? max1 : max2;
}

