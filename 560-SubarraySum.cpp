//
// Created by wu on 2022/3/14.
//

#include "leetcode.h"

int subarraySum(vector<int>& nums, int k) {
    int sum = 0;
    int cnt = 0;
    int l = -1;
    for (int r = 0; r < nums.size(); r++) {
        sum += nums[r];
        while (sum > k) sum -= nums[++l];
        if (sum == k && l < r) cnt++;
    }
    int kk = nums.size() - 1;
    if (l < kk) cout << -1;
    else if (l == kk) cout << -2;
    else if (l > kk) cout << -3;
    while(l < kk) {
        sum -= nums[++l];
        cout << l << ' ' << sum << endl;
        if (sum == k) cnt++;
    }
    return cnt;
}

int main(void) {
    vector<int> nums = {-1,-1,-1};
    int k = 0;
    cout << subarraySum(nums, k);
}