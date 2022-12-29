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

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n;
  while (n--) {
    cin >> m;
    int ans = 1;
    if (m == 1) {
      cout << 1 << '\n';
      continue;
    }
    int cnt = 1;
    while (m % 2 == 0) {
      cnt++;
      m >>= 1;
    }
    ans *= cnt;
    for (int i = 3; i*i <= m; i += 2) {
      if (m % i == 0) {
        cnt = 1;
        while (m % i == 0) {
          cnt++;
          m /= i;
        }
        ans *= cnt;
      }
    }
    if (m != 1) {
      ans *= 2;
    }
    cout << ans << '\n';
  }
  return 0;
}
