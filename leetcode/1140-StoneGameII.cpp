//
// Created by wu on 2023/2/22.
//

#include "leetcode.h"

int stoneGameII(vector<int>& piles) {
    int n = piles.size();
    vector<long long> pref(n+1);
    vector<vector<long long>> dp(n+1, vector<long long>(400, INT_MIN));
    for (int i = 1; i <= n; i++)
        pref[i] = pref[i-1] + piles[i-1];
    function<long long(int,int)> dfs = [&](int i, int d) {
        if (dp[i][d] != INT_MIN)
            return dp[i][d];
        if (i == n)
            return 0LL;
        for (int j = 1; j <= d*2 && i + j <= n; j++) {
            dp[i][d] = max(dp[i][d], pref[i+j]-pref[i]-dfs(i+j, max(d,j)));
        }
        return dp[i][d];
    };
    dfs(0,1);
    return (pref[n]+dp[0][1])/2;
}

int main(void) {
    vector<int> p = {2,7,9,4,4};
    cout << stoneGameII(p);
}