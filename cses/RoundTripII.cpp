#include <functional>
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

bool dfs(vector<vector<int>> &edge, int *vis, vector<int> &s, int i) {
  vis[i] = 1;
  s.push_back(i);
  for (auto &j : edge[i]) {
    if (vis[j] == 0) {
      if (dfs(edge, vis, s, j)) {
        return true;
      }
    } else if (vis[j] == 1) {
      s.push_back(j);
      return true;
    }
  }
  s.pop_back();
  vis[i] = 2;
  return 0;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  ll n, m, a, b;
  cin >> n >> m;
  vector<int> s;
  vector<vector<int>> edge(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    edge[a-1].push_back(b-1);
  }
  int vis[n];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    if (vis[i] == 0 && dfs(edge, vis, s, i)) {
      int j = s.size() - 2;
      int e = s.size() - 1;
      while (s[j] != s[e]) j--;
      cout << e -j + 1 << endl;
      for (; j <= e; j++) {
        cout << s[j] + 1 << ' ';
      }
      return 0;
    }
  }
  cout << "IMPOSSIBLE";
  return 0;
}
