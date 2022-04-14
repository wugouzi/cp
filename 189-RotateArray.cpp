//
// Created by wu on 2022/4/8.
//

#include "leetcode.h"

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = n-k%n;
    int cnt = gcd(k,n);
    for (int i = 0; i < cnt; i++) {
        int j = i;
        do {
            swap(nums[j], nums[(j+k)%n]);
            j = (j+k)%n;
            cnt++;
        } while ((j+k)%n != i);
    }
}

int main(void) {
    vector<int> nums = {1,2,3,4,5,6,7};
    int k = 3;
    rotate(nums, k);
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
}