//
// Created by wu on 2023/3/25.
//

#include "leetcode.h"

vector<int> ds;
int dp[10][1<<10][2];
int f(int i, int mask, bool same) {
    if (dp[i][mask][same]) return dp[i][mask][same];
    if (i == ds.size()) return 1;
    int t = same ? ds[i] : 9;
    for (int j = 0; j <= t; j++) {
        if (mask & (1 << j)) continue;
        dp[i][mask][same] += f(i+1, mask == 0 && j == 0 ? mask : mask | (1 << j), same * (j == ds[i]));
    }
    return dp[i][mask][same];
}
int numDupDigitsAtMostN(int n) {
    int tp = n;
    while (tp) {
        ds.push_back(tp%10);
        tp /= 10;
    }
    reverse(ds.begin(), ds.end());
    return n + 1 - f(0, 0, 1);
}

int main(void) {
    cout << numDupDigitsAtMostN(100);
}