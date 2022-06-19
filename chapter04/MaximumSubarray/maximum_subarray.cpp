//
// Created by 晚风吹行舟 on 2022/4/23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> maximumSubarray_bruteforce(const vector<int> &array) {
    vector<int> ans;    // low,high,max_sum
    int low = 0, high = 0;
    int max_sum = -2147483648;
    unsigned int size = array.size();
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum = 0;
        for (int j = i; j < size; j++) {
            sum += array[j];
            if (sum > max_sum) {
                max_sum = sum;
                low = i;
                high = j;
            }
        }
    }
    ans.push_back(low);
    ans.push_back(high);
    ans.push_back(max_sum);
    return ans;
}

vector<int> find_max_crossing_summary(const vector<int> &array, int mid, int low, int high) {
    int left_sum = -2147483648;
    int right_sum = -2147483648;
    int sum = 0;
    vector<int> ans = {0, 0, 0};
    for (int i = mid; i >= low; i--) {
        sum += array[i];
        if (sum > left_sum) {
            left_sum = sum;
            ans[0] = i;
        }
    }
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += array[i];
        if (sum > right_sum) {
            right_sum = sum;
            ans[1] = i;
        }
    }
    ans[2] = right_sum + left_sum;
    return ans;
}

vector<int> maximumSubarray_divide(const vector<int> &array, int low, int high) {
    vector<int> ans = {low, high, array[low]};
    if (low == high)
        return ans;
    else {
        int mid = low + (high - low) / 2;
        vector<int> ans_left = maximumSubarray_divide(array, low, mid);
        vector<int> ans_right = maximumSubarray_divide(array, mid+1, high);
        ans = find_max_crossing_summary(array, mid, low, high);
        if (ans_left[2] >= ans_right[2] && ans_left[2] >= ans[2])
            return ans_left;
        else if (ans_right[2] >= ans_left[2] && ans_right[2] >= ans[2])
            return ans_right;
        else
            return ans;
    }
}

void test_runtime(){
    vector<int> arr1 = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};

}

int main(){

}

