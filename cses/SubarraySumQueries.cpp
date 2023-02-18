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


typedef struct _test {
  ll sum;
  ll prefix;
  ll suffix;
  ll sumOfAll;
  void init(ll a) {
    sum = prefix = suffix = sumOfAll = a;
  }
} node;

node nodes[1000000];

void update(int u, int l, int r, int d, int v) {
  if (l == r && l == d) {
    nodes[u].init(v);
    return;
  }
  int mid = (l+r) / 2;
  if (d <= mid) {
    update(u*2, l, mid, d, v);
  } else {
    update(u*2+1, mid+1, r, d, v);
  }
  node &cl = nodes[u*2];
  node &cr = nodes[u*2+1];
  nodes[u].sum = max(cl.sum, max(cr.sum, cl.suffix + cr.prefix));
  nodes[u].prefix = max(cl.prefix, cl.sumOfAll + cr.prefix);
  nodes[u].suffix = max(cr.suffix, cl.suffix + cr.sumOfAll);
  nodes[u].sumOfAll = cl.sumOfAll + cr.sumOfAll;
}


int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,x,k;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    update(1, 1, n, i, x);
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> k;
    update(1, 1, n, x, k);
    cout << max(0LL, nodes[1].sum) << '\n';
  }
  return 0;
}
