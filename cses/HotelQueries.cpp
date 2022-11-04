#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;

long long seg[1000000];
void update(int u, int l, int r, int L, int R, int val) {
  if (L > r || R < l) return;
  if (l == r) {
    seg[u] += val;
    return;
  }
  int mid = (l+r)/2;
  update(u*2, l, mid, L, R, val);
  update(u*2+1, mid+1, r, L, R, val);
  seg[u] = max(seg[u*2], seg[u*2+1]);
}

int find(int u, int l, int r, int val) {
  if (u == 1 && seg[u] < val)
    return 0;
  if (l == r)
    return l;
  int mid = (l+r)/2;
  if (seg[u*2] >= val)
    return find(u*2, l, mid, val);
  else
    return find(u*2+1, mid+1, r, val);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, m, a;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a;
    update(1, 1, n, i+1, i+1, a);
  }
  for (int i = 0; i < m; i++) {
    cin >> a;
    int t = find(1, 1, n, a);
    update(1, 1, n, t, t, -a);
    cout << t << endl;
  }
  return 0;
}
