//
// Created by wu on 2022/3/31.
//
#include "leetcode.h"

vector<int> tree;
int tn;
void add(int i) {
    while (i < tn) {
        tree[i]++;
        i += (-i&i);
    }
}
int query(int i) {
    int sum = 0;
    while (i >= 1) {
        sum += tree[i];
        i -= (-i&i);
    }
    return sum;
}
int reversePairs(vector<int>& nums) {
    /*ans = 0;
    int n = nums.size();
    if (nums.empty()) return 0;
    vector<int> tmp(n);
    return mergesort(nums, tmp, 0, n-1);*/
    int ans = 0;
    int n = nums.size();
    tn = n+1;
    vector<int> tmp = nums;
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for (auto& num : nums) {
        num = lower_bound(tmp.begin(), tmp.end(), num) - tmp.begin()+1;
    }
    tree.resize(n+1);
    for (int i = nums.size()-1; i >= 0; i--) {
        ans += query(nums[i]);
        add(nums[i]);
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1,3,2,3,1};
    cout << reversePairs(nums);
}
