//
// Created by wu on 2022/3/9.
//
#include "leetcode.h"
vector<int> ans;
void add(int l, int r) {
    ans[l] += 1;
    if (r + 1 < ans.size()) ans[r+1] -= 1;
}
int bestRotation(vector<int>& nums) {
    int n = nums.size();
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        int r1 = n + i - x;
        int r2 = i - x;
        if (r1 > i) add(i+1,r1);
        if (r2 >= 0) add(0,r2);
    }
    int tp1=0, tp2=0, tp3 = -1;
    for (int i = 0; i < n; i++) {
        tp1 += ans[i];
        if (tp1 > tp2) {
            tp2 = tp1;
            tp3 = i;
        }
    }
    return tp3;
}

int main(void) {
    vector<int> nums = {2,3,1,4,0};
    cout << bestRotation(nums);
}