//
// Created by wu on 2022/5/17.
//

#include <iostream>
#include <vector>
#include <queue>;
using namespace std;

int main(void) {
    int n,m,t1,t2,t3;
    cin >> n >> m;
    vector<vector<int>> edge,E(n);
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        edge.push_back({t1-1,t2-1,-t3});
        E[t1-1].push_back(t2-1);
    }
    vector<long long> dist(n);
    vector<bool> inf(n,true);
    inf[0] = false;
    for (int i = 0; i < n-1; i++)
        for (auto& e : edge) {
            int s = e[0], t = e[1], w = e[2];
            if (!inf[s]) {
                dist[t] = !inf[t] ? min(dist[t],w+dist[s]) : w+dist[s];
                inf[t] = false;
            }
        }
    queue<int> q;
    for (auto& e : edge) {
        if (dist[e[1]]>dist[e[0]]+e[2] && !inf[e[1]]) {
            inf[e[1]] = true;
            q.push(e[1]);
            while (!q.empty()) {
                int src = q.front();q.pop();
                for (auto& t : E[src]) {
                    if (t == n-1) {
                        cout << -1;return 0;
                    }
                    if (!inf[t]) {
                        inf[t] = true;
                        q.push(t);
                    }
                }
            }
        }
    }
    cout << -dist[n-1];
}