//
// Created by wu on 2022/9/25.
//
#include "leetcode.h"
vector<int> goodIndices(vector<int>& nums, int k) {
    int des = 1, eq = 1, n = nums.size();

    vector<int> ans;
    if (k == 1) {
        for (int i = 1; i < n-1; i++)
            ans.push_back(i);
        return ans;
    }
    for (int i = 1; i < n; i++) {
        if (des >= k) {
            int j = i + 1;
            while (j < n && nums[j] == nums[i]) j++;
            int eq = j;
            while (j < n && nums[j] >= nums[j-1]) j++;
            while (i < eq && j - i >= k) {
                ans.push_back(i);
                i++;
            }
            i = j - 1;
            des = 1;
        } else if (nums[i] <= nums[i-1])
            des++;
        else
            des = 1;

    }
    return ans;
}

int main(void) {
    int k = 1;
    vector<int> nums = {4,8,7,9,1,3,5,8};
    nums = goodIndices(nums, k);
    for (auto &n : nums) cout << n << ' ';
}