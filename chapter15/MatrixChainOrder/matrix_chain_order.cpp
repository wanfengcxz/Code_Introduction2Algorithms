//
// Created by 晚风吹行舟 on 2022/6/22.
//

#include <iostream>

using namespace std;

const int MatrixNum = 6;
int seq[MatrixNum + 1] = {30, 35, 15, 5, 10, 20, 25};

int matrix_chain_order(int seq[], int cuts[][MatrixNum - 1]) {
    int min[MatrixNum][MatrixNum];
    // 单个矩阵不用划分，则代价为0
    for (int i = 0; i < MatrixNum; i++)
        min[i][i] = 0;
    // 矩阵链的长度从2开始递增 即自底向上递推
    for (int len = 2; len <= MatrixNum; len++) {
        // 对于长度为len的一组矩阵链Ai....j
        for (int i = 0; i < MatrixNum - len + 1; i++) {
            int j = i + len - 1;
            int curr_min = 999999;
            int tmp = 0;
            // 从k处裁剪矩阵链Ai....j
            for (int k = i; k < j; k++) {
                tmp = min[i][k] + min[k + 1][j] + seq[i] * seq[k + 1] * seq[j + 1];
                if (curr_min > tmp) {
                    curr_min = tmp;
                    cuts[i][j - 1] = k;
                }
            }
            min[i][j] = curr_min;
        }
    }
    return min[0][MatrixNum - 1];
}

// i j为物理存储的下标 即0-5 而不是逻辑上1-6
void print_optimal(int cuts[][MatrixNum - 1], int i, int j) {
    if (i == j)
        cout << 'A' << i + 1;
    else {
        cout << '(';
        print_optimal(cuts, i, cuts[i][j - 1]);
        print_optimal(cuts, cuts[i][j - 1] + 1, j);
        cout << ')';
    }
}

int main() {

    // 在列上，由于单个矩阵无法拆分，因此
    // 横坐标0-4代表五个顶点1-5，纵坐标0-4代表五个顶点2-6
    int cuts[MatrixNum - 1][MatrixNum - 1];
    cout << matrix_chain_order(seq, cuts) << endl;

    for (int i = 0; i < MatrixNum - 1; i++) {
        for (int j = i; j < MatrixNum - 1; j++)
            cout << cuts[i][j] << ' ';
        cout << endl;
    }

    print_optimal(cuts, 0, 5);
}
