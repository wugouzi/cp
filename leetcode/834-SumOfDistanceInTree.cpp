#include "leetcode.h"
const static int N = 40000;
vector<vector<int>> E(N);
int dp[N], sz[N];
int nn;
void bfs(int i) {
    sz[i] = 1;
    for (int j: E[i]) {
        if (!sz[j]) {
            bfs(j);
            dp[i] += dp[j] + sz[j];
            sz[i] += sz[j];
        }
    }
}

void bfs1(int i, vector<int> &ans) {
    for (auto &j: E[i]) {
        if (!ans[j]) {
            ans[j] = ans[i] + nn - 2 * sz[j];
            bfs1(j, ans);
        }
    }
}
vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    if (n == 1) return vector<int>(1, 0);
    nn = n;
    for (auto &e: edges) {
        E[e[0]].push_back(e[1]);
        E[e[1]].push_back(e[0]);
    }
    bfs(0);
    vector<int> ans(n);
    ans[0] = dp[0];
    bfs1(0, ans);
    return ans;
}

int main(void) {
  int n = 6;
  vector<vector<int>> e = {{0,1},{0,2},{2,3},{2,4},{2,5}};
  pv(sumOfDistancesInTree(n, e));
}
