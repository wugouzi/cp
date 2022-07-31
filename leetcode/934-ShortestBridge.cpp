//
// Created by wu on 2022/3/23.
//
#include "leetcode.h"

queue<pair<int, int>> q;
int n, m;
vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
void dfs(vector<vector<int>>& grid, int i, int j) {
    if (i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == 1) {
        grid[i][j] = 2;
        q.emplace(i, j);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
    }
}

int shortestBridge(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();
    for (int i = 0; i < n && q.empty(); i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1) {
                dfs(grid, i, j);
                break;
            }
    int ans = -1;
    while (!q.empty()) {
        ans++;
        int t = q.size();
        while (t--) {
            pair<int, int> tp = q.front();
            int i = tp.first, j = tp.second;
            q.pop();
            for (auto& dir : dirs) {
                int newi = i + dir[0], newj = j + dir[1];
                if (newi >= 0 && newj >= 0 && newi < n && newj < m) {
                    if (grid[newi][newj] == 1) return ans;
                    if (grid[newi][newj] == 0) {
                        grid[newi][newj] = 2;
                        q.emplace(newi, newj);
                    }
                }
            }
        }
    }
    return 0;
}

int main(void) {
    vector<vector<int>> grid = {{0,1},{1,0}};
    cout << shortestBridge(grid);
}
