#include "leetcode.h"

vector<unordered_set<int>> E;
void dfs(int i, int p, vector<int> &coins, vector<int> &vis) {
  vis[i] = 1;
  for (auto &j : E[i]) {
    if (!vis[j])
      dfs(j, i, coins, vis);
  }
  if (E[i].empty() && !coins[i])
    E[p].erase(i);
}

int dfs2(int i, vector<int> &vis) {
  vis[i] = 1;
  if (E[i].size() == 1)
    return 0;
  int h = 0;
  for (auto iter = E[i].begin(); iter != E[i].end();) {
    int t = dfs2(*iter, vis);
    h = max(t, h);
    if (t <= 2)
      E[i].erase(iter++);
    else
      iter++;
  }
  vis[i] = 0;
  return h + 1;
}

int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
  int n = coins.size();
  E.resize(n);
  for (auto &e : edges) {
    E[e[0]].insert(e[1]);
    E[e[1]].insert(e[0]);
  }
  vector<int> vis(n);
  for (int i = 0; i < n; i++)
    if (!vis[i])
      dfs(i, -1, coins, vis);
  dfs2(0, vis);
  int sum = 0;
  for (auto &e : E)
    sum += e.size();
  return sum * 2;
}

int main(void) {
  vector<int> coins = {1, 0, 0, 0, 0, 1};
  vector<vector<int>> e = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}};
  cout << collectTheCoins(coins, e);
}
