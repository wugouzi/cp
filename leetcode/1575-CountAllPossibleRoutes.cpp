//
// Created by wu on 2022/10/12.
//

#include "leetcode.h"

using ll = long long;
int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
    int n = locations.size();
    int mod = 1e9+7;
    vector<int> idx(n);
    for (int i = 0; i < n; i++) idx[i] = i;
    sort(idx.begin(), idx.end(), [&](const int &s1, const int &s2) {
        return locations[s1] < locations[s2];
    });
    for (auto &n : idx) { if (idx[n] == start) {start = n; break;}}
    for (auto &n : idx) { if (idx[n] == finish) {finish = n; break;}}
    vector<vector<ll>> dp(n, vector<ll>(fuel+1, -1));

    function<int(int,int)> dfs = [&](int i, int f) {
        if (dp[i][f] != -1)
            return dp[i][f];
        if (i == finish)
            dp[i][f] = 1;
        else
            dp[i][f] = 0;
        int diff = 0, j = i + 1;
        while (j < n && (diff = locations[idx[j]] - locations[idx[i]]) <= f)
            (dp[i][f] += dfs(j++, f - diff)) %= mod;
        j = i - 1;
        while (j >= 0 && (diff = locations[idx[i]] - locations[idx[j]]) <= f)
            (dp[i][f] += dfs(j--, f - diff)) %= mod;
        return dp[i][f];
    };
    return dfs(start, fuel);
}

int main(void) {
    vector<int> l{2,3,6,8,4};
    int s = 1;
    int f = 3;
    int ff = 5;
    cout << countRoutes(l, s, f, ff);
}