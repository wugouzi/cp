//
// Created by wu on 2022/6/25.
//

#include "leetcode.h"

int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(),nums.end());
    int n = nums.size();
    int l = 0, r = nums[n-1]-nums[0];
    while (l < r) {
        int med = (l+r)/2;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += lower_bound(nums.begin() + i, nums.end(), nums[i] + med+1)-nums.begin()-i-1;
        }
        if (cnt >= k) r = med;
        else l = med+1;
    }
    return l;
}

int main(void) {
    vector<int> n = {62,100,4};
    int k = 2;
    cout << smallestDistancePair(n,k);
}