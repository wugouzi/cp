#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

vector<vector<int>> E;
vector<int> ans;
int n;

void dfs(int i) {
  while (!E[i].empty()) {
    int j = E[i].back();
    E[i].pop_back();
    // cout << "check " << j << '\n';
    dfs(j);
  }
  ans.push_back(i);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int m,a,b;
  cin >> n >> m;
  E.resize(n);
  vector<int> in(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    E[a-1].push_back(b-1);
    in[b-1]++;
    in[a-1]++;
  }
  if (!(in[0] % 2) || !(in[n-1] % 2)) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (int i = 1; i < n-1; i++)
    if (in[i] % 2) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  dfs(0);
  if (ans.size() != m + 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (int i = ans.size() - 1; i >= 0; i--)
    cout << ans[i] + 1 << ' ';

  return 0;
}
