//
// Created by 晚风吹行舟 on 2022/6/23.
//
#include <vector>

using namespace std;

// 55. 跳跃游戏
bool canJump(vector<int>& nums) {
    int size = nums.size();
    if (size == 1)
        return true;
    int last_true = 0;
    for(int i = 1;i<size;i++){
        if (i-1 <= last_true){
            int curr = nums[i-1]+i-1;
            last_true = curr>last_true?curr:last_true;
            if (last_true>=size-1)
                return true;
        } else
            return false;
    }
    return false;
}
