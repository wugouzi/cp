#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

int sb[1000000];

/*
8 36
7 6 4 6 2 9 4 8
6 6
6 7
6 8
7 7
7 8
8 8

9
4
4
4
4
8
 */

void update(int u, int l, int r, int L, int R, int val) {
  if (L <= l && R >= r) {
    sb[u] = min(sb[u], val);
    return;
  }
  int mid = (l+r)/2;
  if (L <= mid) {
      update(2*u, l, mid, L, R, val);
      sb[u] = min(sb[u], sb[2*u]);
  }
  if (R > mid) {
      update(2 * u + 1, mid + 1, r, L, R, val);
      sb[u] = min(sb[u], sb[2*u+1]);
  }
}

int query(int u, int l, int r, int L, int R) {
  if (L <= l && R >= r) {
    return sb[u];
  }
  int mid = (l+r)/2;
  int ans = INT_MAX;
  if (L <= mid) {
      ans = min(ans, query(2*u, l, mid, L, R));
  }
  if (R > mid) {
      ans = min(ans, query(2*u+1, mid+1, r, L, R));
  }
  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, q, tp, a, b;
  cin >> n >> q;
  memset(sb, 0x3f, sizeof(sb));
  for (int i = 0; i < n; i++) {
    cin >> tp;
    update(1, 1, n, i+1, i+1, tp);
  }
  for (int i = 0; i < q; i++) {
    cin >> a >> b;
    cout << query(1, 1, n, a, b) << endl;
  }
  return 0;
}
