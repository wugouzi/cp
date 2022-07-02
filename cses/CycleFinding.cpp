//
// Created by wu on 2022/5/24.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <fstream>

using namespace std;
int main(void) {
    int n, m, t1, t2, t3;
    fstream f("../cses/test_input.txt");
    cin >> n >> m;
    //f >> n>>m;
    vector<long long> pa, dist;
    vector<vector<int>> edges;
    bool neg = true;
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2 >> t3;
        //f>>t1>>t2>>t3;
        if (t3<0) neg = false;
        edges.push_back({t1-1,t2-1,t3});
    }
    if (neg) {
        cout << "NO";
        return 0;
    }
    while (!edges.empty()) {
        pa.resize(n), dist.resize(n,LLONG_MAX);
        dist[edges[0][0]] = 0;
        for (int i = 0; i < m; i++)
            for (auto& e : edges) {
                int t1 = e[0], t2 = e[1], w = e[2];
                if (dist[t1] < LLONG_MAX && dist[t2] > dist[t1]+w) {
                    dist[t2] = dist[t1]+w;
                    pa[t2] = t1;

                }
            }
        for (auto& e : edges) {
            if (dist[e[1]] < LLONG_MAX && dist[e[0]] < LLONG_MAX && dist[e[1]] > dist[e[0]]+e[2]) {
                cout << "YES" << endl;
                int y = e[1];
                for (int i = 0; i < n; i++)
                    y = pa[y];
                vector<int> ans = {y+1};
                for (int cur = pa[y];; cur = pa[cur]) {
                    ans.push_back(cur+1);
                    if (cur == y)
                        break;
                }

                for (int i = (int)ans.size()-1; i >= 0; i--)
                    cout << ans[i] << ' ';
                return 0;
            }
        }
        vector<vector<int>> newedge;
        for (auto& e : edges) {
            if (dist[e[0]] == LLONG_MAX)
                newedge.push_back(e);
        }
        edges = newedge;
    }
    cout << "NO";
}