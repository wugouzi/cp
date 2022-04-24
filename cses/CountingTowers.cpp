//
// Created by wu on 2022/4/22.
//

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n, N=1e9+7;
    cin >> n;
    vector<int> nums(n);
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        k = max(nums[i], k);
    }
    vector<vector<long long>> dp(k+1,vector<long long>(2));
    dp[1][0] = 1, dp[1][1] = 2;
    int sum1 = 1, sum2 = 0;
    for (int i = 2; i <= k; i++) {
        dp[i][0] = sum1+1;
        sum1 += dp[i][0];
        sum1 %= N;
        dp[i][1] += 2*dp[i][0];
        for (int j = 1; j <= i-1; j++) {
            dp[i][1] += dp[j][1] * dp[i-j][1];
        }
        dp[i][1] %= N;
    }
    for (int i = 0; i < n-1; i++)
        cout << dp[nums[i]][1] << endl;
    cout << dp[nums[n-1]][1];
    return 0;
}