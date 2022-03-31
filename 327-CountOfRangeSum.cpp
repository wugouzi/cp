//
// Created by wu on 2022/3/31.
//

#include "leetcode.h"

int low, up;
int merge(vector<int>& nums, vector<int>& tmp, int l, int r) {
    if (l == r) return nums[l] >= low && nums[l] <= up;
    int med = (l+r)/2;
    int cnt = merge(nums, tmp, l, med) + merge(nums, tmp, med+1, r);
    int ll = med+1, rr = med+1, i = l;
    while (i <= med) {
        while (ll <= r && nums[ll] - nums[i] < low) ll++;
        while (rr <= r && nums[rr] - nums[i] <= up) rr++;
        cnt += rr-ll;
        i++;
    }
    int j = med+1, pos = 0;
    i = l;
    while (i <= med && j <= r)
        tmp[pos++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    while (i <= med)
        tmp[pos++] = nums[i++];
    while (j <= r)
        tmp[pos++] = nums[j++];
    copy(tmp.begin(), tmp.begin()+pos, nums.begin()+l);
    return cnt;
}
int countRangeSum(vector<int>& nums, int lower, int upper) {
    low = lower, up = upper;
    for (int i = 1; i < nums.size(); i++)
        nums[i] += nums[i-1];
    vector<int> tmp(nums.size());
    return merge(nums, tmp, 0, nums.size()-1);
}

int main(void) {
    vector<int> nums = {-2,5,-1};
    int lower = -2;
    int upper = 2;
    cout << countRangeSum(nums, lower, upper);
}