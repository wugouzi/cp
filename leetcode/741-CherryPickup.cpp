//
// Created by wu on 2022/7/10.
//
#include "leetcode.h"
int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
    dp[0][0] = grid[0][0];
    for (int k = 1; k < 2*n-1; k++) {
        for (int i = min(k, n - 1); i >= max(k - n + 1, 0); i--) {
            for (int j = min(k, n - 1); j >= i; j--) {
                if (grid[j][k - j] == -1 || grid[i][k - i] == -1) {
                    dp[i][j] = INT_MIN / 2;
                    continue;
                }
                int tp = dp[i][j];
                if (i > 0 && j > 0)
                    tp = max(tp, dp[i - 1][j - 1]);
                if (i > 0)
                    tp = max(tp, dp[i - 1][j]);
                if (j > 0)
                    tp = max(tp, dp[i][j - 1]);
                //cout << i << ' ' << k-i << ' ' << grid[i][k-i] << endl;
                tp += grid[i][k - i];
                if (i != j)
                    tp += grid[j][k - j];
                dp[i][j] = tp;
            }
        }
    }
    return max(dp[n-1][n-1],0);
}


int main(void) {
    vector<vector<int>> g = {{1,1,-1},{1,-1,1},{-1,1,1}};
    //vector<vector<int>> g = {{0,1,-1},{1,0,-1},{1,1,1}};
    cout << cherryPickup(g);
}