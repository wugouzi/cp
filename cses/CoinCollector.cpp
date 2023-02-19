#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <stack>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

// 1. compute scc and then transform the graph into a DAG
// 2. dp on the dag

#define N 200100

vector<vector<int>> v(N);
vector<unordered_set<int>> v2(N);
ll dsc[N], low[N], instack[N], pa[N], coin[N], coin2[N];
int scc, ddd;
stack<int> st;

void tarjan(int i) {
  instack[i] = 1;
  st.push(i);
  dsc[i] = low[i] = ++ddd;

  for (auto &j : v[i]) {
    if (!dsc[j]) {
      tarjan(j);
      low[i] = min(low[i], low[j]);
    } else if (instack[j]) {
      low[i] = min(low[i], dsc[j]);
    }
  }

  if (low[i] == dsc[i]) {
    int t = -1;
    while (t != i) {
      t = st.top();
      pa[t] = scc;
      instack[t] = 0;
      st.pop();
    }
    scc++;
  }
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,m,a,b;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> coin[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    v[a-1].push_back(b-1);
  }
  for (int i = 0; i < n; i++) {
    if (!dsc[i])
      tarjan(i);
  }
  int in[scc];
  memset(in, 0, sizeof(in));
  for (int i = 0; i < n; i++) {
    coin2[pa[i]] += coin[i];
    for (auto &j : v[i]) {
      if (pa[j] != pa[i] && !v2[pa[j]].count(pa[i])) {
        v2[pa[j]].insert(pa[i]);
        in[pa[i]]++;
      }
    }
  }
  queue<int> q;
  ll res[scc];
  memset(res, 0, sizeof(res));
  int ans = 0;
  for (int i = 0; i < scc; i++)
    if (!in[i]) {
      q.push(i);
      res[i] = coin2[i];
    }
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for (auto &j : v2[i]) {
      res[j] = max(res[j], res[i] + coin2[j]);
      in[j]--;
      if (!in[j])
        q.push(j);
    }
  }
  cout << *max_element(res, res + scc);
  return 0;
}
