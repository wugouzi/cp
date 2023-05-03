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
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

/*
** Use binary search to find t, use dynamic programming to check certain t
**
** Time Complexity : O(log(k) * n * m) where k is the max element of r_i and c_i
** Space Complexity : O(1010)
*/

int n, m, T;
vector<ll> r, c;

ll dp[1010];

// mode 1 io mode, 0 compute mode
ll work(int i, int t, int mode) {
  if (mode) return ceil((double)r[i]/2/t) + ceil((double)c[i]/t);
  return ceil((double)r[i]/t) + ceil((double)c[i]/2/t);
}



bool compute(int t) {
  // vary from the maximum of variables
  memset(dp, 0x3f, sizeof(dp));

  for (int j = 0; j <= m; j++) {
    dp[j] = work(0, t, j % 2);
  }

  for (int i = 1; i < n; i++) {
    for (int j = m; j >= 1; j--)
      dp[j] = min(dp[j-1], dp[j]) + work(i, t, j % 2);
    dp[0] = dp[0] + work(i, t, 0);
  }

  ll ret = dp[0];
  for (int i = 1; i <= m; i++)
    ret = min(ret, dp[i]);
  return ret <= T;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> T;
  r.resize(n);
  c.resize(n);
  ll L = 1, R = 1;
  for (int i = 0 ;i < n; i++) {
    cin >> r[i] >> c[i];
    R = max(R, max(r[i], c[i]));
  }
  while (L < R) {
    ll mid = (L + R) / 2;
    if (compute(mid)) {
      R = mid;
    } else {
      L = mid + 1;
    }
  }
  cout << L;
  return 0;
}

/*
6 1 12
1 6
1 6
6 1
1 6
6 1
6 1
*/

/*
6 6 18
6 1
1 6
6 1
1 6
6 1
1 6
*/

/*
6 2 20
1 1
2 3
2 2
4 3
1 4
7 2
*/
