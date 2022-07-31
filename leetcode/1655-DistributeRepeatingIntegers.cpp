//
// Created by wu on 2022/4/29.
//

#include "leetcode.h"

bool canDistribute(vector<int>& nums, vector<int>& quantity) {
    unordered_map<int,int> mp;
    for (auto& c : nums)
        mp[c]++;
    vector<int> cnts;
    for (auto& [_,n] : mp)
        cnts.push_back(n);
    int nc = cnts.size(), nq = quantity.size();
    vector<vector<int>> dp(nc, vector<int>(1<<nq));
    vector<int> sum(1<<nq);
    for (int k = 0; k < nq; k++)
        for (int i = 0; i < 1<<k; i++)
            sum[(1<<k)|i]=sum[i]+quantity[k];
    for (int i = 0; i < (1<<nq); i++)
        if (sum[i] <= cnts[0])
            dp[0][i] = true;
    for (int i = 0; i < nc; i++)
        dp[i][0] = true;
    for (int i = 1; i < nc; i++)
        for (int j = 1; j < 1 << nq; j++) {
            dp[i][j] = dp[i-1][j];
            for (int sub = j; sub; sub = (sub - 1) & j)
                if (sum[sub] <= cnts[i])
                    dp[i][j] |= dp[i - 1][j ^ sub];
        }
    return dp[nc-1][(1<<nq)-1];
}

int main(void) {
    vector<int> nums = {128,812,834,231,658,812,905,128,124,403,812,796,995,510,128,128,750,128,128,128,665,995,812,728,665,128,252,273,252,830,665,128,273,128,128,665,687,785,665,419,834,633,338,665,128,128,128,812,97,720,252,319,620,710,853,128,128,252,812,661,273,231,812,128,410,828,128,84,458,252,252,853,698,128,252},
    q = {15,7};
    cout << canDistribute(nums, q);
}