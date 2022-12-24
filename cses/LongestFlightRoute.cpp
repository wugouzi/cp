#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <fstream>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

vector<vector<int>> edge;
vector<int> to, dis, vis;
int n;

void dfs(int i) {
  vis[i] = 1;
  if (i == n-1) {
    dis[n-1] = 1;
  }
  for (auto &j : edge[i]) {
    if (!vis[j]) {
      dfs(j);
    }
    if (!dis[j]) continue;
    if (dis[j] + 1 > dis[i]) {
      dis[i] = dis[j] + 1;
      to[i] = j;
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // fstream f("../cses/test_input.txt");

  int m, a, b;
  cin >> n >> m;
  // f >> n >> m;
  edge.resize(n);
  to.resize(n);
  dis.resize(n);
  vis.resize(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    // f >> a >> b;
    edge[a-1].push_back(b-1);
  }

  dfs(0);

  if (!vis[n-1]) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << dis[0] << endl;
  vector<int> ans;
  int j = 0;
  cout << 1 << ' ';
  while (j != n-1) {
      j = to[j];
      cout << j+1 << ' ';
  }


  /*
  int vis[n], dis[n], prev[n];
  memset(vis, 0, sizeof(vis));
  memset(dis, 0, sizeof(dis));
  priority_queue<pp, vector<pp>, greater<pp>> q;
  q.push({0,0});
  while (!q.empty()) {
    int c = q.top().first;
    int s = q.top().second;
    q.pop();
    if (dis[s] < c) continue;
    for (auto &t : edge[s]) {
      if (c-1 < dis[t]) {
        dis[t] = c-1;
        q.push({c-1, t});
        prev[t] = s;
      }
    }
  }
  if (dis[n-1] == 0) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << -dis[n-1]+1 << endl;
  vector<int> ans;
  ans.push_back(n-1);
  int j = n-1;
  while (j != 0) {
    j = prev[j];
    ans.push_back(j);
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] + 1 << ' ';
  return 0;
    */
}
