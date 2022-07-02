//
// Created by wu on 2022/6/1.
//

#include <iostream>

using namespace std;
long long dp[200001];
const long long mod = 1000000007;
int main(void) {
    int n, m;
    for (int i = 0; i <= 8; i++)
        dp[i] = 2;
    dp[9] = 3;
    for (int i = 10; i <= 200000;i++) {
        dp[i] = (dp[i - 9] + dp[i - 10])%mod;
    }
    int t;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        long long ans = 0;
        while (n>0) {
            int d = n%10;
            ans += d+m<10 ? 1 : dp[m-10+d];
            ans %= mod;
            n/=10;
        }
        cout << ans << "\n";
    }
}