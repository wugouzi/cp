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
  int n,q,a,b;
  int pre[300000];
  memset(pre, 0, sizeof(pre));
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a;
    pre[i] = i > 0 ? a ^ pre[i-1] : a;
  }
  while (q--) {
    cin >> a >> b;
    a--, b--;
    cout << (pre[b] ^ (a > 0 ? pre[a-1] : 0)) << endl;
  }
  return 0;
}
