#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))
#define N 1000000
int tree[N];

void update(int u, int l, int r, int d, int v) {
  // cout << l << ' ' << r << ' ' << d << endl;
  if (l == r && l == d) {
    tree[u] = v;
    return;
  }
  int mid = (l + r)/2;
  if (d <= mid) {
    update(u*2, l, mid, d, v);
  } else {
    update(u*2+1, mid+1, r, d, v);
  }
  tree[u] = tree[u*2] + tree[u*2+1];
}

int query(int u, int l, int r, int L, int R) {
  // cout << l << ' ' << r << ' ' << L << ' ' << R << endl;
  if (L <= l && R >= r)
    return tree[u];
  int mid = (l+r)/2;
  int ans = 0;
  if (L <= mid)
    ans += query(u*2, l, mid, L, R);
  if (R > mid)
    ans += query(u*2+1, mid+1, r, L, R);
  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a, b;
  cin >> n >> m;
  vector<int> nums(n);
  for (int i = 0; i < n; i++)
    cin >> nums[i];
  unordered_map<int, int> locs;
  vector<vector<int>> queries;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    queries.push_back({b, a, i});
  }
  sort(queries.begin(), queries.end());
  int idx = 0;
  vector<int> ans(m);
  for (auto &q : queries) {
    while (idx < n && idx < q[0]) {
      int num = nums[idx];
      if (locs.count(num)) {
        update(1, 1, n, locs[num], 0);
      }
      locs[num] = idx+1;
      update(1, 1, n, idx+1, 1);
      idx++;
    }
    ans[q[2]] = query(1, 1, n, q[1], q[0]);
  }
  for (auto &a : ans) {
    cout << a << '\n';
  }

  return 0;
}
