//
// Created by wu on 2022/9/11.
//

#include "leetcode.h"

vector<int> mm;

void modify(int o, int l, int r, int i, int val) {
    if (l == r) {
        mm[o] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (i <= mid)
        modify(2 * o, l, mid, i, val);
    else
        modify(2 * o + 1, mid + 1, r, i, val);
    mm[o] = std::max(mm[2 * o], mm[2 * o + 1]);
}

int query(int o, int l, int r, int L, int R) {
    if (L <= l && R >= r)
        return mm[o];
    int mid = (l + r) / 2;
    int res = 0;
    if (L <= mid)
        res = query(2 * o, l, mid, L, R);
    if (R >= mid + 1)
        res = std::max(res, query(2 * o + 1, mid + 1, r, L, R));
    return res;
}

int lengthOfLIS(vector<int> &nums, int k) {
    int u = *max_element(nums.begin(), nums.end());
    mm.resize(u * 4);
    for (auto &n: nums) {
        if (n == 1)
            modify(1, 1, u, 1, 1);
        else {
            int tmp = 1 + query(1, 1, u, std::max(n - k, 1), n - 1);
            modify(1, 1, u, n, tmp);
        }
    }
    return mm[1];
}

int main(void) {
    vector<int> nums = {4, 2, 1, 4, 3, 4, 5, 8, 15};
    int k = 3;
    cout << lengthOfLIS(nums, k);
}