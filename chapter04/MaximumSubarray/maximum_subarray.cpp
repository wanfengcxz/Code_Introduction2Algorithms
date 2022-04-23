//
// Created by 晚风吹行舟 on 2022/4/23.
//

#include <iostream>
#include <vector>

using namespace std;

vector<int> maximumSubarray_bruteforce(const vector<int>& array){
    vector<int> ans;    // low,high,max_sum
    int low = 0, high = 0;
    int max_sum = -2147483648;
    unsigned int size = array.size();
    int sum = 0;
    for (int i = 0;i<size;i++){
        sum = 0;
        for (int j = i;j<size;j++){
            sum += array[j];
            if (sum > max_sum){
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


