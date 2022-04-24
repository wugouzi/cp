//
// Created by wu on 2022/4/21.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, sum, N=1e9+7;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<long long> dp(sum+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= sum; j++)
            if (j >= coins[i]) {
                dp[j] += dp[j-coins[i]];
                dp[j] %= N;
            }
    cout << dp[sum];
    /*vector<vector<long long>> dp(sum+1, vector<long long>(n+1));
    for (int i = 0; i <= n; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1];
            if (coins[j - 1] <= i)
                dp[i][j] += dp[i - coins[j - 1]][j];
            dp[i][j] %= N;
        }
    }
    cout << dp[sum][n];*/
}