//
// Created by wu on 2022/7/2.
//

#include "leetcode.h"

int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    int n = stations.size();
    vector<int> dp(n+1);
    dp[0] = startFuel;
    if (dp[0] >= target)
        return 0;
    sort(stations.begin(),stations.end());

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n && stations[j][0] <= dp[i-1]; j++)
            dp[i] = max(dp[i], dp[i-1]+stations[j][1]);
        if (dp[i] >= target)
            return i;
    }
    return -1;
}

int main(void) {
    int s = 1000;
    int sf = 83;
    vector<vector<int>> ss = {{25,27},{36,187},{140,186},{378,6},{492,202},{517,89},{579,234},{673,86},{808,53},{954,49}};
    cout << minRefuelStops(s,sf,ss);
}