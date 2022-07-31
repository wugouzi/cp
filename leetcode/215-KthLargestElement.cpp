//
// Created by wu on 2022/3/5.
//
#include <vector>
#include <iostream>

using namespace std;
void swap(vector<int>& nums, int i, int j) {
    int tp = nums[i];
    nums[i] = nums[j];
    nums[j] = tp;
}
int partition(vector<int>&nums, int l, int r) {
    int p = nums[r];
    int i = l - 1;
    for (int j = l; j < r; j++)
        if (nums[j] <= p)
            swap(nums,++i, j);
    swap(nums,++i, r);
    return i;
}
int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    k = nums.size() - k;
    int p = -1;
    while (p != k) {
        p = partition(nums, l, r);
        if (p > k) r = p - 1;
        else if (p < k) l = p + 1;
    }
    return nums[p];
}

int main(void) {
    vector<int> nums = {3,2,1,5,6,4};
    //vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 2;
    cout << findKthLargest(nums, k);
}