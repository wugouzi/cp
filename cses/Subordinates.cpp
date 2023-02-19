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

#define N 200100
int ans[N], vis[N];
vector<vector<int>> v(N);

void dfs(int i) {
  vis[i] = 1;
  for (auto &j : v[i]) {
    if (!vis[j])
      dfs(j);
    ans[i] += ans[j] + 1;
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> m;
    v[m].push_back(i);
  }
  dfs(1);
  for (int i = 1; i <= n; i++)
    cout << ans[i] << ' ';
  return 0;
}
