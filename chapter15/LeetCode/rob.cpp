//
// Created by 晚风吹行舟 on 2022/6/21.
//

#include <iostream>
#include <vector>

using namespace std;

// 自底向上 递推
// eg. 20 7 9 3 1
int rob_bottom_up(vector<int> &nums) {
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return nums[0] > nums[1] ? nums[0] : nums[1];
    int size = nums.size();
    int *arr = new int[size];

    arr[0] = nums[0];
    arr[1] = nums[0] > nums[1] ? nums[0] : nums[1];

    for (int i = 2; i < size; i++) {
        int theft = arr[i - 2] + nums[i];
        int no_theft = arr[i - 1];
        arr[i] = theft > no_theft ? theft : no_theft;
    }
    return arr[size - 1];
}

