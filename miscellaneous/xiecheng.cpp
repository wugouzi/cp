//
// Created by wu on 2023/3/29.
//
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using pp = pair<int, int>;
using ll = long long;
vector<vector<pp>> E;
ll dp[100100][2];
int dfs(int i, int c, vector<int> &vis) {
    if (dp[i][c]) return dp[i][c];
    if (E[i].size() == 0) return 0;
    ll sum = 0, ret = 0;
    vis[i] = 1;
    unordered_map<int,int> mp;
    for (auto &p : E[i])
        if (!vis[p.first]) {
            if (dfs(p.first, 0, vis) > dfs(p.first, 1, vis)) {
                mp[p.first] = 1;
                sum += dp[p.first][0];
            } else {
                mp[p.first] = 2;
                sum += dp[p.first][1];
            }
        }
    dp[i][1] = sum;
    if (c == 1) {
        vis[i] = 0;
        return sum;
    }

    for (auto &p : E[i]) {
        if (!vis[p.first]) {
            if (mp[p.first] == 1)
                ret = max(ret, sum - dp[p.first][0] + dp[p.first][1] + p.second);
            else
                ret = max(ret, sum + p.second);
        }
    }
    dp[i][0] = ret;
    vis[i] = 0;
    return dp[i][0];
}
int main(void) {
    int n, a, b, c;
    cin >> n;
    E.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        E[a - 1].push_back(make_pair(b - 1, c));
        E[b - 1].push_back(make_pair(a-1, c));
    }
    vector<int> vis(n);

    cout << max(dfs(0, 0, vis), dfs(0, 1, vis));
}

/*
8
1 2 2
1 3 3
2 4 4
2 5 5
3 6 6
3 7 1
5 8 20
 */