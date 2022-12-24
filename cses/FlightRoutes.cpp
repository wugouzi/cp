//
// Created by wu on 2022/5/25.
//

#include <functional>
#include <iostream>
#include <utility>
#include <cstring>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pp;
#define mp(t1,t2) (make_pair((t1),(t2)))

ll n,m,k,t1,t2,t3;

int main(void) {

    cin >> n >> m >> k;

    vector<vector<pp>> edge(n);
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        edge[t1-1].push_back(mp(t2-1,t3));
    }

    priority_queue<pp, vector<pp>, greater<pp>> q;
    q.push(make_pair(0, 0));
    int count[n];
    vector<ll> ans;
    memset(count, 0, sizeof(count));
    while (count[n-1] < k && !q.empty()) {
      ll c = q.top().first;
      ll t = q.top().second;
      q.pop();
      count[t]++;
      if (t == n-1) {
        ans.push_back(c);
      }
      if (count[t] <= k) {
        for (auto &tt : edge[t]) {
          q.push(mp(c + tt.second, tt.first));
        }
      }
    }
    for (int i = 0; i < k; i++) {
      cout << ans[i] << ' ';
    }

    return 0;
}
