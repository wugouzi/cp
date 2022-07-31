//
// Created by wu on 2022/2/27.
//
#include <vector>
#include <iostream>

using namespace std;
int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 1) return target == nums[0] ? 0 : -1;
    int l = 0, r = n - 1;
    while (l < r) {
        int med = (l + r) / 2;
        int medval = nums[med];
        if (target == medval) return med;
        else if (medval > nums[r] && target > medval) l = med + 1;
        else if (medval > nums[r] && target < medval && target >= nums[0]) r = med - 1;
        else if (medval > nums[r]) l = med + 1;
        else if (medval < nums[l] && target < medval) r = med - 1;
        else if (medval < nums[l] && target > medval && target <= nums[n - 1]) l = med + 1;
        else if (medval < nums[l]) r = med - 1;
        else if (target < medval) r = med - 1;
        else if (target > medval) l = med + 1;
    }
    return nums[l] == target ? l : -1;
}
int main (void) {
    vector<int> nums = {3,5,1};
    cout << search(nums, 3);
}