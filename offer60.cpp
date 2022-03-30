//
// Created by wu on 2022/3/26.
//
#include "leetcode.h"

vector<double> dicesProbability(int n) {
    vector<double> dp(6*n+1);
    dp[1] = dp[2] = dp[3] = dp[4] = dp[5] = dp[6] = 1.0/6;
    for (int i = 2; i <= n; i++) {
        for (int j = 6*i; j >= i; j--) {
            dp[j] = 0;
            if (j == 7) {
                int a = 0;
            }
            for (int k = min(6 * (i-1), j-1); k >= max(j-6, i-1); k--) {

                dp[j] += dp[k] / 6;
            }

        }
    }
    return vector<double>(dp.begin()+n, dp.end());
}

int main(void) {
    vector<double> tp = dicesProbability(3);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}
