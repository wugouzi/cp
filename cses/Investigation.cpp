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

int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, m, a, b, c;
  cin >> n >> m;
  vector<vector<pp>> E(n);
  int N = 1e9+7;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    E[a-1].push_back({b-1, c});
  }
  priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
  vector<int> vis(n);
  q.push({0, 0, 0});
  ll a1 = LONG_MAX;

  vector<ll> sp(n, LONG_MAX), cnt(n, 0), minf(n, LONG_MAX), maxf(n, -1);

  //observation: nodes in shortest path are still shortest path

  cnt[0] = 1;
  minf[0] = 0;
  maxf[0] = 0;
  while (!q.empty()) {
    ll c = q.top()[0];
    ll s = q.top()[1];
    // cout << s << endl;
    q.pop();
    if (vis[s]) continue;
    vis[s] = 1;
    for (auto &tt : E[s]) {
      int t = tt.first, w = tt.second;
      if (vis[t]) continue;
      if (w + c < sp[t]) {
        sp[t] = w + c;
        cnt[t] = cnt[s];
        minf[t] = minf[s] + 1;
        maxf[t] = maxf[s] + 1;
        q.push({w + c, t});
      } else if (w + c == sp[t]) {
        (cnt[t] += cnt[s]) %= N;
        minf[t] = min(minf[t], minf[s] + 1);
        maxf[t] = max(maxf[t], maxf[s] + 1);
      }
    }
  }
  cout << sp[n-1] << ' ' << cnt[n-1] << ' ' << minf[n-1] << ' ' << maxf[n-1];
  return 0;
}
