#include <iostream>
#include <vector>
using namespace std;

static const int N = 10000;
using ll = long long;
using pp = pair<ll,ll>;
pp score[N];
ll ans;
void dfs(vector<vector<int>> &E, int i, int pv, int po, vector<int> &vis) {
  vis[i] = 1;
  if (score[i].second > po) {
    po = score[i].second;
    pv = score[i].first;
  }
  ans += pv;
  for (auto &j: E[i]) {
    if (!vis[j]) dfs(E, j, pv, po, vis);
  }
}
int main() {
  int n, a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    score[i] = make_pair(a, 0);
  }
  vector<vector<int>> E(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    E[a-1].push_back(b-1);
    E[b-1].push_back(a-1);
  }
  cin >> c;
  for (int i = 1; i <= c; i++) {
    cin >> a >> b;
    score[a-1] = make_pair(b, i);
  }
  vector<int> vis(n);
  dfs(E, 0, -1, -1, vis);
  cout << ans;
  return 0;
}
// 64 位输出请用 printf("%lld")