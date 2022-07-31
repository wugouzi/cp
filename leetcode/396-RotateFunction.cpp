//
// Created by wu on 2022/4/22.
//

#include "leetcode.h"

int maxRotateFunction(vector<int>& nums) {
    int ans, n = nums.size();
    int cur = 0;
    int pass = 0;
    for (int i = 0; i < n; i++) {
        cur += nums[i]*i;
        pass += nums[i];
    }
    ans = cur;
    for (int j = 1; j < n; j++) {
        cur += pass - n*nums[n-j-1];
        ans = max(ans, cur);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {4,3,2,6};
    cout << maxRotateFunction(nums);
}