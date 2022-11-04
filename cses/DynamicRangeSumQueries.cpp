#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

ll seg[1000000];

void update(ll u, ll l, ll r, ll L, ll R, ll dif) {
  if (L > r || R < l) {
    return;
  }
  if (L <= l && R >= r) {
    seg[u] += dif;
    return;
  }
  ll mid = (l+r) / 2;
  update(u*2, l, mid, L, R, dif);
  update(u*2+1, mid+1, r, L, R, dif);
  seg[u] = seg[u*2] + seg[u*2+1];
}

ll query(ll u, ll l, ll r, ll L, ll R) {
  if (L > r || R < l) {
    return 0;
  }
  if (L <= l && R >= r) {
    return seg[u];
  }
  ll mid = (l+r)/2;
  return query(u*2, l, mid, L, R) + query(u*2+1, mid + 1, r, L, R);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  memset(seg, 0, sizeof(seg));
  ll n, q, tp, a, b;
  cin >> n >> q;
  ll tmp[n];
  for (ll i = 0; i < n; i++) {
    cin >> tmp[i];
    update(1, 1, n, i+1, i+1, tmp[i]);
  }
  for (ll i = 0; i < q; i++) {
    cin >> tp >> a >> b;
    if (tp == 2) {
      cout << query(1, 1, n, a, b) << endl;
    } else {
      ll dif = b - tmp[a-1];
      update(1, 1, n, a, a, dif);
      tmp[a - 1] = b;
    }
  }
  return 0;
}
