#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

int pa[100010];

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
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a, b, c;
  // fstream f("test.txt");
  // f >> n >> m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++)
    pa[i] = i;

  vector<vector<int>> edge;
  for (int i = 0; i < m; i++) {
    // f >> a >> b >> c;
    cin >> a >> b >> c;
    edge.push_back({c, a, b});
  }
  sort(edge.begin(), edge.end());

  ll ans = 0;
  int dif = n;
  for (auto &vec : edge) {
    if (find(vec[1]) == find(vec[2])) continue;
    ans += (ll)vec[0];
    dif--;
    merge(vec[1], vec[2]);
  }
  if (dif != 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  cout << ans;
  return 0;
}
