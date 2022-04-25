//
// Created by wu on 2022/4/24.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(void) {
    int n, m, tp;
    cin >> n >> m;
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; i++)
        dp[i][1] = i-1;
    for (int i = 1; i <= m; i++)
        dp[1][i] = i-1;
    for (int i = 2; i <= n; i++)
        for (int j = 2; j <= m; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            int tp = INT_MAX;
            for (int k = 1; k < i; k++)
                tp = min(tp, dp[k][j]+dp[i-k][j]+1);
            for (int k = 1; k < j; k++)
                tp = min(tp, dp[i][k]+dp[i][j-k]+1);
            dp[i][j] = tp;
        }
    cout << dp[n][m];
    return 0;
}