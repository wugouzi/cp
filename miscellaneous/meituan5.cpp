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

vector<vector<int>> edge;
vector<int> e;

void spread(int i, int d, vector<int> &vis) {
  e[i]++;
  if (!d) return;
  vis[i] = 1;
  for (auto &j : edge[i]) {
    if (!vis[j]) {
      spread(j, d-1, vis);
    }
  }
  vis[i] = 0;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a, b;
  cin >> n;
  edge.resize(n);
  e.resize(n);
  vector<int> es(n);
  for (int i = 0; i < n; i++) {
    cin >> a;
    es[i] = a;
  }
  for (int i = 0; i < n-1; i++) {
    cin >> a >> b;
    edge[a-1].push_back(b-1);
    edge[b-1].push_back(a-1);
  }
  vector<int> vis(n);
  for (int i = 0; i < n; i++) {
    spread(i, es[i], vis);
  }
  for (auto &n : e)
    cout << n << ' ';
  return 0;
}

/*
10
1 2 1 1 1 2 3 1 1 1
1 2
2 3
1 4
2 5
4 6
3 7
5 8
1 9
2 10
 */
