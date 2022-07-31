//
// Created by wu on 2022/2/27.
//
#include <iostream>
#include <vector>

using namespace std;
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> tp(n, vector<int>(m));
    tp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++) tp[i][0] = tp[i-1][0] + grid[i-1][0];
    for (int j = 1; j < m; j++) tp[0][j] = tp[0][j-1] + grid[0][j-1];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            tp[i][j] = min(tp[i-1][j], tp[i][j-1]) + grid[i][j];
        }
    }
    return tp[n-1][m-1];
}

int main(void) {
    vector<vector<int>> tp = {{1,2,3},{4,5,6}};
    cout << minPathSum(tp);
}