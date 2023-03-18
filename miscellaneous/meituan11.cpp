#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

int a, b, ans;
vector<vector<int>> dots;
void dfs(vector<vector<int>> &curr, int i) {
  if (i == dots.size()) {
    ans = max(ans, (int)curr.size());
    return;
  }
  dfs(curr, i + 1);
  int x = dots[i][0], y = dots[i][1];
  for (auto &cur : curr) {
    if (abs(x-cur[0]) > a || abs(y-cur[1]) > b)
      return;
  }
  curr.push_back({x,y});
  dfs(curr, i+1);
  curr.pop_back();

}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x, y;
  cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    dots.push_back({x,y});
  }
  vector<vector<int>> tp;
  dfs(tp, 0);
  cout << ans;
  return 0;
}
