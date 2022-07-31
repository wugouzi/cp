//
// Created by wu on 2022/4/6.
//
#include "leetcode.h"

int last;
vector<vector<int>> E;
int n;
int bfs(int s, vector<int>& parent) {
    queue<int> q;
    q.push(s);
    int maxlen = 0;
    vector<int> dist(n);
    dist[s] = 1;
    while (!q.empty()) {
        int src = q.front();
        q.pop();
        for (auto& tar : E[src]) {
            if (!dist[tar]) {
                parent[tar] = src;
                dist[tar] = dist[src]+1;
                if (dist[tar] > maxlen) {
                    maxlen = dist[tar];
                    last = tar;
                }
                q.push(tar);
            }
        }
    }
    return maxlen-1;
}
vector<int> findMinHeightTrees(int _n, vector<vector<int>>& edges) {
    n = _n;
    if (n == 1) return {0};
    E.resize(n);
    for (auto& p : edges) {
        E[p[0]].push_back(p[1]);
        E[p[1]].push_back(p[0]);
    }
    vector<int> parent(n);
    bfs(0, parent);
    int u = last;
    int maxlen = bfs(last, parent);
    int v = last;
    vector<int> ans;
    vector<int> path(n);
    int i;
    for (i = 0; u != v; i++, v = parent[v])
        path[i] = v;
    path[i] = u;
    if (maxlen%2) {
        ans.push_back(path[maxlen/2]);
        ans.push_back(path[maxlen/2+1]);
    }
    else {
        ans.push_back(path[maxlen/2]);
    }
    return ans;
}

int main(void) {
    int n = 2;
    vector<vector<int>> e = {{0,1}};
    vector<int> tp = findMinHeightTrees(n, e);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}
