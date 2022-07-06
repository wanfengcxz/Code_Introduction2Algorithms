//
// Created by 晚风吹行舟 on 2022/7/6.
//

#include <vector>
#include <string>

using  namespace std;

// 5. 最长回文子串
// 动态规划
// Time:O(n^2)  Space:O(n^2)
string longestPalindrome(string s) {
    int size = s.size();
    if (size == 1)
        return s;
    if (size == 2)
        return s[0] == s[1] ? s : s.substr(0, 1);

    vector <vector<bool>> dp(size, vector<bool>(size, true));
    int max_len = 1;
    string ans = s.substr(0, max_len);
    for (int i = 0; i < size - 1; i++) {
        int j = i + 1;
        if (s[i] != s[j])
            dp[i][j] = false;
        else {
            max_len = 2;
            ans = s.substr(i, max_len);
        }
    }

    for (int len = 2; len < size; len++) {
        for (int i = 0; i < size - len; i++) {
            int j = i + len;
            if (s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1];
            else
                dp[i][j] = false;
            if (dp[i][j] && j - i + 1 > max_len) {
                max_len = j - i + 1;
                ans = s.substr(i, max_len);
            }
        }
    }
    return ans;
}


pair<int, int> expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        --left;
        ++right;
    }
    return {left + 1, right - 1};
}

// 优化版本 中心扩散方法
// Time:O(n^2)  Space:O(1)
string longestPalindrome2(string s) {
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); ++i) {
        auto [left1, right1] = expandAroundCenter(s, i, i);
        auto [left2, right2] = expandAroundCenter(s, i, i + 1);
        if (right1 - left1 > end - start) {
            start = left1;
            end = right1;
        }
        if (right2 - left2 > end - start) {
            start = left2;
            end = right2;
        }
    }
    return s.substr(start, end - start + 1);
}

