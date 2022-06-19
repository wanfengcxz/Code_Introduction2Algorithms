//
// Created by 晚风吹行舟 on 2022/6/19.
//

#include <iostream>
#include <string>

using namespace std;

const int SIZE = 11;

void PrintWithPrefix(string str, int prefix_num, char prefix_char = '-') {
    cout << string(prefix_num * 4, prefix_char) << str << endl;
}


// 朴素的递归算法
int cut_rod_top_down(int (&rodPrice)[SIZE], int n, int recursion_count) {
    int max_benefit = -1;
    PrintWithPrefix("New Recursion !!!", recursion_count);
    PrintWithPrefix("current rod length is " + to_string(n), recursion_count);
    if (n == 0) {
        PrintWithPrefix("the max_benefit of len " + to_string(n) + " is 0", recursion_count);
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        PrintWithPrefix("start calculate cut_rod_top_down(" + to_string(n - 1) + ")", recursion_count);
        int tmp = rodPrice[i] + cut_rod_top_down(rodPrice, n - i, recursion_count + 1);
        max_benefit = max_benefit > tmp ? max_benefit : tmp;
    }
    PrintWithPrefix("the max_benefit of len " + to_string(n) + " is " + to_string(max_benefit), recursion_count);
    return max_benefit;
}

int cut_rod_top_down_with_memoization_recursion(int (&rodPrice)[SIZE], int n, int max_benefit[]) {
    int curr_max_benefit = -1;
    if (n == 0)
        curr_max_benefit = 0;
    else {
        for (int i = 1; i <= n; i++) {
            int tmp;
            if (max_benefit[n - i] != -1)
                tmp = rodPrice[i] + max_benefit[n - i];
            else
                tmp = rodPrice[i] + cut_rod_top_down_with_memoization_recursion(rodPrice, n - i, max_benefit);
            curr_max_benefit = tmp > curr_max_benefit ? tmp : curr_max_benefit;
        }
    }
    max_benefit[n] = curr_max_benefit;
    return curr_max_benefit;
}

// 带备忘录的自顶向下法
int cut_rod_top_down_with_memoization(int (&rodPrice)[SIZE], int n) {
    if (n == 0)
        return 0;
    int *max_benefit = new int[n + 1];
    for (int i = 0; i <= n; i++)
        max_benefit[i] = -1;
    return cut_rod_top_down_with_memoization_recursion(rodPrice, n, max_benefit);
}

// 自底向上法
int cut_rod_bottom_up(int (&rodPrice)[SIZE], int n) {
    int *max_benefit = new int[n + 1];
    for (int i = 0; i <= n; i++)
        max_benefit[i] = -1;
    max_benefit[0] = 0;
    for (int i = 1; i <= n; i++) {
        int curr_max_benefit = -1;
        for (int j = 1; j <= i; j++) {
            int tmp = rodPrice[j]+max_benefit[i-j];
            curr_max_benefit = curr_max_benefit<tmp?tmp:curr_max_benefit;
        }
        max_benefit[i] = curr_max_benefit;
    }
    return max_benefit[n];
}


int main() {

    int rodPrice[SIZE] = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//    cout << cut_rod_top_down(rodPrice, 4, 0) << endl;
//    cout << cut_rod_top_down_with_memoization(rodPrice, 4);
    cout << cut_rod_bottom_up(rodPrice, 4);

}
