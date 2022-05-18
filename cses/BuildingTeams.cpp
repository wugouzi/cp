//
// Created by wu on 2022/5/1.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void) {
    int n, m, t1, t2;
    cin >> n >> m;
    vector<int> color(n+1,-1);
    queue<int> q;
    vector<vector<int>> E(n+1);
    for (int i = 0; i < m; i++) {
        cin >> t1 >> t2;
        E[t1].push_back(t2);
        E[t2].push_back(t1);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                t1 = q.front();
                q.pop();
                for (auto& t2 : E[t1]) {
                    if (color[t2] == color[t1]) {
                        cout << "IMPOSSIBLE";
                        return 0;
                    }
                    if (color[t2] == -1) {
                        color[t2] = 1-color[t1];
                        q.push(t2);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << color[i]+1 << ' ';
}