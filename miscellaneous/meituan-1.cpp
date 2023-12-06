#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pp = pair<int,int>;
int dep[1000];

void dfs(vector<vector<int>> &E, int i, vector<int> &vis) {
  vis[i] = 1;
  int big = 0;
  for (auto &j: E[i]) {
    if (vis[j]) continue;
    if (!dep[j]) dfs(E, j, vis);
    big = max(big, dep[j]);
  }
  dep[i] = big + 1;
  vis[i] = 0;
}
int main() {
  int n, H, A;
  vector<int> h(1000), a(1000);
  cin >> n >> H >> A;
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  for (int i = 0; i < n; i++)
    cin >> a[i];
  auto big = [&](int i, int j) {
    return h[i] > h[j] && a[i] > a[j];
  };
  vector<vector<int>> E(n);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (big(i, j)) {
        E[i].push_back(j);
      }
    }
  }
  int ans = 0;
  vector<int> vis;
  for (int i = 0; i < n; i++) {
    if (!dep[i])
      dfs(E, i, vis);
    ans = max(dep[i], ans);
  }
  cout << ans;
  return 0;
}
// 64 位输出请用 printf("%lld")