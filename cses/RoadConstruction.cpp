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

int pa[100010], sz[100010];

int find(int x) {
  while (pa[x] != x) {
    pa[x] = pa[pa[x]];
    x = pa[x];
  }
  return x;
}

void merge(int x, int y) {
  int i = find(x), j = find(y);
  pa[j] = i;
  sz[i] += sz[j];
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, a, b;
  cin >> n >> m;


  for (int i = 1; i <= n; i++) {
    pa[i] = i;
    sz[i] = 1;
  }
  int dif = n, msz = 1;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    if (find(a) != find(b)) {
      merge(a,b);
      msz = max(msz, sz[find(a)]);
      dif--;
    }
    cout << dif << ' ' << msz << '\n';
  }
  return 0;
}
