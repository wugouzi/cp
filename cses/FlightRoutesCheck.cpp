#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

void dfs(vector<vector<int>> &edge, int i, int *vis) {
  if (vis[i]) return;

  vis[i] = 1;
  for (auto &j : edge[i]) {
    if (!vis[j])
      dfs(edge, j, vis);
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a, b;
  cin >> n >> m;
  vector<vector<int>> E(n), ER(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    E[a-1].push_back(b-1);
    ER[b-1].push_back(a-1);
  }

  int vis[n];
  memset(vis, 0, sizeof(vis));
  dfs(E, 0, vis);

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << "NO\n" << 1 << ' ' << i+1;
      return 0;
    }
  }

  memset(vis, 0, sizeof(vis));
  dfs(ER, 0, vis);
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << "NO\n" << i+1 << ' ' << 1;
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
