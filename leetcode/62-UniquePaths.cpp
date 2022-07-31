//
// Created by wu on 2022/2/27.
//
#include <vector>
#include <iostream>
using namespace std;

int uniquePaths(int m, int n) {
    vector<vector<int>> tp(m, vector<int>(n));
    for (int i = 0; i < n; i++) tp[0][i] = 1;
    for (int i = 0; i < m; i++) tp[i][0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            tp[i][j] = tp[i - 1][j] + tp[i][j - 1];
        }
    }
    return tp[m - 1][n - 1];
}

int main(void) {
    cout << uniquePaths(3, 7);
}