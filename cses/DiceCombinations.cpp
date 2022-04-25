#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n, N=1e9+7;
    cin >> n;
    vector<unsigned long long> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        int tp = min(i, 6);
        for (int j = 1; j <= tp; j++)
            dp[i] += dp[i-j];
        dp[i] %= N;
    }
    cout << dp[n];
    return 0;
}