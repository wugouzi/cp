//
// Created by wu on 2022/3/13.
//
#include "leetcode.h"
vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    int n = nums.size();
    vector<int> left(n,-k-1), right(n,n+k);
    if (nums[0] == key) left[0] = 0;
    if (nums[n-1] == key) right[n-1] = n-1;
    for (int i = 1; i < n; i++) {
        left[i] = nums[i] == key ? i : left[i-1];
    }
    for (int j = n-2; j >= 0; j--)
        right[j] = nums[j] == key ? j : right[j+1];
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (i - left[i] <= k || right[i] - i <= k) ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(void) {
    vector<int> nums = {3,4,9,1,3,9,5};
    int key = 9, k = 1;
    vector<int> tp = findKDistantIndices(nums, key, k);
    for (int i = 0; i < tp.size(); i++) cout << tp[i] << ' ';
}

