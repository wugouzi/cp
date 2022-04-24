//
// Created by wu on 2022/4/22.
//

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int n;
    cin >> n;
    vector<int> dp(n+1,1000000);
    if (n < 10) {
        cout << 1;
        return 0;
    }
    dp[0] = 0;
    for (int i = 1; i < 10; i++) dp[i] = 1;
    for (int i = 10; i <= n; i++) {
        int tp = i;
        while (tp) {
            if (tp%10)
                dp[i] = min(dp[i], dp[i-tp%10]+1);
            tp /= 10;
        }
    }
    cout << dp[n];
    return 0;
}