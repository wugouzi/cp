//
// Created by wu on 2022/3/29.
//

#include "leetcode.h"

int maxConsecutiveAnswers(string ak, int k) {
    int n = ak.size();
    if (k >= n) return n;
    vector<int> dp(k+1,1);
    for (int i = 1; i < n; i++) {
        for (int j = k; j >= 0; j--)
            if (ak[i] == ak[i-1])
                dp[j]++;
            else if (j > 0)
                dp[j] = dp[j-1]+1;
    }
    return *max_element(dp.begin(), dp.end());
}

int main(void) {
    string s = "TTFTTTTTFT";
    int k = 1;
    cout << maxConsecutiveAnswers(s, k);
}