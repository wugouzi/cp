//
// Created by wu on 2022/3/13.
//

#include "leetcode.h"

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for (auto& c : nums) sum += c;
    if ((sum-target) & 1) return 0;
    int neg = (sum - target)/2;
    if (neg < 0) return 0;
    int n = nums.size();
    vector<int> dp(neg+1);
    dp[0] = 1;
    for (auto& c : nums) {
        for (int j = 0; j <= neg; j++) {
            if (j >= c) dp[j] += dp[j-c];
        }
    }
    return dp[neg];
    /*vector<vector<int>> dp(n+1, vector<int>(neg+1));

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= neg; j++) {
            int num = nums[i-1];
            dp[i][j] = dp[i-1][j];
            if (j >= num) dp[i][j] += dp[i-1][j-num];
        }
    }
    return dp[n][neg];*/

}

int main(void) {
    vector<int> nums = {1,2,1};
    int tar = 0;
    cout << findTargetSumWays(nums, tar);
}