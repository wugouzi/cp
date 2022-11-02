#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;


int main(void) {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);

  int n, q, tp;
  cin >> n >> q;
  std::vector<ll> sb(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> tp;
    sb[i] = i > 0 ? sb[i-1] + tp : tp;
  }
  for (int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    cout << sb[b] - (a > 0 ? sb[a- 1] : 0) << endl;
  }
  return 0;
}
