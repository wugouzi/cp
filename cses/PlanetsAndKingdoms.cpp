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

int n, m;

vector<int> comp;
int cnt = 1;

void tops(vector<int> &top, vector<vector<int>> &E, int *vis, int i) {
  vis[i] = true;
  for (auto &j : E[i]) {
    if (vis[j]) continue;
    tops(top, E, vis, j);
  }
  top.push_back(i);
}

void assign(vector<vector<int>> &E, int i, int root) {
  if (i == root) {
    comp[i] = cnt++;
  } else {
    comp[i] = comp[root];
  }
  for (auto &j : E[i]) {
    if (comp[j] == -1) {
      assign(E, j, root);
    }
  }
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int a,b;
  cin >> n >> m;
  vector<vector<int>> E(n), ER(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    E[a-1].push_back(b-1);
    ER[b-1].push_back(a-1);
  }
  vector<int> top;
  int vis[n];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    if (!vis[i])
      tops(top, E, vis, i);
  }

  comp.resize(n, -1);
  for (int j = top.size() - 1; j >= 0; j--) {
    if (comp[top[j]] == -1) {
      assign(ER, top[j], top[j]);
    }
  }
  
  cout << cnt-1 << '\n';
  for (auto &j : comp) {
    cout << j << ' ';
  }

  return 0;
}

/*
6 9
1 2
2 1
3 4
4 3
5 6
6 5
1 6
2 3
4 5
 */
