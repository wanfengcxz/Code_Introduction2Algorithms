//
// Created by 晚风吹行舟 on 2022/6/30.
//
#include <string>
#include <iostream>

using namespace std;

// 自底向上
int longestCommonSubsequence(string text1, string text2) {
    int **arr = new int *[text1.size() + 1];
    for (int i = 0; i < text1.size() + 1; i++) {
        arr[i] = new int[text2.size() + 1];
        arr[i][0] = 0;
    }
    for (int j = 0; j < text2.size() + 1; j++) {
        arr[0][j] = 0;
    }

    for (int i = 1; i < text1.size() + 1; i++) {
        for (int j = 1; j < text2.size() + 1; j++) {
            if (text1[i - 1] == text2[j - 1])
                arr[i][j] = arr[i - 1][j - 1] + 1;
            else {
                arr[i][j] = arr[i - 1][j] > arr[i][j - 1] ? arr[i - 1][j] : arr[i][j - 1];
            }
        }
    }
    return arr[text1.size()][text2.size()];
}

int lcs_top_down_with_memoization_recursion(string &s1, string &s2, int i, int j, int **&arr) {
    if (i == -1 || j == -1)
        return 0;
    if (arr[i][j] == -1) {
        if (s1[i] == s2[j]) {
            if (i == 0 || j == 0)
                arr[i][j] = 1;
            else
                arr[i][j] = lcs_top_down_with_memoization_recursion(s1, s2, i - 1, j - 1, arr) + 1;
        } else {
//            if (i == 0 && j == 0)
//                arr[i][j] = 0;
//            else if (i == 0 && j != 0)
//                arr[i][j] = lcs_top_down_with_memoization_recursion(s1, s2, i, j - 1, arr);
//            else if (i != 0 && j ==0)
//                arr[i][j] = lcs_top_down_with_memoization_recursion(s1, s2, i - 1, j, arr);
            int tmp1 = lcs_top_down_with_memoization_recursion(s1, s2, i - 1, j, arr);
            int tmp2 = lcs_top_down_with_memoization_recursion(s1, s2, i, j - 1, arr);
            arr[i][j] = tmp1 > tmp2 ? tmp1 : tmp2;
        }
    }
    return arr[i][j];
}

// 自顶向下 带备忘录
int lcs_top_down_with_memoization(string &text1, string &text2) {
    // 分配内存空间
    int **arr = new int *[text1.size()];
    for (int i = 0; i < text1.size(); i++) {
        arr[i] = new int[text2.size()];
//        arr[i][0] = -1;
    }
    for (int i = 0; i < text1.size(); i++) {
        for (int j = 0; j < text2.size(); j++) {
            arr[i][j] = -1;
        }
    }
    return lcs_top_down_with_memoization_recursion(text1, text2, text1.size() - 1, text2.size() - 1, arr);
}


void test1() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << longestCommonSubsequence(s1, s2) << endl;

    string s3 = "bdcaba";
    string s4 = "abcbdab";
    cout << longestCommonSubsequence(s3, s4) << endl;
}

void test2() {
    string s1 = "abcde";
    string s2 = "ace";
    cout << lcs_top_down_with_memoization(s1, s2) << endl;

    string s3 = "bdcaba";
    string s4 = "abcbdab";
    cout << lcs_top_down_with_memoization(s3, s4) << endl;
}

int main() {
    test1();

    return 0;
}
