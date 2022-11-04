#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

int seg[1000000];

void update(int u, int l, int r, int L, int R, int val) {
  if (L > r || R < l) {
    return;
  }
  if (l == r) {
    seg[u] = val;
    return;
  }
  int mid = (l+r)/2;
  update(u*2, l, mid, L, R, val);
  update(u*2+1, mid+1, r, L, R, val);
  seg[u] = min(seg[u*2], seg[u*2+1]);
}

int query(int u, int l, int r, int L, int R) {
  if (L > r || R < l) {
    return INT_MAX;
  }
  if (L <= l && R >= r) {
    return seg[u];
  }
  int mid = (l+r)/2;
  return min(query(u*2, l, mid, L, R), query(u*2+1, mid+1, r, L, R));
}


int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, q, tp, a, b;
  memset(seg, 0x3f, sizeof(seg));
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> tp;
    update(1, 1, n, i+1, i+1, tp);
  }
  while (q--) {
    cin >> tp >> a >> b;
    if (tp == 2) {
      cout << query(1, 1, n, a, b) << endl;
    } else {
      update(1, 1, n, a, a, b);
    }
  }
  return 0;
}
