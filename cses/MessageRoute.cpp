//
// Created by wu on 2022/5/1.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void) {
    int n, m, src, dst;
    cin >> n >> m;
    vector<vector<int>> E(n+1);
    vector<int> pa(n+1);
    for (int i = 0; i < m; i++) {
        cin >> src >> dst;
        E[src].push_back(dst);
        E[dst].push_back(src);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        src = q.front();
        q.pop();
        for (auto& dst: E[src]) {
            if (!pa[dst]) {
                pa[dst] = src;
                q.push(dst);
            }
        }
    }
    if (!pa[n]) {
        cout << "IMPOSSIBLE";
        return 0;
    }
    vector<int> ans;
    src = n;
    ans.push_back(n);
    while (src != 1) {
        ans.push_back(pa[src]);
        src = pa[src];
    }
    cout << ans.size() << endl;
    for (int i = ans.size()-1; i >= 0; i--)
        cout << ans[i] << ' ';

}