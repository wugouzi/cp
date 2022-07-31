//
// Created by wu on 2022/3/21.
//

#include "leetcode.h"

int maxDistance(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, INT_MAX/2));
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i-1][j-1] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j>= 1; j--) {
            if (i+1 <= n)
                dp[i][j] = min(dp[i][j], dp[i+1][j]+1);
            if (j+1 <= m)
                dp[i][j] = min(dp[i][j], dp[i][j+1]+1);
            if (grid[i-1][j-1] == 0)
                ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}

int main(void) {
    vector<vector<int>> tp = {{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1}};
    cout << maxDistance(tp);
}