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
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    E[a-1].push_back({b-1, c});
  }
  priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>> q;
  vector<int> vis(n);
  q.push({0, 0, 0});
  ll a1 = LONG_MAX;

  vector<ll> a2(n, 0), a3(n, LONG_MAX), a4(n, -1);
  a2[0] = 1;
  while (!q.empty()) {
    ll c = q.top()[0];
    ll s = q.top()[1];
    ll t = q.top()[2];
    // cout << s << endl;
    q.pop();
    // if (vis[s]) continue;
    vis[s] = 1;
    for (auto &tt : E[s]) {
      if (vis[tt.first]) continue;
      if (tt.first == n-1) {
        if (tt.second + c <= a1) {
          a1 = c + tt.second;
          a2[n-1] += a2[s];
          a3[n-1] = min(a3[n-1], t+1);
          a4[n-1] = max(a4[n-1], t+1);
        }
      } else {
        a2[tt.first] += a2[s];
        a3[tt.first] = min(a3[tt.first], t+1);
        a4[tt.first] = max(a4[tt.second], t+1);
        q.push({c + tt.second, tt.first, t+1});
      }

    }
  }
  cout << a1 << ' ' << a2[n-1] << ' ' << a3[n-1] << ' ' << a4[n-1];
  return 0;
}
