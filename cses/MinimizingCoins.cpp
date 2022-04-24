//
// Created by wu on 2022/4/21.
//

#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(void) {
    int n, sum;
    cin >> n >> sum;
    vector<int> coins(n);
    vector<int> dp(sum+1, INT_MAX);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= sum; i++) {
        for (auto& c : coins)
            if (c <= i && dp[i-c] != INT_MAX)
                dp[i] = min(dp[i], dp[i-c]+1);
    }
    if (dp[sum] == INT_MAX)
        cout << -1;
    else
        cout << dp[sum]-1;
    return 0;
}