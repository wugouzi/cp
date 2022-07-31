//
// Created by wu on 2022/4/5.
//

#include "leetcode.h"

void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    auto midptr = nums.begin()+(n-1)/2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    int i = 0, j = 0, k = n-1;
    while (j <= k) {
        if (nums[i] < mid) {
            swap(nums[i], nums[j]);
            i++;
            j++;
        } else if (nums[i] == mid)
            j++;
        else {
            swap(nums[j], nums[k]);
            k--;
        }
    }

    vector<int> tmp1(nums.begin(), midptr+1);
    vector<int> tmp2(midptr+1, nums.end());
    int n1 = tmp1.size(), n2 = n-n1;
    for (int i = 0; i < n1; i++)
        nums[2 * i] = tmp1[n1-1-i];
    for (int i = 0; i < n2; i++)
        nums[2*i+1] = tmp2[n2-1-i];
}

int main(void) {
    vector<int> nums = {4,5,5,5,5,6,6,6};
    wiggleSort(nums);
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << ' ';
}