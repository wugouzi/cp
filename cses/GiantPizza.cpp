#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <climits>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))
#define N 200100
vector<vector<int>> v(N), v2(N);
int dsc[N], low[N], pa[N], op[N], color[N];
bool instack[N];
int scc, m, ct;
stack<int> st;

int opp(int x) {
  if (x % 2)
    return x-1;
  return x+1;
}

// 1 -> 0,1
int idx(int x, int sgn) {
  return x*2-1-(sgn == '+');
}

void tarjan(int i) {
  dsc[i] = low[i] = ++ct;
  st.push(i);
  instack[i] = true;
  for (auto &j : v[i]) {
    if (!dsc[j]) {
      tarjan(j);
      low[i] = min(low[i], low[j]);
    } else if (instack[j]) {
      low[i] = min(low[i], dsc[j]);
    }
  }
  if (dsc[i] == low[i]) {
    int g = st.top();
    pa[i] = scc;
    while (g != i) {
      pa[g] = scc;
      st.pop();
      instack[g] = false;
      g = st.top();
    }
    st.pop();
    instack[i] = false;
    scc++;
  }
}

void build() {
  for (int i = 0; i < 2*m; i++) {
    for (auto &j : v[i]) {
      v2[pa[j]].push_back(pa[i]);
      // v2[pa[i]].push_back(pa[j]);
    }
  }
}

void dfs(int i) {
  color[i] = 1;
  for (auto &j : v2[i]) {
    if (!color[j])
      dfs(j);
  }
  st.push(i);
}

void topo() {
  for (int i = 0; i < scc; i++) {
    if (!color[i])
      dfs(i);
  }
  while (!st.empty()) {
    int i = st.top();
    st.pop();
    if (color[i] == 1) {
      color[i] = 2;
      color[op[i]] = 3;
    }
  }
  for (int i = 0; i < 2*m; i += 2) {
    if (color[pa[i]] == 2)
      cout << "+ ";
    else
      cout << "- ";
  }
}

// check if a and neg a are in same scc
bool check() {
  for (int i = 0; i < m*2; i += 2) {
    if (pa[i] == pa[i+1])
      return false;
    op[pa[i]] = pa[i+1];
    op[pa[i+1]] = pa[i];
  }
  return true;
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n,a,b;
  char c, d;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> c >> a >> d >> b;
    v[opp(idx(a,c))].push_back(idx(b,d));
    v[opp(idx(b,d))].push_back(idx(a,c));
  }
  for (int i = 0; i < m*2; i++) {
    if (!dsc[i])
      tarjan(i);
  }
  if (check()) {
    build();
    topo();
  } else {
    cout << "IMPOSSIBLE\n";
  }
  return 0;
}
