//
// Created by wu on 2022/10/12.
//

#include "leetcode.h"

int numPermsDISequence(string s) {
    int n = s.size();
    vector<int> dp(n+1, 1);
    vector<int> tp(n+1);
    for (int i = 1; i <= n; i++) {
        if (s[i-1] == 'D') {
            tp[n-i+1] = 0;
            for (int j = n-i; j >= 0; j--)
                tp[j] = tp[j+1]+dp[j+1];
        } else {
            tp[0] = dp[0];
            for (int j = 1; j <= n-i; j++)
                tp[j] = tp[j-1]+dp[j];
        }
        dp = tp;
    }
    return dp[0];
}

int main(void) {
    cout << numPermsDISequence("DD");
}