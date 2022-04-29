//
// Created by wu on 2022/4/29.
//

#include <iostream>
#include <string>

using namespace std;
long long dp[20];
long long solve(long long c) {
    if (c == 0) return 1;
    if (c < 0) return 0;
    string s = to_string(c);
    int n = s.size();
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += dp[i];
    int prev = 0;
    for (int i = 0; i < n; i++) {
        int digit = s[i]-'0';

        int diff = n-i-1;
        int below = prev < digit ? digit-1 : digit;
        res += digit == 0 ? 0 : below*dp[diff];
        if (prev == digit)
            return res;
        prev = digit;
    }
    return res+1;
}


int main(void) {
    long long n = 1, m;
    dp[0] = 1;
    for (int i = 1; i < 20; i++) {
        dp[i] = 9*dp[i-1];
    }
    cin >> n >> m;
    cout << solve(m)-solve(n-1);
}