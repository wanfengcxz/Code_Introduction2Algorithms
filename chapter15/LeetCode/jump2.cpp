//
// Created by 晚风吹行舟 on 2022/6/23.
//

#include <vector>

using namespace std;

// 45. 跳跃游戏 II
int jump(vector<int>& nums) {
    int size = nums.size();

    int *arr = new int[size];
    for(int i = 0;i<size;i++)
        arr[i] = 999999;
    arr[0] = 0;
    int jump_num = 1;
    for(int i = 0;i<size;i++){
        for(int j = i+1;j<=i+nums[i] && j<size;j++){
            if (arr[i]+1<arr[j])
                arr[j] = arr[i]+1;
        }
    }
    return arr[size-1];
}