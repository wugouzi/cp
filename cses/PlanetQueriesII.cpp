#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#include <fstream>
#include <unordered_map>
#include <chrono>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))
int jmp[200010][19];

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, a, b;
  // fstream f("test_input.txt");
  cin >> n >> m;
  // f >> n >> m;
  vector<std::chrono::steady_clock::time_point> times;

  // process the
  vector<int> next(n);
  vector<vector<int>> prev(n);
  for (int i = 0; i < n; i++) {
    // f >> next[i];
    cin >> next[i];
    next[i]--;
    prev[next[i]].push_back(i);
  }

  // build cycles
  vector<int> cycle_id(n, -2);
  int c_idx = 0;
  vector<unordered_map<int, int>> cycles;


  times.push_back(std::chrono::steady_clock::now());
  int path[n];
  // vector<int> path(n);
  for (int p = 0; p < n; p++) {
    if (cycle_id[p] != -2) {
      continue;
    }
    // vector<int> path{p};
    path[0] = p;
    int at = p, p_idx = 1;
    while (cycle_id[next[at]] == -2) {
      at = next[at];
      cycle_id[at] = -3;  // Leave breadcrumbs for this iteration
      // path.push_back(at);
      path[p_idx++] = at;
    }

    unordered_map<int, int> cycle;
    bool in_cycle = false;
    for (int j = 0 ;j < p_idx; j++) {
      int i = path[j];
      in_cycle = in_cycle || i == next[at];
      if (in_cycle) {
        cycle[i] = cycle.size();
      }
      cycle_id[i] = in_cycle ? cycles.size() : -1;
    }
    // for (int i : path) {
    //   in_cycle = in_cycle || i == next[at];
    //   if (in_cycle) {
    //     cycle[i] = cycle.size();
    //   }
    //   cycle_id[i] = in_cycle ? cycles.size() : -1;
    // }
    cycles.push_back(move(cycle));
  }

  // for (int i = 0; i < n; i++) {
  //   if (cycle_id[i] != -2) continue;

  //   int fast = next[next[i]], slow = next[i];
  //   while (fast != slow) {
  //     fast = next[next[fast]];
  //     slow = next[slow];
  //   }
  //   fast = i;
  //   while (fast != slow) {
  //     cycle_id[fast] = -1;
  //     fast = next[fast];
  //     slow = next[slow];
  //   }
  //   unordered_map<int, int> cycle;
  //   int idx = 0;
  //   while (!cycle.count(fast)) {
  //     cycle[fast] = idx++;
  //     cycle_id[fast] = c_idx;
  //     fast = next[fast];
  //   }
  //   c_idx++;
  //   cycles.push_back(move(cycle));
  // }
  times.push_back(std::chrono::steady_clock::now());

  vector<int> dep(n);
  vector<int> rt(n);
  for (int i = 0; i < n; i++) {
    if (cycle_id[next[i]] != -1 && cycle_id[i] == -1) {
      dep[i] = 1;
      rt[i] = next[i];
      vector<int> stack(prev[i]);
      while (!stack.empty()) {
        int cur = stack.back();
        rt[cur] = next[i];
        stack.pop_back();
        dep[cur] = dep[next[cur]] + 1;
        stack.insert(stack.end(), prev[cur].begin(), prev[cur].end());
      }
    }
  }
  times.push_back(std::chrono::steady_clock::now());

  int log = ceil(std::log2(n));
  // int jmp[n][log+1];
  for (int i = 0; i < n; i++)
    jmp[i][0] = next[i];
  for (int i = 1; i <= log; i++) {
    for (int j = 0; j < n; j++) {
      jmp[j][i] = jmp[jmp[j][i-1]][i-1];
    }
  }
  times.push_back(std::chrono::steady_clock::now());

  while (m--) {
    // f >> a >> b;
    cin >> a >> b;
    if (a == b) {
      cout << 0 << "\n";
      continue;
    }
    a--, b--;
    if (cycle_id[jmp[a][log]] != cycle_id[jmp[b][log]]) {
      cout << -1 << '\n';
    } else if (cycle_id[a] == -1 && cycle_id[b] == -1) {
      if (dep[a] <= dep[b]) {
        cout << -1;
      } else {
        int tp = dep[a] - dep[b];
        for (int i = 0; i <= log; i++) {
          if (tp & (1 << i)) {
            a = jmp[a][i];
          }
        }
        if (a == b) {
          cout << tp;
        } else {
          cout << -1;
        }
      }
      cout << "\n";
    } else if (cycle_id[a] == -1) {
      int root = rt[a];
      unordered_map<int, int> &mp = cycles[cycle_id[b]];
      int ans = mp[b] - mp[root] >= 0 ? mp[b] - mp[root] : mp.size() + mp[b] - mp[root];
      cout << dep[a] + ans << '\n';
    } else if (cycle_id[b] == -1) {
      cout << -1 << "\n";
    } else {
      unordered_map<int, int> &mp = cycles[cycle_id[a]];
      int ans = mp[b] - mp[a] >= 0 ? mp[b] - mp[a] : mp.size() - mp[a] + mp[b];
      cout << ans << '\n';
    }
  }
  // times.push_back(std::chrono::steady_clock::now());
  // for (int i = 0; i < times.size() - 1; i++) {
  //   cout << std::chrono::duration_cast<std::chrono::microseconds>(times[i+1] - times[i]).count() << endl;
  // }

  return 0;
}

/*
4 3
4 1 2 3
4 1

5 1
2 3 4 5 1
1 5
 */
