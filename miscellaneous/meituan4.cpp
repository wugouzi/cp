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
int dp[5010][51];
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, x, y, a, b;
  cin >> n >> x >> y;
  vector<int> nums(n), dis(n);
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    nums[i] = a;
    dis[i] = b;
  }
  int an = 0, ac = 0;
  for (int i = 0; i < n; i++) {
    for (int j = x; j > 0; j--) {
      for (int z = y; z >= 0; z--) {
        if (j >= nums[i])
          dp[j][z] = max(dp[j][z], 1 + dp[j - nums[i]][z]);
        if (j >= dis[i] && z)
          dp[j][z] = max(dp[j][z], 1 + dp[j - dis[i]][z-1]);
        if (dp[j][z] > an) {
          an = dp[j][z];
          ac = j;
        } else if (dp[j][z] == an)
          ac = min(ac, j);
      }
    }
  }
  cout << an << ' ' << ac;
  return 0;
}
