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
int cut_rod_top_down(const int *rodPrice, int n, int recursion_count) {
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

int cut_rod_top_down_with_memoization_recursion(const int *rodPrice, int n, int max_benefit[]) {
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
int cut_rod_top_down_with_memoization(const int *rodPrice, int n) {
    if (n == 0)
        return 0;
    int *max_benefit = new int[n + 1];
    for (int i = 0; i <= n; i++)
        max_benefit[i] = -1;
    return cut_rod_top_down_with_memoization_recursion(rodPrice, n, max_benefit);
}

// 自底向上法
int cut_rod_bottom_up(const int *rodPrice, int n) {
    int *max_benefit = new int[n + 1];
    for (int i = 0; i <= n; i++)
        max_benefit[i] = -1;
    max_benefit[0] = 0;
    for (int i = 1; i <= n; i++) {
        int curr_max_benefit = -1;
        for (int j = 1; j <= i; j++) {
            int tmp = rodPrice[j] + max_benefit[i - j];
            curr_max_benefit = curr_max_benefit < tmp ? tmp : curr_max_benefit;
        }
        max_benefit[i] = curr_max_benefit;
    }
    return max_benefit[n];
}

// 扩展版自底向上法 不仅记录最优值 还记录最优解
void extended_cut_rod_bottom_up(const int *rodPrice, int n, int *max_benefit, int *cuts) {
    for (int i = 1; i <= n; i++) {
        int curr_max_benefit = -1;
        int curr_cut = 0;
        int tmp;
        for (int j = 1; j <= i; j++) {
            tmp = rodPrice[j] + max_benefit[i - j];
            if (curr_max_benefit < tmp) {
                curr_max_benefit = tmp;
                curr_cut = j;
            }
        }
        max_benefit[i] = curr_max_benefit;
        cuts[i] = curr_cut;
    }
}

// 扩展版自顶向下法 不仅记录最优值 还记录最优解
void extended_cut_rod_up_down_with_memoization(const int *rodPrice, int n, int *max_benefit, int *cuts) {
    int curr_max_benefit = -1;
    int tmp = 0;
    for (int i = 1; i <= n; i++) {
        if (max_benefit[n - i] == -1)
            extended_cut_rod_up_down_with_memoization(rodPrice, n - i, max_benefit, cuts);
        tmp = rodPrice[i] + max_benefit[n - i];
        if (tmp > curr_max_benefit) {
            curr_max_benefit = tmp;
            cuts[n] = i;
        }
    }
    max_benefit[n] = curr_max_benefit;
}

const int cut_cost = 0;
// 切割一次成本为cut_cost
void extended_cut_rod_bottom_up_with_cost(const int *rodPrice, int n, int *max_benefit, int *cuts) {
    for (int i = 1; i <= n; i++) {
        int curr_max_benefit = -10000;
        if (i < SIZE)
            curr_max_benefit = rodPrice[i];
        int curr_cut = 0;
        int tmp;
        for (int j = 1; j <= i; j++) {
            tmp = rodPrice[j] + max_benefit[i - j] - cut_cost;
            if (curr_max_benefit < tmp) {
                curr_max_benefit = tmp;
                curr_cut = j;
            }
        }
        max_benefit[i] = curr_max_benefit;
        cuts[i] = curr_cut;
    }
}

void test1() {
    int rodPrice[SIZE] = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int max_benefit[5] = {};
    int cuts[5] = {};
    extended_cut_rod_bottom_up(rodPrice, 4, max_benefit, cuts);
    cout << max_benefit[4] << endl;
    int n = 4;
    while (n > 0) {
        cout << cuts[n] << ' ';
        n = n - cuts[n];
    }
    cout << endl;
    for (int i = 0; i <= 4; i++) {
        cout << max_benefit[i] << ' ' << cuts[i] << endl;
    }
}

void test2() {
    int rodPrice[SIZE] = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    //  全部初始化为0
    int max_benefit[11] = {};
    int cuts[11] = {};
    extended_cut_rod_bottom_up(rodPrice, 10, max_benefit, cuts);
    for (int i = 0; i <= 10; i++) {
        cout << max_benefit[i] << ' ' << cuts[i] << endl;
    }
}

void test3() {
    int rodPrice[SIZE] = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int max_benefit[5] = {-1, -1, -1, -1, -1};
    int cuts[5] = {-1, -1, -1, -1, -1};
    cuts[0] = 0;
    max_benefit[0] = 0;
    extended_cut_rod_up_down_with_memoization(rodPrice, 4, max_benefit, cuts);
    cout << max_benefit[4] << endl;
    int n = 4;
    while (n > 0) {
        cout << cuts[n] << ' ';
        n = n - cuts[n];
    }
    cout << endl;
    for (int i = 0; i <= 4; i++) {
        cout << max_benefit[i] << ' ' << cuts[i] << endl;
    }
}

void  test4() {
    int rodPrice[SIZE] = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
    int max_benefit[5] = {-1, -1, -1, -1, -1};
    int cuts[5] = {-1, -1, -1, -1, -1};
    cuts[0] = 0;
    max_benefit[0] = 0;
    extended_cut_rod_bottom_up_with_cost(rodPrice, 4, max_benefit, cuts);
    cout << max_benefit[4] << endl;
    int n = 4;
    while (n > 0) {
        cout << cuts[n] << ' ';
        if (cuts[n] == 0)
            break;
        n = n - cuts[n];
    }
    cout << endl;
    for (int i = 0; i <= 4; i++) {
        cout << max_benefit[i] << ' ' << cuts[i] << endl;
    }
}


int main() {

    int rodPrice[SIZE] = {-1, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};
//    cout << cut_rod_top_down(rodPrice, 4, 0) << endl;
//    cout << cut_rod_top_down_with_memoization(rodPrice, 4);
//    cout << cut_rod_bottom_up(rodPrice, 4);

    test4();


    return 0;
}
