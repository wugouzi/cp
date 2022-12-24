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

vector<vector<int>> edge;

bool dfs(vector<int> &ans, vector<int> &vis, int i) {
  vis[i] = 1;
  for (auto &j : edge[i]) {
    if (vis[j] == 0 && !dfs(ans, vis, j)) {
      return false;
    }
    else if (vis[j] == 1) {
      return false;
    }
  }
  vis[i] = 2;
  ans.push_back(i);
  return true;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n,m,a,b;
  cin >> n >> m;
  edge.resize(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    edge[a-1].push_back(b-1);
  }
  vector<int> ans;
  vector<int> vis(n);
  for (int i = 0; i < n; i++) {
    if (!vis[i] && !dfs(ans, vis, i)) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << ans[i] + 1 << ' ';
  }
  return 0;
}
