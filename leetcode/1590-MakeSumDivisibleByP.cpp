//
// Created by wu on 2023/3/11.
//

#include "leetcode.h"

int minSubarray(vector<int>& nums, int p) {
    int len = INT_MAX;

    int tar = 0, sum;
    for (auto &n : nums)
        (tar += n) %= p;
    if (tar == 0)
        return 0;
    unordered_map<int,int> mp;
    mp[0] = -1;
    sum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        (sum += nums[i]) %= p;
        mp[sum] = i;
        int tp = ((sum - tar) % p + p) % p;
        if (mp.count(tp) && i - mp[tp] < len) {
            len = i - mp[tp];
        }
    }
    if (len == INT_MAX)
        return -1;
    return len;
}

int main(void) {
    vector<int> t{1,2,3};
    int n = 7;
    //vector<int> t{8,32,31,18,34,20,21,13,1,27,23,22,11,15,30,4,2};
    //int n = 148;
    cout << minSubarray(t,n);
}