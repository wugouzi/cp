#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <unordered_map>
#include <fstream>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))
const int MAXN = 30;
int to[200010][MAXN];
// binary jump
int main(void) {
  ios_base::sync_with_stdio(false);
  // fstream f("test_input.txt");
  cin.tie(NULL);
  int n, m, a, b;
  scanf("%d %d", &n, &m);
  // cin >> n >> m;
  // f >> n >> m;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &to[i][0]);
    // cin >> a;
    // f >> a;
    // to[i][0] = a;
  }
  for (int i = 1; i < MAXN; i++) {
    for (int j = 1; j <= n; j++) {
      to[j][i] = to[to[j][i-1]][i-1];
      // cout << j << ' ' << i << ' ' << to[j][i] << endl;
    }
  }
  while (m--) {
    scanf("%d %d", &a, &b);
    // cin >> a >> b;
    // f >> a >> b;
    for (int i = 0; i < MAXN; i++) {
      if (b & (1 << i)) {
        a = to[a][i];
      }
    }
    printf("%d\n", a);
  }
  return 0;
}
