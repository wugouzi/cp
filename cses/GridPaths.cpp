//
// Created by wu on 2022/4/22.
//

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(void) {
    int n, N=1e9+7;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(n));
    char tp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tp;
            if (tp == '*')
                dp[i][j] = -1;
        }
    }
    if (dp[0][0] == -1 || dp[n-1][n-1] == -1) {
        cout << 0;
        return 0;
    }
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (dp[i][0] == 0)
            dp[i][0] = dp[i-1][0];
        if (dp[0][i] == 0)
            dp[0][i] = dp[0][i-1];
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < n; j++)
            if (dp[i][j] != -1) {
                if (dp[i-1][j] != -1)
                    dp[i][j] += dp[i-1][j];
                if (dp[i][j-1] != -1)
                    dp[i][j] += dp[i][j-1];
                dp[i][j] %= N;
            }
    cout << dp[n-1][n-1];
    return 0;
}