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

void dfs(int i) {
  while (!E[i].empty()) {
    int j = E[i].back();
    E[i].pop_back();
    dfs(j);
  }
  ans.push_back(i);
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  if (n == 1) {
    cout << "01";
    return 0;
  }
  int m = n-1;
  E.resize(1<<m);
  for (int i = 0; i < 1 << m; i++) {
    E[i].push_back((i<<1)&~(1<<m));
    E[i].push_back(((i<<1)&~(1<<m))|1);
  }

  dfs(0);
  for (int i = 0; i < m-1; i++)
    cout << '0';
  for (int i = ans.size()-1; i >= 0; i--)
    cout << ans[i] % 2;

  return 0;
}
