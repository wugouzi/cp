//
// Created by wu on 2022/3/7.
//

#include <vector>
#include <iostream>
using namespace std;
int findDuplicate(vector<int>& nums) {
    /*unordered_map<int, bool> s;
    for (int i = 0; i < nums.size(); i++)
        if (s.find(nums[i]) == s.end())
            s[nums[i]] = true;
        else return nums[i];
    return -1;*/
    int n = nums.size();
    int l = 1, r = n-1;
    int ans = l;
    while (l <= r) {
        int med = (l+r)/2;
        int cnt = 0;
        for (int i = 0; i < n; i++) cnt += nums[i] <= med;
        if (cnt <= med) l = med + 1;
        else {
            r = med-1;
            ans = med;
        }
    }
    return ans;
}

int main(void) {
    vector<int> nums = {1,2,2};
    cout << findDuplicate(nums);
}