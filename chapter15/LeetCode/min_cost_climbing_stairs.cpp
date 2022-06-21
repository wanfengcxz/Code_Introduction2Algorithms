//
// Created by 晚风吹行舟 on 2022/6/21.
//
#include <iostream>
#include <vector>

using namespace std;

// 自底向上 动态规划
// 可以简化为只用两个int存储空间
int min_cost_climbing_stairs_bottom_up(vector<int> &cost) {
    int *minCost = new int[cost.size()];
    minCost[0] = 0;
    minCost[1] = cost[1] > cost[0] ? cost[0] : cost[1];

    for (int i = 2; i < cost.size(); i++) {
        int cost_1 = minCost[i - 1] + cost[i];
        int cost_2 = cost[i - 1] + minCost[i - 2];
        minCost[i] = cost_1 > cost_2 ? cost_2 : cost_1;
    }
    return minCost[cost.size() - 1];
}

void test1() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << min_cost_climbing_stairs_bottom_up(cost);
}

int main() {
    test1();
}
