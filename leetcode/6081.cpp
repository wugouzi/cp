//
// Created by wu on 2022/5/29.
//
#include "leetcode.h"
vector<vector<int>> dirs = {{0,1},{-1,0},{1,0},{0,-1}};
int dist[10000][10000];
int minimumObstacles(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    memset(dist,-1,sizeof(dist));
    dist[n-1][m-1] = grid[n-1][m-1];
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
    q.push({dist[n-1][m-1],n-1,m-1});
    while (!q.empty()) {
        vector<int> tp = q.top();q.pop();
        int w = tp[0], x = tp[1], y = tp[2];
        for (auto& dir : dirs) {
            int nx = x+dir[0], ny = y+dir[1];
            if (0 <= nx && 0 <= ny && nx < n && ny < m) {
                if (dist[nx][ny] != INT_MAX) continue;
                dist[nx][ny] = w+grid[nx][ny];
                q.push({dist[nx][ny],nx,ny});
            }
        }
    }
    return dist[0][0];
}

int main(void) {
    vector<vector<int>> tp = {{0,1,0,0,0},{0,1,0,1,0},{0,0,0,1,0}};
    cout << minimumObstacles(tp);
}