//
// Created by wu on 2022/3/19.
//

#include "leetcode.h"

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    int inf = INT_MAX/2;
    vector<vector<pair<int, int>>> edge(n);
    for (auto& t : times) {
        edge[t[0]-1].push_back(make_pair(t[1]-1, t[2]));
    }
    vector<int> dist(n, inf);
    dist[k-1] = 0;
    using Pair = pair<int, int>;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.emplace(0, k-1);
    vector<bool> visited(n, false);
    while (!q.empty()) {
        Pair s = q.top();
        q.pop();
        visited[s.second] = true;
        for (auto& t : edge[s.second]) {
            dist[t.first] =min(dist[t.first], dist[s.second]+t.second);
            if (!visited[t.first])
                q.emplace(dist[t.first], t.first);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dist[i]);
    if (ans == inf) return -1;
    else return ans;
}

int main(void) {
    vector<vector<int>> times = {{4,2,76},{1,3,79},{3,1,81},{4,3,30},{2,1,47},{1,5,61},{1,4,99},{3,4,68},{3,5,46},{4,1,6},{5,4,7},{5,3,44},{4,5,19},{2,3,13},{3,2,18},{1,2,0},{5,1,25},{2,5,58},{2,4,77},{5,2,74}};
    int n = 5, k = 3;
    cout << networkDelayTime(times, n, k);
}