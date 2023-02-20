#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <stack>
#include <deque>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

#define N 200200
//#define N 10
int n,q;
ll bit[N], contrib[N], x[N], pref[N], ans[N];

void update(int i, ll d) {
  for (; i <= n; i += i & (-i)) {
    bit[i] += d;
  }
}

ll query(int l, int r) {
  ll ans = 0;
  for (l--;l; l -= l & -l) ans -= bit[l];
  for (;r; r -= r & -r) ans += bit[r];
  return ans;
}

// follows https://usaco.guide/problems/cses-2416-increasing-array-queries/solution?lang=cpp

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> q;
  cin >> x[1];
  pref[0] = x[1];
  for (int i = 2; i <= n; i++) {
    cin >> x[i];
    pref[i] = x[i] + pref[i-1];
  }
  vector<vector<pp>> queries(n+1);
  deque<int> stk;
  int a, b;
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    queries[a].push_back({b, i});
  }
  for (int i = n; i >= 1; i--) {
    // a monotone stack
    while (!stk.empty() && x[i] > x[stk.front()]) {
      update(stk.front(), -contrib[stk.front()]);
      stk.pop_front();
    }
    // constribution of each block
    contrib[i] = stk.empty() ? (x[i] * (n - i) - pref[n] + pref[i]) :
                 (x[i] * (stk.front() - 1 - i) - pref[stk.front() - 1] + pref[i]);
    update(i, contrib[i]);
    stk.push_front(i);
    for (auto &p : queries[i]) {
      int pos = upper_bound(stk.begin(), stk.end(), p.first) - stk.begin() - 1;
      ans[p.second] = (pos ? query(i, stk[pos] - 1) : 0) +
                      (p.first - stk[pos]) * x[stk[pos]] - (pref[p.first] - pref[stk[pos]]);
    }
  }
  for (int i = 0; i < q; i++)
    cout << ans[i] << ' ';
  return 0;
}
