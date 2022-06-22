//
// Created by 晚风吹行舟 on 2022/6/22.
//

#include <vector>

using namespace std;

int rob1(vector<int> &nums) {
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];

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

// 740
int deleteAndEarn(vector<int> &nums) {
    int maxValue = -1;
    for (auto v:nums) {
        if (maxValue < v)
            maxValue = v;
    }

    vector<int> sum(maxValue);
    for (auto v:nums) {
        sum[v - 1] += v;
    }

    return rob1(sum);
}
