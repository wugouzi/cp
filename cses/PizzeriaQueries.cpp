#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

int segu[1000000], segd[1000000];

void update(int seg[], int u, int l, int r, int k, int val) {
  if (l == r) {
    seg[u] = val;
    return;
  }
  int mid = (l+r)/2;
  if (k <= mid) {
    update(seg, u*2, l, mid, k, val);
    // seg[u] = min(seg[u], seg[u*2]);
  } else {
    update(seg, u*2+1, mid+1, r, k, val);
    // seg[u] = min(seg[u], seg[u*2+1]);
  }
  seg[u] = min(seg[u*2], seg[u*2+1]);
}

int query(int seg[], int u, int l, int r, int a, int b) {
  if (a > r || b < l)
    return INT_MAX;
  if (a <= l && b >= r)
    return seg[u];
  int mid = (l+r)/2;
  return min(query(seg, u*2, l, mid, a, b), query(seg, u*2+1, mid+1, r, a, b));
}

// since p_a+\abs{a-b} is
// a >= b: p_a+a-b
// a <= b: p_a-a+b
// therefore we maintain two trees for p_a+a and p_a-a respectively
int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, q, t, k, x;
  memset(segu, 0x3f, sizeof(segu));
  memset(segd, 0x3f, sizeof(segd));
  cin >> n >> q;
  // int arr[n];
  for (int i = 1; i <= n; i++) {
    cin >> t;
    update(segu, 1, 1, n, i, t+i);
    update(segd, 1, 1, n, i, t-i);
  }
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> k >> x;
      update(segu, 1, 1, n, k, x+k);
      update(segd, 1, 1, n, k, x-k);
    } else {
      cin >> k;
      int t1 = query(segu, 1, 1, n, k, n) - k;
      int t2 = query(segd, 1, 1, n, 1, k) + k;
      cout << min(t1, t2) << '\n';
    }
  }
  return 0;
}
