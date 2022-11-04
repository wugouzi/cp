#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;


int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  int n, q, a, b, c, d;
  char tp;
  cin >> n >> q;
  int dp[n][n];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> tp;
      if (tp == '*')
        dp[i][j] = 1;
      if (i > 0)
        dp[i][j] += dp[i-1][j];
      if (j > 0)
        dp[i][j] += dp[i][j-1];
      if (i > 0 && j > 0)
        dp[i][j] -= dp[i-1][j-1];
    }
  while (q--) {
    cin >> a >> b >> c >> d;
    a--,b--,c--,d--;
    int ans = dp[c][d];
    if (a > 0)
      ans -= dp[a-1][d];
    if (b > 0)
      ans -= dp[c][b-1];
    if (a > 0 && b > 0)
      ans += dp[a-1][b-1];
    cout << ans << endl;
  }
  return 0;
}
