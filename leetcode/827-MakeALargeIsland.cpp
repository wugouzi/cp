//
// Created by wu on 2022/9/18.
//

#include "leetcode.h"

unordered_map<int,int> is_idx, mp;
int m, n;
int key(int x, int y) {
    return x*n + y + 1;
}
vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
void dfs(vector<vector<int>> &grid, int x, int y, int id) {
    if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1)
        return;
    grid[x][y] = 2;
    is_idx[key(x,y)] = id;
    mp[id]++;
    for (const auto& dir : dirs) {
        int i = x + dir[0], j = y + dir[1];
        dfs(grid, i, j, id);
    }
}
int largestIsland(vector<vector<int>>& grid) {
    n = grid.size(), m = grid[0].size();
    int id = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                dfs(grid, i, j, id++);

    int ans = 0;
    if (mp.size() == 0)
        return 1;
    for (auto& [_, v] : mp)
        ans = max(ans, v);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                unordered_set<int> ids;
                for (const auto& dir : dirs) {
                    int x = i + dir[0], y = j + dir[1];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 2)
                        ids.insert(is_idx[key(x,y)]);
                }
                int n = ids.size();
                if (n == 0)
                    continue;
                vector<int> v;
                for (auto &id : ids)
                    v.push_back(mp[id]);
                sort(v.begin(), v.end());
                if (n == 1)
                    ans = max(ans, 1 + v[0]);
                else
                    ans = max(ans, 1 + v[n-2] + v[n-1]);
            }
        }
    }
    return ans;
}

int main(void) {
    vector<vector<int>> grid{{0,0}, {0,1}};
    cout << largestIsland(grid);
}