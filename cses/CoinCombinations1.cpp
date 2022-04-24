//
// Created by wu on 2022/4/21.
//

#include <iostream>
#include <vector>

using namespace std;
int main(void) {
    int n, sum,N=1e9+7;
    cin >> n >> sum;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    vector<long long> dp(sum+1);
    dp[0] = 1;
    for (int i = 1; i <= sum; i++) {
        for (auto &c: coins)
            if (i >= c && dp[i - c])
                dp[i] += dp[i - c];
        dp[i] %= N;
    }
    cout << dp[sum];
}