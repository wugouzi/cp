//
// Created by wu on 2022/10/9.
//


#include "leetcode.h"
int cnt, n, m;
vector<vector<int>> dirs{{0,1},{0,-1},{-1,0},{1,0}};

int dfs(vector<vector<int>> &grid, int x, int y) {
    grid[x][y] = 2;
    int cnt = 1;
    for (auto &dir : dirs) {
        int i = x + dir[0], j = y + dir[1];
        if (i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1) {
            cnt += dfs(grid, i, j);
        }
    }
    return cnt;
}

bool check(vector<vector<int>> &grid, int x, int y) {
    return x == 0 || (x > 0 && grid[x-1][y] == 2) || (x < n-1 && grid[x+1][y] == 2) ||
           (y > 0 && grid[x][y-1] == 2) || (y < m-1 && grid[x][y+1] == 2);
}

vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
    n = grid.size(), m = grid[0].size();

    for (auto &h : hits) {
        if (grid[h[0]][h[1]])
            grid[h[0]][h[1]] = -1;
    }
    vector<int> ans(hits.size());
    for (int j = 0; j < m; j++)
        if (grid[0][j] == 1)
            dfs(grid, 0, j);
    for (int i = hits.size()-1; i >= 0; i--) {
        int x = hits[i][0], y = hits[i][1];
        if (grid[x][y] == 0) continue;
        grid[x][y] = 1;
        if (check(grid, x, y))
            ans[i] = dfs(grid, x, y) - 1;
    }
    return ans;
}

int main(void) {
    //vector<vector<int>> b{{0,1,1,1,1,1,1,1,1},{1,1,1,1,1,1,1,1,1},{0,0,0,1,0,0,1,1,1},{0,0,1,1,0,1,1,1,0},{0,0,0,0,0,1,1,1,1},{0,0,0,0,0,0,0,1,0}},
    //h{{1,8},{2,1},{1,4},{3,0},{3,4},{0,7},{1,6},{0,8},{2,5},{3,2},{2,0},{0,2},{0,5},{0,1},{4,8},{3,7},{0,6},{5,7},{5,3},{2,6},{2,2},{5,8},{2,8},{4,0},{3,3},{1,1},{0,0},{4,7},{0,3},{2,4},{3,1},{1,0},{5,2},{3,8},{4,2},{5,0},{1,2},{1,7},{3,6},{4,1},{5,6},{0,4},{5,5},{5,4},{1,5},{4,4},{3,5},{4,6},{2,3},{2,7}};
    vector<vector<int>> b{{1,0,1},{1,1,1}}, h{{0,0},{0,2},{1,1}};
    vector<int> tp = hitBricks(b, h);
    for (auto &n : tp) cout << n << ' ';
}