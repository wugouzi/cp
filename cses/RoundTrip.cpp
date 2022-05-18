//
// Created by wu on 2022/5/1.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isFind;
void dfs(vector<vector<int>>& edge, vector<int>& pa, vector<int>& dist, int s) {
    for (auto& t : edge[s]) {
        if (dist[t] > 0 && dist[s]-dist[t] >= 2) {
            vector<int> ans;
            ans.push_back(t);
            while (s != t) {
                ans.push_back(s);
                s = pa[s];
            }
            ans.push_back(t);
            cout << ans.size() << endl;
            for (int i = 0; i < ans.size(); i++)
                cout << ans[i] << ' ';
            isFind = true;
            return;
        }
        if (dist[t]>0)
            continue;
        dist[t] = dist[s]+1;
        pa[t] = s;
        dfs(edge, pa, dist, t);
        dist[t] = 0;
        if (isFind)
            return;
    }
}
int main(void) {
    int n, m, t1, t2;
    cin >> n >> m;
    vector<vector<int>> E(n+1);
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        E[t1].push_back(t2);
        E[t2].push_back(t1);
    }
    queue<int> q;
    vector<int> dist(n+1,-1);
    vector<int> pa(n+1, 0);
    for (int i = 1; i <= n; i++)
        if (dist[i] == -1) {
            dist[i] = 1;
            dfs(E, pa, dist, i);
            if (isFind)
                break;
        }
    if (!isFind)
        cout << "IMPOSSIBLE";
    return 0;
    label:
    return 0;
}