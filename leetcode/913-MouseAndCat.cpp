//
// Created by wu on 2022/5/10.
//

//#include "leetcode.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
/*static const int N=55;
int dp[N*(N-1)+1][N][N];
int NN;
int dfs(vector<vector<int>> edge, int turn, int mouse, int cat) {
    //cout << turn << ' ' << mouse << ' ' << cat << endl;
    if (turn > NN*(NN-1)) {
        return 0;
    }
    if (dp[turn][mouse][cat] != -1)
        return dp[turn][mouse][cat];
    if (mouse == cat) {
        dp[turn][mouse][cat] = 2;
        return 2;
    }
    if (mouse == 0) {
        dp[turn][mouse][cat] = 1;
        return 1;
    }
    int j,tp;
    if (turn%2) {
        j = 1;
        for (auto& t : edge[cat]) {
            if (t == 0) continue;
            tp = dfs(edge,turn+1,mouse,t);
            if (tp == 2) {
                dp[turn][mouse][cat] = 2;
                return 2;
            } else
                j = min(j,tp);
        }

    } else {
        j = 2;
        for (auto& t : edge[mouse]) {
            tp = dfs(edge,turn+1,t,cat);
            if (tp == 1) {
                dp[turn][mouse][cat] = 1;
                return 1;
            } else
                j = min(j,tp);
        }
    }
    dp[turn][mouse][cat] = j;
    return j;
}

int catMouseGame(vector<vector<int>>& graph) {
    NN = 0;
    for (auto& cc : graph)
        for (auto& c : cc)
            NN = max(NN,c+1);
    for (int i = 0; i < NN; i++)
        for (int j = 0; j < NN; j++)
            for (int k = 0; k <= NN*(NN-1);k++)
                dp[k][i][j] = -1;
    return dfs(graph,0,1,2);
}*/

vector<vector<int>> parent(vector<vector<int>>& graph, int m, int c, int t) {
    vector<vector<int>> ans;

    if (t == 1) {
        for (auto& c2 : graph[c]) {
            if (c2 == 0) continue;
            ans.push_back(vector<int>{m,c2,2});
        }
    } else if (t == 2) {
        for (auto& m2 : graph[m]) {
            ans.push_back(vector<int>{m2,c,1});
        }
    }
    return ans;
}
int catMouseGame(vector<vector<int>>& graph) {
    int n = graph.size();
    queue<vector<int>> q;
    vector<vector<vector<int>>> color(n,vector<vector<int>>(n, vector<int>(3))),degree(n,vector<vector<int>>(n, vector<int>(3)));
    for (int m = 0; m < n; m++)
        for (int c = 0; c < n; c++) {
            degree[m][c][1] = graph[m].size();
            degree[m][c][2] = graph[c].size();
            for (int t : graph[c])
                if (t == 0) {
                    degree[m][c][2]--;
                    break;
                }
        }
    for (int i = 0; i < n; i++)
        for (int t = 1; t < 3; t++) {
            color[0][i][t] = 1;
            q.push(vector<int>{0,i,t,1});
            if (i > 0) {
                color[i][i][t] = 2;
                q.push(vector<int>{i,i,t,2});
            }
        }
    while (!q.empty()) {
        vector<int> tp = q.front();q.pop();
        int m = tp[0], c = tp[1], t = tp[2], win = tp[3];
        for (auto& pa : parent(graph, m, c, t)) {
            int m2 = pa[0], c2 = pa[1], t2 = pa[2];
            if (color[m2][c2][t2] != 0) continue;
            if (t2 == win) {
                color[m2][c2][t2] = win;
                q.push(vector<int>{m2,c2,t2,win});
            } else {
                degree[m2][c2][t2]--;
                if (!degree[m2][c2][t2]) {
                    color[m2][c2][t2] = 3-t2;
                    q.push(vector<int>{m2,c2,t2,3-t2});
                }
            }
        }
    }
    return color[1][2][1];
}

int main(void) {
    //vector<vector<int>> graph = {{2,5},{3},{0,4,5},{1,4,5},{2,3},{0,2,3}}; //0
    //vector<vector<int>> graph = {{5,6},{3,4},{6},{1,4,5},{1,3,5},{0,3,4,6},{0,2,5}};
    vector<vector<int>> graph = {{1,3},{0},{3},{0,2}};
    cout << catMouseGame(graph);
}