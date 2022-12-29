#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, a;
  cin >> n;
  vector<int> next(n);
  vector<vector<int>> prev(n);
  for (int i = 0; i < n; i++) {
    cin >> next[i];
    next[i]--;
    prev[next[i]].push_back(i);
  }

  vector<int> cycle_id(n, -2);
  vector<int> cycle_len;

  int path[n];
  for (int i = 0; i < n; i++) {
    if (cycle_id[i] != -2) continue;

    int p_idx = 0, j = i;
    while (cycle_id[j] == -2) {
      path[p_idx++] = j;
      cycle_id[j] = -3;
      j = next[j];
    }

    int z = i;
    bool cyc = false;
    int cyc_len = 0;
    for (int w = 0; w < p_idx; w++) {
      int v = path[w];
      cyc = cyc || v == j;
      if (cyc) {
        cyc_len++;
      }
      cycle_id[v] = cyc ? cycle_len.size() : -1;
    }
    cycle_len.push_back(cyc_len);
  }

  vector<int> dep(n), rt(n);
  for (int i = 0; i < n; i++) {
    if (cycle_id[next[i]] != -1 && cycle_id[i] == -1) {
      int root = next[i];
      rt[i] = root;
      dep[i] = 1;
      vector<int> stack(prev[i]);
      while (!stack.empty()) {
        int j = stack.back();
        stack.pop_back();
        dep[j] = dep[next[j]] + 1;
        rt[j] = root;
        stack.insert(stack.end(), prev[j].begin(), prev[j].end());
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (cycle_id[i] == -1) {
      cout << dep[i] + cycle_len[cycle_id[rt[i]]] << ' ';
    } else {
      cout << cycle_len[cycle_id[i]] << ' ';
    }
  }

  return 0;
}
