#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

// class node {
//  public:
//   ll sum = 0;
//   ll pref = 0;
//   node(ll x, ll y) : sum(x), pref(y) {}
//   node(ll x): sum(x) {}
// };

// node operator+(node &s1, node &s2) {
//   return {s1.sum+s2.sum, max(s1.pref, s1.sum+s2.pref)};
// }

// node seg[1000000];

struct node {
  ll sum, pref;
  node(ll sum, ll pref): sum(sum), pref(pref) {}
  node(ll x=0) : sum(x), pref(max(0LL, x)) {}
  friend node operator+(const node &a, const node &b) {
    return {a.sum + b.sum, max(a.pref, a.sum+b.pref)};
  }
} seg[1000000];

const int N = 200010;
int arr[N];

void build(int u = 1, int l = 1, int r = N) {
  if (l == r) {
    seg[u] = node(arr[l]);
    return;
  }
  int mid = (l+r)/2;
  build(u*2, l, mid);
  build(u*2+1, mid+1, r);
  seg[u] = seg[u*2]+seg[u*2+1];
}

void update(int u, int l, int r, int k, int dif) {
  if (l == r) {
    seg[u] = node(dif);
    return;
  }
  int mid = (l+r)/2;
  if (k <= mid) {
    update(u*2, l, mid, k, dif);
  } else {
    update(u*2+1, mid+1, r, k, dif);
  }
  seg[u] = seg[u*2]+seg[u*2+1];
}

struct node query(int u, int l, int r, int L, int R) {
  if (L > r || R < l)
    return 0;
  if (L <= l && R >= r)
    return seg[u];
  int mid = (l+r)/2;
  return query(u*2, l, mid, L, R) + query(u*2+1, mid+1, r, L, R);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, q, t, k, u;
  cin >> n >> q;
  for (int i = 0; i < n; i++)
    cin >> arr[i+1];
  build(1, 1, n);
  while (q--) {
    cin >> t >> k >> u;
    if (t == 1) {
      update(1, 1, n, k, u);
    } else {
      cout << query(1, 1, n, k, u).pref << '\n';
    }
  }
  return 0;
}


/*
100 2
58 36 81 -7 46 49 87 -58 98 -15 -2 62 -8 -22 0 78 -48 94 68 -7 -73 8 62 2 -84 29 78 71 -11 3 3 88 -21 69 -96 -10 52 -70 17 -37 -57 -20 73 76 54 17 54 -33 -49 40 -83 63 34 58 47 98 -89 -82 4 67 58 -87 72 -96 62 -50 -50 -74 -28 -50 15 91 45 -20 -97 56 -15 10 46 -42 40 -89 98 42 85 65 -22 -46 56 -54 35 34 35 -53 98 69 -88 91 26 80
1 8 -57
2 7 77
 */
