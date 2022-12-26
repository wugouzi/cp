#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

void top(vector<vector<int>> &E, vector<int> &ans, vector<int> &vis, int i) {
  vis[i] = 1;
  for (auto &j : E[i]) {
    if (!vis[j]) {
      top(E, ans, vis, j);
    }
  }
  ans.push_back(i);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  cin >> n >> m;
  int N = 1e9+7;
  vector<vector<int>> E(n), ER(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    E[a-1].push_back(b-1);
    ER[b-1].push_back(a-1);

  }
  vector<int> dp(n), sss, vis(n);
  top(E, sss, vis, 0);
  dp[0] = 1;
  for (int i = sss.size() - 1; i >= 0; i--) {
    int d = sss[i];
    for (auto &e : ER[d]) {
      (dp[d] += dp[e]) %= N;
    }
  }

  cout << dp[n-1];
  return 0;
}
