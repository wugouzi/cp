#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

ll ans[200100], lazy[1000000];

void update(ll u, ll l, ll r, ll L, ll R, ll val) {
  if (L > r || R < l) {
    return;
  }
  if (L <= l && R >= r) {
    lazy[u] += val;
    return;
  }
  ll mid = (l+r)/2;
  update(u*2, l, mid, L, R, val);
  update(u*2+1, mid+1, r, L, R, val);
}

void push(int u, int l, int r, int k) {
  if (k < l || k > r) {
    return;
  }
  if (l == r) {
    ans[k] += lazy[u];
    lazy[u] = 0;
    return;
  }
  if (lazy[u]) {
    lazy[u*2] += lazy[u];
    lazy[u*2+1] += lazy[u];
    lazy[u] = 0;
  }
  int mid = (l+r)/2;
  push(u*2, l, mid, k);
  push(u*2+1, mid+1, r, k);
}



int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  ll n, q, m, a, b, u;
  memset(lazy, 0, sizeof(lazy));
  memset(ans, 0, sizeof(ans));
  cin >> n >> q;
  for (ll i = 0; i < n; i++) {
    cin >> a;
    update(1, 1, n, i+1, i+1, a);
  }
  while (q--) {
    cin >> m;
    if (m == 1) {
      cin >> a >> b >> u;
      update(1, 1, n, a, b, u);
    } else {
      cin >> a;
      push(1, 1, n, a);
      cout << ans[a] << endl;
    }
  }
  return 0;
}

/*
8 900
7 6 4 6 2 9 4 8
1 8 8 10
2 1
0
 */
