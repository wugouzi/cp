//
// Created by wu on 2022/3/22.
//

#include "leetcode.h"

vector<vector<int>> dirs = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
int m, n;
int dfs(vector<vector<int>>& grid, int i, int j) {
    //cout << i << ' ' << j << endl;
    if (i == n-1 && j == m-1)
        return 1;
    grid[i][j] = 2;
    int len = INT_MAX/2;
    for (auto& dir : dirs) {
        int newi = i+dir[0], newj = j+dir[1];
        if (newi >= 0 && newj >= 0 && newi < n && newj < m && grid[newi][newj] == 0) {
            int tp = dfs(grid, newi, newj) + 1;
        }

    }
    grid[i][j] = 0;
    //cout << i << ' ' << j << ' ' << len << endl;
    return len;
}
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    int len = dfs(grid, 0, 0);
    if (len >= INT_MAX/2) return -1;
    return len;
}

int main(void) {
    vector<vector<int>> m = {{0,1,0,0,1,1,0},{1,0,0,0,0,0,0},{1,0,0,1,1,1,1},{0,1,0,0,0,0,0},{1,0,0,0,0,0,1},{1,0,0,1,0,0,0},{1,0,1,0,0,1,0}};
    cout << shortestPathBinaryMatrix(m);
}