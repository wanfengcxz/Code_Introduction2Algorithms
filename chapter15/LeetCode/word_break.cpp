//
// Created by 晚风吹行舟 on 2022/7/6.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// 139. 单词拆分
bool wordBreak(string s, vector<string> &wordDict) {
    int size = s.size();
    unordered_set<string> hashset;
    int max_len = 0;
    for (auto v:wordDict) {
        hashset.insert(v);
        if (max_len < v.size())
            max_len = v.size();
    }

    bool *dp = new bool[size];
    bool left, right;
    // [0, j-1] [j, i]
    for (int i = 0; i < size; i++) {
        dp[i] = false;
        for (int j = i; j >= 0; j--) {
            // 剪枝
            if (i-j+1>max_len)
                break;
            if (j - 1 < 0)
                left = true;
            else
                left = dp[j - 1];
            right = hashset.count(s.substr(j, i - j + 1)) > 0 ? true : false;
            if (right && left)
                dp[i] = true;
        }
    }
    return dp[size - 1];

}

bool wordBreak2(string s, vector<string>& wordDict) {
    int size = s.size();
    unordered_set<string> hashset;
    int max_len = 0;
    for(auto v:wordDict){
        hashset.insert(v);
        if (max_len < v.size())
            max_len = v.size();
    }

    bool *dp = new bool[size+1];
    dp[0] = true;
    bool left, right;

    for(int i = 0;i<size;i++){
        dp[i+1] = false;
        // [0, j-1] [j, i]
        for(int j = i;j>=0;j--){
            // 剪枝
            if (i-j+1>max_len)
                break;
            right = hashset.count(s.substr(j, i-j+1))>0?true:false;
            if (right && dp[j])
                dp[i+1] = true;
        }
    }
    return dp[size];

}

void test1() {
    string s = "leetcode";
    vector<string> dict = {"leet", "code"};
    cout << wordBreak(s, dict) << endl;
}

int main(){
    test1();

    return 0;
}