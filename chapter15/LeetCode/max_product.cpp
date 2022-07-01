//
// Created by 晚风吹行舟 on 2022/6/24.
//
#include <vector>

using namespace std;


int max_3(int a, int b, int c){
    if (a>b){
        if (a>c)
            return a;
        return c;
    }
    else {
        if (b>c)
            return b;
        return c;
    }
}

int min_3(int a, int b, int c){
    if (a>b){
        if (b>c)
            return c;
        return b;
    }
    else {
        if (a>c)
            return c;
        return a;
    }
}

// 152. 乘积最大子数组
int maxProduct(vector<int>& nums) {
    int Max[2] = {nums[0], 0};
    int Min[2] = {nums[0], 1};
    int ans = nums[0];
    for(int i = 1;i<nums.size();i++){
        // 此处可以调用两次内置函数max
        Max[i % 2] = max_3(Max[(i + 1) % 2] * nums[i], Min[(i + 1) % 2] * nums[i], nums[i]);
        Min[i % 2] = min_3(Max[(i + 1) % 2] * nums[i], Min[(i + 1) % 2] * nums[i], nums[i]);
        ans = max(ans, Max[i % 2]);
    }
    return ans;
}
