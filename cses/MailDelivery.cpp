#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

unordered_map<int, unordered_set<int>> E;
vector<int> ans;

// VERY VERY NICE Euler circuit from https://yuihuang.com/cses-1691/
void dfs(int i) {
  while (E[i].size()) {
    int j = *(E[i].begin());
    E[i].erase(j);
    E[j].erase(i);
    dfs(j);
  }
  ans.push_back(i);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


  int n, m, a, b;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    E[a].insert(b);
    E[b].insert(a);
  }
  for (auto &[_,e] : E) {
    if (e.size() & 1) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  dfs(1);
  if (ans.size() != m + 1) {
    cout << "IMPOSSIBLE";
    return 0;
  }
  for (auto &n : ans)
    cout << n << ' ';
  return 0;
}
