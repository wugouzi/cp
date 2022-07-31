//
// Created by wu on 2022/3/15.
//

#include "leetcode.h"

int maximumGap(vector<int>& nums) {
    int nmax = 0;
    for (auto& c : nums) nmax = max(nmax, c);
    int n = nums.size();
    double ep = (double) n / nmax;
    vector<vector<int>> bucket(n);
    for (int i = 0; i < n; i++) {
        int nth = floor(ep * nums[i]);
        if (nth == n) nth--;
        bucket[nth].push_back(nums[i]);
        if (bucket[nth].size() > 1) sort(bucket[nth].begin(), bucket[nth].end());
    }
    int l = -1;
    int ans = 0;
    for (auto& c : bucket)
        for (auto& d : c) {
            if (l == -1) l = d;
            else {
                ans = max(d-l, ans);
                l = d;
            }
        }
    return ans;
}

int main(void) {
    vector<int> nums = {3,6,9,1};
    cout << maximumGap(nums);
}