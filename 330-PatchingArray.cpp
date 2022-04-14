//
// Created by wu on 2022/4/14.
//

#include "leetcode.h"

int minPatches(vector<int>& nums, int n) {
    int i = 0, ans = 0, k = nums.size();
    long long r = 1;
    while (r <= n) {
        if (i >= k || r < nums[i]) {
            ans++;
            r = 2*r;
        } else {
            r += nums[i];
            i++;
        }
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1,3,};
    cout << minPatches(nums, 6);
}