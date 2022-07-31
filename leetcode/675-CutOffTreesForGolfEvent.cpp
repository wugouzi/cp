//
// Created by wu on 2022/5/23.
//

#include "leetcode.h"
vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int bfs(vector<vector<int>>& forest, int sx, int sy, int ex, int ey) {
    if (sx == ex && sy == ey) return 0;
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    int dist = 0;
    vector<int> visited(n*m,0);
    visited[sx*m+sy] = 1;
    while (!q.empty()) {
        int k = q.size();
        dist++;
        while (k--) {
            pair<int,int> tp = q.front();q.pop();
            int tx = tp.first, ty = tp.second;
            for (auto& dir : dirs) {
                int ntx = tx+dir[0], nty = ty+dir[1];
                if (ntx >= 0 && nty >= 0 && ntx < n && nty < m && forest[ntx][nty] != 0) {
                    if (visited[ntx*m+nty]) continue;
                    if (ntx == ex && nty == ey) return dist;
                    visited[ntx*m+nty] = 1;
                    q.push(make_pair(ntx,nty));
                }
            }
        }
    }
    return -1;
}
int cutOffTree(vector<vector<int>>& forest) {
    n = forest.size(), m = forest[0].size();
    vector<vector<int>> trees;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (forest[i][j] > 1)
                trees.push_back({forest[i][j], i, j});
        }
    sort(trees.begin(), trees.end());
    int ans = bfs(forest,0,0,trees[0][1], trees[0][2]);
    for (int i = 0; i < trees.size()-1; i++) {
        int tp = bfs(forest, trees[i][1], trees[i][2], trees[i+1][1], trees[i+1][2]);
        if (tp == -1)
            return -1;
        ans += tp;
    }
    return ans;
}

int main(void) {
    //vector<vector<int>> t = {{54581641,64080174,24346381,69107959},{86374198,61363882,68783324,79706116},{668150,92178815,89819108,94701471},{83920491,22724204,46281641,47531096},{89078499,18904913,25462145,60813308}};
    //vector<vector<int>> t = {{1,2,3},{0,0,4},{7,6,5}};
    vector<vector<int>> t = {{2,3,4},{0,0,5},{8,7,6}};
    cout << cutOffTree(t);
}