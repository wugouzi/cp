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

int N = 1e9+7;

inline int calc(ll a, ll b, int mod) {
  if (a == 0 && b == 0) return 1;
  ll ans = 1;
  while (b) {
    if (b & 1) {
      (ans *= a) %= mod;
    }
    (a *= a) %= mod;
    b >>= 1;
  }
  return ans;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q, a, b, c;
  cin >> q;
  while (q--) {
    cin >> a >> b >> c;
    cout << calc(a,calc(b,c, N-1), N) << '\n';
  }
  return 0;
}
