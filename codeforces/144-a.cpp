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

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<int> nums(n);
  int ii = -1, ai = -1, min = INT_MAX, max = INT_MIN;
  int c;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (c <= min) {
      min = c;
      ii = i;
    }
    if (c > max) {
      max = c;
      ai = i;
    }
  }
  int ans = n - ii - 1 + ai - (ii < ai ? 1 : 0);
  cout << ans;
  return 0;
}
