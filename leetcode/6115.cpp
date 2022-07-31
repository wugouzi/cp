//
// Created by wu on 2022/7/10.
//

#include "leetcode.h"

long long dp[10004];
int idealArrays(int n, int maxValue) {
    int mod = 1e9+7;
    for (int i = 1; i <= maxValue; i++)
        dp[i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = maxValue; j >= 1; j--) {
            for (int k = 2; j*k <= maxValue; k++) {
                dp[j*k] += dp[j];
                dp[j*k] %= mod;
            }
        }
    }
    long long ans = 0;
    for (int i = 1; i <= maxValue; i++) {
        ans += dp[i];
        ans %= mod;
    }
    return ans;
}

int main(void) {
    cout << idealArrays(9767,9557);
}
