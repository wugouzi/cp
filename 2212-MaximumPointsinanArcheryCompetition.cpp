//
// Created by wu on 2022/3/21.
//

#include "leetcode.h"

vector<int> maximumBobPoints(int n, vector<int>& aliceArrows) {
    vector<vector<int>> dp(12, vector<int>(n+1));
    for (int i = 1; i < 12; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = dp[i-1][j];
            if (aliceArrows[i] < j)
                dp[i][j] = max(dp[i][j], dp[i-1][j-aliceArrows[i]-1]+i);
        }
    }
    vector<int> ans(12,0);
    for (int i = 11; i > 0; i--) {
        if (dp[i][n] > dp[i-1][n]) {
            ans[i] = aliceArrows[i]+1;
            n -= aliceArrows[i]+1;
        }
    }
    return ans;
}

int main(void) {
    int n = 3;
    vector<int> a = {0,0,1,0,0,0,0,0,0,0,0,2};
    vector<int> tp = maximumBobPoints(n, a);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}