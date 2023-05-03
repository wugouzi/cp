#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int,int> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

/*
**
** The description of the problem is not very clear. The solution below
** assumes that all task are done at time l_i
**
** Time Complexity : O(m * (\sum w_i) + mlogm + rlogr)
** Space Complexity : O(\sum w_i)
*/
int n, m, r;
vector<pp> dg, lw;
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> r;

  int a, b, c;
  vector<pp> tp_dg;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    tp_dg.emplace_back(a, b);
  }

  int minl = INT_MAX;
  for (int i = 0; i < r; i++) {
    cin >> a >> b >> c;
    lw.emplace_back(a, c);
    minl = min(minl, a);
  }

  // delete impossible task
  for (auto &p : tp_dg) {
    if (p.first >= minl)
      dg.push_back(p);
  }
  m = dg.size();

  // sort each worker and make prefix sum of task capacity
  // look like
  //
  // work capacity
  // |      _________
  // |      |
  // |  ____|
  // |  |
  // |__|
  // |_______________ worker
  //    1   2
  sort(lw.begin(), lw.end());
  for (int i = 1; i < r; i++)
    lw[i].second += lw[i-1].second;

  sort(dg.begin(), dg.end());
  vector<int> vv;
  // vv[i] is the work capacity before the deadline of task i
  for (int i = 0; i < m; i++) {
    auto iter = lower_bound(lw.begin(), lw.end(), make_pair(dg[i].first, -1));
    if (iter == lw.end() || iter->first > dg[i].first) iter--;
    vv.push_back(iter->second);
  }

  // like 0-1 knapsack, but the capacity grows over time
  vector<int> dp(lw.back().second + 1);
  for (int i = 1; i <= m; i++) {
    for (int v = vv[i-1]; v >= 1; v--) {
      dp[v] = max(dp[v], dp[v-1] + dg[i-1].second);
    }
  }
  cout << dp[vv[m-1]];
  /*
  vector<vector<int>> dp(m + 1, vector<int>(lw.back().second + 1));
  for (int i = 1; i <= m; i++) {
    for (int v = 1; v <= vv[i-1]; v++) {
      dp[i][v] = max(dp[i-1][v], dp[i-1][v-1] + dg[i-1].second);
    }
  }
  cout << dp[m][vv[m-1]];
  */

  return 0;
}

/*
3 5 2
2 3
1 10
2 10
3 2
3 10
1 3 2
2 2 2
*/
