//
// Created by wu on 2022/4/27.
//

#include "leetcode.h"

int minSessions(vector<int>& tasks, int sessionTime) {
    int n = tasks.size();
    int m = 1 << n;
    vector<pair<int,int>> best(m, {n,sessionTime+1});
    best[0] = {0, 0};
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                auto op = best[i^(1<<j)];
                if (op.second+tasks[j] <= sessionTime)
                    op.second += tasks[j];
                else {
                    op.first++;
                    op.second = tasks[j];
                }
                best[i] = min(best[i], op);
            }
        }
    }
    return best[m-1].first+1;
    /*int m = 1 << n;
    vector<int> sum(m);
    for (int i = 0; i < n; i++)
        for (int j = 0, k = 1 << i; j < k; j++)
            sum[j|k] = sum[j]+tasks[i];
    vector<int> dp(m, n);
    dp[0] = 0;
    for (int i = 1; i < m; i++)
        for (int sub = i; sub; sub = (sub-1)%i)
            if (sum[sub] <= sessionTime)
                dp[i] = min(dp[i], dp[i^sub]+1);
    return dp[m-1];*/
}

int main(void) {
    vector<int> nums = {1,2,3};
    cout << minSessions(nums, 3);
}