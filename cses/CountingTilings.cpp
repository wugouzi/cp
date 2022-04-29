//
// Created by wu on 2022/4/28.
//

#include <iostream>
#include <vector>
//https://discuss.codechef.com/t/bitmask-dp-note-cses-counting-tilings/92175
using namespace std;
int main(void) {
    int n, m, N=1e9+7;
    cin >> n >> m;
    vector<int> dp(1<<n);
    dp[(1<<n)-1] = 1;
    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++) {
            vector<int> DP(1<<n);
            for (int k = 0; k < 1<<n; k++) {
                (DP[k] = dp[k^(1<<i)])%=N;
                if (i && (k&1<<i) && (k&1<<(i-1)))
                    (DP[k] += dp[k^(1<<(i-1))])%=N;
            }
            swap(dp, DP);
        }
    cout << dp[(1<<n)-1];
    return 0;
}