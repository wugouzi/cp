#include "leetcode.h"

bool find(vector<vector<int>> &E, int i, int j, vector<int> &vis, vector<int> &num) {
  if (i == j) {
    return true;
  }
  vis[i] = 1;
  for (auto &c : E[i]) {
    if (!vis[c] && find(E, c, j, vis, num)) {
      num[c]++;
      vis[i] = 0;
      return true;
    }
  }
  vis[i] = 0;
  return false;
}
int dfs(int i, bool pa, vector<vector<int>> &E, vector<int> &vis, vector<int> &p) {
  vis[i] = 1;
  int res1 = p[i];
  for (auto &j : E[i]) {
    if (vis[j]) continue;
    res1 += dfs(j, false, E, vis, p);
  }
  if (!pa) {
    int res2 = p[i] / 2;
    for (auto &j : E[i]) {
      if (vis[j]) continue;
      res2 += dfs(j, true, E, vis, p);
    }
    res1 = min(res1, res2);
  }
  vis[i] = 0;
  return res1;
}
int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price, vector<vector<int>> &trips) {
  vector<int> nums(n), vis(n);
  vector<vector<int>> E(n);
  for (auto &p: edges) {
    E[p[0]].push_back(p[1]);
    E[p[1]].push_back(p[0]);
  }
  for (auto &p : trips) {
    find(E, p[0], p[1], vis, nums);
    nums[p[0]]++;
  }
  for (int i = 0; i < n; i++) {
    price[i] *= nums[i];
  }
  return dfs(0, false, E, vis, price);
}

int main(void) {
  int n = 4;
  vector<vector<int>> e = {{0, 1}, {1, 2}, {1, 3}};
  vector<int> p = {2, 2, 10, 6};
  vector<vector<int>> t = {{0, 3}, {2, 1}, {2, 3}};
  cout << minimumTotalPrice(n, e, p, t);
}